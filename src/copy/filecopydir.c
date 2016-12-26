/************************************************************
* NIIT FUJITSU SECOND GROUP
* File name:	filecopydir.c
* Summary:   	File to the destination directory
* Author:    	Zhu xiang <jszx1995@126.com>
************************************************************/
#include "copy.h"

void file_copy_directory(char *sou,char *des){
	char filename[500];
	char filepath[500];
	int i;
	int length = strlen(sou);
	for(i = length-1;i >= 0; i--){
		if(sou[i] == '/'){
			strncpy(filename,sou+i+1,length-i);
			break;
		}
	}

	if(i <= -1) strcpy(filename,sou);

	strcpy(filepath,des);

	strcat(filepath,"/");

	strcat(filepath,filename);

	file_copy(sou,filepath);

	exit(1);
}
