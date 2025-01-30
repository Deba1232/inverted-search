#include "inverted_search.h"

void search_database(HashT *hash_arr, char *word_to_search){
    int empty_database_flag = 1, word_present_flag = 0;
    
    for(int i=0;i<HASHTABLE_SIZE;i++){
        if(hash_arr[i].link){
            empty_database_flag = 0;
            break;
        }
    }

    if(!empty_database_flag){
        int idx, uppercase_flag = 0;

        if((word_to_search[0] - 'A') <= 25){
            word_to_search[0] = tolower(word_to_search[0]);
            uppercase_flag = 1;
        }

        if(isalpha(word_to_search[0])){
            idx = word_to_search[0] % 97;
        }
        else if(isdigit(word_to_search[0])){
            idx = 26;
        }
        else{
            idx = 27;
        }
        //to convert back the first letter of the word which was made lowercase to uppercase
        if(uppercase_flag){
            word_to_search[0] = toupper(word_to_search[0]);
        }

        if(hash_arr[idx].link){
            MainNode *main_temp = hash_arr[idx].link; 
            SubNode *sub_temp = main_temp->sub_link;

            while(main_temp){

                if(strcmp(word_to_search, main_temp->word) == 0){
                    word_present_flag = 1;

                    printf("Word \"%s\" is present in %d file(s)\n", word_to_search, main_temp->file_count);

                    while(sub_temp){
                        printf("In file : %s %d time(s)\n",sub_temp->file_name, sub_temp->word_count);

                        sub_temp = sub_temp->sub_link;
                    }

                    break;
                }

                main_temp = main_temp->main_link;
                sub_temp = main_temp->sub_link;
            }

            if(!word_present_flag){
                printf("Word \"%s\" not present in the database\n", word_to_search);
            }
        }
        else{
            printf("Word \"%s\" not present in the database\n", word_to_search);
        }

    }
    else{
        printf("\033[0;31m" "Database is empty!!\n" "\033[0m");
    }
    
}