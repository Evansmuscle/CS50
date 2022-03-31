#include <stdio.h>

int get_value(int additionArray[]) {
    char calc;
    int arrayLength = sizeof(additionArray) / sizeof(int);

    printf("Calculate total or enter a number? Enter 't' for total and 'n' for another number\n");
    scanf("%c", &calc);
    
    if (calc == 't') {
        int total;
        for (int i = 0; i < arrayLength; i++) {
            total += additionArray[i];
        }
        printf("The total is: %i", total);
        return 0;
    }

    if (calc == 'n') {
        int num;

        printf("Please enter the number:\n");
        scanf("%i", &num);
        
        for (int i = 0; i < arrayLength; i++) {
            if (additionArray[i] == 0) {
                additionArray[i] = num;
            }
        }

        return get_value(additionArray);
    }
}

int main(int argc, char const *argv[]) {
    int additionArray[20] = { NULL };

    get_value(additionArray);

    return 0;
}
