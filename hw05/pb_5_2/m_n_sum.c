#include<stdio.h>

int main(int argc, char ** argv){
    if(argc != 3){
        printf("This function requires exactly 2 arguments\n");
        return -1;
    }
    int m, n;
    if(sscanf(argv[1], "%d", &m) == 0){
        printf("\'M\' should be an integer\n");
        return -1;
    }
    if(sscanf(argv[2], "%d", &n) == 0){
        printf("\'N\' should be an integer\n");
        return -1;
    }
    if(m > n){
        printf("\'M\' should be less than or equal to \'N\'\n");
        return -1;
    }

    int i, sum = 0;
    for(i = m; i <= n; i++, m++)
        sum += m;
    printf("Sum: %d\n", sum);
    return 0;
}
