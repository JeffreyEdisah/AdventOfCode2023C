#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char* delimiters = " ,;:\n";

int checkGame(char* line)
{
    int REDMIN = 0;
    int GREENMIN = 0;
    int BLUEMIN = 0;
    char* parts = strtok(line, delimiters);
    parts = strtok(NULL, delimiters);
    parts = strtok(NULL, delimiters);
    int number;
    while(parts != NULL)
    {

        number = atoi(parts);
        if (number == 0)
        {
            parts = strtok(NULL, delimiters);
        }
        else
        {
            parts = strtok(NULL, delimiters);
            if (strcmp(parts, "red") == 0)
            {
                printf("%d red\n", number);
                if (number > REDMIN)
                {
                    REDMIN = number;
                }
                
            }
            if (strcmp(parts, "green") == 0)
            {
                printf("%d green\n", number);
                if (number > GREENMIN)
                {
                    GREENMIN = number;
                }
                
            }
            if (strcmp(parts, "blue") == 0)
            {
                printf("%d blue\n", number);
                if (number > BLUEMIN)
                {
                    BLUEMIN = number;
                }
                
            }
        }
    }

    printf("%d %d %d\n", REDMIN, GREENMIN, BLUEMIN);
    return REDMIN * GREENMIN * BLUEMIN;
}

void main(){
    int sum = 0;
    FILE *inputfile;
    char line[512];
    inputfile = fopen("input_day_2.txt", "r");
    while (fgets(line, sizeof(line), inputfile))
    {
        printf("%s\n", line);
        int element = checkGame(line);
        printf("%d\n", element);
        sum += element;
    }
    fclose(inputfile);
    printf("%d", sum);
    getchar();
}
