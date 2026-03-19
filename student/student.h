#ifndef STUDENT_H
#define STUDENT_H

#define SUBJECTS 4
#define MAX_STUDENTS 10
#define NAME_LEN 50
#define GROUP_LEN 30
#define MAX_LINE 256

typedef struct {
    char name[NAME_LEN];
    char group[GROUP_LEN];
    int ses[SUBJECTS];
    float average;
    int original_index;
} STUD;

// Функции для работы со студентами
int readStudentsFromFile(const char *filename, STUD *students, int maxCount);
void printStudent(const STUD *s);
void printStudentToFile(FILE *file, const STUD *s);
float calculateAverage(const int *ses);
void sortStudentsByName(STUD *students, int count);
void printHighAchieversToFile(STUD *students, int count, const char *filename);
int compareByName(const void *a, const void *b);
int compareByAverage(const void *a, const void *b);

#endif
