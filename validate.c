#include "validate.h"
#include "list_operations.h"

int proper_argument_count(int argc){
    if(argc > 1){
        return SUCCESS;
    }
    
    return FAILURE;
}

int proper_extension(char *arg){
    if(strstr(arg, ".txt") && (*(strstr(arg, ".txt") + 4) == '\0')){
        return SUCCESS;
    }
    
    return FAILURE;
}

int is_file_empty(FILE *file){
    fseek(file, 0, SEEK_END);

    if(ftell(file) == 0){
        return SUCCESS;
    }

    return FAILURE;
}

int is_duplicate_file(char *arg, int index, char *argv[]){
    
    for(int i=1;i<index;i++){

        if(strcmp(arg, argv[i]) == 0){
            return SUCCESS;
        }
    }

    return FAILURE;
}

void parse_arguments(int argc, char *argv[], FileList **head){
    FILE *file;

    for(int i=1;i<argc;i++){

        if(proper_extension(argv[i])){

            if(file = fopen(argv[i], "r")){

                if(!is_file_empty(file)){

                    if(!is_duplicate_file(argv[i], i, argv)){
                        insert_at_last(head, argv[i]);
                        printf("%s is successfully added\n", argv[i]);
                    }
                    else{
                        printf("%s is already added\n", argv[i]);
                    }
                }
                else{
                    printf("%s is empty file\n", argv[i]);
                }

                fclose(file);
            }
            else{
                printf("%s is not available\n", argv[i]);
            }
        }
        else{
            printf("%s is not a .txt file\n", argv[i]);
        }
    }
}