#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	int val;
	struct node* left;
    struct node* right;
};
typedef struct node TreeNode;
TreeNode* createNewTreeNode(int val) {
	TreeNode* node = (TreeNode *) malloc(sizeof(TreeNode));
	node->val = val;
	node->left = NULL;
	node->right = NULL;
	return node;
}

// struct node {
// 	int val;
// 	struct node* left;
//     struct node* right;
// };
// typedef struct node TreeNode;
// TreeNode* createNewTreeNode(int val) {
// 	TreeNode* node = (TreeNode *) malloc(sizeof(treenode));
// 	node->val = val;
// 	node->left = NULL;
// 	node->right = NULL;
// }

// Please Refrain from using print statements
int isValidBinarySearchTree(TreeNode* root) {
	// Implement the solution
	return 1;
}

void tostr(int x, char* buffer) {
	sprintf(buffer, "%d", x);
}

int toint(char* buffer) {
	return atoi(buffer);
}

// void printTreeToOutputFormat(TreeNode* root) {
//     vector<string> ret;
//     if (!root) {
//         cout << endl;
//     }
//     queue<TreeNode*> q;
//     q.push(root);
//     while(!q.empty()) {
//         TreeNode* tmp = q.front(); q.pop();
//         if (!tmp) {
//             ret.push_back("#");
//             continue;
//         }
//         ret.push_back(tostr(tmp->val));
//
//         q.push(tmp->left);
//         q.push(tmp->right);
//     }
//     for (int i = 0; i < ret.size(); i++) {
//         cout << ret[i];
//         if (i != ret.size() - 1) {
//             cout << " ";
//         }
//     }
//     cout << endl;
// }

struct node** createQueue(int *, int *);
void enQueue(struct node **, int *, struct node *);
struct node *deQueue(struct node **, int *);

TreeNode* deserializeTree(const vector<string>& inputItems) {
    if (inputItems.size() == 0) return NULL;
    // make it integer.
    TreeNode* root = new TreeNode(toint(inputItems[0]));
    queue<TreeNode*> q;
    q.push(root);
    int index = 1;

    while (index < inputItems.size()) {
        TreeNode* tmp = q.front();
        q.pop();

        if (inputItems[index] == "#") {
            tmp->left = NULL;
        } else {
            int val = toint(inputItems[index]);
            TreeNode* leftNode = new TreeNode(val);
            tmp->left = leftNode;
            q.push(leftNode);
        }
        index++;

        if (inputItems[index] == "#") {
            tmp->right = NULL;
        } else {
            int val = toint(inputItems[index]);
            TreeNode* rightNode = new TreeNode(val);
            tmp->right = rightNode;
            q.push(rightNode);
        }
        index++;
    }
    return root;
}

TreeNode* constructTree(char* inputItems[], int *index, int n) {
	printf("%d\n", *index);
    if (*index == n) return NULL;
    char* x = inputItems[*index];
	*index = *index + 1;
	printf("%s-%lu\n", x, strlen(x));
    if (strcmp(x, "#") == 0) {
        return NULL;
    }

	printf("Creating node for %s \n", x);
	TreeNode* tmp =  createNewTreeNode(toint(x));
	printf("Index before left %d\n", *index);
    tmp->left = constructTree(inputItems, index, n);
	printf("Index after left %d\n", *index);
    tmp->right = constructTree(inputItems, index, n);
	printf("Index after right %d\n", *index);
    return tmp;
}


TreeNode* deserializeTree(char* inputItems[], int n) {
    if (n == 0) return NULL;
    int index = 0;
    return constructTree(inputItems, &index, n);
}

void inorder(TreeNode* root) {
	if (!root) {
		return;
	}
	printf("current -> %d\n", root->val);
	inorder(root->left);
	printf("Done with left\n");
	printf("%d ", root->val);
	inorder(root->right);
	printf("Done with right\n");
}
int main() {
	int testcases;
    scanf("%d", &testcases);

	for (int t = 0; t < testcases; t++) {
        int n; scanf("%d ", &n);
        char* inputItems[n];
        for (int i = 0; i < n; i++) {
			inputItems[i] = malloc(15);
            scanf("%s", inputItems[i]);
        }

        TreeNode *root = deserializeTree(inputItems, n);
		printf("%d\n", root->val);
		printf("%d\n", root->left->val);
		printf("%d\n", root->right->val);
		printf("---------\n");
		inorder(root);
		printf("\n");
        // int result = isValidBinarySearchTree(root);
        // printf("%d\n", result);
	}
	return 0;
}
