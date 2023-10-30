#include "main.h"

/**
 * create_file - function that creates a file
 * @filename: name of file
 * @text_content: content in the file.
 *
 * Return: 1 - success -1 - failure
 */

int create_file(const char *filename, char *text_content)
{
	int ed;
	int no_of_letters;
	int per;

	if (!filename)
	{
		return (-1);
	}
	ed = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (ed == -1)
	{
		return (-1);
	}
	if (!text_content)
		text_content = "";
	for (no_of_letters = 0; text_content[no_of_letters]; no_of_letters++)
		;
	per = write(ed, text_content, no_of_letters);
	if (per == -1)
	{
		return (-1);
	}
	close(ed);
	return (1);
}
