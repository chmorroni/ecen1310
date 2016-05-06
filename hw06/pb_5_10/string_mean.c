#include<stdio.h>

int main(){
    int letters = 0, words = 0;
    char in, last = ' ';
    while(scanf("%c",&in) != EOF){
        if(in != ' ' && in != '\n') letters++;
        else if(last != ' ' && last != '\n') words++;
        last = in;
    }
    if(last != ' ' && last != '\n') words++;
    if(letters == 0) printf("Average length: 0\n");
    else printf("Average length: %f\n",(float)letters/(float)words);
    return 0;
}
