#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <errno.h>

#define SOCKET_PATH "/tmp/split_sendmsg.sock"

void run_sender() {
    int sock = socket(AF_UNIX, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_un addr = {0};
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, SOCKET_PATH, sizeof(addr.sun_path) - 1);

    const char *header = "HEADER: ";
    const char *body = "This is the body.";

    struct iovec iov[2];
    iov[0].iov_base = (void *)header;
    iov[0].iov_len  = strlen(header);
    iov[1].iov_base = (void *)body;
    iov[1].iov_len  = strlen(body);

    struct msghdr msg = {0};
    msg.msg_name    = &addr;
    msg.msg_namelen = sizeof(addr);
    msg.msg_iov     = iov;
    msg.msg_iovlen  = 2;

    if (sendmsg(sock, &msg, 0) == -1) {
        perror("sendmsg");
        close(sock);
        exit(1);
    }

    printf("[Sender] Sent message with header and body\n");
    close(sock);
}

void run_receiver() {
    unlink(SOCKET_PATH);

    int sock = socket(AF_UNIX, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_un addr = {0};
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, SOCKET_PATH, sizeof(addr.sun_path) - 1);

    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        close(sock);
        exit(1);
    }

    char header_buf[128] = {0};
    char body_buf[128]   = {0};

    struct iovec iov[2];
    iov[0].iov_base = header_buf;
    iov[0].iov_len  = sizeof(header_buf);
    iov[1].iov_base = body_buf;
    iov[1].iov_len  = sizeof(body_buf);

    struct msghdr msg = {0};
    msg.msg_iov    = iov;
    msg.msg_iovlen = 2;

    ssize_t n = recvmsg(sock, &msg, 0);
    if (n == -1) {
        perror("recvmsg");
        close(sock);
        exit(1);
    }

    printf("[Receiver] Received: '%s%s'\n", header_buf, body_buf);
    close(sock);
    unlink(SOCKET_PATH);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s sender|receiver\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "sender") == 0) {
        run_sender();
    } else if (strcmp(argv[1], "receiver") == 0) {
        run_receiver();
    } else {
        fprintf(stderr, "Invalid argument. Use sender or receiver.\n");
        return 1;
    }

    return 0;
}
