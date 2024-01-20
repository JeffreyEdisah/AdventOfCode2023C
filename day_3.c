#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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