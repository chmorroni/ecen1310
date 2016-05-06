#! /bin/bash

run () {
  echo "$*"
  if $*
  then echo 'success'
  else echo 'error'
  fi
}

run ./hide -encrypt <<EOF
attention home planet STOP prepare invasion stop earth is
ripe for the taking STOP cu soon FULL STOP
EOF

./hide -encrypt <<EOF | run ./hide -decrypt
attention home planet STOP prepare invasion stop earth is
ripe for the taking STOP cu soon FULL STOP
EOF

run ./hide -encrypt <<EOF
abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789 ~!@#$%^&*
EOF

exit 0
