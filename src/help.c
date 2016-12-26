/************************************************************
* NIIT FUJITSU SECOND GROUP
* File name: help.c
* Summary:   Matches command line options and arguments
* Author:    Zhu Xiang <jszx1995@126.com>
*************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>
#include "io.h"

/*View the help documentation*/
void display_usage(int argc,char *argv[]){
	if(argc == 2){
		if(strcmp(argv[1], "-h") && strcmp(argv[1], "--help")){
			fprintf(stderr,"usages: %s Use -h or --help to see the command usage\n",
					argv[0]);
			exit(1);
		}else{
			FILE *fp = NULL;        
			char ch;
			fp = fopen("/work/linuxc/niitfujitsu/src/help.txt","r");
			while((ch = fgetc(fp)) != EOF)
			        putchar(ch);
			fclose(fp);
			exit(1);
		}
	}else{
		fprintf(stderr,"usages: %s Use -h or --help to see the command usage\n",
				argv[0]);
		exit(1);
	}
}

