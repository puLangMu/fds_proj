#include <stdio.h>
#include <stdlib.h>

struct node  {
    double data; // 修改为 double 类型
    struct node *left;
    struct node *right;
};

typedef struct node treeNode;

treeNode *newNode(double data) {   // 修改参数类型为 double
    treeNode *node = (treeNode *)malloc(sizeof(treeNode));
    node->data = data;
    node->left = NULL; // initialize left child as NULL
    node->right = NULL; // initialize right child as NULL
    return (node);
}

// in case you need it
void printInorder(treeNode *node) { //print the tree in inorder
    if (node == NULL) return;
    printInorder(node->left); // first recur on left child
    printf("%d ", (int)node->data); // 修改为 %d 格式符并强制转换为 int
    printInorder(node->right);
}

void printPreorder(treeNode *node) { //print the tree in preorder
    if (node == NULL) return;
    printf("%d ", (int)node->data); // 修改为 %d 格式符并强制转换为 int
    printPreorder(node->left);
    printPreorder(node->right);
}

// in case you need it
// void printPostorder(treeNode *node) { //print the tree in postorder
//     if (node == NULL) return;
//     printPostorder(node->left); // first recur on left child
//     printPostorder(node->right);
//     printf("%d ", (int)node->data); // 修改为 %d 格式符并强制转换为 int
// }

treeNode *createTree(int n) { //convert the tree list to a tree
 
    treeNode *root = NULL;

    treeNode **node_list = (treeNode **)malloc(sizeof(treeNode *) * n);  // allocate space for node locations
    int *parent_list = (int *)malloc(sizeof(int) * n); // allocate space for the parent list for every node 

    for (int i = 0; i < n; i++) { //read the data from the console
        double temp; // 修改为 double 类型
        scanf("%lf", &temp); // 修改为 %lf 格式符
        node_list[i] = newNode(temp); //create each node in the node list 
        scanf("%lf", &temp);
        parent_list[i] = (int)temp; // 保持 parent_list 为 int 类型
    }

    for(int i = 0; i < n; i++) {
        if (parent_list[i] == -1)  //if it is the root node 
            root = node_list[i]; //set the root node
        else {
            treeNode *parent = node_list[parent_list[i]]; //record the information to one node 
            treeNode *child = node_list[i];
            
            if (parent->data <= child->data) { // build the binary search tree
                parent->right = child;
            } else {
                parent->left = child;
            }
        }
    }

    free(parent_list);

    return root;
}

//only for test 
// int main () {
//     treeNode *root;
//     int number;
//     scanf("%d", &number);
//     root = createTree(number);

//     printPreorder(root);
//     return 0;
// }

treeNode *find(treeNode *root, double target) { // 修改参数类型为 double
    if (root == NULL) {
        return NULL; // If the tree is empty or the target value is not found, return NULL
    }
    if (root->data == target) {
        return root; // Target value found, return the current node
    }
    if (target < root->data) {
        return find(root->left, target); // Recursively search in the left subtree
    } else {
        return find(root->right, target); // Recursively search in the right subtree
    }
}

int isValueInArray(double *array, int size, double value) { // 修改 array 类型为 double*
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return 1;
        }
    }
    return 0;
}

void treeToArrayHelper(treeNode *root, double *array, int *size) { // 修改 array 类型为 double*
    if (root == NULL) return;

    // Recursively traverse the left subtree
    treeToArrayHelper(root->left, array, size);

    // Add the current node's value to the array
    if (!isValueInArray(array, *size, root->data)) { // 修改 isValueInArray 调用
        // If it does not exist, add the current node's value to the array
        array[*size] = root->data;
        (*size)++;
    }

    // Recursively traverse the right subtree
    treeToArrayHelper(root->right, array, size);
}

double *treeToArray(treeNode *root, int *returnSize, int n) { // 修改返回值类型为 double*
    if (root == NULL) {
        *returnSize = 0;
        return NULL; // If the tree is empty, return NULL
    }

    // Assume the tree has at most 1000 nodes, adjust as needed
    double *array = (double *)malloc(sizeof(double) * n); // 修改为 double 类型
    *returnSize = 0;

    // Use a helper function to perform an inorder traversal and fill the array
    treeToArrayHelper(root, array, returnSize);

    return array;
}
