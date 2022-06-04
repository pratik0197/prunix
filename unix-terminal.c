#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
#include<errno.h>

void read_command(char* command);
char* err_msg(int status);
void print_prompt();

int main(int argc, char*argv[]){

    char command[198];
    print_prompt();
    read_command(command);

    while(strcmp(command,"quit") != 0){
        
        char* delim = " "; 
        char* token = strtok(command,delim); 
        char* list_of_arguments[40];
        int i = 0;


        while(token != NULL){
            list_of_arguments[i++] = token;
            token = strtok(NULL,delim);
        }

        list_of_arguments[i] = 0;
        
        int status;
        
        if(fork() == 0){
            execvp(list_of_arguments[0], list_of_arguments);
            exit(errno);
        }
        else{
            wait(&status);
            printf("%s",err_msg(status));
        }
        print_prompt();
        read_command(command);
    }
}

// TODO: Put in separate header and library files.
int NO_COMMAND_FOUND_EXCEPTION = 512;
void read_command(char *command){

    fgets(command, sizeof command, stdin);
    command[strcspn(command, "\n")] = 0;
}


char* err_msg(int status){
    if(status == NO_COMMAND_FOUND_EXCEPTION){
        return "No such command found!\n";
    }
    return "";
}

void print_prompt(){
    printf("prunix> ");
}