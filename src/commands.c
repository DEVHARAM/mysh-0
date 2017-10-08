#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define SIZE 1000

#include <string.h>
#include "commands.h"

char buf[SIZE];
char dir[1025];
int do_cd(int argc, char** argv) {
char cmp[1025];
  if (!validate_cd_argv(argc, argv))
    return -1;

  chdir(argv[1]);
  getcwd(cmp,1025);
  if(strcmp(dir,cmp)==0)
  return -1;
  return 0;

}


int do_pwd(int argc, char** argv) {
  if (!validate_pwd_argv(argc, argv))
    return -1;
  
	getcwd(dir,1025);
  	printf("%s\n",dir);

  return 0;
}

int validate_cd_argv(int argc, char** argv) {


  if(argc==2&&argv[1]!=NULL&&strcmp(argv[0],"cd")==0)
 	 return 1;
  else
 	 return 0;
}

int validate_pwd_argv(int argc, char** argv) {
  if(argc==1&&strcmp(argv[0],"pwd")==0)
 	 return 1;
  else 
	return 0;
}
