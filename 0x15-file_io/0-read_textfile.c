#include "main.h"

/**
 * read_textfile - function reads the textfile
 * as it prints it stdout posix
 * @filename: name of file.
 * @letters: no. of letters
 *
 * Return: no. of letters read
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int ed;
	ssize_t rd_len, w_len;
	char *buff;

	if (filename == NULL)
		return (0);
	ed = open(filename, O_RDONLY);
	if (ed == -1)
	{
		return (0);
	}
	buff = malloc(sizeof(char) * letters);
	if (buff == NULL)
	{
		close(ed);
		return (0);
	}
	rd_len = read(ed, buff, letters);
	close(ed);
	if (rd_len == -1)
	{
		free(buff);
		return (0);
	}
	w_len = write(STDOUT_FILENO, buff, rd_len);
	free(buff);
	if (rd_len != w_len)
		return (0);
	return (w_len);
}
