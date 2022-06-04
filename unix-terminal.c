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
void execute_individual_command(char* command);
int main(int argc, char*argv[]){

    char command[2000];
    print_prompt();
    read_command(command);
    
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
        while((wpid = wait(&status)) > 0);
        
        print_prompt();
        read_command(command);
    }
}

// TODO: Put in separate header and library files.
// Constants
const int NO_COMMAND_FOUND_EXCEPTION = 512;



void read_command(char *command){
    fflush(stdin);
    fgets(command, 2000, stdin);
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

void execute_individual_command(char* command){

    char delim[2] = " "; 
    char* list_of_arguments[200];
    int i = 0;
    char* token = strtok(command,delim); 

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
}