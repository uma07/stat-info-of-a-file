/***

	Write a program that takes in filenames (with or without a preceding path) as arguments and for each filename prints out the stat info.

	*********************************************************************************************************************************
						SUBMITTED BY Uma Sankar(Regd. No. - 16008) 
	*********************************************************************************************************************************

***/


#include "apue.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <time.h>

int main(int argc, char **argv)
{

	char *ptr;
    	struct stat buf;

	for(int i = 1; i < argc; i++)
	{
    		if(stat(argv[i],&buf) < 0)    
		        return 1;

		printf("\nSTAT INFO of file '%s'is : ------------------->", argv[i]);
		printf("\nSize : %ld", buf.st_size);
		printf("\nDevice Name : %lu", buf.st_dev);
		printf("\nInode : %lu", buf.st_ino);
		printf("\nNo. of links : %lu", buf.st_nlink);
		printf("\nOwner : %u", buf.st_uid);
		printf("\nNo.of blocks : %lu", buf.st_blocks);
		printf("\nGroup owner : %u", buf.st_gid);
		printf("\nBlocks size : %lu", buf.st_blksize);
		printf("\nLast file modification : %s", ctime(&buf.st_mtime));
		printf("Last access modification : %s", ctime(&buf.st_atime));
		printf("Time of last modified : %s", ctime(&buf.st_ctime));

		if (S_ISREG(buf.st_mode))
			ptr = "regular";

		else if (S_ISDIR(buf.st_mode))
			ptr = "directory";
	
		else if (S_ISCHR(buf.st_mode))
			ptr = "character special";

		else if (S_ISBLK(buf.st_mode))
			ptr = "block special";

		else if (S_ISFIFO(buf.st_mode))
			ptr = "fifo";

		else if (S_ISLNK(buf.st_mode))
			ptr = "symbolic link";

		else if (S_ISSOCK(buf.st_mode))
			ptr = "socket";

		else
			ptr = "** unknown mode **";

		printf("MODE : %s\n\n", ptr);
	}

	return 0;

}
