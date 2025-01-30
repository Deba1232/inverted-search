#ifndef VALIDATE_H
#define VALIDATE_H

#define FAILURE 0
#define SUCCESS 1

#include "inverted_search.h"

int proper_argument_count(int);
int proper_extension(char *);
int is_file_empty(FILE *);
int is_duplicate_file(char *, int, char *[]);
void parse_arguments(int, char *[], FileList **);

#endif