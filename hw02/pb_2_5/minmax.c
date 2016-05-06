#include<stdio.h>
#include<assert.h>

void minmax(int a, int b, int * min, int * max){
    // compare a and b and put them into min and max
    if(a < b){
        *min = a;
        *max = b;
    }else{
        *min = b;
        *max = a;
    }
}

int main(void){
    int a, b, min = 0, max = 0;

    a = 5, b = 6;
    minmax(a, b, &min, &max);
    assert(min == 5 && max == 6);
    printf("%d is larger than %d\n", max,  min);

    a = 5, b = 4;
    minmax(a, b, &min, &max);
    assert(min == 4 && max == 5);
    printf("%d is larger than %d\n", max,  min);

    a = -5, b = 6;
    minmax(a, b, &min, &max);
    assert(min == -5 && max == 6);
    printf("%d is larger than %d\n", max,  min);

    a = 5, b = -6;
    minmax(a, b, &min, &max);
    assert(min == -6 && max == 5);
    printf("%d is larger than %d\n", max,  min);

    return 0;
}
