#include<stdio.h>

int main(int argc, char ** argv){
    if(argc < 2){
        printf("This function requires arguments.\n");
        return -1;
    }

    int i, val, max, min;
    if(sscanf(argv[1], "%d", &max) == 0){
        printf("All arguments must be integers.\n");
        return -1;
    }
    min = max;
    for(i = 2; i < argc; i++){
        if(sscanf(argv[i], "%d", &val) == 0){
            printf("All arguments must be integers.\n");
            return -1;
        }

        if(val < min) min = val;
        if(val > max) max = val;
    }

    int range = max - min;
    printf("Range: %d\n", range);
    return 0;
}
