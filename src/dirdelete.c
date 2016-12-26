/********************************************************
* IT FUJITSU SECOND GROUP
* File name:	dirdelete.c
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
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
