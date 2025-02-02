#ifndef INVERTED_SEARCH_H
#define INVERTED_SEARCH_H

#define HASHTABLE_SIZE 28

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct List{
    char file[50];
    struct List *link;
}FileList;

typedef struct SubNode{
    int word_count;
    char file_name[50];
    struct SubNode *sub_link;
}SubNode;

typedef struct MainNode{
    int file_count;
    char word[50];
    struct MainNode *main_link;
    SubNode *sub_link;
}MainNode;

typedef struct HashTable{
    int index;
    MainNode *link;
}HashT;

void add_to_database(HashT *, char *, char *);
void create_database(FileList *, HashT *, int);
void display_database(HashT *);
void search_database(HashT *, char *);
void save_database_to_file(HashT *, char *, FILE *);
void update_database(HashT *, FileList **, char *, FILE *);

#endif