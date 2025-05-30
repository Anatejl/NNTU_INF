// VAR 14
#include "5a.h"

void func_input(book_t catalog[], int size) {

    for (int i = 0; i < size; i++) {

        printf("\nBook %d:\n", i + 1);
        printf("Enter book code: ");
        scanf("%s", catalog[i].book_code);
        printf("Enter UDK: ");
        scanf("%s", catalog[i].udk);
        printf("Enter author's full name: ");
        getchar();
        fgets(catalog[i].author_name, sizeof(catalog[i].author_name), stdin);
        catalog[i].author_name[strcspn(catalog[i].author_name, "\n")] = '\0';
        printf("Enter book title: ");
        fgets(catalog[i].book_title, sizeof(catalog[i].book_title), stdin);
        catalog[i].book_title[strcspn(catalog[i].book_title, "\n")] = '\0';
        printf("Enter year of publication: ");
        scanf("%d", &catalog[i].publication_year);
        printf("Enter availability (1 - available, 0 - not available): ");
        scanf("%d", &catalog[i].is_available);

    }

}

int func_process(book_t catalog[], int size, char search_code[]) {

    for (int i = 0; i < size; i++) {

        if (strcmp(catalog[i].book_code, search_code) == 0) {

            return i;

        }

    }

    return -1;
}

void func_output(book_t book) {

    printf("Book Code: %s\n", book.book_code);
    printf("UDK: %s\n", book.udk);
    printf("Author: %s\n", book.author_name);
    printf("Title: %s\n", book.book_title);
    printf("Year: %d\n", book.publication_year);
    
    if (book.is_available == 1) {

        printf("Availability: Available\n");

    } 
    else {

        printf("Availability: Not Available\n");

    }

}

int main() {
    
    book_t catalog[SIZE];
    char search_code[10];
    int found_index;

    printf("Input book details for %d books:\n", SIZE);
    func_input(catalog, SIZE);

    printf("\nEnter the book code to search: ");
    scanf("%s", search_code);

    found_index = func_process(catalog, SIZE, search_code);

    if (found_index != -1) {

        printf("\nBook found!\n");
        func_output(catalog[found_index]);

    } 
    else {

        printf("\nBook with code \"%s\" not found in the catalog.\n", search_code);

    }

    return 0;
}