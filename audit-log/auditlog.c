#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void write_str(int fd, const char *str)
{
    size_t len = strlen(str);
    ssize_t written = write(fd, str, len);
    if (written != len)
    {
        perror("write");
    }
}

#define LOG_FILE "audit.log"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage:\n");
        printf("./auditlog --add \"message\"\n");
        printf("./auditlog --view\n");
        return 1;
    }
    if (strcmp(argv[1], "--add") == 0)
    {
        int fd = open(LOG_FILE, O_WRONLY | O_CREAT | O_APPEND, 0644);
        if (fd == -1)
        {
            perror("open");
            return 1;
        }
        write_str(fd, argv[2]);
        write_str(fd, "\n");
        close(fd);
    }
    else if (strcmp(argv[1], "--view") == 0)
    {
        int fd = open(LOG_FILE, O_RDONLY);
        if (fd == -1)
        {
            perror("open");
            return 1;
        }
        char buffer[1024];
        ssize_t bytes_read;
        int line = 1;
        int start = 1;
        while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0)
        {
            for (int i = 0; i < bytes_read; i++)
            {
                if (start)
                {
                    printf("%d. ", line);
                    start = 0;
                }

                printf("%c", buffer[i]);

                if (buffer[i] == '\n')
                {
                    line++;
                    start = 1;
                }
            }
        }
        close(fd);
    }
    else
    {
        printf("Invalid option. Use --add, --view.\n");
        return 1;
    }

    return 0;
}

