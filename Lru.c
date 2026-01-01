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
    int time[frames];      
    int count = 0;
    int pageFaults = 0;


    for (int i = 0; i < frames; i++) {
        frame[i] = -1;
        time[i] = 0;
    }

    printf("\nPage\tFrames\n");

    for (int i = 0; i < pages; i++) {
        int found = 0;


        for (int j = 0; j < frames; j++) {
            if (frame[j] == page[i]) {
                found = 1;
                count++;
                time[j] = count;   
                break;
            }
        }


        if (!found) {
            int pos = -1;


            for (int j = 0; j < frames; j++) {
                if (frame[j] == -1) {
                    pos = j;
                    break;
                }
            }


            if (pos == -1) {
                int min = time[0];
                pos = 0;
                for (int j = 1; j < frames; j++) {
                    if (time[j] < min) {
                        min = time[j];
                        pos = j;
                    }
                }
            }


            frame[pos] = page[i];
            count++;
            time[pos] = count;
            pageFaults++;
        }


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
