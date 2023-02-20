
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#include <sys/mount.h>

#define TEST_MESSAGE "Hello world!"
#define TEST_MESSAGE_LEN 12

int main(int argc, const char *argv[])
{
    int fdLog = -1;
    char buffer[TEST_MESSAGE_LEN + 1];

    if ((fdLog = open("/secure.log", O_WRONLY | O_CREAT)) < 0 )
    {
        fprintf(stderr,"Error: can't create log!\n");
    }

    write(fdLog, TEST_MESSAGE, TEST_MESSAGE_LEN);
    close(fdLog);

    fdLog = open("/secure.log", O_RDONLY);
    read(fdLog, buffer, TEST_MESSAGE_LEN);
    buffer[TEST_MESSAGE_LEN] = '\0';
    fprintf(stderr, "Read message: %s\n", buffer);
    close(fdLog);

    return EXIT_SUCCESS;
}
