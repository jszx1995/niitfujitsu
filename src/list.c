/************************************************************
* IT FUJITSU SECOND GROUP
* File name:	list.c
* Summary:   	List the object properties
* Author:    	Zhu Xiang <jszx1995@126.com>
*************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>
#include <time.h>
#include "io.h"

/*List the object properties*/
void list_object(int argc,char * argv[]){
	//Determine the number of parameters
        if(argc != 3){
		fprintf(stderr,"usage: %s Incorrect\n",argv[0]);
		exit(1);
	}
	if(strcmp(argv[1], "-l") && strcmp(argv[1], "--list")){
		fprintf(stderr,"usages: %s Use -h or --help to see the command usage\n",
				argv[0]);
		exit(1);
	}

	char * modefile = argv[2];
	struct stat buff;
	memset(&buff,0,sizeof(buff));
	lstat(modefile,&buff);
	//Determine whether the file or directory exists
	mode_t mode = buff.st_mode;
	if((access(modefile,F_OK) == 0) || S_ISLNK(mode)){
		printf("Operational attributes:\n");
		//Determine whether the directory
		if(S_ISDIR(mode)){
			printf("d");				
		}else if(S_ISREG(mode)){//Determine whether the file
			printf("-");
		}else if(S_ISCHR(mode)){
			printf("c");
		}else if(S_ISBLK(mode)){
			printf("b");
		}else if(S_ISFIFO(mode)){
			printf("f");
		}else if(S_ISLNK(mode)){
			printf("l");
		}else if(S_ISSOCK(mode)){
			printf("s");
		}
		//Access permission
		int i;
		for(i = 8;i >= 0;i--){
			if(mode & (1<<i)){
				switch(i % 3){
					case 2:
						printf("r");
						break;
					case 1:
						printf("w");
						break;
					case 0:
						printf("x");
						break;
				}
			}else{
				printf("-");
			}
		}
		printf(".\t");
		//File size
		long long size = (long long)buff.st_size;
		printf("%ld\t",size);
		//Last access time
		char *wday[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
		time_t atime = buff.st_atime;
		struct tm *p;
		p = localtime(&atime);
		printf("%d-%02d-%02d ",(1900+p->tm_year),(1+p->tm_mon),(p->tm_mday));
		printf("%s %02d:%02d:%02d\t", 
				wday[p->tm_wday], p->tm_hour, p->tm_min, p->tm_sec);
		printf("    %s\n",modefile);
	}else{
		fprintf(stderr,"%s file does not exist!\n",modefile);
		exit(1);
	}
}

