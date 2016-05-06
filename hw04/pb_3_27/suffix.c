#include<assert.h>
#include<stdlib.h>
#include<string.h>

int suffix(char * str, char * suf){
    // check for malformed input
    if(!str || !suf)
        return 0;

    // find the end of str
    int lena;
    for(lena=0;str[lena] != '\0';lena++);

    // find the end of suf
    int lenb;
    for(lenb=0;suf[lenb] != '\0';lenb++);

    // compare
    int i;
    for(i=lenb;i>=0;i--){
        if(str[lena - i] != suf[lenb - i])
            return 0;
    }
    return 1;
}

int main(void){
    char str[] = "qwerty";
    int ret;

    char a[] = "erty";
    ret = suffix(str, a);
    assert(ret);

    char b[] = "y";
    ret = suffix(str, b);
    assert(ret);

    char c[] = "ert";
    ret = suffix(str, c);
    assert(!ret);

    ret = suffix(NULL, c);
    assert(!ret);

    ret = suffix(str, NULL);
    assert(!ret);

    return 1;
}
