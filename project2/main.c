#include <stdio.h>
#include <string.h>
#include "type.h"
// menu
menu_function()
{
	printf("usage : mp3tag -[tTaAycg] <value> file1\n"
			"mp3tag -v\n"
		"-t    Modifies a Title tag\n"
		"-T    Modifies a Track tag\n"
		"-a    Modifies an Artist tag\n"
		"-A    Modifies an Album tag\n"
		"-y    Modifies a Year tag\n"
		"-c    Modifies a Comment tag\n"
		"-g    Modifies a Genre tag\n"
		"-v    Prints version info\n");
}


int main(int argc, char *argv[])
{ 
	mp3 file;
	char menu[100] = "mp3--help";

	// error checking
	if (argc < 2)
	{
	printf("ERROR: for menu -> ./<executablefile> <mp3--help>\n"
			"for reading -> ./<executablefile> <r> <mp3_file>\n"
			"for editing -> ./<executablefile> <e> <t/T/a/A/y/c/g/v> <mp3_file>\n");
	return failure;
	}
	if (!strcmp(argv[1],menu))
	{
		if (argc != 2)
		{
			printf("invalid arguments\n");
			return failure;
		}
		menu_function();
	}
	else if(*argv[1] == 'r')
	{
		file.mp3_file = fopen(argv[2], "r");
		file.mp3_file_name = argv[2];
		if (file.mp3_file == NULL)
		{
			printf("file %s is not found\n",file.mp3_file_name);
			return failure;
		}
		if (argc != 3)
		{
		printf("pass valid arguments\n");
		return failure;
		}
		read_tags(&file,argv[2]);
	}
	else if (*argv[1] == 'e')
	{
		file.mp3_file = fopen(argv[3], "r");
		file.mp3_file_name = argv[3];
		if (file.mp3_file == NULL)
		{
			printf("file %s is not found\n",file.mp3_file_name);
			return failure;
		}
		if (argc != 4)
		{
		printf("pass valid arguments\n");
		return failure;
		}
		edit_tags(&file,argv[2],argv[3]);
	}
	fcloseall();
}
