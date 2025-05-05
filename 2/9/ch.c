#include <stdio.h>
#include <string.h>

#define MAX_PUBLICATIONS 100
#define MAX_TITLE_LENGTH 100
#define MAX_GENRE_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    int year;
    char genre[MAX_GENRE_LENGTH];
} Library;

void do_fill(Library catalog[], int *total_publications) {
    printf("Enter the number of publications: ");
    scanf("%d", total_publications);
    getchar();
    
    for (int i = 0; i < *total_publications; i++) {
        printf("Enter title for publication %d: \n", i + 1);
        fgets(catalog[i].title, MAX_TITLE_LENGTH, stdin);
        catalog[i].title[strcspn(catalog[i].title, "\n")] = 0;

        printf("Enter year for publication %d: \n", i + 1);
        scanf("%d", &catalog[i].year);
        getchar();

        printf("Enter genre for publication %d: \n", i + 1);
        fgets(catalog[i].genre, MAX_GENRE_LENGTH, stdin);
        catalog[i].genre[strcspn(catalog[i].genre, "\n")] = 0;
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

int do_search(Library catalog[], int catalog_size, const char *genre, int year_start, int year_end, Library matches[]) {
    int match_count = 0;
    for (int i = 0; i < catalog_size; i++) {
        if ((strcmp(catalog[i].genre, genre) == 0) &&
        (catalog[i].year >= year_start && catalog[i].year <= year_end)) {
            matches[match_count++] = catalog[i];
        }
    }
    return match_count;
}

void do_output(Library matches[], int match_count, const char *genre, int year_start, int year_end) {
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

    Library catalog[MAX_PUBLICATIONS];
    int total_publications;
    do_fill(catalog, &total_publications);

    char search_genre[MAX_GENRE_LENGTH];
    int search_year_start, search_year_end;
    do_input(search_genre, &search_year_start, &search_year_end);

    Library matches[MAX_PUBLICATIONS];
    int match_count = do_search(catalog, total_publications, search_genre, search_year_start, search_year_end, matches);
    do_output(matches, match_count, search_genre, search_year_start, search_year_end);

    return 0;
}
