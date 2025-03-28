#include "tree_libary.c"
#include <time.h>

#define N1 200000  // Number of nodes in Tree 1
#define N2 2000  // Number of nodes in Tree 2    

#define RANGE 1000  // Range of node values

#define TEST_ITERATIONS 10  // Number of test iterations

treeNode* insert(treeNode* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

treeNode* createRandomTree(int n) {
    treeNode* root = NULL;
    for (int i = 0; i < n; i++) {
        int value = rand() % (2 * RANGE) - RANGE + 1;  // Randomly generate a value
        root = insert(root, value);
    }
    return root;
}

void findPairs(treeNode* T1, treeNode* T2, int N) {
    int* N1_array;
    int returnSize;
    N1_array = treeToArray(T1, &returnSize, N1);  // Convert Tree 1 to an array

    int flag = 0;
    for (int i = 0; i < returnSize; i++) {
        if (N1_array[i] > N) {  // If the value is greater than N, exit the loop
            break;
        }

        if (find(T2, N - N1_array[i]) != NULL) {  // If the value is found in Tree 2
            if (flag == 0) {
                printf("True\n");
                flag = 1;
            }
            printf("%d = %d + %d\n", N, N1_array[i], N - N1_array[i]);
        }
    }

    if (flag == 0) {
        printf("False\n");
    }
}

// Function to automatically generate test cases
int generateRandomTarget(int minValue, int maxValue) {
    return rand() % (maxValue - minValue) + minValue;  // Generate a target value N
}

void test() {
    srand(time(NULL) + rand());  // Set random seed with additional randomness

    // Generate test cases
    int maxValue = 100;    // Maximum range of node values

    treeNode* T1 = createRandomTree(N1);  // Create Tree 1
    treeNode* T2 = createRandomTree(N2);  // Create Tree 2

    // Output the preorder traversal of Tree 1
    printf("Tree 1 Preorder Traversal:\n");
    printInorder(T1);
    printf("\n");

    // Output the preorder traversal of Tree 2
    printf("Tree 2 Preorder Traversal:\n");
    printInorder(T2);
    printf("\n");

    // Generate a random target value N
    int N = generateRandomTarget(-RANGE, RANGE);  // Target value range

    // Output the generated target value
    printf("Generated target value N = %d\n", N);

    // Output the result of pair finding
    findPairs(T1, T2, N);
}

int main() {
    // Call the test function
    
    for(int i = 0; i < TEST_ITERATIONS; i++) {
        test();
        printf("\n\n");
    }
    
    return 0;
}
