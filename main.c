#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"
#include "twins.h"
#include "student.h"

#define INPUT_FILE "data/students.txt"
#define OUTPUT_FILE "data/results.txt"

int main() {
    int choice;
    
    printf("=== File Processing Program (Variant 3) ===\n");
    printf("1. Process student data from file\n");
    printf("2. Find twin primes and save to file\n");
    printf("3. Run both tasks\n");
    printf("4. Exit\n");
    printf("Choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            // Создаем входной файл
            createInputFile(INPUT_FILE);
            
            // Обрабатываем файл
            readAndProcessFile(INPUT_FILE, OUTPUT_FILE);
            
            printf("\nProcessing complete. Check %s for results.\n", OUTPUT_FILE);
            break;
            
        case 2: {
            int limit;
            printf("Enter upper limit for twin primes: ");
            scanf("%d", &limit);
            
            findTwinPrimes(limit, OUTPUT_FILE);
            printf("\nResults appended to %s\n", OUTPUT_FILE);
            break;
        }
            
        case 3:
            // Создаем входной файл
            createInputFile(INPUT_FILE);
            
            // Обрабатываем файл со студентами
            readAndProcessFile(INPUT_FILE, OUTPUT_FILE);
            
            // Добавляем числа-близнецы
            int limit;
            printf("\nEnter upper limit for twin primes: ");
            scanf("%d", &limit);
            
            findTwinPrimes(limit, OUTPUT_FILE);
            
            printf("\nAll results saved to %s\n", OUTPUT_FILE);
            break;
            
        case 4:
            printf("Exiting...\n");
            break;
            
        default:
            printf("Invalid choice!\n");
    }
    
    return 0;
}
