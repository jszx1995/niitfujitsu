/************************************************************
* NIIT FUJITSU SECOND GROUP
* File name:	filecopy.c
* Summary:   	File replication	
* Author:    	Zhu xiang <jszx1995@126.com>
************************************************************/
#include "copy.h"
#include <fcntl.h>
#include <errno.h>
void fcopy(int,int);
void file_copy(char *sou,char *des){
    if (strcmp(sou,des) == 0){
        printf("error:%s already exists!\n",sou);
    }
	struct stat buff;
	memset(&buff,0,sizeof(buff));
	lstat(sou,&buff);
	mode_t mode = buff.st_mode;
	int fdin, fdout;
	fdin = open(sou,O_RDONLY);
	if(fdin < 0){
		fprintf(stderr,"open 1file error:%s\n",
				strerror(errno));
		exit(1);
	}
	umask(0);
	fdout = open(des,O_TRUNC | O_WRONLY | O_CREAT,mode);
	if(fdout < 0){
		fprintf(stderr,"open 2file error:%s\n",
				strerror(errno));
		exit(1);
	}
	
	fcopy(fdin,fdout);

	close(fdin);
	close(fdout);
}

void fcopy(int fdin,int fdout){
	char buffer[4096];
	ssize_t size;
	while((size = read(fdin,buffer,4096)) > 0){
		if(write(fdout,buffer,size) != size){
			fprintf(stderr,"write error:%s\n",strerror(errno));
			exit(1);
		}
	}
	if(size < 0){
		fprintf(stderr,"read error:%s\n",strerror(errno));
		exit(1);
	}
}
