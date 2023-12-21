#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkLineNumbers (char* currentLine, char* previousLine){
    char* current = NULL;
    char* previous = NULL;
    if(previousLine){
        strcpy(current, currentLine);
        strcpy(previous, previousLine);
        
    }
}

int main() {
    int sum = 0;
    FILE* inputfile;
    char* previousLine = NULL;
    char currentLine[256];
    inputfile = fopen("input_day_3_example.txt", "r");
    while (fgets(currentLine, sizeof(currentLine), inputfile))
    {
        sum += checkLineNumbers(currentLine, previousLine);
    }
    printf("%d\n", sum);
    getchar();
}