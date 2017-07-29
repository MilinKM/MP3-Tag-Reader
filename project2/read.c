#include <stdio.h>
#include "type.h"
#include <stdlib.h>

read_tags(mp3 *ptr, char *file)
{
	int count = 0;
	int idx;
	long temp;
	ptr -> album_length = 0;
	ptr -> title_length = 0;
	ptr -> artist_length = 0;
	ptr -> comment_length = 0;
	ptr -> year_length = 0;
	ptr -> picture_length = 0;
	ptr -> track_length = 0;
	ptr -> comment_length = 0;
	ptr -> mp3_file = fopen(file, "r");
	fseek(ptr -> mp3_file,0l,SEEK_END);
	ptr -> file_size = ftell(ptr -> mp3_file);
	fseek(ptr -> mp3_file,0l,SEEK_SET);
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	ptr -> temp1 = fgetc(ptr -> mp3_file);
	ptr -> temp2 = fgetc(ptr -> mp3_file);
	ptr -> temp3 = fgetc(ptr -> mp3_file);
	printf("ID\t: %c%c%c\n", ptr -> temp1, ptr -> temp2, ptr -> temp3);
	while (1)
	{
		ptr -> temp1 = fgetc(ptr -> mp3_file);
		//store album name
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
				for (idx = 0; idx < ptr -> album_length; idx++)
				{
					if(isprint((temp = fgetc(ptr -> mp3_file))))
						ptr -> album[idx] = (char)temp;
				}
			}
			//storing title
			if (ptr -> temp2 == 0x49 && ptr -> temp3 == 0x54 && ptr -> temp4 == 0x32)
			{
				count++;
				for (idx = 3; idx >= 0; idx--)
				{
					ptr -> title_length = ptr -> title_length | (fgetc(ptr -> mp3_file) << (idx * 8));
				}
				fseek(ptr -> mp3_file,2l,SEEK_CUR);
				ptr -> title = malloc(ptr -> title_length * sizeof(char)); 
				for (idx = 0; idx < ptr -> title_length; idx++)
				{
					if(isprint((temp = fgetc(ptr -> mp3_file))))
						ptr -> title[idx] = (char)temp;
				}
			}
			//storing track
			if (ptr -> temp2 == 0x43 && ptr -> temp3 == 0x4F && ptr -> temp4 == 0x4E)
			{
				count++;
				for (idx = 3; idx >= 0; idx--)
				{
					ptr -> track_length = ptr -> track_length | (fgetc(ptr -> mp3_file) << (idx * 8));
				}
				fseek(ptr -> mp3_file,2l,SEEK_CUR);
				ptr -> track = malloc(ptr -> track_length * sizeof(char)); 
				for (idx = 0; idx < ptr -> track_length; idx++)
				{
					if(isprint((temp = fgetc(ptr -> mp3_file))))
						ptr -> track[idx] = (char)temp;
				}
			} 
			//storing artist
			if (ptr -> temp2 == 0x50 && ptr -> temp3 == 0x45 && ptr -> temp4 == 0x31)
			{
				count++;
				for (idx = 3; idx >= 0; idx--)
				{
					ptr -> artist_length = ptr -> artist_length | (fgetc(ptr -> mp3_file) << (idx * 8));
				}
				fseek(ptr -> mp3_file,2l,SEEK_CUR);
				ptr -> artist = malloc(ptr -> artist_length * sizeof(char)); 
				for (idx = 0; idx < ptr -> artist_length; idx++)
				{
					if(isprint((temp = fgetc(ptr -> mp3_file))))
						ptr -> artist[idx] = (char)temp;
				}
			}
			//storing year
			if (ptr -> temp2 == 0x59 && ptr -> temp3 == 0x45 && ptr -> temp4 == 0x52)
			{
				count++;
				for (idx = 3; idx >= 0; idx--)
				{
					ptr -> year_length = ptr -> year_length | (fgetc(ptr -> mp3_file) << (idx * 8));
				}
				fseek(ptr -> mp3_file,2l,SEEK_CUR);
				ptr -> year = malloc(ptr -> year_length * sizeof(char)); 
				for (idx = 0; idx < ptr -> year_length; idx++)
				{
					if(isprint((temp = fgetc(ptr -> mp3_file))))
						ptr -> year[idx] = (char)temp;
				}
				break;
			}

		} 
		// storing comment
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
				for (idx = 0; idx < ptr -> comment_length; idx++)
				{
					if(isprint((temp = fgetc(ptr -> mp3_file))))
						ptr -> comment[idx] = (char)temp;
				}
			}
		}	
	}
	printf("Title\t: ");
	for (idx = 0; idx < ptr -> title_length; idx++ )
	{
		printf("%c", ptr -> title[idx]);
	}
	printf("\nArtist\t: ");
	for (idx = 0; idx < ptr -> artist_length; idx++ )
	{
		printf("%c", ptr -> artist[idx]);
	}
	printf("\nAlbum\t: ");
	for (idx = 0; idx < ptr -> album_length; idx++ )
	{
		printf("%c", ptr -> album[idx]);
	}
	printf("\nYear\t: ");
	for (idx = 0; idx < ptr -> year_length; idx++ )
	{
		printf("%c", ptr -> year[idx]);
	}
	printf("\nComment\t: ");
	for (idx = 0; idx < ptr -> comment_length; idx++ )
	{
		printf("%c", ptr -> comment[idx]);
	}
	printf("\nTrack\t: ");
	for (idx = 0; idx < ptr -> track_length; idx++ )
	{
		printf("%c", ptr -> track[idx]);
	}
	printf("\n");
	printf("-----------------------------------------------------------------------------------------------------------\n");
	fseek(ptr -> mp3_file,0l,SEEK_SET);
	int test = 0;
	while(1)
	{
		ptr -> temp1 = fgetc(ptr -> mp3_file);
		ptr -> temp2 = fgetc(ptr -> mp3_file);
		// storing picture
		if (ptr -> temp1 == 0xff && ptr -> temp2 == 0xd8)
		{
			ptr -> picture = fopen("my_file.jpeg","w+");
			fseek(ptr -> picture,0l,SEEK_SET);
			fputc(ptr -> temp1, ptr -> picture);
			fputc(ptr -> temp2, ptr -> picture);
			test = 1;
			continue;
		}
		if (ptr -> temp1 == 0xff && ptr -> temp2 == 0xd9)
		{
			fputc(ptr -> temp1, ptr -> picture);
			fputc(ptr -> temp2, ptr -> picture);
			break;	
		}
		if (test == 1)
		{
			fputc(ptr -> temp1, ptr -> picture);
			fputc(ptr -> temp2, ptr -> picture);
		}
	}
	fcloseall();
}

