#include "utils.h"
#include <stdlib.h>
#include <string.h>
#define MAX 10000

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
int i=0;
*argc=0;
char* token=(char*)malloc(MAX*sizeof(char));
char *set=(char*)malloc(MAX*sizeof(char));
*argv=(char**)malloc(MAX*sizeof(char));
**argv=(char*)malloc(MAX*sizeof(char));
strcpy(set,command);


	token=strtok(set," ");
		while(token!=NULL)
		{
			if(strcmp(token,"\n")==0||strcmp(token,"\t")==0){
				token=strtok(NULL," ");
				continue;
				}
			else{
			*(*argv+i)=(char*)malloc(MAX*sizeof(char));
			strcpy(*((*argv)+i),token);
			i++;
			(*argc)++;
			
			token=strtok(NULL," ");
			}
		}
}

