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

    double *n1_array; // 修改为 double 类型
    int returnSize;
    n1_array = treeToArray(T1, &returnSize, n1); //use the return size to avoid space waste

    // // test the function 
    // for(int i = 0; i< returnSize; i++) {
    //     printf("%d ", n1_array[i]);
    // }

    int flag = 0;
    for(int i = 0; i < returnSize; i++) {
        if(n1_array[i] > N) { // 修改为 double 类型比较
            break;
        }

        if(find(T2, N - n1_array[i]) != NULL) { // 修改为 double 类型计算
            if(flag == 0) {
                printf("True\n");
                flag = 1;
             }
            printf("%d = %d + %d\n", N, (int)n1_array[i], (int)(N - n1_array[i])); // 修改格式符
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

