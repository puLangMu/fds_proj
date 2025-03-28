#include <stdio.h>
#include <stdlib.h>
#include "tree_libary.c"

// Use the previous code, including tree node definitions and related functions

// Test tree creation
treeNode* testCreateTree() {
    printf("Test: Create Tree\n");
    int n;
    scanf("%d", &n);
    treeNode *root = createTree(n);
    printPreorder(root);
    printf("\n");

    return root;
}

// Test target search
void testFind(treeNode *root) {
    printf("Test: Search for a Target in the Tree\n");
    int target;
    scanf("%d", &target);
    treeNode *result = find(root, target);
    if (result != NULL) {
        printf("Found node with value: %d\n", result->data);
    } else {
        printf("Node with value %d not found.\n", target);
    }
}

// Test tree to array conversion
void testTreeToArray(treeNode *root) {
    printf("Test: Convert Tree to Sorted Array\n");
    int returnSize;
    int *array = treeToArray(root, &returnSize, 8);
    printf("Converted array: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    free(array);
}


// Test tree traversal
void testPreorderTraversal(treeNode *root) {
    printf("Test: Preorder Traversal\n");
    printPreorder(root);
    printf("\n");
}

int main() {
    // Call various test functions
    treeNode *root = testCreateTree();
    testFind(root);
    testTreeToArray(root);
    testPreorderTraversal(root);

    return 0;
}
