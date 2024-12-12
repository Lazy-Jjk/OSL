#include <stdio.h>

int main() {
    int numPages, numFrames;

    printf("Enter the number of pages: ");
    scanf("%d", &numPages);

    int pages[numPages];

    printf("Enter the page sequence:\n");
    for (int i = 0; i < numPages; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &numFrames);

    int frames[numFrames], time[numFrames], faults = 0, count = 0;
    int isPageInFrame, leastRecentlyUsed;

    for (int i = 0; i < numFrames; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    printf("\nPage Replacement Process (LRU):\n");

    for (int i = 0; i < numPages; i++) {
        isPageInFrame = 0;

        for (int j = 0; j < numFrames; j++) {
            if (frames[j] == pages[i]) {
                isPageInFrame = 1;
                time[j] = ++count; 
                break;
            }
        }

        if (!isPageInFrame) {
            leastRecentlyUsed = 0;

            for (int j = 1; j < numFrames; j++) {
                if (time[j] < time[leastRecentlyUsed]) {
                    leastRecentlyUsed = j;
                }
            }

            frames[leastRecentlyUsed] = pages[i];
            time[leastRecentlyUsed] = ++count;
            faults++;
        }

        printf("Page %d -> Frames: ", pages[i]);
        for (int j = 0; j < numFrames; j++) {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", faults);

    return 0;
}





include <stdio.h>
#define MAX_FRAMES 3
#define MAX_PAGES 10

void lru(int pages[], int n) {
    int frames[MAX_FRAMES] = {-1, -1, -1};
    int page_faults = 0;
    printf("LRU Page Replacement Algorithm:\n");

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int page_found = 0;
        int lru_index = 0;
        int last_used[MAX_FRAMES] = {-1, -1, -1};
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == page) {
                page_found = 1;
                break;
            }
        }
        if (!page_found) {
            for (int j = 0; j < MAX_FRAMES; j++) {
                last_used[j] = -1;
                for (int k = i - 1; k >= 0; k--) {
                    if (pages[k] == frames[j]) {
                        last_used[j] = k;
                        break;
                    }
                }
                if (last_used[j] == -1) {
                    lru_index = j;
                    break;
                } 
                
            }
            frames[lru_index] = page;  
            page_faults++;
        }
        printf("Pages: ");
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] != -1) {
			    printf("%d ", frames[j]);
            }
        }
        printf("\n");
    }
    printf("Total Page Faults: %d\n", page_faults);
}
int main() {
	int i,n;
	printf("No.of references : ");
	scanf("%d",&n);
	int pages[MAX_PAGES];
	printf("Enter pages : ");
	for(i=0;i<n;i++) {
		scanf("%d",&pages[i]);
	}
	lru(pages,n);
}
