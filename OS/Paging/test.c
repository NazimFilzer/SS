#include <stdio.h>

void main()
{
    int referenceString[50], i, j, k, length, numFrames, counter[20], frames[20], min, pageFaults = 0, time = 0, lru[20];

    printf("\nEnter number of page references -- ");
    scanf("%d", &length);
    printf("\nEnter the reference string -- ");
    for (i = 0; i < length; i++)
        scanf("%d", &referenceString[i]);
    printf("\nEnter the available no. of frames -- ");
    scanf("%d", &numFrames);

    for (i = 0; i < numFrames; i++)
    {
        counter[i] = 0;
        frames[i] = -1;
        lru[i] = 0;
    }
    for (i = 0; i < length; i++)
    {
        time++;
        for (j = 0; j < numFrames; j++)
            if (referenceString[i] == frames[j])
            {
                counter[j]++;
                break;
            }
        if (j == numFrames)
        {
            min = 0;
            for (k = 1; k < numFrames; k++)
                if (counter[k] < counter[min] || (counter[k] == counter[min] && lru[k] < lru[min]))
                {
                    min = k;
                }
            frames[min] = referenceString[i];
            counter[min] = 1;
            lru[min] = time;
            pageFaults++;
            printf("\tPF No. %d\n", pageFaults);
        }

        for (j = 0; j < numFrames; j++)
            printf("\t%d\n", frames[j]);
        printf("\n");
    }

    printf(" Total number of page faults -- %d", pageFaults);
}
