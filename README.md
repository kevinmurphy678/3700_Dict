## Table of Contents
* [Sorting algorithms](#sorting)
* [Other algorithms](#other)
* [Theory of computation](#computation)
* [Complexity](#complexity)
* [Encryption](#encryption)
* [Computational Problems](#problems)

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

Binary search tree code with explanations:


* [Finding Minimum](https://github.com/kevinmurphy678/3700_Dict/blob/master/BST/main.c#L104)

* [Finding Maximum](https://github.com/kevinmurphy678/3700_Dict/blob/master/BST/main.c#L95)

* [Printing in order](https://github.com/kevinmurphy678/3700_Dict/blob/master/BST/main.c#L121)

----


* ##### Dijkstras Algorithm
Explanation: Dijkstras algorithm is used to find the shortest path from one node to another. Consider the following graph:
![Dijkstra Graph](https://files.catbox.moe/yi30on.png)
With Dijkstra's algorithm it is possible to find the shortest given a start node and destination node. 

A matrix can be  constructed with the distances to use in the algorithm:

![](https://files.catbox.moe/fgxu66.png)

Dijkstra's algorithm makes use of three arrays:
Distance, Allowed, and Previous


Distance: The distance required to get to a node.

Allowed: Whether or not the shortest path to this node is known

Previous: Stores the previous node value, to calculate the shortest path in the end


Explanation: Pick a node to start at and then travel to all ajacent nodes updating the distance array. If the new distance is less than the current distance, update the array and set the previous value to the node you traveled from. When all paths to a node are calculated set the allowed array value to 1.

Below are the final array values for traveling from A to C. The shortest path is A->D->C for a total distance of 8.
```
The pre array is
0 0 3 0 2 3
The distance array is
0 5 8 4 9 10
The allowed array is
1 1 1 1 1 1
The minimum distance between the start and end node is:
0->3->2
```
[View C Code](https://github.com/kevinmurphy678/3700_Dict/tree/master/DIJKSTRA)


### <a name = "computation"></a> Theory of computation

* ##### Finite Automata
A finite automata is a deterministic model that builds a string output defined by various states. A final state is represented by a double circle. The arrows represent a transition from one state to another, which will add the corresponding value to the output string.


Example Finite Automata: Creates a string with any amount of 1's followed by one zero.


![](https://files.catbox.moe/nwlbp3.png)
----

* ##### Push Down Automata

Push down automata is a more advanced version of finite automata which introduces the concept of a stack. Values can be pushed and pulled from the stack. The stack acts as memory and allows more complex outputs than finite state automata. A push down automata cannot be accepted until the stack is empty.

Example of a palindrome building PDA:

![](https://files.catbox.moe/4ikkq9.png)


----

* ##### Turing Machine

A turing machine is a model capable of solving any computational problem. It is more advanced than push down automota and finite automota models. 

[View Turing Machine Examples](https://github.com/kevinmurphy678/3700_Dict/blob/master/Turing%20Machine/Turing%20Machine%20Examples.pdf)


* ##### Context Free Grammar

Context free grammar is a method used to generate strings by following a set of rules defined in the grammar. Examples:

`````

Generate n 0's followed by n+2 1's:

S -> 0S1
S -> 11


Genrate n 0's followed by 2n+2 1's:

S -> 0S11
S -> 11

Generate a palindrome:

S->0
S->1
S->1S1
S->0S0

`````

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
	
	
### <a name = "problems"></a>Computational Problems

* [Manhattan problem](https://github.com/kevinmurphy678/3700_Dict/blob/master/Problems/Manhattanproblem.pdf)
