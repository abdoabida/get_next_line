#include "get_next_line.h"

int main(int argc, char **argv)
{
    int fd;
    int ret;
    char *line;

    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        while ((ret = get_next_line(fd, &line)) == 1)
        {
            printf("%s\n", line);
        }
    }
    return (0);
}