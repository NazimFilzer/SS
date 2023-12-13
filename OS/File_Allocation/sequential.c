#include <stdio.h>

void displayFiles(int numFiles, int numBlocks[], int startingBlock[], int blockMatrix[][20])
{
    printf("\nFilename\tStart block\tLength\n");
    for (int i = 0; i < numFiles; i++)
        printf("%d\t\t%d\t\t%d\n", i + 1, startingBlock[i], numBlocks[i]);
}

void displayBlocks(int fileName, int numBlocks[], int blockMatrix[][20])
{
    printf("File name is %d\n", fileName);
    printf("Length is %d\n", numBlocks[fileName - 1]);

    printf("Blocks occupied:");
    for (int i = 0; i < numBlocks[fileName - 1]; i++)
        printf("%4d", blockMatrix[fileName - 1][i]);
    printf("\n");
}

int main()
{
    int numFiles, numBlocks[20], startingBlock[20], tempStartingBlock[20], fileName, blockMatrix[20][20];
    int choice;

    // tempStartingBlock is temporary starting block
    printf("Enter the number of files: ");
    scanf("%d", &numFiles);

    for (int i = 0; i < numFiles; i++)
    {
        printf("Enter the number of numBlocks occupied by file %d: ", i + 1);
        scanf("%d", &numBlocks[i]);

        printf("Enter the starting block of file %d: ", i + 1);
        scanf("%d", &startingBlock[i]);
        tempStartingBlock[i] = startingBlock[i];

        for (int j = 0; j < numBlocks[i]; j++)
        {
            blockMatrix[i][j] = tempStartingBlock[i]++;
        }
    }

    do
    {
        printf("\nMenu:\n");
        printf("1. Display all files\n");
        printf("2. Display numBlocks occupied by a file\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displayFiles(numFiles, numBlocks, startingBlock, blockMatrix);
            break;
        case 2:
            printf("Enter file name: ");
            scanf("%d", &fileName);
            displayBlocks(fileName, numBlocks, blockMatrix);
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
