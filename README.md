#	Sorting Algorithms && Big-O
![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white) ![Ubuntu](https://img.shields.io/badge/Ubuntu-E95420?style=for-the-badge&logo=ubuntu&logoColor=white)

The ```Big-O``` notation, in simple terms shows how the code slows as input grows. It profits to know in the long run how large of an input a code can take before it slows down significantly, thus ```Big-O``` measures in terms of input ```n or N``` the how long the code runs as n gets large.

For example, say a simple code prints a sequence of numbers from 0 to n - 1:
```
#include <stdio.h>

/**
 * print_number - prints a sequence of numbers
 * @n: limit of sequence to print
 * Return: nothing
 */
void print_number(int n)
{
	int i = 0;

	for (i = 0; i < n; ++i)
	{
		if (i == 0 || i == n - 1)
			printf("%d");
		else
			printf("%d, ", i);
	}
	printf("\n");
}
```
The amount of time it would take for the above code to run is dependent on the value of n. If n is < 100, it would ttake less time to run compared to when n is 10 ** 34. This is the time complexity. In ```Big-O``` notation, we say
its time complexity is ```O(n)```. 

- Time Complexity
	- Worst case Scenarios (O)
	- Best case Scenarios (Omega)
	- Average (Theta)
- Best algorithm to use as per trade-offs

## Requirements
- gcc compiler 9.3.0
- Ubuntu 20.04
