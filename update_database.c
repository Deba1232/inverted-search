#include "inverted_search.h"
#include "validate.h"
#include "list_operations.h"

int is_proper_file(FILE *database_file){
    char ch;
    int count = 0;

    while((ch = fgetc(database_file)) != EOF){
        if(count == 0 && ch != '#'){
            return FAILURE;
        }
        count++;
    }

    fseek(database_file, -2, SEEK_END);

    if((ch = fgetc(database_file)) != '#'){
        return FAILURE;
    }

    rewind(database_file);
    return SUCCESS;
}

int is_valid_database_file(char *database_file_name, FILE *database_file){
    if(proper_extension(database_file_name)){

        if(database_file){
            
            if(!is_file_empty(database_file)){
                rewind(database_file);
                
                if(is_proper_file(database_file)){
                    return SUCCESS;
                }
                else{
                    printf("%s is not a proper database file\n", database_file_name);
                    return FAILURE;
                }
            }
            else{
                printf("%s is an empty file\n", database_file_name);
                return FAILURE;
            }
        }
        else{
            printf("%s is not available, please create one first\n", database_file_name);
            return FAILURE;
        }
    }
    else{
        printf("Please provide file extension as \".txt\"");
        return FAILURE;
    }
}

int update_database(HashT *hash_arr, FileList **head, char *database_file_name, FILE *database_file){
    int hash_index, file_count, word_count;
    char word[50], file_name[50];
    MainNode *main_node = NULL, *prev_main_node = NULL;
    SubNode *sub_node = NULL, *prev_sub_node = NULL;

    database_file = fopen(database_file_name, "r");

    if(is_valid_database_file(database_file_name, database_file)){
        //load the data from database file to the hash table, so that we don't lose the already available data
        while(fscanf(database_file, "#%d;%[^;];%d;", &hash_index, word, &file_count) != EOF){
            main_node = create_main_node(main_node, word);
            main_node->file_count = file_count;

            MainNode *temp = hash_arr[hash_index].link;
            //this condition prevents a segfault when we try to access temp->main_link for temp = NULL for when we want to add a node at the end
            while(temp && temp->main_link){
                temp = temp->main_link;
            }

            for(int i=0;i < file_count;i++){
                fscanf(database_file, "%[^;];%d;", file_name, &word_count);

                sub_node = create_sub_node(sub_node, file_name);
                sub_node->word_count = word_count;
                //remove the files from the file list which are already present in the database
                delete_file_node(head, file_name);
                //in the first iteration, just add main nodes and update main node links with first subnode
                if(i == 0){
                    if(!temp){
                        hash_arr[hash_index].link = main_node;
                        main_node->sub_link = sub_node;
                    }
                    else{
                        temp->main_link = main_node;
                        main_node->sub_link = sub_node;
                    }   
                }
                else{
                    prev_sub_node->sub_link = sub_node;
                }

                prev_sub_node = sub_node;
            }

            fscanf(database_file, "#\n");
        }

        fclose(database_file);

        return SUCCESS;
    }
    else{
        return FAILURE;
    }
}