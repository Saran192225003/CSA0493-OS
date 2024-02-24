#include <stdio.h>

#define FRAME_SIZE 3
#define PAGE_REF_SIZE 10

void simulateFIFO(int pageReferences[], int numPages) {
    int frames[FRAME_SIZE] = { -1, -1, -1 };
    int pageFaults = 0;
    int frameIndex = 0;

    for (int i = 0; i < numPages; ++i) {
        int page = pageReferences[i];
        int pageHit = 0;

        // Check if page is already in frames
        for (int j = 0; j < FRAME_SIZE; ++j) {
            if (frames[j] == page) {
                pageHit = 1;
                break;
            }
        }

        // Page fault
        if (!pageHit) {
            frames[frameIndex] = page;
            frameIndex = (frameIndex + 1) % FRAME_SIZE;
            pageFaults++;

            // Print current frames
            printf("Frames: ");
            for (int j = 0; j < FRAME_SIZE; ++j) {
                printf("%d ", frames[j]);
            }
            printf("\n");
        }
    }

    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int pageReferences[PAGE_REF_SIZE] = {1, 2, 3, 4, 1, 5, 6, 2, 7, 8};
    simulateFIFO(pageReferences, PAGE_REF_SIZE);

    return 0;
}

