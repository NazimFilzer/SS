#include <stdio.h>
void main()
{
    int i, j, k, f, pf = 0, count = 0, rs[25], frame[10], len, dist[25], maxdist, index;
    printf("\n Enter the length of reference string -- ");
    scanf("%d", &len);
    printf("\n Enter the reference string -- ");
    for (i = 0; i < len; i++)
        scanf("%d", &rs[i]);
    printf("\n Enter no. of frames -- ");
    scanf("%d", &f);
    for (i = 0; i < f; i++)
    {
        frame[i] = -1;
    }
    // 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1  pf = 12

    printf("\n The Page Replacement Process is -- \n");
    for (i = 0; i < len; i++)
    {
        if (i < f) // f = no of frames  Here directly giving them page faults
        {
            pf++;
            frame[i] = rs[i];
            printf("\t\t");
            for (j = 0; j < f; j++)
                printf("\t%d", frame[j]);
            printf("\n");
        }
        else
        {

            for (k = 0; k < f; k++)
            {
                if (frame[k] == rs[i]) //// checking for hit
                {
                    printf("\t\t");
                    for (j = 0; j < f; j++)
                        printf("\t%d", frame[j]);
                    break;
                }
            }
            if (k == f)
            { // finding page to replace
              // here we find the distace of Each element from the frames to left side of the current reference string and then chooses the largest distance and swaps them
                maxdist = -1;
                for (j = 0; j < f; j++)
                {
                    dist[j] = 0;
                    for (int rev = i - 1; rev >= 0; rev--)
                    {
                        dist[j]++;
                        if (rs[rev] == frame[j])
                        {
                            break;
                        }
                    }
                    if (dist[j] > maxdist)
                    {
                        maxdist = dist[j];
                        index = j;
                    }
                }
                frame[index] = rs[i];
                pf++;
                printf("\tPF No. %d", pf);

                for (j = 0; j < f; j++)
                    printf("\t%d", frame[j]);
            }
            printf("\n");
        }
    }
    printf("\n The number of Page Faults using FIFO are %d", pf);
}