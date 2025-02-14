// 思路: 通过 ioctl 重定向 console 输出到 标准输出
// https://man7.org/linux/man-pages/man2/TIOCCONS.2const.html
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>

void show_window_size()
{
    struct winsize win = { 0, 0, 0, 0 };

    if (ioctl(STDIN_FILENO, TIOCGWINSZ, &win)) {
        printf("Failed to get tty size.\n");
        return;
    }

    /* default */
    win.ws_row = win.ws_row ? : 24;
	win.ws_col = win.ws_col ? : 80;

    printf("rows %d; columns %d\n", win.ws_row, win.ws_col);
}

void set_window_size(int rows, int cols)
{
    struct winsize win = { 0, 0, 0, 0 };

    if (rows <= 0 || cols <= 0) {
        printf("Invalid rows or columns : %d X %d.\n", rows, cols);
        return;
    }

    win.ws_row = rows;
    win.ws_col = cols;

    if (ioctl(STDIN_FILENO, TIOCSWINSZ, (char *) &win)) {
        printf("Failed to set tty size.\n");
    }

    show_window_size();
}

int main(int argc, char *argv[])
{
    int tty = -1;
    char *tty_name = NULL;

    if(argc < 2)
    {
        printf("vconsole on|off|size [X Y]\n");
        return 0;
    }

    tty_name = ttyname(STDOUT_FILENO);
    printf("tty : %s\n", tty_name);

    if(!strcmp(argv[1], "on"))
    {
        tty = open(tty_name, O_RDONLY | O_WRONLY);
        if (tty < 0) goto exit;
        (void)ioctl(tty, TIOCCONS);
        perror("change");
    }
    else if(!strcmp(argv[1], "off"))
    {
        tty = open("/dev/console", O_RDONLY | O_WRONLY);
        if (tty < 0) goto exit;
        (void)ioctl(tty, TIOCCONS);
        perror("change");
    }
	else if(!strcmp(argv[1], "size"))
    {
		if(argc == 4)
			set_window_size(atoi(argv[2]), atoi(argv[3]));
		else
			show_window_size();
    }
    else
    {
        printf("error argument\n");
        return 0;
    }

exit:
    if (tty >= 0) close(tty);
    return 0;
}

