#include <stdio.h>
#include "string.h"
#include "math.h"

void wordlist_generator(char inputs[], int inputsLength, int start, int stop, char fileName[]) {
    FILE *filePointer = fopen(fileName, "w");
    for (int k = start; k <= stop; ++k) {
        int lengthh = k;
        short percent = 0, ppercent = 1;
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
                printf("Stage %d/%d Percent : %d\n", k - start + 1, stop - start + 1, percent);
            }
            if (flag) {
                break;
            }
            counters[lengthh - 1]++;
        }
    }

    fclose(filePointer);
}

int main() {
    int a, b;
    scanf("%d-%d", &a, &b);
    char inputs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                     'U', 'V', 'W', 'X', 'Y', 'Z'};
    wordlist_generator(inputs, 26, a, b, "wordlist.txt");
    return 0;
}