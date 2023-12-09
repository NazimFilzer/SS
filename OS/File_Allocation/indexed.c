#include <stdio.h>

void main()
{
    int numFiles, fileSize[20], startingBlock[20], blockCount[20], blocksOccupied[20][20], fileName;

    // Input file information
    printf("Enter the number of files: ");
    scanf("%d", &numFiles);

    for (int i = 0; i < numFiles; i++)
    {
        printf("Enter the starting block and size of file %d: ", i + 1);
        scanf("%d %d", &startingBlock[i], &fileSize[i]);

        printf("Enter the number of blocks occupied by file %d: ", i + 1);
        scanf("%d", &blockCount[i]);

        printf("Mention the blocks of file %d: ", i + 1);
        for (int j = 0; j < blockCount[i]; j++)
            scanf("%d", &blocksOccupied[i][j]);
    }

    // Display file information
    printf("\nFile\tIndex (Starting Block)\tLength\n");
    for (int i = 0; i < numFiles; i++)
        printf("%d\t%d\t\t\t\t%d\n", i + 1, startingBlock[i], blockCount[i]);

    // Get file name and display details
    printf("\nEnter the file name: ");
    scanf("%d", &fileName);
    printf("File name is: %d\n", fileName);

    int index = fileName - 1;
    printf("Index is: %d\n", startingBlock[index]);

    printf("Blocks occupied are: ");
    for (int j = 0; j < blockCount[index]; j++)
        printf("%3d", blocksOccupied[index][j]);
}
