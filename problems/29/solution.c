#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int val;
	TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

// struct TreeNode {
// 	string val;
// 	TreeNode* left;
//     TreeNode* right;
//     TreeNode(string x): val(x), left(NULL), right(NULL) {}
// };
// Please Refrain from using print statements
int isValidBinarySearchTree(TreeNode* root) {
	// Implement the solution
}

string tostr(int x) {
    if (x == 0) return "0";
    string ret = "";
    int neg = 0;
    if (x < 0) {
        neg = 1;
        x = -x;
    }

    while(x) {
        int mod = x % 10;
        ret += (mod + '0');
        x = x/10;
    }
    reverse(ret.begin(), ret.end());
    if (neg) return "-" + ret;
    return ret;
}

void printTreeToOutputFormat(TreeNode* root) {
    vector<string> ret;
    if (!root) {
        cout << endl;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* tmp = q.front(); q.pop();
        if (!tmp) {
            ret.push_back("#");
            continue;
        }
        ret.push_back(tostr(tmp->val));

        q.push(tmp->left);
        q.push(tmp->right);
    }
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i];
        if (i != ret.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

int toint(string x) {
    if (x.size() == 0) return 0;
    int start = 1;
    int ret = 1;
    if (x[0] == '-') {
        ret = x[1] - '0';
        ret = -ret;
        start = 2;
    } else {
        ret = x[0] - '0';
    }
    for (int i = start; i < x.size(); i++) {
        ret = ret * 10 + x[i] - '0';
    }
    return ret;
}

TreeNode* deserializeTree(char* inputItems[], int n) {
    if (n == 0) return NULL;
    int index = 0;
    return constructTree(inputItems, &index, n);
}

TreeNode* constructTree(char* inputItems[], int *index, int n) {
    if (*index == n) return NULL;

    char* x = inputItems[*index];
    if (strcmp(x, "#") == 0) {
        return NULL;
    }

    TreeNode tmp = (TreeNode*) malloc(sizeof (TreeNode));
    tmp->val = toint(inputItems[*index]);
    tmp->left = tmp->right = NULL;

    *index = *index + 1;
    tmp->left = constructTree(inputItems, index, n);
    *index = *index + 1;
    tmp->right = constructTree(inputItems, index, n);
    return tmp;
}

int main() {
	int testcases;
    scanf("%d", &testcases);

	for (int t = 0; t < testcases; t++) {
        int n; scanf("%d", &n);
        char* inputItems[n];
        for (int i = 0; i < n; i++) {
            scanf("%s", &inputItems[i]);
        }

        TreeNode *root = deserializeTree(inputItems, n);
        int result = isValidBinarySearchTree(root);
        printf("%d\n", result);
	}
	return 0;
}
