#include "inverted_search.h"

void save_database_to_file(HashT *hash_arr){
    int empty_database_flag = 1;
    FILE *database_file = NULL;

    for(int i=0;i < HASHTABLE_SIZE;i++){
        if(hash_arr[i].link){
            empty_database_flag = 0;
            break;
        }
    }

    if(!empty_database_flag){
        database_file = fopen("database.txt", "w");

        if(!database_file){
            fprintf(stderr, "File couldn't be opened for writing, unable to proceed further\n");
            exit(EXIT_FAILURE);
        }

        for(int i=0;i < HASHTABLE_SIZE;i++){
            if(hash_arr[i].link){
                MainNode *temp_main = hash_arr[i].link;

                while(temp_main){
                    fprintf(database_file, "#%d;%s;%d;", i, temp_main->word, temp_main->file_count);
                    SubNode *temp_sub = temp_main->sub_link;

                    while(temp_sub){
                        fprintf(database_file, "%s;%d;",temp_sub->file_name, temp_sub->word_count);
                        temp_sub = temp_sub->sub_link;
                    }

                    fprintf(database_file, "#\n");

                    temp_main = temp_main->main_link;
                }
            }
        }

        fclose(database_file);
    }
    else{
        printf("\033[0;31m" "Database is empty!!\n" "\033[0m");
    }
}