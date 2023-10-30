#include "main.h"

/**
 * append_text_to_file - function to append text
 * at the end of the given file
 * @filename: name of file
 * @text_content: content to add.
 *
 * Return: 1 file exist, (-1) - file don't exist
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int ed;
	int no_of_letters;
	int per;

	if (!filename)
	{
		return (-1);
	}
	ed = open(filename, O_WRONLY | O_APPEND);
	if (ed == -1)
	{
		return (-1);
	}
	if (text_content)
	{
		for (no_of_letters = 0; text_content[no_of_letters]; no_of_letters++)
			;
		per = write(ed, text_content, no_of_letters);
		if (per == -1)
		{
			return (-1);
		}
	}
	close(ed);
	return (1);
}
