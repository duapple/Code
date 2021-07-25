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

#define MAX_CONNECT_NUM 2
#define BUFFER_SIZE 1024
const char *filename = "uds-tmp";
static pthread_t th;
static pthread_t th1;

void *thread_recv(void *ptr)
{
    int fd = *(int *)ptr;
    char buffer[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE);

    while (1)
    {
        printf("waiting recv...\n");
        int ret = recv(fd, buffer, BUFFER_SIZE, 0);

        if (ret <= 0)
        {
            printf("recv failed\n");
            close(fd);
            pthread_cancel(th1);
            return NULL;
        }

        printf("%s\n", buffer);

        if (strncmp("end", buffer, 3) == 0)
        {
            close(fd);
            exit(0);
        }
    }
}

void *thread_send(void *ptr)
{
    int fd = *(int *)ptr;
    while(1)
    {
        char buff[128] = {0};
        fgets(buff, 128, stdin);

        int ret = send(fd, buff, 128, 0);
        if (ret <= 0)
        {
            close(fd);
            pthread_cancel(th);
            return NULL;
        }
    }
}

int main()
{
    int fd, new_fd, len, i;
    struct sockaddr_un un;
    fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (fd < 0)
    {
        printf("Request socket failed!\n");
        return -1;
    }
    un.sun_family = AF_UNIX;
    unlink(filename);
    strcpy(un.sun_path, filename);
    if (bind(fd, (struct sockaddr *)&un, sizeof(un)) < 0)
    {
        printf("bind failed!\n");
        return -1;
    }
    if (listen(fd, MAX_CONNECT_NUM) < 0)
    {
        printf("listen failed!\n");
        return -1;
    }
    while (1)
    {
        printf("wait to accept...\n");

        new_fd = accept(fd, NULL, NULL);

        printf("new accept.\n");

        if (new_fd < 0)
        {
            printf("accept failed\n");
            return -1;
        }
        pthread_create(&th, NULL, thread_recv, (void *)(&new_fd));
        pthread_create(&th1, NULL, thread_send, (void *)(&new_fd));

    }
    close(fd);
}