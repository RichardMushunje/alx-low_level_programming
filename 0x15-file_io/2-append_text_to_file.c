#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: name of file
 * @text_content: added content
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd; /* file descriptor */
	int nletters; /* number of letters in text_content */
	int rwr; /* return value from write() */

	/* check if filename is NULL */
	if (!filename)
		return (-1);

	/* open file with O_WRONLY and O_APPEND flags */
	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd == -1) /* if open() fails */
		return (-1);

	if (text_content) /* if text_content is not NULL */
	{
		/* calculate the number of letters in text_content */
		for (nletters = 0; text_content[nletters]; nletters++)
			;

		/* write the content to the end of the file */
		rwr = write(fd, text_content, nletters);

		if (rwr == -1) /* if write() fails */
			return (-1);
	}

	/* close the file and return 1 on success */
	close(fd);
	return (1);
}

