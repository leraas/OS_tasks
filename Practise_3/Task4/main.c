#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void generateRandomArray(double arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = (((rand() % 10001) / 100.0) - 50.0);
    }
}

void printArray(double arr[], int n) {
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%.2lf ", arr[i]);
    }
    printf("\n");
}

double calculateAverage(double arr[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

int countElementsAboveAverage(double arr[], int n, double average) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > average) {
            count++;
        }
    }
    return count;
}

double sumAfterFirstNegative(double arr[], int n) {
    double sum_after_negative = 0;
    int negative_found = 0;

    for (int i = 0; i < n; i++) {
        if (!negative_found && arr[i] < 0) {
            negative_found = 1;
        }

        if (negative_found) {
            sum_after_negative += fabs(arr[i]);
        }
    }

    return sum_after_negative;
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    double arr[n];
    generateRandomArray(arr, n);
    printArray(arr, n);

    double average = calculateAverage(arr, n);
    printf("Number of elements greater than the average: %d\n", countElementsAboveAverage(arr, n, average));
    printf("Sum of absolute values after the first negative element: %.2lf\n", sumAfterFirstNegative(arr, n));

    return 0;
}
