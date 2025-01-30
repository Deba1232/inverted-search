#include "inverted_search.h"

void display_database(HashT *hash_arr){
    int empty_database_flag = 1;
    printf("---------------------------------------------------------------------------------------------\n");
    printf("%-20s%-20s%-20s%-20s%-20s\n","Index","Word","File Count","File Name","Word Count");
    printf("---------------------------------------------------------------------------------------------\n");

    for(int i=0;i<HASHTABLE_SIZE;i++){
        if(hash_arr[i].link){
            empty_database_flag = 0;
            break;
        }
    }
    
    if(!empty_database_flag){
        MainNode *temp_main;
        SubNode *temp_sub;

        for(int i = 0; i < HASHTABLE_SIZE; i++){
            if(hash_arr[i].link){
                temp_main = hash_arr[i].link;

                while(temp_main){
                    int count = 0;

                    printf("%-20d", i);
                    printf("%-20s%-20d", temp_main->word, temp_main->file_count);
                    temp_sub = temp_main->sub_link;

                    while(temp_sub){
                        if(count == 0){
                            printf("%-20s%-20d\n", temp_sub->file_name, temp_sub->word_count);
                            temp_sub = temp_sub->sub_link;
                        }
                        else{
                            printf("%66s%15d\n", temp_sub->file_name, temp_sub->word_count);
                            temp_sub = temp_sub->sub_link;
                        }
                        count++;
                    }
                    printf("\n");
                    
                    temp_main = temp_main->main_link;
                }
                printf("---------------------------------------------------------------------------------------------\n");
            }
        }
    }
    else{
        printf("\033[0;31m" "Database is empty!!\n" "\033[0m");
    }
}