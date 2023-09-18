#!/bin/bash

echo "Simple Calculator"
echo "Enter the first number:" 
read num1
echo "Enter the second number:" 
read num2
echo "Enter the operator (+, -, /, *):"
read operator

case $operator in 
	"+")
		result=$((num1 + num2))
		;;
	"-")
		result=$((num1 - num2))
		;;
	"/")
		if [ $num2 -eq 0 ]; then
			echo "Error: Division by zero."
			exit 1
		fi

		result=$(echo "scale=2; $num1 / $num2" | bc)
		;;
	"*")
		result=$((num1 * num2))
		;;
	*)
		echo "Invalid operator."
		exit 1
		;;
esac

echo "Result: $num1 $operator $num2 = $result"
