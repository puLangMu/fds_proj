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
    int *return_size;
    n1_array = treeToArray(T1,return_size, n1);

    // // test the function 
    // for(int i = 0; i< n1; i++) {
    //     printf("%d ", n1_array[i]);
    // }



    
}

