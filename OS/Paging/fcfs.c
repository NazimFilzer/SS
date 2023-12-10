#include <stdio.h>

void main()
{
    int i, j, k, frameCount, pageFaults = 0, len;

    printf("\nEnter the length of the reference string: ");
    scanf("%d", &len);

    int referenceString[25];

    printf("\nEnter the reference string: ");
    for (i = 0; i < len; i++)
        scanf("%d", &referenceString[i]);

    printf("\nEnter the number of frames: ");
    scanf("%d", &frameCount);

    int frames[10];

    for (i = 0; i < frameCount; i++)
        frames[i] = -1;

    printf("\nThe Page Replacement Process is -- \n");

    for (i = 0; i < len; i++)
    {
        for (k = 0; k < frameCount; k++)
        {
            if (frames[k] == referenceString[i])
            {
                printf("\t\t");
                for (j = 0; j < frameCount; j++)
                    printf("\t%d", frames[j]);
                break;
            }
        }

        if (k == frameCount)
        {
            frames[pageFaults++] = referenceString[i];
            printf("\tPage Fault No. %d", pageFaults);

            for (j = 0; j < frameCount; j++)
                printf("\t%d", frames[j]);
        }

        printf("\n");

        if (pageFaults == frameCount)
            pageFaults = 0;
    }

    printf("\nThe number of Page Faults using FIFO is %d", pageFaults);
}
