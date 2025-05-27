#include <stdio.h>
#define LEFT -1
#define RIGHT 1
int n;
int getMobile(int a[], int dir[]) {
    int mobile = 0;
    for (int i = 0; i < n; i++) {
        int next = i + dir[i];
        if (next >= 0 && next < n && a[i] > a[next] && a[i] > mobile)
            mobile = a[i];
    }
    return mobile;
}
int getPos(int a[], int mobile) {
    for (int i = 0; i < n; i++)
        if (a[i] == mobile)
            return i;
    return -1;
}
void printPerm(int a[]) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
void generatePermutations() {
    int a[10], dir[10]; 
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        dir[i] = LEFT; //first one
    }
    printPerm(a);
    while (1) {
        int mobile = getMobile(a, dir);
        if (mobile == 0)
            break;
        int pos = getPos(a, mobile);
        int next = pos + dir[pos];
        int temp = a[pos];
        a[pos] = a[next];
        a[next] = temp;
        int tmpDir = dir[pos];
        dir[pos] = dir[next];
        dir[next] = tmpDir;
        for (int i = 0; i < n; i++)
            if (a[i] > mobile)
                dir[i] = -dir[i];
        printPerm(a);
    }
}
int main() {
    printf("Enter n (number of elements): ");
    scanf("%d", &n);
    generatePermutations();
    return 0;
}
