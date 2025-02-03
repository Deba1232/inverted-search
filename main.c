#include "inverted_search.h"
#include "validate.h"

int main(int argc, char *argv[])
{
	char choice_to_continue;
	int option, create_database_flag = 0, update_database_flag = 0;
	char word_to_search[50], database_file_name[50];
	FILE *database_file = NULL;
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
					if(!create_database_flag || !update_database_flag){
						create_database(head, hash_arr, update_database_flag);
					
						printf("\033[0;34m" "Database created successfully for the file(s) : " "\033[0m");
						while(head){
							printf("%s ", head->file);
							head = head->link;
						}
						printf("\n");

						create_database_flag = 1;
						update_database_flag = 1;
					}
					else{
						printf("\033[0;31m" "\nDatabase already created!!\n" "\033[0m");
					}
	
					break;
				case 2:
					display_database(hash_arr);
					break;
				case 3:
					if(!update_database_flag){
						while(getchar()!='\n');

						printf("\nEnter the database file: ");
						scanf("%s", database_file_name);

						if(proper_extension(database_file_name)){

							if(update_database(hash_arr, &head, database_file_name, database_file)){

								if(head){
									printf("\033[0;34m" "Database updated successfully\n" "\033[0m");
								}
								else{
									printf("\033[0;31m" "\nFiles are already in the database!!\n" "\033[0m");
									create_database_flag = 1;
								}
								
								update_database_flag = 1;
							}
						}
						else{
							printf("Please provide the file name as <filename>.txt\n");
						}
					}
					else{
						printf("\033[0;31m" "\nDatabase is already updated!!\n" "\033[0m");
					}

					break;
				case 4:
					while(getchar()!='\n');

					printf("\nEnter the word you want to search: ");
					scanf("%s",word_to_search);

					search_database(hash_arr, word_to_search);

					break;
				case 5:
					if(create_database_flag){
						while(getchar()!='\n');

						printf("\nEnter the file name to save the database: ");
						scanf("%s", database_file_name);

						if(proper_extension(database_file_name)){
							save_database_to_file(hash_arr, database_file_name, database_file);

							sleep(1);
							printf("\033[0;34m" "Database Saved!\n" "\033[0m");
						}
						else{
							printf("Please provide the file name as <filename>.txt\n");
						}
					}
					else{
						printf("\033[0;31m" "\nCreate a database first!!\n" "\033[0m");
					}

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
		printf("\033[0;31m" "Please provide a file to start\n\n" "\033[0m");
	}
}

