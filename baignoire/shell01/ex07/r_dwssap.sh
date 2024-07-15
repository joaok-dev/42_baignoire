#!/bin/sh

# Define the values for FT_LINE1 and FT_LINE2
FT_LINE1=7
FT_LINE2=15

# Process the /etc/passwd file according to the requirements
grep -v '^#' /etc/passwd |     # Remove lines that start with '#' (comments)
sed -n 'n;p' |                 # Select every other line starting from the second line
cut -d':' -f1 |                # Extract the first field (login name)
rev |                          # Reverse the login names
sort -r |                      # Sort the reversed login names in reverse alphabetical order
sed -n "${FT_LINE1},${FT_LINE2}p" |  # Select lines between FT_LINE1 and FT_LINE2 (inclusive)
paste -sd ', ' - |             # Join the selected lines into a single line, separated by ', '
sed 's/$/./'                   # Add a period (.) at the end of the line

