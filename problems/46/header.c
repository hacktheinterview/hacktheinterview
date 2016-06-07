#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int val;
	struct node* left;
    struct node* right;
};
typedef struct node TreeNode;
