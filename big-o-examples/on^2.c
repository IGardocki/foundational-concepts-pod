#include <stdio.h>

int main() {
    int n = 5;
    int catSum = 0;
    for(int i=0; i < n; i++) {
        for(int j = 0; j < n; j++){
            catSum++;
        }
    }
    printf("%i is an acceptable number of cats to have in your home.\n", catSum);
    return 0;
}