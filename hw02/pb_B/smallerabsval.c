#include<stdio.h>
#include<assert.h>

int abs(int a){
    // return absolute value
    if(a < 0)
        return -a;
    else
        return a;
}

int smallerabsval(int x, int y){
    // return the value of the one with the smaller absolute value
    if(abs(x) < abs(y))
        return x;
    else if(abs(x) > abs (y))
        return y;
    // if one is the negative of the other, return the value of the positive one
    else if(x == -y)
        return abs(x);
    // if they are equal, return their value
    else
        return x;
}

int main(void){
    int a, b;

    a = 3;
    b = 7;
    assert(smallerabsval(a, b) == 3);
    printf("given %d and %d, the function returned %d\n", a, b, smallerabsval(a, b));

    a = 3;
    b = -2;
    assert(smallerabsval(a, b) == -2);
    printf("given %d and %d, the function returned %d\n", a, b, smallerabsval(a, b));

    a = 3;
    b = -3;
    assert(smallerabsval(a, b) == 3);
    printf("given %d and %d, the function returned %d\n", a, b, smallerabsval(a, b));

    a = -6;
    b = -6;
    assert(smallerabsval(a, b) == -6);
    printf("given %d and %d, the function returned %d\n", a, b, smallerabsval(a, b));

    a = 3;
    b = 3;
    assert(smallerabsval(a, b) == 3);
    printf("given %d and %d, the function returned %d\n", a, b, smallerabsval(a, b));

    return 0;
}
