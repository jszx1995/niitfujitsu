/************************************************************
* NIIT FUJITSU SECOND GROUP
* File name:	create_dir.c
* Summary:   	Create a directory	
* Author:    	Zhu xiang <jszx1995@126.com>
************************************************************/
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include "copy.h"

int createdir(char *des){
	char dirpath[500];
	int i;
	int len;
	strcpy(dirpath,des);
	len = strlen(dirpath);

	if(dirpath[len-1] != '/'){
		strcat(dirpath,"/");
		len++;
	}
	for(i = 1;i < len; i++){
		if(dirpath[i] == '/'){
			dirpath[i] = '\0';
			if(access(dirpath,F_OK) < 0){
				if(mkdir(dirpath,0755) < 0){
					fprintf(stderr,"mkdir %s error!\n",dirpath);
					return -1;
				}
			}else if(!isdir(dirpath)){
				fprintf(stderr,"cannot create directory ‘%s’,File exists!\n",
						des);
				return -2;
			}
			dirpath[i] = '/';
		}
	}
	return 0;
}
