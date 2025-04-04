#include "tree_libary.c"
#include <time.h>

#define N1 200  // Number of nodes in Tree 1
#define N2 200  // Number of nodes in Tree 2    

#define RANGE 20  // Range of node values

#define TEST_ITERATIONS 10  // Number of test iterations

treeNode* insert(treeNode* root, double data) { // 修改参数类型为 double
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
        double value = (rand() % (2 * RANGE) - RANGE + 1) + 0.5; // 修改为 double 类型
        root = insert(root, value);
    }
    return root;
}

void findPairs(treeNode* T1, treeNode* T2, double N) { // 修改 N 类型为 double
    double* N1_array; // 修改为 double 类型
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
            printf("%d = %d + %d\n", (int)N, (int)N1_array[i], (int)(N - N1_array[i])); // 修改为整数格式符
        }
    }

    if (flag == 0) {
        printf("False\n");
    }

    free(N1_array); // 释放分配的内存
}

// Function to automatically generate test cases
int generateRandomTarget(double minValue, double maxValue) { // 修改返回值类型为 double
    return (rand() % (int)(maxValue - minValue)) + minValue + 0.5; // 修改为 double 类型
}

void test() {
    srand(time(NULL) + rand());  // Set random seed with additional randomness

    // Generate test cases
    double maxValue = 100.0;    // 修改为 double 类型

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
    double N = generateRandomTarget(-RANGE, RANGE);  // 修改为 double 类型

    // Output the generated target value
    printf("Generated target value N = %d\n", (int)N); // 修改为整数格式符

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
