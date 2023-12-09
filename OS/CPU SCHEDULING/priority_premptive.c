#include <stdio.h>

// Structure to store process details
struct Process
{
    int processID;
    int arrivalTime;
    int burstTime;
    int priority;
    int remainingTime;
    int waitingtime;
};

// Function to find the process with highest priority
int findHighestPriority(struct Process processes[], int n, int time)
{
    int highestPriority = 9999;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (processes[i].arrivalTime <= time && processes[i].priority < highestPriority && processes[i].remainingTime > 0)
        {
            highestPriority = processes[i].priority;
            index = i;
        }
    }
    return index;
}

// Function to perform preemptive priority scheduling
void priorityScheduling(struct Process processes[], int n)
{
    int gantchart[50], ganttime[50], gantindex = 0;
    int time = 0;
    int completed = 0;

    while (completed < n)
    {
        int currentProcess = findHighestPriority(processes, n, time);

        if (currentProcess == -1)
        {
            time++;
            continue;
        }

        processes[currentProcess].remainingTime--;
        time++;

        gantchart[gantindex] = currentProcess;
        ganttime[gantindex++] = time;
        if (processes[currentProcess].remainingTime == 0)
        {
            completed++;
            processes[currentProcess].waitingtime = time - processes[currentProcess].arrivalTime - processes[currentProcess].burstTime;
            // printf("Process %d completed at time %d\n", processes[currentProcess].processID, time);
        }
    }
    printf("\n Gant chart \t");
    for (int i = 0; i < gantindex; i++)
    {
        printf("%d\t| ", gantchart[i]);
    }
    printf("\n Time   \t");
    for (int i = 0; i < gantindex; i++)
    {
        printf("\t %d", ganttime[i]);
    }
    printf("\n");
}

void printDetails(struct Process processes[], int n)
{
    float totwait = 0, tottat = 0;
    printf("Process Id \t Arrival Time\tPriority \tBurst Time \t Waiting time \t Turnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t %d\t\t%d\t\t%d\t\t%d\t\t%d\t\n", processes[i].processID,
               processes[i].arrivalTime, processes[i].priority, processes[i].burstTime, processes[i].waitingtime, processes[i].waitingtime + processes[i].burstTime);
        totwait += processes[i].waitingtime;
        tottat += processes[i].waitingtime + processes[i].burstTime;
    }
    printf("Average waiting time is    :  %.3f\n", totwait / n);
    printf("Average turnaround time is :   %.3f", tottat / n);
}
int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[100];

    printf("Enter process details:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Process ID: ");
        scanf("%d", &processes[i].processID);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrivalTime);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burstTime);
        printf("Priority: ");
        scanf("%d", &processes[i].priority);

        processes[i].remainingTime = processes[i].burstTime;
    }

    printf("\nPreemptive Priority Scheduling:\n");
    priorityScheduling(processes, n);
    printDetails(processes, n);

    return 0;
}
