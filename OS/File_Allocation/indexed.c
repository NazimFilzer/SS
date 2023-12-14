#include <stdio.h>

void displayFileInformation(int numFiles, int startingBlock[], int blockCount[])
{
    printf("\nFile\tIndex (Starting Block)\tLength\n");
    for (int i = 0; i < numFiles; i++)
        printf("%d\t%d\t\t\t\t%d\n", i + 1, startingBlock[i], blockCount[i]);
}

void displayFileDetails(int numFiles, int startingBlock[], int blockCount[], int blocksOccupied[][20], int fileName)
{
    int index = fileName - 1;
    printf("File name is: %d\n", fileName);
    printf("Index is: %d\n", startingBlock[index]);
    printf("Blocks occupied are: ");
    for (int j = 0; j < blockCount[index]; j++)
        printf("%3d", blocksOccupied[index][j]);
    printf("\n");
}

int main()
{
    int numFiles, fileSize[20], startingBlock[20], blockCount[20], blocksOccupied[20][20], fileName;
    int choice;

    // Input file information
    printf("Enter the number of files: ");
    scanf("%d", &numFiles);

    for (int i = 0; i < numFiles; i++)
    {
        printf("Enter the starting block (Index Block) and size of file %d: ", i + 1);
        scanf("%d %d", &startingBlock[i], &fileSize[i]);

        printf("Enter the number of blocks occupied by file %d: ", i + 1);
        scanf("%d", &blockCount[i]);

        printf("Mention the blocks of file %d: ", i + 1);
        for (int j = 0; j < blockCount[i]; j++)
            scanf("%d", &blocksOccupied[i][j]);
    }

    do
    {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Display all file information\n");
        printf("2. Display file details\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displayFileInformation(numFiles, startingBlock, blockCount);
            break;
        case 2:
            printf("Enter the file name: ");
            scanf("%d", &fileName);
            displayFileDetails(numFiles, startingBlock, blockCount, blocksOccupied, fileName);
            break;
        case 3:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
