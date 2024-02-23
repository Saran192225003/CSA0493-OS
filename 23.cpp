#include <stdio.h>
#include <stdlib.h>

// Function to sort an array in ascending order
void sort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Function to perform SCAN disk scheduling
void scan(int arr[], int head, int size, char direction) {
    sort(arr, size);

    int distance = 0;
    int currentPos = head;
    int index;
    for (index = 0; index < size; index++) {
        if (direction == 'left' && arr[index] >= head) {
            break;
        } else if (direction == 'right' && arr[index] > head) {
            break;
        }
    }

    // Move the disk arm to the end in the given direction
    for (int i = index; i < size; i++) {
        printf("Move from %d to %d\n", currentPos, arr[i]);
        distance += abs(currentPos - arr[i]);
        currentPos = arr[i];
    }

    // Move the disk arm to the other end
    if (direction == 'left') {
        printf("Move from %d to 0\n", currentPos);
        distance += currentPos;
        currentPos = 0;
    } else {
        printf("Move from %d to 199\n", currentPos);
        distance += (200 - currentPos - 1);
        currentPos = 199;
    }

    // Move the disk arm back to the starting position
    for (int i = index - 1; i >= 0; i--) {
        printf("Move from %d to %d\n", currentPos, arr[i]);
        distance += abs(currentPos - arr[i]);
        currentPos = arr[i];
    }

    printf("Total distance traveled: %d\n", distance);
}

int main() {
    int size, head;
    char direction;

    printf("Enter the size of the disk queue: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the disk queue:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the initial position of the disk head: ");
    scanf("%d", &head);

    printf("Enter the direction (left or right): ");
    scanf(" %c", &direction);

    scan(arr, head, size, direction);

    return 0;
}

