#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct digit
{
    char* writtenDigit;
    char numberDigit;
    char realDigit;
} Digit;

const Digit digits[9] = {
        {"one", '1', 1},
        {"two", '2', 2},
        {"three", '3', 3},
        {"four", '4', 4},
        {"five", '5', 5},
        {"six", '6', 6},
        {"seven", '7', 7},
        {"eight", '8', 8},
        {"nine", '9', 9}
    };

int getCalibrationValue(char word[]){

    Digit firstDigit = {"zero",'0',0};
    int firstDigitIndex = 0;
    Digit lastDigit = {"zero",'0',0};
    int len_word = strlen(word);
    int lastDigitIndex = 100;

    for (int i=0; i < len_word; i++){
        if (word[i] >= 48 && word[i] <= 57 && firstDigit.numberDigit == '0') {
            firstDigit.numberDigit = word[i];
            firstDigit.realDigit = word[i] - '0';
            firstDigitIndex = i;
            //printf("%c", firstDigit.numberDigit);
            //getchar();
        }

        if (word[i] >= 48 && word[i] <= 57) {
            lastDigit.numberDigit = word[i]; 
            lastDigit.realDigit = word[i] - '0';
            lastDigitIndex = i;
            //printf("%c", lastDigit.numberDigit);
            //getchar();
        }
    }

    //printf("%d,%d", firstDigitIndex, lastDigitIndex);
    //getchar();

    if(lastDigitIndex == 100){
                lastDigitIndex = 0;
            }

    for(int j = 0; j < 9; j++){
            char *number = strstr(word, digits[j].writtenDigit);


            if (number){
                do{
                int numberIndex = (int) (number - word); 
                //printf("number index : %d", numberIndex);
                //getchar();
                if (numberIndex <= firstDigitIndex)
                {
                    firstDigit = digits[j];
                    firstDigitIndex = numberIndex;
                    //printf("%s", firstDigit.writtenDigit);
                    //getchar();
                }
                if (numberIndex >= lastDigitIndex)
                {
                    lastDigit = digits[j];
                    lastDigitIndex = numberIndex;
                    //printf("%s", lastDigit.writtenDigit);
                    //getchar();
                }
                number++;
                }while (strstr(number, digits[j].writtenDigit));
                   
            }
        }
    
    int value = firstDigit.realDigit * 10 + lastDigit.realDigit;
    //printf("%d", value);
    //getchar();
    return value;
}

int main(){
    int sum = 0;
    FILE *inputfile;
    char line[120];

    inputfile = fopen("input_day_1.txt", "r");
    int counter = 1;

    while (fgets(line, sizeof(line), inputfile)){
        sum += getCalibrationValue(line);
        //printf("%d\n", counter);
        //counter++;
    }

    fclose(inputfile);
    printf("%d", sum);
    getchar();
    return sum;

}


