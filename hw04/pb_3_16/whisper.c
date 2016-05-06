#include<assert.h>
#include<stdio.h>
#include<string.h>

int whisper(char * msgIn, char * msgOut){
    // check arguments
    if(msgIn == NULL || msgOut == NULL)
        return -1;

    // loop through and make all letters lowercase
    while(*msgIn != '\0'){
        if(*msgIn >= 'A' && *msgIn <= 'Z')
            *msgOut = *msgIn - ('A' - 'a');
        else
            *msgOut = *msgIn;
        msgIn++;
        msgOut++;
    }
    *msgOut = '\0';
    return 0;
}

int main (void){
    int error, same;
    char a[] = "AaJekLzZ", b[9], c[] = "aajeklzz";

    error = whisper(a, b);
    same = strcmp(b,c);
    assert(!error && same == 0);

    error = whisper(NULL, b);
    assert(error);

    error = whisper(a, NULL);
    assert(error);

    return 0;
}
