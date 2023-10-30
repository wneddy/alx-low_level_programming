#include "main.h"

/**
 * file_status - checks the status of the file
 * if it can be accessed or not.
 * @s_file: source from(file)
 * @d_file: destination of file.
 * @argv: arg.. vector.
 *
 * Return: void
 */

void file_status(int s_file, int d_file, char *argv[])
{
	if (s_file == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (d_file == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - holberton code check for students
 * @argc: no. of args.
 * @argv: args vector.
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int file_s, file_d, close_error;
	ssize_t no_of_chars, per;
	char buff[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}
	file_s = open(argv[1], O_RDONLY);
	file_d = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	file_status(file_s, file_d, argv);
	no_of_chars = 1024;
	while (no_of_chars == 1024)
	{
		no_of_chars = read(file_s, buff, 1024);
		if (no_of_chars == -1)
			file_status(-1, 0, argv);
		per = write(file_d, buff, no_of_chars);
		if (per == -1)
			file_status(0, -1, argv);
	}
	close_error = close(file_s);
	if (close_error == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_s);
		exit(100);
	}
	close_error = close(file_d);
	if (close_error == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_s);
		exit(100);
	}
	return (0);
}
