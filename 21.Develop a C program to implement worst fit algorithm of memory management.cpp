#include <stdio.h>

#define MAX_BLOCKS 10

int main() {
    int blockSize[MAX_BLOCKS], processSize[MAX_BLOCKS];
    int m, n, allocation[MAX_BLOCKS];
    
    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);
    
    printf("Enter the size of each memory block:\n");
    for(int i = 0; i < m; i++) {
        scanf("%d", &blockSize[i]);
    }
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    printf("Enter the size of each process:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &processSize[i]);
    }
    
    for(int i = 0; i < n; i++) {
        int worstFitBlockIndex = -1;
        for(int j = 0; j < m; j++) {
            if(blockSize[j] >= processSize[i]) {
                if(worstFitBlockIndex == -1 || blockSize[j] > blockSize[worstFitBlockIndex]) {
                    worstFitBlockIndex = j;
                }
            }
        }
        
        if(worstFitBlockIndex != -1) {
            allocation[i] = worstFitBlockIndex;
            blockSize[worstFitBlockIndex] -= processSize[i];
        } else {
            allocation[i] = -1;
        }
    }
    
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i+1, processSize[i]);
        if(allocation[i] != -1) {
            printf("%d\n", allocation[i] + 1);
        } else {
            printf("Not Allocated\n");
        }
    }
    return 0;
}
