#include<assert.h>
#include<stdlib.h>
#include<string.h>

int copyStringN(char * in, char * out, int a){
    // check for malformed input
    if(!in || !out || a < 1)
        return -1;

    // perform copy
    int i = 1;
    while(*in){
        if(i == a){
            *out = '\0';
            return -2;
        }
        *out = *in;
        in++;
        out++;
        i++;
    }
    return 0;
}

int main(void){
    char in[] = "qwerty", out[7];
    int a, error;

    a = 9;
    error = copyStringN(in, out, a);
    assert(!error && strcmp(in, out) == 0);

    a = 3;
    char b[] = "qw";
    error = copyStringN(in, out, a);
    assert(error && strcmp(b, out) == 0);

    error = copyStringN(NULL, out, a);
    assert(error);

    error = copyStringN(in, NULL, a);
    assert(error);

    error = copyStringN(in, out, 0);
    assert(error);

    return 0;
}
