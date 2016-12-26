/************************************************************
* IT FUJITSU SECOND GROUP
* File name:	copy.c
* Summary:   	File directory replication
* Author:    	Zhu xiang <jszx1995@126.com>
************************************************************/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <getopt.h>
#include "io.h"
#include "copy.h"

/*File directory replication*/
void copy_file_dir(int argc,char * argv[]){
        //Determine the number of parameters
	if(argc != 4){
		fprintf(stderr,"usage: %s Incorrect\n",argv[0]);
		exit(1);
	} 
	if(strcmp(argv[1], "-p") && strcmp(argv[1], "--copy")){
		fprintf(stderr,"usages: %s Use -h or --help to see the command usage\n",
				argv[0]);
		exit(1);
	}

	char *source = argv[2];
	char *destin = argv[3];
	struct stat soubuff;
	memset(&soubuff,0,sizeof(soubuff));
	lstat(source,&soubuff);
	struct stat desbuff;
	memset(&desbuff,0,sizeof(desbuff));
	lstat(destin,&desbuff);
	if(access(source,F_OK)){
		fprintf(stderr,"%s does not exist!\n",source);
		exit(1);
	}else if(S_ISDIR(soubuff.st_mode) && !S_ISDIR(desbuff.st_mode)){
		directory_copy(source,destin);
	}else if(S_ISDIR(soubuff.st_mode) && S_ISDIR(desbuff.st_mode)){
		directory_copy_directory(source,destin);
	}else if(!S_ISDIR(desbuff.st_mode)){
		file_copy(source,destin);	
	}else if(S_ISDIR(desbuff.st_mode)){
		file_copy_directory(source,destin);
	}
}
