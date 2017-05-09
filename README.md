## Table of Contents
* [Sorting algorithms](#sorting)
* [Other algorithms](#other)
* [Theory of computation](#computation)
* [Complexity](#complexity)
* [Encryption](#encryption)

### <a name = "sorting"></a> Sorting Algorithms
* ##### Bubble Sort
```c	
int swapped = 1;	
while (swapped)
{
	swapped = 0;
	for (int j = 0; j < size - 1; j++)
	{
		if (data[j] > data[j + 1])
		{
			swap(&data[j], &data[j + 1]);
			swapped = 1;
		}
	}
}
```
* ##### Insertion Sort


### <a name = "other"></a> Other Algorithms

### <a name = "computation"></a> Theory of computation

### <a name = "complexity"></a> Complexity


| Complexity        | Example    |
| ------------- |-------------:| 
| 1           | Swap two numbers. Always 3 steps | 
| log(n)      | Binary Search      | 
| n           | Min, Max, Best case insertion sort      |   
| nlog(n)     | Merge Sort, Quick Sort, Heap Sort      |   
| n^2          | Bubble Sort, Worst case Insertion Sort      |   
| 2^n        | Subset sum     |   
| n!           | Permutations      |   

### <a name = "encryption"></a> Encryption
