#include <stdio.h>
#include <stdlib.h>
#define MAX_FRAMES 10
#define MAX_PAGES 100
void fifo(int pages[], int n, int frames) {
    int frame[MAX_FRAMES], pageFaults = 0, index = 0, i, j;
    int isPageInFrame;

    for (i = 0; i < frames; i++) {
        frame[i] = -1;
    }

    for (i = 0; i < n; i++) {
        isPageInFrame = 0;
        for (j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                isPageInFrame = 1;
                break;
            }
        }
        if (!isPageInFrame) {
            frame[index] = pages[i];
            index = (index + 1) % frames;
            pageFaults++;
        }
    }

    printf("FIFO Page Faults: %d\n", pageFaults);
}
void lru(int pages[], int n, int frames) {
    int frame[MAX_FRAMES], pageFaults = 0, i, j, k;
    int isPageInFrame;

    for (i = 0; i < frames; i++) {
        frame[i] = -1; 
    }

    for (i = 0; i < n; i++) {
        isPageInFrame = 0;
        for (j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                isPageInFrame = 1;
                break;
            }
        }
        if (!isPageInFrame) {
            int lruIndex = 0, lruPage = -1;
            for (j = 0; j < frames; j++) {
                if (frame[j] == -1) {
                    lruIndex = j;
                    break;
                }
                for (k = i - 1; k >= 0; k--) {
                    if (frame[j] == pages[k]) {
                        if (k < lruPage || lruPage == -1) {
                            lruPage = k;
                            lruIndex = j;
                        }
                        break;
                    }
                }
            }

            frame[lruIndex] = pages[i];
            pageFaults++;
        }
    }

    printf("LRU Page Faults: %d\n", pageFaults);
}

int main() {
    int pages[MAX_PAGES], n, frames, i;

    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter the reference string (space-separated): ");
    for (i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }
    printf("Enter number of frames: ");
    scanf("%d", &frames);

    fifo(pages, n, frames);
    lru(pages, n, frames);

    return 0;
}
