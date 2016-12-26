/************************************************************
* NIIT FUJITSU SECOND GROUP
* File name:	dircopy.c
* Summary:   	Directory replication
* Author:    	Zhu xiang <jszx1995@126.com>
************************************************************/
#include "copy.h"

int isdir(char *);

//Directory replication
int directory_copy(char *sou,char *des){
	struct stat dirbuff;
	memset(&dirbuff,0,sizeof(dirbuff));
	lstat(sou,&dirbuff);
	DIR *dp;
	struct dirent *entry;
	char soufilepath[500];
	char desfilepath[500];
	if((dp = opendir(sou)) == NULL){
		printf("%s is not a directory!\n",sou);
		return -1;
	}

	if(createdir(des) != 0) return -2;
	
	while((entry = readdir(dp)) != NULL){
		strcpy(soufilepath,sou);
		strcpy(desfilepath,des);
		strcat(soufilepath,"/");
		strcat(desfilepath,"/");
		strcat(soufilepath,entry->d_name);
		strcat(desfilepath,entry->d_name);

		if(isdir(soufilepath)){
			if(!strcmp(entry->d_name,".") || !strcmp(entry->d_name,".."))
				continue;
			directory_copy(soufilepath,desfilepath);
		}else{
			file_copy(soufilepath,desfilepath);
		}
	}
	return 0;
}

//Determine whether the directory exists
int isdir(char * path){
	DIR *dp;
	if((dp = opendir(path)) == NULL){
		return 0;
	}else{
		closedir(dp);
		return 1;
	}
}
