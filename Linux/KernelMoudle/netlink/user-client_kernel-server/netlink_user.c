#include <stdint.h>
#include <sys/socket.h>
#include <linux/netlink.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#define NETLINK_TEST    30
#define MAX_PAYLOAD     1024    /* maximum payload size*/
#define MAX_NL_BUFSIZ   NLMSG_SPACE(MAX_PAYLOAD)

int PORTID = 1;

int create_nl_socket(uint32_t pid, uint32_t groups)
{
    int fd = socket(PF_NETLINK, SOCK_RAW, NETLINK_TEST);
    if (fd == -1) {
        return -1;
    }

    struct sockaddr_nl addr;
    memset(&addr, 0, sizeof(addr));
    addr.nl_family = AF_NETLINK;
    addr.nl_pid = pid;
    addr.nl_groups = groups;

    if (bind(fd, (struct sockaddr *)&addr, sizeof(addr)) != 0) {
        close(fd);
        return -1;
    }

    return fd;
}

ssize_t nl_recv(int fd)
{
    char nl_tmp_buffer[MAX_NL_BUFSIZ];
    struct nlmsghdr *nlh;
    ssize_t ret;

    // 设置 Netlink 消息缓冲区
    nlh = (struct nlmsghdr *)&nl_tmp_buffer;
    memset(nlh, 0, MAX_NL_BUFSIZ);

    ret = recvfrom(fd, nlh, MAX_NL_BUFSIZ, 0, NULL, NULL);
    if (ret < 0) {
        return ret;
    }

    // // 通过MSG结构体来发送信息
    // struct iovec iov;
    // struct msghdr msg;
    // iov.iov_base = (void *)nlh;
    // iov.iov_len = MAX_NL_BUFSIZ;
    // msg.msg_name = (void *)&addr;
    // msg.msg_namelen = sizeof(*addr);
    // msg.msg_iov = &iov;
    // msg.msg_iovlen = 1;
    // ret = recvmsg(fd, &msg, 0);
    // if (ret < 0) {
    // return ret;
    // }

    printf("==== LEN(%d) TYPE(%d) FLAGS(%d) SEQ(%d) PID(%d)\n\n", nlh->nlmsg_len, nlh->nlmsg_type,
           nlh->nlmsg_flags, nlh->nlmsg_seq, nlh->nlmsg_pid);
    printf("Received data: %s\n", NLMSG_DATA(nlh));
    return ret;
}

int nl_sendto(int fd, void *buffer, size_t size, uint32_t pid, uint32_t groups)
{
    char nl_tmp_buffer[MAX_NL_BUFSIZ];
    struct nlmsghdr *nlh;

    if (NLMSG_SPACE(size) > MAX_NL_BUFSIZ) {
        return -1;
    }

    // 目的地址信息
    struct sockaddr_nl addr;
    memset(&addr, 0, sizeof(addr));
    addr.nl_family = AF_NETLINK;
    addr.nl_pid = pid;          /* Send messages to the linux kernel. */
    addr.nl_groups = groups;    /* unicast */

/*
   消息格式：
	 <--- nlmsg_total_size(payload)  --->
	 <-- nlmsg_msg_size(payload) ->
	+----------+- - -+-------------+- - -+------------
	| nlmsghdr | Pad |   Payload   | Pad | nlmsghdr
	+----------+- - -+-------------+- - -+------------
	nlmsg_data(nlh)---^                   ^
	nlmsg_next(nlh)-----------------------+

   消息头结构体：
	struct nlmsghdr {
	    __u32       nlmsg_len;     
	    __u16       nlmsg_type;    
	    __u16       nlmsg_flags;   
	    __u32       nlmsg_seq;     
	    __u32       nlmsg_pid;     
	};
*/
    // 设置 Netlink 消息缓冲区
    nlh = (struct nlmsghdr *)&nl_tmp_buffer;
    memset(nlh, 0, MAX_NL_BUFSIZ);
    nlh->nlmsg_len = NLMSG_LENGTH(size);
    nlh->nlmsg_pid = PORTID;
    memcpy(NLMSG_DATA(nlh), buffer, size);

    printf("====[USER] LEN(%d) TYPE(%d) FLAGS(%d) SEQ(%d) PID(%d)\n", nlh->nlmsg_len, nlh->nlmsg_type,
           nlh->nlmsg_flags, nlh->nlmsg_seq, nlh->nlmsg_pid);
    printf("User send %d bytes: %s\n", size, (char *)buffer);

    return sendto(fd, nlh, NLMSG_LENGTH(size), 0, (struct sockaddr *)&addr, sizeof(addr));

    // // 通过MSG结构体来发送信息
    // struct iovec iov;
    // struct msghdr msg;
    // iov.iov_base = (void *)nlh;
    // iov.iov_len = nlh->nlmsg_len;
    // msg.msg_name = (void *)dst_addr;
    // msg.msg_namelen = sizeof(*dst_addr);
    // msg.msg_iov = &iov;
    // msg.msg_iovlen = 1;
    // return sendmsg(sock_fd, &msg, 0);
}

int main(void)
{
    char data[] = "Hello kernel server, this is user client";
    int sock_fd= 0;
    int ret = 0;
    struct sockaddr_nl addr={};

    // 创建 Netlink 套接字
    sock_fd = socket(PF_NETLINK, SOCK_RAW, NETLINK_TEST);
    if (sock_fd == -1) {
        return -1;
    }

    memset(&addr, 0, sizeof(addr));
    addr.nl_family = AF_NETLINK;
    addr.nl_pid = PORTID;
    addr.nl_groups = 0;

    // 绑定自身 Netlink 套接字相关信息
    if (bind(sock_fd, (struct sockaddr *)&addr, sizeof(addr)) != 0) {
        close(sock_fd);
        return -1;
    }

    // 发送 Netlink 消息
    ret = nl_sendto(sock_fd, data, sizeof(data), 0, 0);
    if (ret < 0) {
        printf("Fail to send\n");
        return 1;
    }
    printf("====[USER] Sent %d bytes in totals\n\n", ret);

    // 接收 Netlink 回复消息
    ret = nl_recv(sock_fd);
    if (ret < 0) {
        printf("Fail to receive\n");
    }
    printf("====[USER] Received %d bytes\n", ret);

    // while (1) {
    // nl_recv(sock_fd);
    // nl_sendto(sock_fd, data, sizeof(data), 0, 0);
    // }

    return 0;
}
