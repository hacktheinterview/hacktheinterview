#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

struct node {
	int val;
	struct node* left;
    struct node* right;
};
typedef struct node TreeNode;
