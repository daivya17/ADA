#include <stdio.h>

#define MAX 100

int main() {
    int n, W;
    float weight[MAX], value[MAX], ratio[MAX];
    
    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter maximum weight of knapsack: ");
    scanf("%d", &W);

    // Input weights and values
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight of item %d: ", i + 1);
        scanf("%f%f", &value[i], &weight[i]);
        ratio[i] = value[i] / weight[i];
    }

    // Sort items by value/weight ratio (descending)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                // swap ratio
                float temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;
                // swap value
                temp = value[i];
                value[i] = value[j];
                value[j] = temp;
                // swap weight
                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;
            }
        }
    }

    // Greedy selection
    float totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (W == 0)
            break;

        if (weight[i] <= W) {
            // take whole item
            totalValue += value[i];
            W -= weight[i];
        } else {
            // take fractional part
            totalValue += ratio[i] * W;
            W = 0;
        }
    }

    printf("Maximum value in knapsack = %.2f\n", totalValue);
    return 0;
}
