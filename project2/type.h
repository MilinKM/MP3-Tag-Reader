#ifndef TYPE_H
#define TYPE_H
#define _GNU_SOURCE
#include <stdio.h>
typedef struct
{
	FILE *mp3_file, *picture;
	char *mp3_file_name;
	size_t file_size;
	char *album;
	char *title;
	char *artist;
	char *comment;
	char *track;
	char *year;
	int year_length;
	int album_length;
	int title_length;
	int artist_length;
	int track_length;
	int comment_length;
	int picture_length;
	int temp1,temp2,temp3,temp4;
}mp3;
typedef enum
{
failure,
success,
}status;
typedef enum
{
read = 1,
edit,
}operationtype;
#endif
