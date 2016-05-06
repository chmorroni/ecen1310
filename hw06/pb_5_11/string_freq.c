#include<stdio.h>
#include<string.h>

int main(int argc, char ** argv){
    int n = 32;

    // read arguments
    if(argc == 1);
    else if(argc == 2){
        if(!strcmp(argv[1],"-h")){
            printf("./string_freq.c [-h | -s int i]\n\n-h           print usage\n-s int i     set threshold to i\n");
            return 0;
        }
        else{
            printf("That argument is not defined. -h for usage.\n");
            return -1;
        }
    }else if(argc == 3){
        if(!strcmp(argv[1],"-s") && sscanf(argv[2],"%d",&n) == 1);
        else{
            printf("Those arguments are not defined. -h for usage.\n");
            return -1;
        }
    }else{
        printf("Those arguments are not defined. -h for usage.\n");
        return -1;
    }

    int counts[n], len = 0, i;
    char in = ' ', last = ' ';

    // make all starting values 0
    for(i=0;i<n;i++) counts[i] = 0;

    // count the letters in each word
    while(scanf("%c",&in) != EOF){
        if(in != ' ' && in != '\n') len++;
        else if(last != ' ' && last != '\n'){
            if(len < n) counts[len - 1]++;
            else counts[n - 1]++;
            len = 0;
        }
        last = in;
    }

    // print data
    int j;
    for(i=0;i<n;i++){
        printf("%2d %3d ",i+1,counts[i]);
        for(j=0;j<counts[i];j++) printf("*");
        printf("\n");
    }

    return 0;
}
