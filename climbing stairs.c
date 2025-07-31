int climbStairs(int n) {
    
    int arr[n+1];

    arr[0] = 1;
    arr[1] = 1;

    if (n == 1) return 1;

    for(int i = 2; i <= n; i++){
        arr[i] = arr[i-1]+arr[i-2];
    }

    return arr[n];
}

#include <stdio.h>

// Function declaration
int climbStairs(int n);

int main() {
    int n1 = 2;
    int n2 = 3;
    int n3 = 5;

    printf("Ways to climb %d stairs: %d\n", n1, climbStairs(n1));
    printf("Ways to climb %d stairs: %d\n", n2, climbStairs(n2));
    printf("Ways to climb %d stairs: %d\n", n3, climbStairs(n3));

    return 0;
}