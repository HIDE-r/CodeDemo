// 思路： 防止后续使用 0 1 2 的文件描述符
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#ifndef _PATH_DEVNULL
# define _PATH_DEVNULL "/dev/null"
#endif

void
sanitise_stdfd(void)
{
	int nullfd, dupfd;

	// 尝试打开一个文件获取文件描述符
	if ((nullfd = dupfd = open(_PATH_DEVNULL, O_RDWR)) == -1) {
		fprintf(stderr, "Couldn't open /dev/null: %s\n",
		    strerror(errno));
		exit(1);
	}

	// 如果发现刚打开的文件描述符小于 2, 则指向 /dev/null
	// 目的是为了保证 0 1 2 都是有效的文件描述符
	while (++dupfd <= STDERR_FILENO) {

		// 检查文件描述符是否有效
		/* Only populate closed fds. */
		if (fcntl(dupfd, F_GETFL) == -1 && errno == EBADF) {
			if (dup2(nullfd, dupfd) == -1) {
				fprintf(stderr, "dup2: %s\n", strerror(errno));
				exit(1);
			}
		}
	}

	// 如果发现刚打开的文件描述符大于 2, 则关闭它
	if (nullfd > STDERR_FILENO)
		close(nullfd);
}

int main(int argc, char *argv[])
{
	// close(1);
	sanitise_stdfd();
	while (1);
	return EXIT_SUCCESS;
}
