#include <stdio.h>

void main()
{
    int rs[50], i, j, k, m, f, cntr[20], a[20], min, pf = 0, time = 0, lru[20];

    printf("\nEnter number of page references -- ");
    scanf("%d", &m);
    printf("\nEnter the reference string -- ");
    for (i = 0; i < m; i++)
        scanf("%d", &rs[i]);
    printf("\nEnter the available no. of frames -- ");
    scanf("%d", &f);
    for (i = 0; i < f; i++)
    {
        cntr[i] = 0;
        a[i] = -1;
        lru[i] = 0;
    }
    for (i = 0; i < m; i++)
    {
        time++;
        for (j = 0; j < f; j++)
            if (rs[i] == a[j])
            {
                cntr[j]++;

                break;
            }
        if (j == f)
        {
            min = 0;
            for (k = 1; k < f; k++)
                if (cntr[k] < cntr[min] || (cntr[k] == cntr[min] && lru[k] < lru[min]))
                {
                    min = k;
                }
            a[min] = rs[i];
            cntr[min] = 1;
            lru[min] = time;
            pf++;
            printf("\tPF No. %d\n", pf);
        }

        for (j = 0; j < f; j++)
            printf("\t%d\n", a[j]);
        printf("\n");
    }

    printf(" Total number of page faults -- %d", pf);
}
