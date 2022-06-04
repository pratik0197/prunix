
#include "constants.h"
void print_prompt(){
    printf("prunix> ");

}


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

void interactive_mode(char* command){
    print_prompt();
    read_command(command);
}

void batch_mode(char* command, FILE* fptr){
    if(feof(fptr))
        exit(0);
    int buffer_length = 2000;
    fgets(command,buffer_length,fptr);
    command[strcspn(command, "\n")] = 0;
}

void input_command(char*command, FILE* fptr){

    if(fptr == NULL)
        interactive_mode(command);
    else 
        batch_mode(command,fptr);
}