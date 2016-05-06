#include<stdio.h>

int main(){
    char c;
    int a = 0, e = 0, i = 0, o = 0, u = 0;
    while(scanf("%c", &c) != EOF){
        if(c == 'A' || c == 'a') a++;
        else if(c == 'E' || c == 'e') e++;
        else if(c == 'I' || c == 'i') i++;
        else if(c == 'O' || c == 'o') o++;
        else if(c == 'U' || c == 'u') u++;
    }

    printf("A/a: %d\n", a);
    printf("E/e: %d\n", e);
    printf("I/i: %d\n", i);
    printf("O/o: %d\n", o);
    printf("U/u: %d\n", u);
    return 0;
}
