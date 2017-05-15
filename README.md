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
Visualization:
![Bubble Sort](https://files.catbox.moe/bvwejh.gif)
* ##### Insertion Sort
```c
int i, j, temp;
for (i = 1; i < size; i++)
{
	j = i;
	while (j > 0 && data[j] <  data[j - 1])
	{
		temp = data[j];
		data[j] = data[j - 1];
		data[j - 1] = temp;
		j--;
	}
}
```
Visualization:
![Insertion Sort](https://files.catbox.moe/xf8cjs.gif)

### <a name = "other"></a> Other Algorithms

* ##### Binary Search Tree

![Binary Search Tree](https://upload.wikimedia.org/wikipedia/commons/thumb/d/da/Binary_search_tree.svg/300px-Binary_search_tree.svg.png)

Explanation: A binary search consists of nodes with left and right children. For a binary search tree to be valid: a parent's left node value must be less than itself and its right node value must be greater than itself.

Binary search tree code:


* [Finding Minimum](https://github.com/kevinmurphy678/3700_Dict/blob/master/BST/main.c#L104)

* [Finding Maximum](https://github.com/kevinmurphy678/3700_Dict/blob/master/BST/main.c#L95)

* [Printing in order](https://github.com/kevinmurphy678/3700_Dict/blob/master/BST/main.c#L121)






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

* #### RSA
	- [RSA key generation and signature verification](https://github.com/kevinmurphy678/3700_Dict/blob/master/RSA.md)
