#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int sum = 0;
    FILE* inputfile;
    char* currentLine;
    char* copiedCurrentLine;
    char* previousLine;
    char* copiedPreviousLine;
    inputfile = fopen("input_day_3_example.txt", "r");
    fgets(currentLine, sizeof(currentLine), inputfile);
    previousLine = currentLine;
    while (fgets(currentLine, sizeof(currentLine), inputfile))
    {
        copiedPreviousLine = previousLine;
        copiedCurrentLine = currentLine;
        

    }
    printf("%d\n", sum);
    getchar();
}