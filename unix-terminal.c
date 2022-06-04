#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
#include<errno.h>
#include"utils/inpop.h"
#include"commands/execute.h"

int main(int argc, char*argv[]){
    FILE* fptr = NULL;

    if(argc == 2){
        char* fname = argv[1];
        if(access(fname,F_OK) == 0){
            fptr = fopen(fname,"r");
        }
        else{
            printf("%s",FILE_NOT_FOUND);
            exit(0);
        }
    } 

    char command[2000];
    input_command(command,fptr);
        
    while(strcmp(command,"quit") != 0){
        
        char delim[2] = ";";
        char* list_of_commands[200];
        char* token = strtok(command,delim);
        int wpid,status;
        int i = 0;
        while(token != NULL){
            list_of_commands[i++] = token;
            token = strtok(NULL,delim);
        }
        for(int j=0;j<i;j++){
            execute_individual_command(list_of_commands[j]);
        }
        while((wpid = wait(&status)) > 0){
            printf("%s",err_msg(status));
        }
        
        input_command(command,fptr);
            
    }
    fclose(fptr);
}
