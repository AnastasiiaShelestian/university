#!/bin/bash

# Check if at least one file is provided as a parameter
if [ "$#" -eq 0 ]; then
    echo "Provide files for processing, please."
    exit 1
fi

for file in "$@"; do
    # Check if file exists
    if [ ! -f "$file" ]; then
        echo "File '$file' doesn't exist."
        continue
    fi

    while IFS= read -r line; do
        if [ ! "$line" ]; then
            continue
        fi
        most_common_word_per_line=$(echo "$line" | tr -d [:punct:] | tr -s [:space:] '\n' | sort | uniq -c | sort -r | head -n1 | tr -s [:space:])
        echo "$file:$most_common_word_per_line"
    done < "$file"
done