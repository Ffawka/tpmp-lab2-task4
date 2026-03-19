#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_utils.h"
#include "student.h"
#include "twins.h"

#define MAX_LINE 256

int createInputFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Cannot create file %s\n", filename);
        return -1;
    }
    
    fprintf(file, "Иванов И.И.|ФИТ 3-1|5 5 5 5\n");
    fprintf(file, "Петров П.П.|ФИТ 3-1|4 4 4 4\n");
    fprintf(file, "Сидоров С.С.|ФИТ 3-1|5 5 4 5\n");
    fprintf(file, "Кузнецов К.К.|ФИТ 3-1|4 5 4 4\n");
    fprintf(file, "Васильев В.В.|ФИТ 3-1|5 4 5 4\n");
    fprintf(file, "Федоров Ф.Ф.|ФИТ 3-1|3 4 3 3\n");
    fprintf(file, "Николаев Н.Н.|ФИТ 3-1|5 5 5 4\n");
    fprintf(file, "Михайлов М.М.|ФИТ 3-1|4 3 4 3\n");
    fprintf(file, "Александров А.А.|ФИТ 3-1|5 5 5 5\n");
    fprintf(file, "Сергеев С.С.|ФИТ 3-1|4 4 5 4\n");
    
    fclose(file);
    printf("Created input file: %s\n", filename);
    return 0;
}

int readAndProcessFile(const char *inputFile, const char *outputFile) {
    STUD students[MAX_STUDENTS];
    
    // Читаем студентов из файла
    int count = readStudentsFromFile(inputFile, students, MAX_STUDENTS);
    if (count <= 0) {
        printf("Error: No students read from file\n");
        return -1;
    }
    
    // Открываем выходной файл для записи
    FILE *out = fopen(outputFile, "w");
    if (out == NULL) {
        printf("Error: Cannot create output file %s\n", outputFile);
        return -1;
    }
    
    fprintf(out, "=== File Processing Results ===\n");
    fprintf(out, "Input file: %s\n", inputFile);
    fprintf(out, "Number of students: %d\n\n", count);
    fclose(out);
    
    // Сортируем по алфавиту
    sortStudentsByName(students, count);
    
    // Записываем отсортированный список в файл
    out = fopen(outputFile, "a");
    fprintf(out, "=== Students sorted by name ===\n");
    fclose(out);
    
    for(int i = 0; i < count; i++) {
        out = fopen(outputFile, "a");
        printStudentToFile(out, &students[i]);
        fclose(out);
    }
    
    // Записываем студентов с баллом > 4.2
    printHighAchieversToFile(students, count, outputFile);
    
    return 0;
}
