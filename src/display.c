/***********************************************************
* IT FUJITSU SECOND GROUP
* File name:	display.c
* Summary:   	List the contents of the file
* Author:    	Zhu Xiang <jszx1995@126.com>
***********************************************************/
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <getopt.h>
#include "io.h"

/*List the contents of the file*/

void display_file(int argc, char * argv[]){
	//Determine the number of parameters
	if(argc != 3){
		fprintf(stderr,"usage: %s Incorrect\n",argv[0]);
		exit(1);
	}
	if(strcmp(argv[1], "-d") && strcmp(argv[1], "--display")){
		fprintf(stderr,"usages: %s Use -h or --help to see the command usage\n",
				argv[0]);
		exit(1);
	}
	
	char * modefile = argv[2];
	struct stat buff;
	memset(&buff,0,sizeof(buff));
	lstat(modefile,&buff);
	//Determine whether the file exists
	if(access(modefile,F_OK) == 0){
		//Determine whether the directory
		if(S_ISDIR(buff.st_mode)){
			fprintf(stderr,"Parameters are not supported!\n");
			exit(1);
		}else{
			FILE *fp = NULL;
			char ch;
			fp = fopen(modefile,"r");
			while((ch = fgetc(fp)) != EOF)
				putchar(ch);
			fclose(fp);
			exit(1);
		}	
	}else{
		fprintf(stderr,"%s file does not exist!\n",modefile);
		exit(1);
	}
}

