#include<stdio.h>

void shout(){
    char c;
    while(scanf("%c", &c) != EOF){
        if('a' <= c && c <= 'z')
            c += 'A' - 'a';
        printf("%c", c);
    }
    //printf("\n");
}

void whisper(){
    char c;
    while(scanf("%c", &c) != EOF){
        if('A' <= c && c <= 'Z')
            c -= 'A' - 'a';
        printf("%c", c);
    }
    //printf("\n");
}

int main(int argc,  char ** argv){
    if(argc != 2){
        printf("Expected exactly 2 arguments\n");
        return -1;
    }
    char arg = argv[1][1];
    if(argv[1][2] == '\0'){
        if(arg == 's'){
            shout();
            return 0;
        }
        else if(arg == 'w'){
            whisper();
            return 0;
        }
    }
    printf("Expected either \"-s\" or \"-w\"\n");
    return -1;
}
