#! /bin/bash

run(){
    echo "$*"
    if $*
    then echo 'success'
    else echo 'error'
    fi
}

run ./range 1 8 40 5
run ./range 6 -5 5 0
run ./range 4
run ./range
run ./range a 0 3 7
run ./range 7 8 t 5

exit 0
