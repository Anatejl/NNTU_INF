#include "5p-header.h"

void do_input(Student *students, int totalStudents) {
    for (int i = 0; i < totalStudents; i++) {
        printf("Enter name for student %d: ", i + 1);
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';

        printf("Enter marks for 4 laboratory works (0 = failed, 1 = passed) for %s:\n", students[i].name);
        for (int j = 0; j < LABS; j++) {
            printf("Lab %d: ", j + 1);
            scanf("%d", &students[i].marks[j]);
        }
        getchar();
    }
}
