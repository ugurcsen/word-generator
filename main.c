#include <stdio.h>
#include "string.h"
#include "math.h"

int main() {
    FILE *filePointer = fopen("wordlist.txt", "w");

    int lengthh;
    short percent = 0, ppercent = 1;
    scanf("%d", &lengthh);
    int inputsLength = 26;
    char inputs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                     'U', 'V', 'W', 'X', 'Y', 'Z'};
    int counters[lengthh], i = 0;
    short flag;
    for (int j = 0; j < lengthh; ++j) {
        counters[j] = 0;
    }
    char chars[lengthh + 1];
    chars[lengthh] = '\0';
    while (1) {
        i++;
        flag = 1;
        for (short j = 0; j < lengthh; ++j) {
            if (inputsLength - 1 != counters[j]) {
                flag = 0;
            }
            if (counters[j] == inputsLength) {
                counters[j] = 0;
                counters[j - 1]++;
            }
            chars[j] = inputs[counters[j]];
        }
        fprintf(filePointer, "%s\n", chars);
        percent = 100 * (i / pow(inputsLength, lengthh));
        if (percent != ppercent) {
            ppercent = percent;
            printf("Percent : %d\n", percent);
        }
        if (flag) {
            break;
        }
        counters[lengthh - 1]++;
    }
    fclose(filePointer);
    return 0;
}