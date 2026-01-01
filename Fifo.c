#include <stdio.h>

int main() {
    int frames, pages;
    
    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    int page[pages];
    printf("Enter page reference string:\n");
    for (int i = 0; i < pages; i++) {
        scanf("%d", &page[i]);
    }

    int frame[frames];
    int index = 0;          
    int pageFaults = 0;


  
    for (int i = 0; i < frames; i++) {
        frame[i] = -1;
    }

    printf("\nPage\tFrames\n");

    for (int i = 0; i < pages; i++) {
        int found = 0;


        for (int j = 0; j < frames; j++) {
            if (frame[j] == page[i]) {
                found = 1;
                break;
            }
        }


        if (!found) {
            frame[index] = page[i];
            index = (index + 1) % frames;  
            pageFaults++;
        }

        // Print current frame status
        printf("%d\t", page[i]);
        for (int j = 0; j < frames; j++) {
            if (frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);

    return 0;
}
