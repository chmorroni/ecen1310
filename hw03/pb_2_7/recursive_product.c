#include<stdio.h>
#include<assert.h>

int _product(int a){
    // the end of the line, return 1 and collapse recursion
    if(a == 1) return 1;
    // return n * (n-1)
    return _product(a-1) * a;
}

int product(int x, int *y){
    // if x is 0 or negative or y is NULL, return -1
    if(x < 0 || y == NULL) return -1;
    // 0! = 1
    if(x == 0){
        *y = 1;
        return 0;
    }
    *y = _product(x);
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
