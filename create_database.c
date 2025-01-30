#include "inverted_search.h"
#include "list_operations.h"

void add_to_database(HashT *arr, char *file_name, char *word){
	int idx, uppercase_flag = 0;

	if((word[0] - 'A') <= 25){
		word[0] = tolower(word[0]);
		uppercase_flag = 1;
	}

	if(isalpha(word[0])){
		idx = word[0] % 97;
	}
	else if(isdigit(word[0])){
		idx = 26;
	}
	else{
		idx = 27;
	}
	//to convert back the first letter of the word which was made lowercase to uppercase
	if(uppercase_flag){
		word[0] = toupper(word[0]);
	}
	
	MainNode *new_main_node = NULL;
	SubNode *new_sub_node = NULL;

	if(!arr[idx].link){
		new_main_node = create_main_node(new_main_node, word);
		new_sub_node = create_sub_node(new_sub_node, file_name);

		arr[idx].link = new_main_node;
		new_main_node->sub_link = new_sub_node;
	}
	else{
		MainNode *temp_main_node = arr[idx].link;
		
		while(temp_main_node->main_link){
			//if we get the same word, just break out of the loop
			if(strcmp(word, temp_main_node->word) == 0){
				break;
			}
			temp_main_node = temp_main_node->main_link;
		}
		//update the pointer to the sub node everytime the pointer to main node changes
		SubNode *temp_sub_node = temp_main_node->sub_link;
		//same word
		if(strcmp(word, temp_main_node->word) == 0){

			while(temp_sub_node->sub_link){
				temp_sub_node = temp_sub_node->sub_link;
			}
			//same file
			if(strcmp(file_name, temp_sub_node->file_name) == 0){
				temp_sub_node->word_count++;
			}
			//different file
			else{
				temp_main_node->file_count++;
				new_sub_node = create_sub_node(new_sub_node, file_name);
				temp_sub_node->sub_link = new_sub_node;
			}
		}
		//different words
		else{
			new_main_node = create_main_node(new_main_node, word);
			new_sub_node = create_sub_node(new_sub_node, file_name);

			temp_main_node->main_link = new_main_node;
			new_main_node->sub_link = new_sub_node;
		}
	}
}

void create_database(FileList *head, HashT *hash_arr){
	char word[50];

	create_hashtable(hash_arr, HASHTABLE_SIZE);

	if(!head){
		fprintf(stderr, "File list is empty, unable to proceed further\n");
		exit(EXIT_FAILURE);
	} 

	FileList *temp = head;

	while(temp){
		FILE *file = fopen(temp->file, "r");

		while(fscanf(file, "%s", word) != EOF){
			add_to_database(hash_arr, temp->file, word);
		}

		fclose(file);
		temp = temp->link;
	}
}

