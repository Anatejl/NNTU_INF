#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {
    FILE *fd = fopen("test.txt", "r");
    int str_count = 0;
    if (fd != NULL) {
        char *tmpStr = malloc(32 * sizeof (char));
        char* kek;
        do {
            kek = fgets(tmpStr, 32, fd);

            if (kek != NULL) {
                ++str_count;
            }
        } while (kek != NULL);
        free(tmpStr);

        fseek(fd, 0, SEEK_SET);
//        * == []  [2]
        char** file_strings = malloc(sizeof (char*) * str_count);
        for (int i = 0; i < str_count; ++i) {
            file_strings[i] = malloc(32 * sizeof (char));
            kek = fgets(file_strings[i], 32, fd);
            if (kek != NULL) {
                printf("%s\n", file_strings[i]);
            }
        }

        printf("\n\n");

        srand(time(0));
        for (int i = 0; i < str_count; ++i) {
            printf("%s\n", file_strings[(rand() % str_count)]);
        }

        for (int i = 0; i < str_count; ++i) {
            free(file_strings[i]);
        }
        free(file_strings);
        fclose(fd);
    }
    return 0;
}