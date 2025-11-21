#!/bin/zsh
# Run sample inputs against the built `16` executable and display outputs.
EXE="$(pwd)/build/16"
if [[ ! -x "$EXE" ]]; then
  EXE="$(pwd)/build/16"
fi

cases=("input_case1.txt" "input_case2.txt" "input_case3.txt")
for c in ${cases[@]}; do
  echo "--- Running $c ---"
  cat "1/2025/16/tests/$c" | "$EXE"
  echo "Exit code: $?"
  echo
done
