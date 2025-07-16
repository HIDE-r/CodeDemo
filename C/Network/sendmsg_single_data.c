#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <errno.h>

#define SOCKET_PATH "/tmp/sendmsg_example.sock"

void run_sender() {
    int sock = socket(AF_UNIX, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_un addr = {0};
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, SOCKET_PATH, sizeof(addr.sun_path)-1);

    char msg[] = "Hello from sender";
    struct iovec iov = {
        .iov_base = msg,
        .iov_len = strlen(msg)
    };

    struct msghdr hdr = {0};
    hdr.msg_name = &addr;
    hdr.msg_namelen = sizeof(addr);
    hdr.msg_iov = &iov;
    hdr.msg_iovlen = 1;

    if (sendmsg(sock, &hdr, 0) < 0) {
        perror("sendmsg");
        close(sock);
        exit(1);
    }

    printf("[Sender] Message sent\n");
    close(sock);
}

void run_receiver() {
    unlink(SOCKET_PATH); // 确保没有残留

    int sock = socket(AF_UNIX, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_un addr = {0};
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, SOCKET_PATH, sizeof(addr.sun_path)-1);

    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        close(sock);
        exit(1);
    }

    char buf[256] = {0};
    struct iovec iov = {
        .iov_base = buf,
        .iov_len = sizeof(buf)
    };

    struct msghdr hdr = {0};
    hdr.msg_iov = &iov;
    hdr.msg_iovlen = 1;

    if (recvmsg(sock, &hdr, 0) < 0) {
        perror("recvmsg");
        close(sock);
        exit(1);
    }

    printf("[Receiver] Received: %s\n", buf);
    close(sock);
    unlink(SOCKET_PATH);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s sender|receiver\n", argv[0]);
        return 1;
    }

    if (!strcmp(argv[1], "sender")) {
        run_sender();
    } else if (!strcmp(argv[1], "receiver")) {
        run_receiver();
    } else {
        fprintf(stderr, "Invalid mode. Use sender or receiver\n");
        return 1;
    }

    return 0;
}
