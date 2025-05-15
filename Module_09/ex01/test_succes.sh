#!/bin/bash

# Test cases: "expression" => expected result
declare -A tests=(
    ["8 9 * 9 - 9 - 9 - 4 - 1 +"]="42"
    ["7 7 * 7 -"]="42"
    ["1 2 * 2 / 2 * 2 4 - +"]="0"
    ["5 1 2 + 4 * + 3 -"]="14"
    ["3 4 +"]="7"
    ["2 3 * 4 +"]="10"
    ["9 1 - 2 /"]="4"
    ["9 3 / 1 -"]="2"
    ["2 3 + 4 *"]="20"
)

# Run each test
for expr in "${!tests[@]}"; do
    expected="${tests[$expr]}"
    output=$(./RPN "$expr" 2> /dev/null)

    if [ "$output" = "$expected" ]; then
        echo "✅ '$expr' = $output"
    else
        echo "❌ '$expr' returned '$output' (expected $expected)"
    fi
done