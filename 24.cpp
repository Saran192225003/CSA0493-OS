#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void c_scan(int arr[], int head, int size, int disk_size) {
    int seek_count = 0;
    int distance;
    int cur_track;

    int left[MAX], right[MAX];
    int left_size = 0, right_size = 0;

    // Separate the tracks into left and right of the head
    for (int i = 0; i < size; i++) {
        if (arr[i] < head)
            left[left_size++] = arr[i];
        if (arr[i] > head)
            right[right_size++] = arr[i];
    }

    // Sort both left and right arrays
    for (int i = 0; i < left_size - 1; i++) {
        for (int j = 0; j < left_size - i - 1; j++) {
            if (left[j] < left[j + 1]) {
                int temp = left[j];
                left[j] = left[j + 1];
                left[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < right_size - 1; i++) {
        for (int j = 0; j < right_size - i - 1; j++) {
            if (right[j] > right[j + 1]) {
                int temp = right[j];
                right[j] = right[j + 1];
                right[j + 1] = temp;
            }
        }
    }

    // Move the disk arm to the end in the right direction
    for (int i = 0; i < right_size; i++) {
        cur_track = right[i];
        seek_count += abs(cur_track - head);
        head = cur_track;
    }

    // Move the disk arm to the beginning in the left direction
    seek_count += abs(head - 0);
    head = 0;

    for (int i = 0; i < left_size; i++) {
        cur_track = left[i];
        seek_count += abs(cur_track - head);
        head = cur_track;
    }

    printf("Total number of seek operations = %d\n", seek_count);
}

int main() {
    int size, head, disk_size;

    printf("Enter the number of requests: ");
    scanf("%d", &size);

    int arr[MAX];

    printf("Enter the request queue:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the initial position of the disk head: ");
    scanf("%d", &head);

    printf("Enter the size of the disk: ");
    scanf("%d", &disk_size);

    c_scan(arr, head, size, disk_size);

    return 0;
}

