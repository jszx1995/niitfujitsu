/************************************************************
* NIIT FUJITSU SECOND GROUP
* File name:	dircopydir.c
* Summary:   	Directory to the destination directory	
* Author:    	Zhu xiang <jszx1995@126.com>
************************************************************/

#include "copy.h"
int directory_copy_directory(char *sou,char *des){
	char dirname[500];
	char dirpath[500];
	int i;
	int length = strlen(sou);
	for(i = length-2;i >= 0;i--){
		if(sou[i] == '/'){
			strncpy(dirname,sou+i+1,length-i);
			break;
		}
	}

	if(i <= -1) strcpy(dirname,sou);

	strcpy(dirpath,des);
	if(dirpath[strlen(dirpath)-1] != '/')
		strcat(dirpath,"/");
	strcat(dirpath,dirname);
	return directory_copy(sou,dirpath);
}
