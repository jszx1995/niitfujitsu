/***********************************************************
 *NIIT FUJITSU SECOND GROUP
 *File name: main.c
 *Summary:   Matches command line options and arguments
 *Author:    Zhu Xiang <jszx1995@126.com>
 ***********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include "io.h"

static const char *optString = "hl:d:c:m:r:p:s:";

int main(int argc, char *argv[]){
	int opt = 0;
	int option_index = 0;

	//h View the help documentation
	//l List the properties of the object
	//d List the contents of the file
	//c Create a file
	//m Create a directory
	//r Delete a file or directory
	//p Copy the file
	//s Create a soft connection

	while( (opt = getopt_long( argc, argv, optString, long_options, &option_index)) != -1 ){
		switch( opt ){
			case 'h':
				display_usage(argc,argv);
				break;
			case 'l':
				list_object(argc,argv);
				break;
			case 'd':
				display_file(argc,argv);
				break;
			case 'c':
				create_file(argc,argv);
				break;
			case 'm':
				create_directory(argc,argv);	
				break;
			case 'r':
				delete_file_dir(argc,argv);
				break;
			case 'p':
				copy_file_dir(argc,argv);
				break;
			case 's':
				symkink_file_dir(argc,argv);
				break;
			default:
				fprintf(stderr,"usages: %s Use -h or --help to see the command usage\n",argv[0]);
				break;
		}
	}
	
	return 0;
}
