#include <stdio.h>

#define MAX_BLOCKS 100
#define MAX_PROCESS 100

// Structure to represent a memory block
struct MemoryBlock {
    int id;
    int size;
    int allocated;
};

// Function to allocate memory blocks to processes using best fit algorithm
void bestFit(int blockSize[], int m, int processSize[], int n) {
    struct MemoryBlock allocatedBlocks[MAX_PROCESS];
    
    // Initialize all blocks as unallocated
    for (int i = 0; i < n; i++) {
        allocatedBlocks[i].id = -1;
        allocatedBlocks[i].allocated = 0;
    }

    // Iterate through all processes
    for (int i = 0; i < n; i++) {
        int bestIdx = -1;
        // Find the best fit block for the current process
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx])
                    bestIdx = j;
            }
        }
        // If a block is found, allocate it to the process
        if (bestIdx != -1) {
            allocatedBlocks[i].id = i;
            allocatedBlocks[i].size = blockSize[bestIdx];
            allocatedBlocks[i].allocated = 1;
            blockSize[bestIdx] -= processSize[i];
        }
    }

    // Display allocation result
    printf("Process No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocatedBlocks[i].allocated)
            printf("%d\n", allocatedBlocks[i].id + 1);
        else
            printf("Not Allocated\n");
    }
}

int main() {
    int blockSize[MAX_BLOCKS], processSize[MAX_PROCESS];
    int m, n;

    // Input the number of memory blocks
    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);

    // Input the size of each memory block
    printf("Enter the size of each memory block:\n");
    for (int i = 0; i < m; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    // Input the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input the size of each process
    printf("Enter the size of each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
    }

    // Call the best fit function
    bestFit(blockSize, m, processSize, n);

    return 0;
}

