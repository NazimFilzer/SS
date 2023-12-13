#include <stdio.h>

void displayFiles(int numFiles, int blocks[], int startingBlock[], int blockMatrix[][20])
{
    printf("\nFilename\tStart block\tLength\n");
    for (int i = 0; i < numFiles; i++)
        printf("%d\t\t%d\t\t%d\n", i + 1, startingBlock[i], blocks[i]);
}

void displayBlocks(int fileName, int blocks[], int blockMatrix[][20])
{
    printf("File name is %d\n", fileName);
    printf("Length is %d\n", blocks[fileName - 1]);

    printf("Blocks occupied:");
    for (int i = 0; i < blocks[fileName - 1]; i++)
        printf("%4d", blockMatrix[fileName - 1][i]);
    printf("\n");
}

int main()
{
    int numFiles, blocks[20], startingBlock[20], tempStartingBlock[20], fileName, blockMatrix[20][20];
    int choice;

    // tempStartingBlock is temporary starting block
    printf("Enter the number of files: ");
    scanf("%d", &numFiles);

    for (int i = 0; i < numFiles; i++)
    {
        printf("Enter the number of blocks occupied by file %d: ", i + 1);
        scanf("%d", &blocks[i]);

        printf("Enter the starting block of file %d: ", i + 1);
        scanf("%d", &startingBlock[i]);
        tempStartingBlock[i] = startingBlock[i];

        for (int j = 0; j < blocks[i]; j++)
        {
            blockMatrix[i][j] = tempStartingBlock[i]++;
        }
    }

    do
    {
        printf("\nMenu:\n");
        printf("1. Display all files\n");
        printf("2. Display blocks occupied by a file\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displayFiles(numFiles, blocks, startingBlock, blockMatrix);
            break;
        case 2:
            printf("Enter file name: ");
            scanf("%d", &fileName);
            displayBlocks(fileName, blocks, blockMatrix);
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
