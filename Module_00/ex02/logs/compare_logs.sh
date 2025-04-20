#!/bin/bash

REFERENCE_LOG="19920104_091532.log"
ACCOUNT_LOG="account.log"

CLEAN_REF="clean_19920104_091532.log"
CLEAN_ACC="clean_account.log"

sed 's/^\[[0-9_]*\] //' "$REFERENCE_LOG" > "$CLEAN_REF"
sed 's/^\[[0-9_]*\] //' "$ACCOUNT_LOG" > "$CLEAN_ACC"

echo "Comparing logs without timestamps..."
if diff "$CLEAN_REF" "$CLEAN_ACC" > /dev/null; then
    echo "✅ The files are identical (ignoring timestamps)."
else
    echo "❌ The files are different:"
    diff "$CLEAN_REF" "$CLEAN_ACC"
fi

rm "$CLEAN_REF" "$CLEAN_ACC"