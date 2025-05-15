#!/bin/bash

tests=(
    "1 +"
    "1 2"
    "1 0 /"
    "a b +"
    "12 3 +"
    "(1 + 1)"
    "1 2 ^"
    ""
    "9 8 * *"
    "1 2 * 2 / 2 * 2 4 - + +"
)

for expr in "${tests[@]}"; do
    echo -n "Testing '$expr' => "
    ./RPN "$expr" 2> /dev/null && echo "❌ Should have failed" || echo "✅ Error caught"
done