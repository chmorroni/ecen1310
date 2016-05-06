#include<assert.h>
#include<stdlib.h>

int hasSubstring(char * str, char * substr){
    // check for malformed input
    if(!str || !substr)
        return 0;

    // compare
    int i, j;

    // loop through str
    for(i=0;str[i] != '\0';i++){
        // compare the ith letter of str to the first of substr
        if(str[i] == substr[0]){
            // loop through substr and compare to str
            for(j=1;str[i + j] == substr[j] || substr[j] == '\0';j++){
                // if '\0' is reached, success
                if(substr[j] == '\0')
                    return 1;
            }
        }
    }
    return 0;
}

int main(void){
    char str[] = "qwerty";
    int ret;

    char a[] = "er";
    ret = hasSubstring(str, a);
    assert(ret);

    char b[] = "qwerty";
    ret = hasSubstring(str, b);
    assert(ret);

    char c[] = "re";
    ret = hasSubstring(str, c);
    assert(!ret);

    ret = hasSubstring(NULL, c);
    assert(!ret);

    ret = hasSubstring(str, NULL);
    assert(!ret);

    return 0;
}

