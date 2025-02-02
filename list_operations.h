#ifndef LIST_OPERATIONS_H
#define LIST_OPERATIONS_H

#include "inverted_search.h"
//for the file list
void insert_at_last(FileList **, char *);
int find_file_node(FileList *, char *);
void delete_file_node(FileList **, char *);
void delete_list(FileList **);
void print_list(FileList *);
//for hashtable
void initialize_hashtable(HashT *, int);
MainNode *create_main_node(MainNode *, char *);
SubNode *create_sub_node(SubNode *, char *);

#endif