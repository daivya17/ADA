#include <stdio.h>

#define MAX_ITEMS 100
#define MAX_CAPACITY 100

int knapsack(int values[], int weights[], int n, int capacity) {
    int dp[n + 1][capacity + 1]; 
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = (dp[i - 1][w] > (dp[i - 1][w - weights[i - 1]] + values[i - 1])) ?
                            dp[i - 1][w] : (dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][capacity];
}

int main() {
    int n, capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter capacity of the knapsack: ");
    scanf("%d", &capacity);

    int values[n], weights[n];
    printf("Enter the values and weights of the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d value: ", i + 1);
        scanf("%d", &values[i]);
        printf("Item %d weight: ", i + 1);
        scanf("%d", &weights[i]);
    }
    int maxValue = knapsack(values, weights, n, capacity);

    printf("Maximum value that can be obtained: %d\n", maxValue);

    return 0;
}
