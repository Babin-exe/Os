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
    int refBit[frames];   
    int pointer = 0;      
    int pageFaults = 0;


    for (int i = 0; i < frames; i++) {
        frame[i] = -1;
        refBit[i] = 0;
    }

    printf("\nPage\tFrames\tRefBits\n");

    for (int i = 0; i < pages; i++) {
        int found = 0;


        for (int j = 0; j < frames; j++) {
            if (frame[j] == page[i]) {
                found = 1;
                refBit[j] = 1;   
                break;
            }
        }

        // Page fault
        if (!found) {
            while (1) {
                // Empty frame
                if (frame[pointer] == -1) {
                    frame[pointer] = page[i];
                    refBit[pointer] = 1;
                    pointer = (pointer + 1) % frames;
                    break;
                }


                if (refBit[pointer] == 0) {
                    frame[pointer] = page[i];
                    refBit[pointer] = 1;
                    pointer = (pointer + 1) % frames;
                    break;
                }


                refBit[pointer] = 0;
                pointer = (pointer + 1) % frames;
            }
            pageFaults++;
        }


        printf("%d\t", page[i]);
        for (int j = 0; j < frames; j++) {
            if (frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }

        printf("\t");

        for (int j = 0; j < frames; j++) {
            printf("%d ", refBit[j]);
        }

        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);

    return 0;
}
