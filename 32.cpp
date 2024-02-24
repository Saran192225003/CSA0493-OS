#include <stdio.h>

#define FRAME_SIZE 3
#define PAGE_REF_SIZE 10

void simulateLRU(int pageReferences[], int numPages) {
    int frames[FRAME_SIZE] = { -1, -1, -1 };
    int pageFaults = 0;
    int frameIndex = 0;
    int recentCount[FRAME_SIZE] = {0};

    for (int i = 0; i < numPages; ++i) {
        int page = pageReferences[i];
        int pageHit = 0;

        // Check if page is already in frames
        for (int j = 0; j < FRAME_SIZE; ++j) {
            if (frames[j] == page) {
                pageHit = 1;
                recentCount[j] = 0;  // Reset recent count for the used page
                break;
            }
        }

        // Page fault
        if (!pageHit) {
            int leastRecentIndex = 0;

            // Find the least recently used page
            for (int j = 1; j < FRAME_SIZE; ++j) {
                if (recentCount[j] > recentCount[leastRecentIndex]) {
                    leastRecentIndex = j;
                }
            }

            frames[leastRecentIndex] = page;
            recentCount[leastRecentIndex] = 0;
            pageFaults++;

            // Update recent count for other pages
            for (int j = 0; j < FRAME_SIZE; ++j) {
                if (j != leastRecentIndex) {
                    recentCount[j]++;
                }
            }

            // Print current frames
            printf("Frames: ");
            for (int j = 0; j < FRAME_SIZE; ++j) {
                printf("%d ", frames[j]);
            }
            printf("\n");
        }

        // Update recent count for used pages
        for (int j = 0; j < FRAME_SIZE; ++j) {
            if (frames[j] != -1) {
                recentCount[j]++;
            }
        }
    }

    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int pageReferences[PAGE_REF_SIZE] = {1, 2, 3, 4, 1, 5, 6, 2, 7, 8};
    simulateLRU(pageReferences, PAGE_REF_SIZE);

    return 0;
}

