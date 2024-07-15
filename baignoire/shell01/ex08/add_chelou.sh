#!/bin/sh

# Define the input variables
FT_NBR1="'\?\"'\"'"
FT_NBR2='rcrdmddd'

# Convert FT_NBR1 from its base to decimal
DECIMAL_NBR1=$(echo "$FT_NBR1" | tr "\'\\\?\!\" " "01234" | xargs echo "ibase=5;" | bc)

# Convert FT_NBR2 from its base to decimal
DECIMAL_NBR2=$(echo "$FT_NBR2" | tr "mrdoc" "01234" | xargs echo "ibase=5;" | bc)

# Sum the decimal values
SUM=$(echo "$DECIMAL_NBR1 + $DECIMAL_NBR2" | bc)

# Convert the result to the gtaio luSnemf base
RESULT=$(echo "obase=13; $SUM" | bc | tr "0123456789ABC" "gtaioluSnemf")

# Display the result
echo $RESULT
