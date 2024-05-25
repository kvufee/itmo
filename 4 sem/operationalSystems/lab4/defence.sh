#!/bin/bash

FILE_PATH="$1"
COMMAND="$2"
AS_GIT_DIR="./as_git"

check_create() {
  if [ ! -d "$AS_GIT_DIR" ]; then
    mkdir "$AS_GIT_DIR"
  fi
}

check_command() {
  check_create
  if [ -f "$AS_GIT_DIR/$(basename $FILE_PATH)" ]; then
    diff $FILE_PATH "$AS_GIT_DIR/$(basename $FILE_PATH)" > "$(basename $FILE_PATH).log"
  else
    cp $FILE_PATH "$AS_GIT_DIR/"
  fi
}

recover_command() {
  if [ -f "$AS_GIT_DIR/$(basename $FILE_PATH)" ]; then
    rm $FILE_PATH
    ln "$AS_GIT_DIR/$(basename $FILE_PATH)" $FILE_PATH
  else
    echo "net takogo."
  fi
}

case $COMMAND in
  "check")
    check_command
    ;;
  "recover")
    recover_command
    ;;
  *)
    echo "takoy komandy net. check, recover."
    ;;
esac

