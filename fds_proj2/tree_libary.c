#include <stdio.h>
#include <stdlib.h>

struct node  {
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node treeNode;

treeNode *newNode(int data) {   //create a new node
    treeNode *node = (treeNode *)malloc(sizeof(treeNode));
    node->data = data;
    node->left = NULL; // initialize left child as NULL
    node->right = NULL; // initialize right child as NULL
    return (node);
}



void printInorder(treeNode *node) { //print the tree in inorder
    if (node == NULL) return;
    printInorder(node->left); // first recur on left child
    printf("%d ", node->data);
    printInorder(node->right);
}

void printPreorder(treeNode *node) { //print the tree in preorder
    if (node == NULL) return;
    printf("%d ", node->data); // first print data of node
    printPreorder(node->left);
    printPreorder(node->right);
}

void printPostorder(treeNode *node) { //print the tree in postorder
    if (node == NULL) return;
    printPostorder(node->left); // first recur on left child
    printPostorder(node->right);
    printf("%d ", node->data);
}

treeNode *createTree(int n) { //change the tree list to a tree
 
    treeNode *root = NULL;

    treeNode **node_list = (treeNode **)malloc(sizeof(treeNode *) * n);  // malloc the space for node location 
    int *parent_list = (int *)malloc(sizeof(int) * n); //malloc the parent list for every node 

    for (int i = 0; i < n; i++) { //read the data from the console
        int temp; 
        scanf("%d", &temp); 
        node_list[i] = newNode(temp); //create each node in the node list 
        scanf("%d", &temp);
        parent_list[i] = temp;
    }

    for(int i = 0; i < n; i++) {
        if (parent_list[i] == -1)  //if it is the root node 
            root = node_list[i]; //set the root node
        else {
            treeNode *parent = node_list[parent_list[i]]; //record the information to one node 
            treeNode *child = node_list[i];
            
            if (parent->data <= child->data) { // bulid the binary search tree
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


treeNode *find(treeNode *root, int target) {
    if (root == NULL) {
        return NULL; // 如果树为空或未找到目标值，返回 NULL
    }
    if (root->data == target) {
        return root; // 找到目标值，返回当前节点
    }
    if (target < root->data) {
        return find(root->left, target); // 在左子树中递归查找
    } else {
        return find(root->right, target); // 在右子树中递归查找
    }
}

void treeToArrayHelper(treeNode *root, int *array, int *size) {
    if (root == NULL) return;

    // 递归遍历左子树
    treeToArrayHelper(root->left, array, size);

    // 添加当前节点的值到数组中
    array[*size] = root->data;
    (*size)++;

    // 递归遍历右子树
    treeToArrayHelper(root->right, array, size);
}

int *treeToArray(treeNode *root, int *returnSize, int n) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL; // 如果树为空，返回 NULL
    }

    // 假设树中最多有 1000 个节点，可以根据实际情况调整
    int *array = (int *)malloc(sizeof(int) * n);
    *returnSize = 0;

    // 使用辅助函数进行中序遍历并填充数组
    treeToArrayHelper(root, array, returnSize);

    return array;
}
