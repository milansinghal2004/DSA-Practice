// 1385-find-dist-value-between-two-array.cpp;binary-search;help-syntax;leetcode

#include <stdio.h>
#include <stdlib.h>

int findTheDistanceValue(int* arr1, int arr1Size, int* arr2, int arr2Size, int d) {

    int count = 0;

    for (int i = 0; i < arr1Size; i++) {

        int valid = 1;

        for (int j = 0; j < arr2Size; j++) {

            if (abs(arr1[i] - arr2[j]) <= d) {
                valid = 0;
                break;
            }
        }

        if (valid) {
            count++;
        }
    }

    return count;
}

int main() {

    int n, m, d;

    // Size of arr1
    scanf("%d", &n);

    int arr1[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }

    // Size of arr2
    scanf("%d", &m);

    int arr2[m];

    for (int i = 0; i < m; i++) {
        scanf("%d", &arr2[i]);
    }

    // Distance
    scanf("%d", &d);

    int answer = findTheDistanceValue(arr1, n, arr2, m, d);

    printf("%d\n", answer);

    return 0;
}