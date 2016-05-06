#include<stdlib.h>
#include<assert.h>

int product(int x, int *y){
    // if x is negative or y is NULL, return -1
    if(x < 0 || y == NULL) return -1;
    int i, temp = 1;
    // factorial loop
    for(i = 1;i <= x;i++){
        temp *= i;
    }
    *y = temp;
    return 0;
}

int main(void){
    int c, d, error;

    c = 4, d = 0;
    error = product(c,&d);
    assert(!error && d == 24);

    c = 1, d = 0;
    error = product(c,&d);
    assert(!error && d == 1);

    c = -4, d = 0;
    error = product(c,&d);
    assert(error);

    c = 0, d = 0;
    error = product(c,&d);
    assert(!error && d == 1);

    c = 4, d = 0;
    error = product(c,NULL);
    assert(error);

    return 0;
}
