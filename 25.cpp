#include <stdio.h>
#include <stdlib.h>

// Function to sort an array using the Bubble Sort algorithm
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap the elements if they are in the wrong order
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Function to perform C-SCAN disk scheduling
void cScan(int arr[], int n, int head) {
    // Sort the array of disk requests
    bubbleSort(arr, n);

    int totalCylinders = 200; // Assuming total cylinders on the disk
    int distance = 0;
    
    // Find the index where the head is located
    int index;
    for (index = 0; index < n; index++) {
        if (arr[index] >= head) {
            break;
        }
    }

    // Go in the forward direction
    printf("Forward Movement:\n");
    for (int i = index; i < n; i++) {
        printf("Move from %d to %d\n", head, arr[i]);
        distance += abs(head - arr[i]);
        head = arr[i];
    }

    // Go to the end of the disk
    printf("Move from %d to %d\n", head, totalCylinders - 1);
    distance += abs(head - (totalCylinders - 1));
    head = totalCylinders - 1;

    // Go in the reverse direction
    printf("Backward Movement:\n");
    for (int i = 0; i < index; i++) {
        printf("Move from %d to %d\n", head, arr[i]);
        distance += abs(head - arr[i]);
        head = arr[i];
    }

    printf("Total head movement: %d\n", distance);
}

int main() {
    int n, head;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter the disk requests:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the initial position of the disk head: ");
    scanf("%d", &head);

    cScan(arr, n, head);

    free(arr);
    return 0;
}

