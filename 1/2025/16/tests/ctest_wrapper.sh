#!/bin/zsh
# Wrapper for CTest: run an executable with input redirected from a file,
# capture output and compare to expected output file. Exit non-zero on mismatch.
EXE="$1"
INPUT="$2"
EXPECTED="$3"
LABEL="$4"
EXPECTED_RC=${5:-0}

if [[ ! -x "$EXE" ]]; then
  echo "Executable $EXE not found or not executable"
  exit 2
fi

OUTFILE=$(mktemp /tmp/ex16_out.XXXXXX)
# Run the program with input redirected
cat "$INPUT" | "$EXE" > "$OUTFILE" 2>&1
RC=$?

if [[ $RC -ne $EXPECTED_RC ]]; then
  echo "Program exit code: $RC (expected $EXPECTED_RC)"
  echo "Program output:" 
  sed -n '1,200p' "$OUTFILE"
  exit $RC
fi

# Compare output to expected (trim trailing spaces)
if diff -u --strip-trailing-cr "$EXPECTED" "$OUTFILE"; then
  echo "[PASS] $LABEL"
  rm -f "$OUTFILE"
  exit 0
else
  echo "[FAIL] $LABEL - output differs"
  echo "--- Expected ($EXPECTED) ---"
  sed -n '1,200p' "$EXPECTED"
  echo "--- Actual ($OUTFILE) ---"
  sed -n '1,200p' "$OUTFILE"
  exit 1
fi
