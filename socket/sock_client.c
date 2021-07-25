#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <errno.h>
#include <stddef.h>
#include <unistd.h>
#include <pthread.h>
#define BUFFER_SIZE 1024
const char *filename = "uds-tmp";

void *thread_recv(void *ptr)
{
    int sock_fd = *(int *)ptr;
    char buffer[128] = {0};
    while (1)
    {
        int ret = recv(sock_fd, buffer, 128, 0);
        if (ret <= 0)
        {
            printf("recv error: %s\n", strerror(ret));
            close(sock_fd);
            exit(EXIT_FAILURE);
        } else {
            printf("%s\n", buffer);
        }
    }
}

int main()
{
    while (1)
    {
        struct sockaddr_un un;
        int sock_fd;
        char buffer[BUFFER_SIZE] = "hello world";
        un.sun_family = AF_UNIX;
        strcpy(un.sun_path, filename);
        sock_fd = socket(AF_UNIX, SOCK_STREAM, 0);
        if (sock_fd < 0)
        {
            printf("Request socket failed\n");
            return -1;
        }
        if (connect(sock_fd, (struct sockaddr *)&un, sizeof(un)) < 0)
        {
            printf("connect socket failed\n");
            return -1;
        }

        pthread_t pth;

        pthread_create(&pth, NULL, thread_recv, (void *)(&sock_fd));

        while (1)
        {
            memset(buffer, 0, BUFFER_SIZE);
            fgets(buffer, BUFFER_SIZE, stdin);

            printf("send data: %s\n", buffer);

            int error = 0;
            socklen_t len = sizeof(error);
            int retval = getsockopt(sock_fd, SOL_SOCKET, SO_ERROR, &error, &len);

            if (retval != 0)
            {
                /* there was a problem getting the error code */
                fprintf(stderr, "error getting socket error code: %s\n", strerror(retval));
                return 0;
            }

            if (error != 0)
            {
                /* socket has a non zero error status */
                fprintf(stderr, "socket error: %s\n", strerror(error));
                return 0;
            }

            ssize_t size = send(sock_fd, buffer, BUFFER_SIZE, MSG_NOSIGNAL);

            if (size <= 0)
            {
                // close(sock_fd);
                // return 0;
                printf("send data failed.\n");
            }
        }
    }

    return 0;
}