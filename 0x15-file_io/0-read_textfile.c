#include "main.h"

/**
 * read_textfile - reads a text file and prints the letters
 * @filename: name of the file to read
 * @letters: number of letters to print
 *
 * Return: number of letters printed, or 0 if it fails
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t num_read, num_written;
	char *buffer;

	if (filename == NULL)
		return 0;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return 0;

	buffer = (char *)malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return 0;

	num_read = read(fd, buffer, letters);
	if (num_read == -1) {
		free(buffer);
		close(fd);
		return 0;
	}

	num_written = write(STDOUT_FILENO, buffer, num_read);
	if (num_written == -1) {
		free(buffer);
		close(fd);
		return 0;
	}

	close(fd);
	free(buffer);

	return num_written;
}

