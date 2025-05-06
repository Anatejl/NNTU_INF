#include <stdio.h>
#include <string.h>

#define MAX_PUBLICATIONS 100
#define MAX_TITLE_LENGTH 100
#define MAX_GENRE_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    int year;
    char genre[MAX_GENRE_LENGTH];
} Book;

void do_fill(Book library[], int *total_publications) {
    printf("Enter the number of publications: ");
    scanf("%d", total_publications);
    getchar();
    
    for (int i = 0; i < *total_publications; i++) {
        printf("Enter title for publication %d: \n", i + 1);
        fgets(library[i].title, MAX_TITLE_LENGTH, stdin);
        library[i].title[strcspn(library[i].title, "\n")] = 0;

        printf("Enter year for publication %d: \n", i + 1);
        scanf("%d", &library[i].year);
        getchar();

        printf("Enter genre for publication %d: \n", i + 1);
        fgets(library[i].genre, MAX_GENRE_LENGTH, stdin);
        library[i].genre[strcspn(library[i].genre, "\n")] = 0;
    }
}

void do_input(char *search_genre, int *search_year_start, int *search_year_end) {
    printf("Enter genre to search: \n");
    fgets(search_genre, MAX_GENRE_LENGTH, stdin);
    search_genre[strcspn(search_genre, "\n")] = 0;
    
    printf("Enter start year: \n");
    scanf("%d", search_year_start);
    printf("Enter end year: \n");
    scanf("%d", search_year_end);
}

int do_search(Book library[], int library_size, const char *genre, int year_start, int year_end, Book matches[]) {
    int match_count = 0;
    for (int i = 0; i < library_size; i++) {
        if ((strcmp(library[i].genre, genre) == 0) &&
        (library[i].year >= year_start && library[i].year <= year_end)) {
            matches[match_count++] = library[i];
        }
    }
    return match_count;
}

void do_output(Book matches[], int match_count, const char *genre, int year_start, int year_end) {
    printf("Titles in genre \"%s\" from %d to %d:\n", genre, year_start, year_end);
    if (match_count == 0) {
        printf("No matching publications found.\n");
        return;
    }
    for (int i = 0; i < match_count; i++) {
        printf(" - %s (%d)\n", matches[i].title, matches[i].year);
    }
}

int main() {

    Book library[MAX_PUBLICATIONS];
    int total_publications;
    do_fill(library, &total_publications);

    char search_genre[MAX_GENRE_LENGTH];
    int search_year_start, search_year_end;
    do_input(search_genre, &search_year_start, &search_year_end);

    Book matches[MAX_PUBLICATIONS];
    int match_count = do_search(library, total_publications, search_genre, search_year_start, search_year_end, matches);
    do_output(matches, match_count, search_genre, search_year_start, search_year_end);

    return 0;
}
