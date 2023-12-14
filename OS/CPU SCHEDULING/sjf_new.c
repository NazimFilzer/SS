#include <stdio.h>

struct Process
{
    int pid;
    int arrivaltime; // Process ID
    int burst_time;  // Burst time
    int waittime;
    int status;
};

void sjfScheduling(struct Process proc[], int n)
{
    int i, j, index, total_waiting_time = 0, total_turnaround_time = 0;
    struct Process temp;
    int completed = 0, time = 0;
    while (completed < n)
    {

        for (int i = 0, smallest = 9999; i < n; i++)
        {
            if (proc[i].arrivaltime <= time && proc[i].status == 1 && proc[i].burst_time < smallest)
            {
                smallest = proc[i].burst_time;
                index = i;
            }
        }
        time += proc[index].burst_time;
        completed++;
        proc[index].status = 0;
        proc[index].waittime = time - proc[index].burst_time - proc[index].arrivaltime;
        total_waiting_time += proc[index].waittime;
        total_turnaround_time += proc[index].waittime + proc[index].burst_time;
    }

    printf("Process\tBurst Time\tWaiting Time \t Turn around time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t\t%d\t%d\n", proc[i].pid, proc[i].burst_time, proc[i].waittime, proc[i].waittime + proc[i].burst_time);
    }
    printf("\nAverage Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
}

void main()
{
    int n, i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process proc[100];
    printf("Enter process details (Process ID, Burst Time,arrival time:)\n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d %d %d", &proc[i].pid, &proc[i].burst_time, &proc[i].arrivaltime);
        proc[i].status = 1;
    }
    sjfScheduling(proc, n);
}

/*

#include <stdio.h>
#include <string.h>

struct process
{
    char name[20];
    int at, tt, bt, wt, status, ct;
} p[20], temp;

struct done
{
    char name[20];
    int st, ct;
} d[20];

void main()
{
    int n, i, j, ls, min, fnd, num, idle;
    float twt = 0.0, ttt = 0.0;

    printf("ENTER THE NUMBER OF PROCESSES: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        // Input process details
        printf("\nENTER DETAILS OF PROCESS %d", i + 1);
        printf("\nPROCESS NAME: ");
        scanf(" %s", p[i].name);
        printf("ARRIVAL TIME: ");
        scanf("%d", &p[i].at);
        printf("BURST TIME: ");
        scanf("%d", &p[i].bt);
        p[i].status = 0;
    }

    for (i = 0, ls = 0, num = 0, idle = 0; ls < n;)
    {
        for (j = 0, fnd = 0; j < n; j++)
        {
            if (i >= p[j].at && p[j].status == 0)
            {
                if (fnd == 0)
                {
                    min = j;
                    fnd = 1;
                }
                else if (fnd != 0 && p[min].bt > p[j].bt)
                {
                    min = j;
                }
            }
        }

        if (idle == 0 && fnd == 0)
        {
            strcpy(d[num].name, "Idle");
            d[num].st = i;
            i++;
            idle = 1;
        }
        else if (fnd == 1)
        {
            if (idle == 1)
            {
                d[num].ct = i;
                num++;
                idle = 0;
            }
            strcpy(d[num].name, p[min].name);
            p[min].status = 1;
            d[num].st = i;
            d[num].ct = i + p[min].bt;
            i = d[num].ct;
            p[min].ct = d[num].ct;
            p[min].tt = p[min].ct - p[min].at;
            p[min].wt = p[min].tt - p[min].bt;
            num++;
            ls++;
        }
        else
        {
            i++;
        }
    }

    printf("\nPROCESS NAME\tARRIVAL TIME\tCOMPLETION TIME (ms)\tWAITING TIME (ms)\tTURNAROUND TIME (ms)\n\n");

    for (i = 0; i < n; i++)
    {
        printf("    %s\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n", p[i].name, p[i].at, p[i].ct, p[i].wt, p[i].tt);
        twt += p[i].wt;
        ttt += p[i].tt;
    }

    printf("\n\nGANTT CHART ");
    printf("\n\t--------------------------------------------------------------------\n\t");

    for (i = 0; i < num; i++)
    {
        printf("|");
        printf("%s\t", d[i].name);
    }

    printf(" |");
    printf("\n\t--------------------------------------------------------------------\n\t");

    for (i = 0; i < num; i++)
    {
        printf("%d\t", d[i].st);
    }

    printf("%d\t\n", d[num - 1].ct);
    printf("\nAVERAGE WAITING TIME : %f", (twt / n));
    printf("\nAVERAGE TURNAROUND TIME : %f\n", (ttt / n));
}


*/