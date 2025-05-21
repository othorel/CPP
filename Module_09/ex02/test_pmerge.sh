#!/bin/bash

EXEC=./PmergeMe

function trim() {
    echo "$1" | sed 's/[[:space:]]*$//'
}

function test_sort() {
    input="$1"
    echo "Input: $input"
    # Run your program
    output=$($EXEC $input)

    # Extract the 'After' line
    after_line=$(echo "$output" | grep '^After:' | sed 's/After: //')

    # Sort input with Unix sort for comparison
    sorted_ref=$(echo $input | tr ' ' '\n' | sort -n | tr '\n' ' ')

    # Trim trailing spaces before comparing
    after_trimmed=$(trim "$after_line")
    ref_trimmed=$(trim "$sorted_ref")

    echo "Program sorted: $after_trimmed"
    echo "Reference sort: $ref_trimmed"

    if [ "$after_trimmed" == "$ref_trimmed" ]; then
        echo "Result: SUCCESS"
    else
        echo "Result: FAILURE"
    fi
    echo "$output" | grep -E "Time to process"
    echo "-------------------------"
}

# Test cases
test_sort "37387 1183 90522 42200 54473 71733 65343 77178 46574 57882"
test_sort "5 3 9 1 7"
test_sort "42"
test_sort "$(shuf -i 1-1000 -n 100 | tr '\n' ' ')"
test_sort "1 2 3 4 5 6 7 8 9 10"
test_sort "100 90 80 70 60 50 40 30 20 10"
test_sort "5 5 5 5 5"
test_sort "2147483647 1 100 500000"

# Invalid input test (expected to fail or show error, won't check sort correctness)
echo "Invalid input test:"
$EXEC "1 2 a 3"
echo "-------------------------"
$EXEC "1 -2 3"
echo "-------------------------"
