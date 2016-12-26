#ifndef __IO_H__
#define __IO_H__
static struct option long_options[] = {
	        {"help",no_argument,NULL,'h'},          //View the help documentation
	        {"list",required_argument,NULL,'l'},    //List the properties of the object
	        {"display",required_argument,NULL,'d'}, //List the contents of the file
	        {"create",required_argument,NULL,'c'},  //Create a file
	        {"mkdir",required_argument,NULL,'m'},   //Create a directory
	        {"delete",required_argument,NULL,'r'},  //Delete a file or directory
	        {"copy",required_argument,NULL,'p'},    //Copy the file
	        {"symlink",required_argument,NULL,'s'}, //Create a soft connection
	        {NULL,no_argument,NULL,0}
};

extern void display_usage(int, char *[]);

extern void list_object(int, char *[]);

extern void display_file(int, char *[]);

extern void create_file(int, char *[]);

extern void create_directory(int, char *[]);

extern void delete_file_dir(int, char *[]);

extern void delete_dir(char *);

extern void copy_file_dir(int, char *[]);

extern void symkink_file_dir(int,char *[]);
#endif
