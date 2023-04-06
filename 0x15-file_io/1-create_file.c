#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int create_file(const char *filename, char *text_content) {
    int fd, nletters, rwr;

    if (filename == NULL) {
        return -1;
    }

    fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
    if (fd == -1) {
        return -1;
    }

    if (text_content == NULL) {
        text_content = "";
    }

    nletters = strlen(text_content);
    rwr = write(fd, text_content, nletters);

    if (rwr == -1) {
        close(fd);
        return -1;
    }

    if (close(fd) == -1) {
        return -1;
    }

    return 1;
}

