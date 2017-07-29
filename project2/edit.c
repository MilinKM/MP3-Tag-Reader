#include <stdio.h>
#include "type.h"
#include <stdlib.h>
#include <string.h>

status edit_tags(mp3 *ptr, char *choice, char *file)
{
	int count = 0;
	int idx;
	int temp;
	ptr -> album_length = 0;
	ptr -> title_length = 0;
	ptr -> artist_length = 0;
	ptr -> comment_length = 0;
	ptr -> year_length = 0;
	ptr -> picture_length = 0;
	ptr -> track_length = 0;
	ptr -> comment_length = 0;
	ptr -> mp3_file = fopen(file, "r+");
	fseek(ptr -> mp3_file,0l,SEEK_END);
	ptr -> file_size = ftell(ptr -> mp3_file);
	fseek(ptr -> mp3_file,0l,SEEK_SET);
	switch (*choice)
	{
		case 'A' : 
			while (1)
			{
				ptr -> temp1 = fgetc(ptr -> mp3_file);
				//edit album name
				if (ptr -> temp1 == 0x54 )
				{
					ptr -> temp2 = fgetc(ptr -> mp3_file);
					ptr -> temp3 = fgetc(ptr -> mp3_file);
					ptr -> temp4 = fgetc(ptr -> mp3_file);
					if (ptr -> temp2 == 0x41 && ptr -> temp3 == 0x4c && ptr -> temp4 == 0x42)
					{
						count++;
						for (idx = 3; idx >= 0; idx--)
						{
							ptr -> album_length = ptr -> album_length | (fgetc(ptr -> mp3_file) << (idx * 8));
						}
						fseek(ptr -> mp3_file,2l,SEEK_CUR);
						ptr -> album = malloc(ptr -> album_length * sizeof(char)); 
						printf("Enter new album name\n");
						scanf("%s", ptr->album);
						if (strlen(ptr->album) > ptr->album_length)
						{
							printf("enter a name less than or equal to %d length\n", ptr->album_length);
							return failure;
						}
						for (idx = 0; idx < ptr -> album_length; idx++)
						{
							if (idx < strlen(ptr->album))
								fputc(ptr->album[idx], ptr->mp3_file);
							else
								fputc(0, ptr -> mp3_file);

						}
						break;
					}
				}
			}
			break;
		case 't':
			// edit title length
			while (1)
			{
				ptr -> temp1 = fgetc(ptr -> mp3_file);
				if (ptr -> temp1 == 0x54 )
				{
					ptr -> temp2 = fgetc(ptr -> mp3_file);
					ptr -> temp3 = fgetc(ptr -> mp3_file);
					ptr -> temp4 = fgetc(ptr -> mp3_file);
					if (ptr -> temp2 == 0x49 && ptr -> temp3 == 0x54 && ptr -> temp4 == 0x32)
					{
						count++;
						for (idx = 3; idx >= 0; idx--)
						{
							ptr -> title_length = ptr -> title_length | (fgetc(ptr -> mp3_file) << (idx * 8));
						}
						fseek(ptr -> mp3_file,2l,SEEK_CUR);
						ptr -> title = malloc(ptr -> title_length * sizeof(char)); 
						printf("Enter new title\n");
						scanf("%s", ptr -> title);
						if (strlen(ptr -> title) > ptr -> title_length)
						{
							printf("enter a title less than or equal to %d length\n", ptr -> title_length);
							return failure;
						}
						for (idx = 0; idx < ptr -> title_length; idx++)
						{
							if (idx < strlen(ptr -> title))
								fputc(ptr -> title[idx], ptr->mp3_file);
							else
								fputc(0, ptr -> mp3_file);
						}
						break;
					}
				}
			}
			break;
		case 'T':
			while (1)
			{
				ptr -> temp1 = fgetc(ptr -> mp3_file);
				if (ptr -> temp1 == 0x54 )
				{
					ptr -> temp2 = fgetc(ptr -> mp3_file);
					ptr -> temp3 = fgetc(ptr -> mp3_file);
					ptr -> temp4 = fgetc(ptr -> mp3_file);
					//edit track
					if (ptr -> temp2 == 0x43 && ptr -> temp3 == 0x4F && ptr -> temp4 == 0x4E)
					{
						count++;
						for (idx = 3; idx >= 0; idx--)
						{
							ptr -> track_length = ptr -> track_length | (fgetc(ptr -> mp3_file) << (idx * 8));
						}
						fseek(ptr -> mp3_file,2l,SEEK_CUR);
						ptr -> track = malloc(ptr -> track_length * sizeof(char)); 
						printf("Enter new track\n");
						scanf("%s", ptr -> track);
						if (strlen(ptr -> track) > ptr -> track_length)
						{
							printf("enter a track less than or equal to %d length\n", ptr -> track_length);
							return failure;
						}
						for (idx = 0; idx < ptr -> track_length; idx++)
						{
							if (idx < strlen(ptr -> track))
								fputc(ptr -> track[idx], ptr -> mp3_file);
							else
								fputc(0, ptr -> mp3_file);
						}
						break;
					}
				}
			}
			break;
		case 'a':
			//edit artist
			while (1)
			{
				ptr -> temp1 = fgetc(ptr -> mp3_file);
				if (ptr -> temp1 == 0x54 )
				{
					ptr -> temp2 = fgetc(ptr -> mp3_file);
					ptr -> temp3 = fgetc(ptr -> mp3_file);
					ptr -> temp4 = fgetc(ptr -> mp3_file);
					if (ptr -> temp2 == 0x50 && ptr -> temp3 == 0x45 && ptr -> temp4 == 0x31)
					{
						count++;
						for (idx = 3; idx >= 0; idx--)
						{
							ptr -> artist_length = ptr -> artist_length | (fgetc(ptr -> mp3_file) << (idx * 8));
						}
						fseek(ptr -> mp3_file,2l,SEEK_CUR);
						ptr -> artist = malloc(ptr -> artist_length * sizeof(char)); 
						printf("Enter new artist\n");
						scanf("%s", ptr -> artist);
						if (strlen(ptr -> artist) > ptr -> artist_length)
						{
							printf("enter an artist less than or equal to %d length\n", ptr -> artist_length);
							return failure;
						}
						for (idx = 0; idx < ptr -> artist_length; idx++)
						{
							if (idx < strlen(ptr -> artist))
								fputc(ptr -> artist[idx], ptr -> mp3_file);
							else
								fputc(0, ptr -> mp3_file);
						}
						break;
					}
				}
			}
			break;
		case 'y':
			//edit year
			while (1)
			{
				ptr -> temp1 = fgetc(ptr -> mp3_file);
				if (ptr -> temp1 == 0x54 )
				{
					ptr -> temp2 = fgetc(ptr -> mp3_file);
					ptr -> temp3 = fgetc(ptr -> mp3_file);
					ptr -> temp4 = fgetc(ptr -> mp3_file);
					if (ptr -> temp2 == 0x59 && ptr -> temp3 == 0x45 && ptr -> temp4 == 0x52)
					{
						count++;
						for (idx = 3; idx >= 0; idx--)
						{
							ptr -> year_length = ptr -> year_length | (fgetc(ptr -> mp3_file) << (idx * 8));
						}
						fseek(ptr -> mp3_file,2l,SEEK_CUR);
						ptr -> year = malloc(ptr -> year_length * sizeof(char)); 
						printf("Enter year\n");
						scanf("%s", ptr -> year);
						if (strlen(ptr -> year) > ptr -> year_length)
						{
							printf("enter a year less than or equal to %d length\n", ptr -> year_length);
							return failure;
						}
						for (idx = 0; idx < ptr -> year_length; idx++)
						{
							if (idx < strlen(ptr -> year))
								fputc(ptr -> year[idx], ptr -> mp3_file);
							else
								fputc(0, ptr -> mp3_file);
						}
						break;
					}
				}
			}
			break;
		case 'c':
			while (1)
			{
				// editing comment
				if (ptr -> temp1 == 0x43)
				{
					ptr -> temp2 = fgetc(ptr -> mp3_file);
					ptr -> temp3 = fgetc(ptr -> mp3_file);
					ptr -> temp4 = fgetc(ptr -> mp3_file);
					if (ptr -> temp2 == 0x4F && ptr -> temp3 == 0x4D && ptr -> temp4 == 0x4D)
					{
						count++;
						for (idx = 3; idx >= 0; idx--)
						{
							ptr -> comment_length = ptr -> comment_length | (fgetc(ptr -> mp3_file) << (idx * 8));
						}
						fseek(ptr -> mp3_file,2l,SEEK_CUR);
						ptr -> comment = malloc(ptr -> comment_length * sizeof(char)); 
						printf("Enter comment\n");
						scanf("%s", ptr -> comment);
						if (strlen(ptr -> comment) > ptr -> comment_length)
						{
							printf("enter a comment less than or equal to %d length\n", ptr -> comment_length);
							return failure;
						}
						for (idx = 0; idx < ptr -> comment_length; idx++)
						{
							if (idx < strlen(ptr -> comment))
								fputc(ptr -> comment[idx], ptr -> mp3_file);
							else
								fputc(0, ptr -> mp3_file);
						}
						break;
					}
				}
			}
			break;
	}
	fcloseall();
}
