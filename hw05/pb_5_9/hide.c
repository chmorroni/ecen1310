#include<stdio.h>
#include<string.h>

void encrypt(){
    char c;
    while(scanf("%c", &c) != EOF){
        if(('A' <= c && c <= 'W') || ('a' <= c && c <= 'w'))
            c += 3;
        else if(('X' <= c && c <= 'Z') || ('x' <= c && c <= 'z'))
            c -= 23;
        printf("%c", c);
    }
}

void decrypt(){
    char c;
    while(scanf("%c", &c) != EOF){
        if(('A' <= c && c <= 'C') || ('a' <= c && c <= 'c'))
            c += 23;
        else if(('D' <= c && c <= 'Z') || ('d' <= c && c <= 'z'))
            c -= 3;
        printf("%c", c);
    }
}

int main(int argc, char ** argv){
    if(argc != 2){
        printf("Expected exactly 1 argument\n");
        return -1;
    }
    if(strcmp(argv[1],"-encrypt") == 0) encrypt();
    else if(strcmp(argv[1],"-decrypt") == 0) decrypt();
    else{
        printf("Expected \"-encrypt\" or \"-decrypt\"\n");
        return -1;
    }
    return 0;
}
