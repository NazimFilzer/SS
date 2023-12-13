#include <stdio.h>

void main()
{
    int rs[50], i, j, k, len, f, cntr[20], frame[20], min, pf = 0, time = 0, lru[20];

    printf("\nEnter number of page references -- ");
    scanf("%d", &len);
    printf("\nEnter the reference string -- ");
    for (i = 0; i < len; i++)
        scanf("%d", &rs[i]);
    printf("\nEnter the available no. of frames -- ");
    scanf("%d", &f);

    // 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2
    for (i = 0; i < f; i++)
    {
        cntr[i] = 0;
        frame[i] = -1;
        lru[i] = 0;
    }
    for (i = 0; i < len; i++)
    {
        time++;
        for (j = 0; j < f; j++)
        {
            if (rs[i] == frame[j]) // increment counter if the page is in the frame
            {
                cntr[j]++;

                break;
            }
        }
        if (j == f)
        {
            min = 0;
            for (k = 1; k < f; k++)
                if (cntr[k] < cntr[min] || (cntr[k] == cntr[min] && lru[k] < lru[min]))
                {
                    min = k;
                }
            frame[min] = rs[i];
            cntr[min] = 1;
            lru[min] = time;
            pf++;
            printf("\tPF No. %d\t\t", pf);
        }

        for (j = 0; j < f; j++)
            printf("\t%d", frame[j]);
        printf("\n");
    }

    printf(" Total number of page faults -- %d", pf);
}
