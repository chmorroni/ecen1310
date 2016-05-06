#include<stdlib.h>
#include<assert.h>

int power(int a, int n,  int *p){
    // if n is negative or p is NULL, return -1
    if(n < 0 || p == NULL) return -1;
    int temp = 1;
    // exponent loop
    for(int i = 1; i <= n; i++){
        temp *= a;
    }
    *p = temp;
    return 0;
}

int main(void){
    int a, b, c, error;

    a = 5, b = 4, c = 0;
    error = power(a,b,&c);
    assert(!error && c == 625);

    a = 5, b = 1, c = 0;
    error = power(a,b,&c);
    assert(!error && c == 5);

    a = 5, b = 0, c = 0;
    error = power(a,b,&c);
    assert(!error && c == 1);

    a = 0, b = 4, c = 0;
    error = power(a,b,&c);
    assert(!error && c == 0);

    a = -5, b = 4, c = 0;
    error = power(a,b,&c);
    assert(!error && c == 625);

    a = -5, b = 3, c = 0;
    error = power(a,b,&c);
    assert(!error && c == -125);

    a = 5, b = -4, c = 0;
    error = power(a,b,&c);
    assert(error);

    a = 5, b = 4, c = 0;
    error = power(a,b,NULL);
    assert(error);

    return 0;
}
