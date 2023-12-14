#include <stdio.h>

struct Process
{
    int pid;        // Process ID
    int burst_time; // Burst time
    int priority;
    int waittime;
};

void priorityScheduling(struct Process proc[], int n)
{
    int i, j;
    struct Process temp;

    // Sort the processes based on priority
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (proc[j].priority > proc[j + 1].priority)
            {
                // Swap the processes
                temp = proc[j];
                proc[j] = proc[j + 1];
                proc[j + 1] = temp;
            }
        }
    }

    // Calculate waiting time, turnaround time, and average waiting time
    int total_waiting_time = 0;
    int total_turnaround_time = proc[0].burst_time;

    proc[0].waittime = 0;

    for (i = 1; i < n; i++)
    {
        proc[i].waittime = proc[i - 1].waittime + proc[i - 1].burst_time;
        total_turnaround_time += proc[i].waittime + proc[i].burst_time;
        total_waiting_time += proc[i].waittime;
    }
    printf("Process\tBurst Time\tPriority\tWaiting Time \t Turn around time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t%d\t%d\n", proc[i].pid, proc[i].burst_time, proc[i].priority, proc[i].waittime, proc[i].waittime + proc[i].burst_time);
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
}

int main()
{
    int n, i;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[100];

    printf("Enter process details (Process ID, Burst Time, Priority):\n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d %d %d", &proc[i].pid, &proc[i].burst_time, &proc[i].priority);
    }

    // Call the priority scheduling function
    priorityScheduling(proc, n);

    return 0;
}