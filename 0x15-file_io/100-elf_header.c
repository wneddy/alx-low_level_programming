#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void elf_check(unsigned char *e_ident);
void magic_print(unsigned char *e_ident);
void class_print(unsigned char *e_ident);
void data_print(unsigned char *e_ident);
void version_print(unsigned char *e_ident);
void abi_print(unsigned char *e_ident);
void osabi_print(unsigned char *e_ident);
void type_print(unsigned int e_type, unsigned char *e_ident);
void entry_print(unsigned long int e_entry, unsigned char *e_ident);
void elf_close(int des);

/**
 * elf_check - prototype function to checks if a
 * file is an ELF file.
 * @e_ident: * to the ELF magic numbers.
 *
 * Description: If none existing elf file - exit code.
 */

void elf_check(unsigned char *e_ident)
{
	int x;

	for (x = 0; x < 4; x++)
	{
		if (e_ident[x] != 127 &&
		    e_ident[x] != 'E' &&
		    e_ident[x] != 'L' &&
		    e_ident[x] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * magic_print - prototype function to print
 * the elf header magic numbers.
 * @e_ident: A * to the ELF magic numbers.
 *
 * Description: separation of magic numbers by spaces.
 */

void magic_print(unsigned char *e_ident)
{
	int x;

	printf("  Magic:   ");
	for (x = 0; x < EI_NIDENT; x++)
	{
		printf("%02x", e_ident[x]);
		if (x == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * class_print - function to print class of an ELF header.
 * @e_ident: * to the ELF class.
 */

void class_print(unsigned char *e_ident)
{
	printf("  Class:                             ");
	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * data_print - function to print the data of an ELF header.
 * @e_ident: * to the ELF class.
 */

void data_print(unsigned char *e_ident)
{
	printf("  Data:                              ");
	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * version_print - function to print the version of an ELF header.
 * @e_ident: A pointer to the ELF version.
 */

void version_print(unsigned char *e_ident)
{
	printf("  Version:                           %d",
	       e_ident[EI_VERSION]);
	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * osabi_print - function to print the OS/ABI of an ELF header.
 * @e_ident: pointer to the ELF version.
 */

void osabi_print(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");
	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * abi_print - function to print the ABI version of an ELF header.
 * @e_ident: * to the ELF ABI version.
 */

void abi_print(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
	       e_ident[EI_ABIVERSION]);
}

/**
 * type_print - function prints the type of an ELF header.
 * @e_type: The ELF type.
 * @e_ident: A pointer to an array containing the ELF class.
 */

void type_print(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;
	printf("  Type:                              ");
	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * entry_print - function to print the entry point of an ELF header.
 * @e_entry: address of entry point.
 * @e_ident: pointer to the ELF class.
 */

void entry_print(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");
	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", e_entry);
}

/**
 * elf_close- function to close an ELF file.
 * @des: file descriptor.
 *
 * Description: file cannot be found - exit code 98.
 */

void elf_close(int des)
{
	if (close(des) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", des);
		exit(98);
	}
}

/**
 * main - info. display of he elf header at start of file.
 * @argc: argument count
 * @argv: arguments vector(array to hold args).
 *
 * Return: success.
 *
 * Description: checks ELF file status if not - exit code 98.
 */

int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;

	int e, d;

	e = open(argv[1], O_RDONLY);
	if (e == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		elf_close(e);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	d = read(e, header, sizeof(Elf64_Ehdr));
	if (d == -1)
	{
		free(header);
		elf_close(e);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}
	elf_check(header->e_ident);
	printf("ELF Header:\n");
	magic_print(header->e_ident);
	class_print(header->e_ident);
	data_print(header->e_ident);
	version_print(header->e_ident);
	osabi_print(header->e_ident);
	abi_print(header->e_ident);
	type_print(header->e_type, header->e_ident);
	entry_print(header->e_entry, header->e_ident);

	free(header);

	elf_close(e);

	return (0);
}
