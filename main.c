#include "inverted_search.h"
#include "validate.h"

int main(int argc, char *argv[])
{
	char choice_to_continue;
	int option;
	FileList *head = NULL;

	if(proper_argument_count(argc)){
		parse_arguments(argc, argv, &head);

		while(1){
			printf("\nSelect your choice among the following options:\n1. Create Database\n2. Display Database\n3. Update Database\n4. Search a Word\n5. Save Database\n");

			printf("Enter your choice: ");
			scanf("%d",&option);

			switch(option){
				case 1:
					create_database(head);
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
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

