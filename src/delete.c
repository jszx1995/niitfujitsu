/********************************************************
* IT FUJITSU SECOND GROUP
* File name:	delete.c
* Summary:   	Delete files and directories
* Author:    	Zhu Xiang <jszx1995@126.com>
************************************************************/
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>
#include "io.h"

/*Delete files and directories*/

void delete_file_dir(int argc,char * argv[]){
	//Determine the number of parameters
	if(argc != 3){
		fprintf(stderr, "usage: %s Incorrect\n",argv[0]);
			exit(1);
	}
	if(strcmp(argv[1], "-r") && strcmp(argv[1], "--delete")){
		fprintf(stderr,"usages: %s Use -h or --help to see the command usage\n",
				argv[0]);
		exit(1);
	}
	char *modefile = argv[2];
	struct stat buff;
	memset(&buff,0,sizeof(buff));
	lstat(modefile,&buff);
	//Determine whether there is
	if((access(modefile,F_OK) == 0) || S_ISLNK(buff.st_mode)){
		if(S_ISDIR(buff.st_mode)){
			DIR *dir;
			struct dirent * ptr;

			dir = opendir(modefile);
			while((ptr = readdir(dir)) != NULL){
				chdir(modefile);
				char *dname = ptr->d_name;
				if(strcmp(ptr->d_name,".") == 0 || strcmp(ptr->d_name,"..") == 0){
					continue;
				}
				delete_dir(dname);
			}
			chdir("../");
			unlinkat(AT_FDCWD,modefile,AT_REMOVEDIR);
			closedir(dir);
		}else{
			unlinkat(AT_FDCWD,modefile,0);
		}
	}else{
		fprintf(stderr,"%s file does not exist!\n",modefile);	
	}

	exit(1);
}
/*
//Recursive calls to delete
void delete_dir(char * dirname){
	struct stat dirbuff;
	memset(&dirbuff,0,sizeof(dirbuff));
	lstat(dirname,&dirbuff);
	
	if(S_ISDIR(dirbuff.st_mode)){
		DIR *dir;
		struct dirent * ptr;
		dir = opendir(dirname);
		while((ptr = readdir(dir)) != NULL){
			chdir(dirname);
			char *dname = ptr->d_name;
			if(strcmp(ptr->d_name,".") == 0 || strcmp(ptr->d_name,"..") == 0){
				continue;
			}
			unlinkat(AT_FDCWD,dname,AT_REMOVEDIR);
			delete_dir(dname);
			unlinkat(AT_FDCWD,dname,0);
		}
		chdir("../");
		unlinkat(AT_FDCWD,dirname,AT_REMOVEDIR);
		closedir(dir);
	}else{
		unlinkat(AT_FDCWD,dirname,0);
	}
}
*/
