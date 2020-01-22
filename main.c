#include <stdio.h>
#include "string.h"
#include "math.h"

int main() {
    int lengthh = 3;
    int counter = -1;
    char chars[(int) pow(26, lengthh)][lengthh + 1];

    for (int j = 0; j < lengthh; ++j) {
        counter = -1;
        for (int i = 0; i < (int) pow(26, lengthh); ++i) {
            if (i % (int) pow(26, j) == 0) {
                counter++;
            }
            if (counter > 25) {
                counter = 0;
            }
            chars[i][j] = counter + 65;
        }
    }
    /*
    for (int i = 0; i < (int) pow(26, lengthh); ++i) {
        if (i % (int) (26 / pow(26, 0)) == 0) {
            counter++;
        }
        chars[i][0] = counter + 65;
    }
    counter = -1;
    for (int i = 0; i < (int) pow(26, lengthh); ++i) {
        if (i % (int) (26 / pow(26, 1)) == 0) {
            counter++;
        }
        if(counter>25){
            counter = 0;
        }
        chars[i][1] = counter + 65;
    }
    */
    for (int i = 0; i < (int) pow(26, lengthh); ++i) {
        chars[i][lengthh] = '\0';
    }


    for (int k = 0; k < (int) pow(26, lengthh); ++k) {
        printf("%s\n", chars[k]);
    }
    return 0;
}
//AAA
//AAB
//000
//001
//011
//111
//112

//000
//100
//200

//00
//10
//20
//260
//01
//11
//21
