#! /bin/bash

if [ $# -eq 1 ]; then
  mv *.cpp ${1};
  rm *.out;
  > input;
else
  echo "Where to?"
fi
