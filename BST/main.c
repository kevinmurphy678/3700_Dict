#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int value;
    struct Node *left;
    struct Node *right;

};
typedef struct Node* NodePointer;

void insert_node(NodePointer root);
void inorder_walk(NodePointer x);
NodePointer create_node();
//find max, min
//search the tree

int main()
{
    NodePointer root, temp;
    int count_nodes;
    int counter = 0;
    int input;

    printf("How many numbers do you want to accommodate in the binary search tree? \n");
    scanf("%d", &count_nodes);
    printf("\nPlease enter your numbers \n");

    root = create_node();
    counter++;

    while (counter != count_nodes)
    {
        insert_node(root);
        counter++;
    }

    printf("Printing the tree using in-order tree walk. The numbers will appear sorted \n");
    inorder_walk(root);

    printf("Max : ");
    printf("%d \n", findMax(root));

    printf("Min : ");
    printf("%d \n", findMin(root));

    system("pause");

    return 0;
}

NodePointer create_node()
{
    NodePointer temp;
    temp = (NodePointer)malloc(sizeof(struct Node));
    scanf("%d", &temp->value);
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
void insert_node(NodePointer root)
{
    NodePointer temp, temp1 = root;
    int stopl = 0;
    int stopr = 0;
    temp = create_node();
    while (stopl != 1 && stopr != 1)
    {
        if (temp->value< temp1->value)
        {
            if (temp1->left != NULL)
                temp1 = temp1->left;
            else
                stopl = 1;
        }
        else
        {
            if (temp1->right != NULL)
                temp1 = temp1->right;
            else
                stopr = 1;
        }
    }
    if (stopl == 1)
        temp1->left = temp;
    if (stopr == 1)
        temp1->right = temp;
}


int findMax(NodePointer x)
{
    if (x == NULL) return 0;
    while (x->right != NULL)
        x = x->right;

    return x->value;
}

int findMin(NodePointer x)
{
    if (x == NULL) return 0;
    while (x->left != NULL)
        x = x->left;

    return x->value;
}
void inorder_walk(NodePointer x)
{
    if (x != NULL)
    {
        inorder_walk(x->left);
        printf("%d\n", x->value);
        inorder_walk(x->right);
    }
}
