#include<stdio.h>
#include<stdlib.h>
#define nodeCount 6

struct Node {
	int arrow[nodeCount];
};

void travel(int next, int j, int* distance, int* pre, int* allowed, struct Node *node);
int find_next(int* distance, int* allowed);
int terminate(int* allowed);
void printShortestPath(int start, int dest, int* pre);

int main() {
	FILE *inputp;
	struct Node node[nodeCount];
	int i, j;
	int distance[nodeCount];
	int allowed[nodeCount];
	int pre[nodeCount];
	int start, destination;
	int next;
	printf("Please enter the start node \n");
	scanf("%d", &start);
	printf("Please enter the destination node \n");
	scanf("%d", &destination);
	for (i = 0; i < nodeCount; i++) {
		if (i == start)
			distance[i] = 0;
		else
			distance[i] = -1;
	}
	for (i = 0; i < nodeCount; i++) {
		if (i == start)
			allowed[i] = 1;
		else
			allowed[i] = 0;
	}
	for (i = 0; i < nodeCount; i++) {
		if (i == start)
			pre[i] = start;
		else
			pre[i] = -1;
	}
	inputp = fopen("graph.txt", "r");
	for (j = 0; j < nodeCount; j++)
		for (i = 0; i < nodeCount; i++)
			fscanf(inputp, "%d", &node[j].arrow[i]);
	for (j = 0; j < nodeCount; j++, printf("\n"))
		for (i = 0; i < nodeCount; i++) {
			printf("%d ", node[j].arrow[i]);
		}
	next = start;
	while (terminate(allowed) != 1) {
		for (j = 0; j < nodeCount; j++) {
			//if j is not allowed and reachable from next, find new distance from next
			if (allowed[j] == 0 && node[next].arrow[j] != -1)
				travel(next, j, distance, pre, allowed, node);
		}
		if (terminate(allowed) != 1) {
			next = find_next(distance, allowed);
			printf("The next allowed node is %d \n", next);
		}
	}
	printf("The pre array is \n");
	for (i = 0; i < nodeCount; i++)
		printf("%d ", pre[i]);
	printf(" \n");
	printf("The distance array is \n");
	for (i = 0; i < nodeCount; i++)
		printf("%d ", distance[i]);
	printf(" \n");
	printf("The allowed array is \n");
	for (i = 0; i < nodeCount; i++)
		printf("%d ", allowed[i]);
	printf(" \n");
	printf("The minimum distance between the start and end node is: \n");
	printShortestPath(start, destination, pre); //Was printShortestDistance
	printf("\n");
	system("pause");
	return 0;
}

void travel(int next, int j, int* distance, int* pre, int* allowed, struct Node *node) {
	int new_distance;
	new_distance = distance[next] + node[next].arrow[j];
	if (new_distance < distance[j] || distance[j] == -1) {
		distance[j] = new_distance;
		pre[j] = next;
	}
}

int find_next(int* distance, int* allowed) {
	int min = 100, i, next;
	for (i = 0; i < nodeCount; i++) {
		if (allowed[i] == 0 && distance[i] > 0 && distance[i] < min) {
			min = distance[i];
			next = i;
		}
	}
	allowed[next] = 1;
	return next;
}

int terminate(int* allowed) {
	int end = 1;
	int i;
	for (i = 0; i < nodeCount; i++)
		if (allowed[i] == 0)
			end = 0;
	return end;
}

void printShortestPath(int start, int dest, int* pre) {
	if (pre[dest] == start)
		printf("%d", start);
	else
		printShortestPath(start, pre[dest], pre);
	printf("->");
	printf("%d", dest);
}
