#include <stdio.h>
void main()
{
    int i, j, k, f, pf = 0, count = 0, rs[25], m[10], n, dist[25], maxdist, index;
    printf("\n Enter the length of reference string -- ");
    scanf("%d", &n);
    printf("\n Enter the reference string -- ");
    for (i = 0; i < n; i++)
        scanf("%d", &rs[i]);
    printf("\n Enter no. of frames -- ");
    scanf("%d", &f);
    for (i = 0; i < f; i++)
    {
        m[i] = -1;
    }
    // 1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3

    printf("\n The Page Replacement Process is -- \n");
    for (i = 0; i < n; i++)
    {
        if (i < f)
        {
            pf++;
            m[i] = rs[i];
            printf("\t\t");
            for (j = 0; j < f; j++)
                printf("\t%d", m[j]);
            printf("\n");
        }
        else
        {

            for (k = 0; k < f; k++)
            {
                if (m[k] == rs[i])
                {
                    printf("\t\t");
                    for (j = 0; j < f; j++)
                        printf("\t%d", m[j]);
                    break;
                }
            }
            if (k == f)
            {
                maxdist = -1;
                for (j = 0; j < f; j++)
                {
                    dist[j] = 0;
                    for (int rev = i - 1; rev >= 0; rev--)
                    {
                        dist[j]++;
                        if (rs[rev] == m[j])
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
                m[index] = rs[i];
                pf++;
                printf("\tPF No. %d", pf);

                for (j = 0; j < f; j++)
                    printf("\t%d", m[j]);
            }
            printf("\n");
        }
    }
    printf("\n The number of Page Faults using FIFO are %d", pf);
}