#include <stdio.h>

struct Process
{
    int pid;
    int arrivaltime; // Process ID
    int burst_time;  // Burst time
    int waittime;
    int status;
    int tat;
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
        proc[index].tat = time - proc[index].arrivaltime;
        proc[index].waittime = proc[index].tat - proc[index].burst_time;
        total_turnaround_time += proc[index].tat;
        total_waiting_time += proc[index].waittime;
    }

    printf("Process\tBurst Time\tArrival Time \tWaiting Time \t Turnaround Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].burst_time, proc[i].arrivaltime, proc[i].waittime, proc[i].tat);
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