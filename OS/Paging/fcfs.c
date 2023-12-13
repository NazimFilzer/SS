#include <stdio.h>
void main()
{
    int i, j, k, f, pf = 0, count = 0, rs[25], frames[10], len;
    printf("\n Enter the length of reference string -- ");
    scanf("%d", &len);
    printf("\n Enter the reference string -- ");
    for (i = 0; i < len; i++)
        scanf("%d", &rs[i]);
    printf("\n Enter no. of frames -- ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
        frames[i] = -1;

    printf("\n The Page Replacement Process is -- \n");
    for (i = 0; i < len; i++)
    {
        for (k = 0; k < f; k++)
        {
            if (frames[k] == rs[i]) // checking for hit
            {
                printf("\t\t");
                for (j = 0; j < f; j++)
                    printf("\t%d", frames[j]);
                break;
            }
        }
        if (k == f) // page fault
        {
            frames[count++] = rs[i];
            pf++;
            printf("\tPF No. %d", pf);

            for (j = 0; j < f; j++)
                printf("\t%d", frames[j]);
        }
        printf("\n");
        if (count == f)
            count = 0;
    }
    printf("\n The number of Page Faults using FIFO are %d", pf);
}