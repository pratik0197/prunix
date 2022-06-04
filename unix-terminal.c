#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
int main(int argc, char*argv[]){
    char command[198];
    fgets(command, sizeof command, stdin);
    command[strcspn(command, "\n")] = 0;
    while(strcmp(command,"quit") != 0){
        char* delim = ";/ "; 
        char* token = strtok(command,delim); // tokenizes the string based on delimiters
        char* list_of_arguments[40];
        int i = 0;
        while(token != NULL){
            list_of_arguments[i++] = token;
            token = strtok(NULL,delim);
        }
        list_of_arguments[i] = 0;
        // for(int j = 0; j <=i ; j++)
        //     printf("%s ",list_of_arguments[j]);
        // printf("\n");
        execvp(list_of_arguments[0], list_of_arguments);
    }
}