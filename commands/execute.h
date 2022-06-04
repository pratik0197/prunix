
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