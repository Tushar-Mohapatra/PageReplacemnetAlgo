#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_FRAMES 10
#define MAX_PAGES 50

void FIFO(int pages[], int numPages, int numFrames) {
    //Here in frames[] we store the pages that are in the frame
    int frames[MAX_FRAMES] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    
    //front is the index that determine the page that is in frame for longest period of time
    int front = 0;
    
    //pageFaults is the counter that counts the no. of page faults
    int pageFaults = 0;
    bool found;

    printf("\nFIFO Simulation:\n");
    for (int i = 0; i < numPages; i++) {
        found = false;
        
        //Here we check if the page in sequence is present in the frame or not
        for (int j = 0; j < numFrames; j++) {
            if (frames[j] == pages[i]) {
                found = true;
                break;
            }
        }
        
        //if the the page in sequence is not in frame then it swap with page in frame that is there for the longest time
        if (!found) {
            frames[front] = pages[i];
            front = (front + 1) % numFrames;
            pageFaults++;
        }
        
        //Printing the frame after every page in sequence
        printf("Step %d: ", i + 1);
        for (int j = 0; j < numFrames; j++) {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        printf("\n");
    }
    printf("Total Page Faults: %d\n", pageFaults);
}

void OPTIMAL(int pages[], int numPages, int numFrames){
    int frames[MAX_FRAMES] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    int occurancePages[MAX_PAGES]={-1};
    int occuranceFrames[MAX_FRAMES]={-1};
    int pageFaults=0;
    bool found;
    
    //finding the occurances of the pages
    for(int i=0;i<numPages;i++){
        found=false;
        for(int j=i+1;j<numPages;j++){
            if(pages[i]==pages[j]){
                occurancePages[i]=j;
                found=true;
                break;
            }
        }
        if(!found){
            occurancePages[i]=-1;
        }
    }
         printf("\nOPTIMAL Simulation:\n");
    for (int i = 0; i < numPages; i++) {
        found = false;
        for (int j = 0; j < numFrames; j++) {
            if (frames[j] == pages[i]) {
                found = true;
                break;
            }
        }

        if (!found) {
            int optimalIndex = 0;
            int farthest=0;
            for(int j=0;j<numFrames;j++){
                if (frames[j] == -1 ){
                    optimalIndex = j;
                    break;
                }
                int nextOccurrence = pow(2,31)-1;
                for (int k = i + 1; k < numPages; k++) {
                    if (frames[j] == pages[k]) {
                        nextOccurrence = k;
                        break;
                    }
                }
                if (nextOccurrence > farthest) {
                    farthest = nextOccurrence;
                    optimalIndex = j;
                }
            }
            frames[optimalIndex] = pages[i];
            pageFaults++;
        }
        //Printing the frame after every page in sequence
        printf("Step %d: ", i + 1);
        for (int j = 0; j < numFrames; j++) {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        printf("\n");
    }
    printf("Total Page Faults: %d\n", pageFaults);
}
void LRU(int pages[], int numPages, int numFrames) {
    int frames[MAX_FRAMES] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    int recent[MAX_FRAMES] = {0,0,0,0,0,0,0,0,0,0};
    int pageFaults = 0, time = 0;
    bool found;

    printf("\nLRU Simulation:\n");
    for (int i = 0; i < numPages; i++) {
        found = false;
        for (int j = 0; j < numFrames; j++) {
            if (frames[j] == pages[i]) {
                found = true;
                recent[j] = time++;
                break;
            }
        }

        if (!found) {
            int lruIndex = 0;
            for (int j = 0; j < numFrames; j++) {
                if (frames[j] == -1 ){
                    lruIndex = j;
                    break;
                }
                if(recent[j] < recent[lruIndex]) {
                    lruIndex = j;
                }
            }
            frames[lruIndex] = pages[i];
            recent[lruIndex] = time++;
            pageFaults++;
        }

        printf("Step %d: ", i + 1);
        for (int j = 0; j < numFrames; j++) {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        printf("\n");
    }
    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int numFrames, numPages;
    int pages[MAX_PAGES];

    printf("Enter the number of frames: ");
    scanf("%d", &numFrames);

    printf("Enter the number of pages: ");
    scanf("%d", &numPages);

    printf("Enter the page sequence: ");
    for (int i = 0; i < numPages; i++) {
        scanf("%d", &pages[i]);
    }

    FIFO(pages, numPages, numFrames);
    OPTIMAL(pages, numPages, numFrames);
    LRU(pages, numPages, numFrames);

    return 0;
}
