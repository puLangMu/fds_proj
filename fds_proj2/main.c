#include "tree_libary.c"


int main() {
    int n1, n2;   
    treeNode *T1;  
    treeNode *T2;

    scanf("%d", &n1); 
    T1 = createTree(n1);

    scanf("%d", &n2);
    T2 = createTree(n2);

    int N;
    scanf("%d", &N);

    int *n1_array;
    int returnSize;
    n1_array = treeToArray(T1, &returnSize, n1); //use the return size to avoid space waste

    // // test the function 
    // for(int i = 0; i< returnSize; i++) {
    //     printf("%d ", n1_array[i]);
    // }

    int flag = 0;
    for(int i = 0; i < returnSize; i++) {
        if(n1_array[i] > N) { // if the value is greater than N, break the loop
            break;
        }

        if(find(T2, N - n1_array[i]) != NULL) { // if the value is found in the tree
            if(flag == 0) {
                printf("True\n");
                flag = 1;
             }
            printf("%d = %d + %d\n", N, n1_array[i], N - n1_array[i]);
        }
    }

    if(flag == 0) {
        printf("False\n");
    }

    printPreorder(T1);
    printf("\n");
    printPreorder(T2);
    
    return 0;
    
}

