// VAR 14
#ifndef LIBRARY_CATALOG_H
#define LIBRARY_CATALOG_H

#include <stdio.h>
#include <string.h>

#define SIZE 3

typedef struct {

    char book_code[10];
    char udk[10];
    char author_name[50];
    char book_title[50];
    int publication_year;
    int is_available;

} book_t;

void func_input(book_t *catalog, int size);
void func_process(book_t *catalog, int size, char *search_code, book_t **result);
void func_output(book_t *book);

#endif