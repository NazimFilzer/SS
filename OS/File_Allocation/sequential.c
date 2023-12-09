#include <stdio.h>

void main()
{
    int numFiles, blocks[20], startingBlock[20], tempStartingBlock[20], fileName, blockMatrix[20][20];

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

    printf("\nFilename\tStart block\tLength\n");
    for (int i = 0; i < numFiles; i++)
        printf("%d\t\t%d\t\t%d\n", i + 1, tempStartingBlock[i], blocks[i]);

    printf("\nEnter file name: ");
    scanf("%d", &fileName);

    printf("File name is %d\n", fileName);
    printf("Length is %d\n", blocks[fileName - 1]);

    printf("Blocks occupied:");
    for (int i = 0; i < blocks[fileName - 1]; i++)
        printf("%4d", blockMatrix[fileName - 1][i]);
}
