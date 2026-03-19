#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"

float calculateAverage(const int *ses) {
    float sum = 0;
    for(int i = 0; i < SUBJECTS; i++) {
        sum += ses[i];
    }
    return sum / SUBJECTS;
}

int readStudentsFromFile(const char *filename, STUD *students, int maxCount) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        return -1;
    }
    
    char line[MAX_LINE];
    int count = 0;
    
    while (fgets(line, sizeof(line), file) != NULL && count < maxCount) {
        // Убираем символ новой строки
        line[strcspn(line, "\n")] = 0;
        
        // Парсим строку формата: Name|Group|grade1 grade2 grade3 grade4
        char *token = strtok(line, "|");
        if (token != NULL) {
            strcpy(students[count].name, token);
            
            token = strtok(NULL, "|");
            if (token != NULL) {
                strcpy(students[count].group, token);
                
                token = strtok(NULL, "|");
                if (token != NULL) {
                    // Парсим оценки
                    sscanf(token, "%d %d %d %d", 
                           &students[count].ses[0],
                           &students[count].ses[1],
                           &students[count].ses[2],
                           &students[count].ses[3]);
                    
                    students[count].average = calculateAverage(students[count].ses);
                    students[count].original_index = count;
                    count++;
                }
            }
        }
    }
    
    fclose(file);
    printf("Read %d students from %s\n", count, filename);
    return count;
}

void printStudent(const STUD *s) {
    printf("Name: %s\n", s->name);
    printf("Group: %s\n", s->group);
    printf("Grades: ");
    for(int i = 0; i < SUBJECTS; i++) {
        printf("%d ", s->ses[i]);
    }
    printf("\nAverage: %.2f\n", s->average);
    printf("Original position: %d\n", s->original_index + 1);
    printf("------------------------\n");
}

void printStudentToFile(FILE *file, const STUD *s) {
    fprintf(file, "Name: %s\n", s->name);
    fprintf(file, "Group: %s\n", s->group);
    fprintf(file, "Grades: ");
    for(int i = 0; i < SUBJECTS; i++) {
        fprintf(file, "%d ", s->ses[i]);
    }
    fprintf(file, "\nAverage: %.2f\n", s->average);
    fprintf(file, "Original position: %d\n", s->original_index + 1);
    fprintf(file, "------------------------\n");
}

int compareByName(const void *a, const void *b) {
    STUD *studentA = (STUD *)a;
    STUD *studentB = (STUD *)b;
    return strcmp(studentA->name, studentB->name);
}

int compareByAverage(const void *a, const void *b) {
    STUD *studentA = (STUD *)a;
    STUD *studentB = (STUD *)b;
    
    if (studentA->average < studentB->average) return -1;
    if (studentA->average > studentB->average) return 1;
    return 0;
}

void sortStudentsByName(STUD *students, int count) {
    qsort(students, count, sizeof(STUD), compareByName);
}

void printHighAchieversToFile(STUD *students, int count, const char *filename) {
    STUD highAchievers[MAX_STUDENTS];
    int highCount = 0;
    
    // Отбираем студентов со средним баллом > 4.2
    for(int i = 0; i < count; i++) {
        if(students[i].average > 4.2) {
            highAchievers[highCount] = students[i];
            highCount++;
        }
    }
    
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        return;
    }
    
    if(highCount == 0) {
        fprintf(file, "\nNo students with average grade > 4.2\n");
        printf("\nNo students with average grade > 4.2\n");
        fclose(file);
        return;
    }
    
    // Сортируем по возрастанию среднего балла
    qsort(highAchievers, highCount, sizeof(STUD), compareByAverage);
    
    fprintf(file, "\n=== Students with average grade > 4.2 (sorted by average) ===\n");
    printf("\n=== Students with average grade > 4.2 (sorted by average) ===\n");
    
    for(int i = 0; i < highCount; i++) {
        printStudentToFile(file, &highAchievers[i]);
        printStudent(&highAchievers[i]);
    }
    
    fclose(file);
}
