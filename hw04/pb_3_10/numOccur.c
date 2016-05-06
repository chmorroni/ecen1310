#include<assert.h>
#include<stdlib.h>

int numOccur(int a[], int n, int v, int * occ){
    // check the variables
    if(a == NULL || occ == NULL)
        return -1;
    if(n < 0)
        return -2;

    // compute
    *occ = 0;
    int i, temp = 0;
    for(i=0;i<n;i++){
        if(a[i] == v)
            temp++;
    }
    *occ = temp;
    return 0;
}

int main(void){
    int n = 10, a[n], v, occ, error, i;

    a[0] = 0;
    a[1] = 1;
    a[2] = 1;
    for(i=3;i<(n-1);i++)
        a[i] = i - 2;
    a[n-1] = 4;

    v = 5;
    error = numOccur(a, n, v, &occ);
    assert(!error && occ == 1);

    v = 1;
    error = numOccur(a, n, v, &occ);
    assert(!error && occ == 3);

    v = 4;
    error = numOccur(a, n, v, &occ);
    assert(!error && occ == 2);

    v = 4;
    error = numOccur(a, 0, v, &occ);
    assert(!error && occ == 0);

    error = numOccur(NULL, n, v, &occ);
    assert(error);

    error = numOccur(a, n, v, NULL);
    assert(error);

    error = numOccur(a, -1, v, &occ);
    assert(error);

    return 0;
}
