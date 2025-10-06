#include <stdio.h>

int main() {
    int pages[50], frame[10], n, f, count = 0, time[10];
    int i, j, k, pos, min, flag1, flag2;
    
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter page reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++) {
        frame[i] = -1;
        time[i] = 0;
    }

    printf("\nPage Replacement Process:\n");
    for(i = 0; i < n; i++) {
        flag1 = flag2 = 0;

        for(j = 0; j < f; j++) {
            if(frame[j] == pages[i]) { // Page hit
                flag1 = flag2 = 1;
                time[j] = i + 1; // Update usage time
                break;
            }
        }

        if(flag1 == 0) { // Page fault
            for(j = 0; j < f; j++) {
                if(frame[j] == -1) {
                    frame[j] = pages[i];
                    time[j] = i + 1;
                    flag2 = 1;
                    count++;
                    break;
                }
            }
        }

        if(flag2 == 0) { // Replace least recently used page
            min = time[0];
            pos = 0;
            for(k = 1; k < f; k++) {
                if(time[k] < min) {
                    min = time[k];
                    pos = k;
                }
            }
            frame[pos] = pages[i];
            time[pos] = i + 1;
            count++;
        }

        printf("After inserting %d: ", pages[i]);
        for(j = 0; j < f; j++)
            if(frame[j] != -1)
                printf("%d ", frame[j]);
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", count);
    return 0;
}
