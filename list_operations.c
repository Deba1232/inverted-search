#include "list_operations.h"

void insert_at_last(FileList **head, char *file_name){
    FileList *new_node = (FileList *)calloc(1, sizeof(FileList));
    if(!new_node){
        fprintf(stderr, "Memory couldn't be allocated for the node\n");
        exit(EXIT_FAILURE);
    }

    strcpy(new_node->file,file_name);
    new_node->link = NULL;

    if(!*head){
        *head = new_node;
        return;
    }

    FileList *temp = *head;

    while(temp->link){
        temp = temp->link;
    }

    temp->link = new_node;
    return;
}

void delete_list(FileList **head){
	if(!*head){
	    printf("List is empty, nothing to delete\n");
	}
	
	FileList *temp = *head;
	
	while(*head){
	    temp = *head;
	    *head = (*head)->link;
	    free(temp);
	}
	
	free(*head);
	*head = NULL;
}

void print_list(FileList *head){
    if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
    else
    {
	    printf("Head -> ");
        while (head)		
	    {
		    printf("%s -> ", head -> file);
		    head = head -> link;
	    }

	    printf("NULL\n");
    }
}

void create_hashtable(HashT *arr, int size){
    for(int i=0;i<size;i++){
		arr[i].index = i;
		arr[i].link = NULL;
	}
}

MainNode *create_main_node(MainNode *main_node, char *word){
    main_node = (MainNode *)calloc(1, sizeof(MainNode));
	if(!main_node){
		fprintf(stderr, "Memory couldn't be allocated for main node\n");
		exit(EXIT_FAILURE);
	}
	main_node->file_count = 1;
	strcpy(main_node->word, word);
	main_node->main_link = NULL;
	main_node->sub_link = NULL;

    return main_node;
}

SubNode *create_sub_node(SubNode *sub_node, char *file_name){
    sub_node = (SubNode *)calloc(1, sizeof(SubNode));
	if(!sub_node){
		fprintf(stderr, "Memory couldn't be allocated for main node\n");
		exit(EXIT_FAILURE);
	}
	sub_node->word_count = 1;
	strcpy(sub_node->file_name, file_name);
	sub_node->sub_link = NULL;

    return sub_node;
}