#! /bin/bash

run(){
    echo "$*"
    if $*
    then echo 'success'
    else echo 'error'
    fi
}

run ./m_n_sum 3 5
run ./m_n_sum -3 5
run ./m_n_sum 3 3
run ./m_n_sum 3 5 7
run ./m_n_sum 3 2
run ./m_n_sum
run ./m_n_sum a 5
run ./m_n_sum 3 a

exit 0
