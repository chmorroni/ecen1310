#! /bin/bash

run(){
    echo "$*"
    if $*
    then echo 'success'
    else echo 'error'
    fi
}

run ./shout_whisper -s <<EOF
QWERTY qwerty 123456 !@#$%^
EOF

run ./shout_whisper -w <<EOF
QWERTY qwerty 123456 !@#$%^
EOF

run ./shout_whisper -sa
run ./shout_whisper -wa
run ./shout_whisper -a
run ./shout_whisper

exit 0
