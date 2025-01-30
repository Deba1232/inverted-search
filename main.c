#include "inverted_search.h"
#include "validate.h"

int main(int argc, char *argv[])
{
	char choice_to_continue;
	int option;
	char word_to_search[50];
	FileList *head = NULL;
	HashT hash_arr[HASHTABLE_SIZE] = {0};

	if(proper_argument_count(argc)){
		parse_arguments(argc, argv, &head);

		while(1){
			printf("\nSelect your choice among the following options:\n1. Create Database\n2. Display Database\n3. Update Database\n4. Search a Word\n5. Save Database\n");

			printf("Enter your choice: ");
			scanf("%d",&option);

			switch(option){
				case 1:
					create_database(head, hash_arr);

					printf("\033[0;34m" "Database created successfully for the files : " "\033[0m");
					while(head){
						printf("%s ", head->file);
						head = head->link;
					}

					break;
				case 2:
					display_database(hash_arr);
					break;
				case 3:
					break;
				case 4:
					while(getchar()!='\n');

					printf("Enter the word you want to search: ");
					scanf("%s",word_to_search);
					
					search_database(hash_arr, word_to_search);

					break;
				case 5:
					break;
				default:
					printf("Not a proper choice\n");
			}
			//clear the input buffer
			while(getchar()!='\n');
			printf("\nDo you want to continue?\nEnter Y/y to continue and N/n to stop: ");
			scanf(" %c",&choice_to_continue);

			if(choice_to_continue == 'Y' || choice_to_continue == 'y'){
				continue;
			}
			else{
				break;
			}
		}
		
	}
	else{
		//pass
	}
}

