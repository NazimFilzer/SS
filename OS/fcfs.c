#include <stdio.h>

struct process
{
    int pid;
    int bt;
    int wt;
    int tat;
    int at; // Arrival time
} p[50];

void swap(struct process *xp, struct process *yp)
{
    struct process temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sortProcessesByArrivalTime(struct process p[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (p[j].at > p[j + 1].at)
                swap(&p[j], &p[j + 1]);
}

int main()
{
    int n, temp, i, j;

    printf("Please Enter no of processes : ");
    scanf("%d", &n);

    printf("\nPlease Enter Burst Time and Arrival Time of processes : \n");
    for (i = 0; i < n; i++)
    {
        printf("P%d (BT AT): ", i + 1);
        p[i].pid = i + 1;
        scanf("%d %d", &p[i].bt, &p[i].at);
    }

    // Sort processes based on arrival time
    sortProcessesByArrivalTime(p, n);

    // wt&tat
    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            p[i].wt = 0;
            p[i].tat = p[i].wt + p[i].bt;
            continue;
        }

        p[i].wt = p[i - 1].bt + p[i - 1].wt;
        p[i].tat = p[i].wt + p[i].bt;
    }

    // print
    printf("\nPid\tBT\tAT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].bt, p[i].at, p[i].wt, p[i].tat);
    }

    // Avg wt
    temp = 0;
    for (i = 0; i < n; i++)
        temp += p[i].wt;
    printf("average waiting time\t\t:%f\n", (float)temp / n - 1);

    // Avg tat
    temp = 0;
    for (i = 0; i < n; i++)
        temp += p[i].tat;
    printf("average turn around time\t:%f\n", (float)temp / n - 1);
}
