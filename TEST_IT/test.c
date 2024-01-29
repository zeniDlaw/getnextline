#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int fd;
    char buf[256];
    int char_read;

    fd = open("check.txt", O_RDONLY);

    while((char_read = read(fd, buf, 10)))
    {
        buf[char_read] = '\0';
        printf("buf->%s\n", buf);
    }
    return(0);
}
