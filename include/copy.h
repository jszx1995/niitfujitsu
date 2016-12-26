#ifndef __COPY_H__
#define __COPY_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
extern int directory_copy(char *,char *);

extern int directory_copy_directory(char *,char *);

extern void file_copy(char *,char *);

extern void file_copy_directory(char *,char *);

extern int createdir(char *);

#endif
