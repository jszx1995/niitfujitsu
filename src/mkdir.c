/***********************************************************
* IT FUJITSU SECOND GROUP
* File name: mkdir.c
* Summary:   Create a directory, set the new property to mode.
* Author:    Zhu Xiang <jszx1995@126.com>
************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "io.h"

/*Create a directory*/
void create_directory(int argc, char * argv[]){
	//Determine the number of parameters	
	if(argc > 4){
		fprintf(stderr, "usage: %s Incorrect\n",argv[0]);
		exit(1);
	}
	if(strcmp(argv[1], "-m") && strcmp(argv[1], "--mkdir")){
		fprintf(stderr,"usages: %s Use -h or --help to see the command usage\n",
				argv[0]);
		exit(1);
	}
	
	char *modefile = argv[2];
	struct stat buff;
	memset(&buff,0,sizeof(buff));
	lstat(modefile,&buff);
	
    int i;
    int length = strlen(modefile);
	for(i = length-2;i >= 0;i--){
		if(modefile[i] == '/'){
	        printf("The path is not supported %s \n",modefile);	
            exit(1);
		}
	}
	if(argc == 4 ){
        if(strlen(argv[3]) != 3){
            printf("Error: The [%s] you entered is illegal\n",argv[3]);
            exit(1);
        }
        for(i = strlen(argv[3])-1;i >= 0;i--){
            if(argv[3][i] > '7' || argv[3][i] < '0'){
                printf("Error: The [%s] you entered is illegal\n",argv[3]);
                exit(1);
            }
        }
		long int mode = strtol(argv[3],NULL,8);
		if(S_ISDIR(buff.st_mode) && (access(modefile,F_OK) == 0)){
			fprintf(stderr,"The directory exists for overwrite creation %s!\n",modefile);
			delete_dir(modefile);
			umask(0);
			mkdir(modefile,mode);
			exit(1);
		}else{
            if(access(modefile,F_OK) == 0){
                fprintf(stderr,"Error: %s already exists\n",modefile);
                exit(1);
            }
			fprintf(stderr,"Create a new directory %s!\n",modefile);
			umask(0);
			mkdir(modefile,mode);
			exit(1);
		}
	}else if(argc == 3){
		if(S_ISDIR(buff.st_mode) && (access(modefile,F_OK) == 0)){
			fprintf(stderr,"The directory exists for overwrite creation %s!\n",modefile);
			delete_dir(modefile);
			mkdir(modefile,0755);
			exit(1);
		}else{
            if(access(modefile,F_OK) == 0){
                fprintf(stderr,"Error: %s already exists\n",modefile);
                exit(1);
            }
			fprintf(stderr,"Create a new directory %s!\n",modefile);
			mkdir(modefile,0755);
			exit(1);

		}
	}



/*
	char * modefile = argv[3];
	struct stat buff;
	memset(&buff,0,sizeof(buff));
	lstat(modefile,&buff);
	//long int mode = strtol(argv[3],NULL,8);

	//Determine whether the directory exists
	if(S_ISDIR(buff.st_mode) && (access(modefile,F_OK) == 0)){
		fprintf(stderr,"Overlay into a new %s directory!\n",modefile);
		//Gets the file attributes
		mode_t mode = buff.st_mode;
		umask(0);
		mkdir(argv[2],mode);
		exit(1);
	}else{
		fprintf(stderr,"%s does not exist, the default attribute new %s!\n",
				modefile,argv[2]);
		mkdir(argv[2],0755);
		exit(1);
	}
*/
}

