#include <stdio.h>
#include "string.h"
#include "math.h"

int main() {
    int lengthh;
    scanf("%d",&lengthh);
    int inputsLength = 26;
    char inputs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                     'U', 'V', 'W', 'X', 'Y', 'Z'};
    int counters[lengthh];
    short flag;
    for (int j = 0; j < lengthh; ++j) {
        counters[j] = 0;
    }
    char chars[lengthh + 1];
    chars[lengthh] = '\0';
    while (1) {
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

        printf("%s\n", chars);
        if (flag) {
            break;
        }
        counters[lengthh - 1]++;
    }

    return 0;
}