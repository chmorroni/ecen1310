#include<stdio.h>
#include<assert.h>

int multipleof3(int n){
    // check if n is a multiple of 3
    if(n % 3 == 0)
        return 1;
    else
        return 0;
}

int main(void){
    int a = 1;
    assert(multipleof3(a) == 0);
    printf("%d yields %d\n", a, multipleof3(a));

    a = 3;
    assert(multipleof3(a) == 1);
    printf("%d yields %d\n", a, multipleof3(a));

    a = 5;
    assert(multipleof3(a) == 0);
    printf("%d yields %d\n", a, multipleof3(a));

    a = 234;
    assert(multipleof3(a) == 1);
    printf("%d yields %d\n", a, multipleof3(a));

    return 0;
}
