#include<assert.h>
#include<stdlib.h>

int vectorSum(int x[], int y[], int n, int sum[]){
    // make sure the function can complete
    if(x == NULL || y == NULL || sum == NULL)
        return -1;
    if(n <= 0)
        return -2;

    // compute the sum
    int i;
    for(i = 0;i < n;i++)
        sum[i] = x[i] + y[i];

    return 0;
}

int main(void){
    int n = 5, x[n], y[n], sum[n], error;

    int i;
    for(i = 0;i < n;i++){
        x[i] = i;
        y[i] = i - 2;
    }
    error = vectorSum(x, y, n, sum);
    assert(!error);
    for(i = 0;i < n;i++)
        assert(sum[i] == 2 * i - 2);

    error = vectorSum(NULL, y, n, sum);
    assert(error);

    error = vectorSum(x, NULL, n, sum);
    assert(error);

    error = vectorSum(x, y, n, NULL);
    assert(error);

    error = vectorSum(x, y, 0, sum);
    assert(error);

    return 0;
}
