#include <stdio.h>
#include <string.h>

struct Process
{
    char name[20];
    int arrivalTime, turnaroundTime, burstTime, waitingTime, status, completionTime;
} processes[20], temp;

struct Done
{
    char name[20];
    int startTime, completionTime;
} doneProcesses[20];

void main()
{
    int numProcesses, i, j, lastScheduled, minIndex, found, processCount, idleFlag;
    float totalWaitingTime = 0.0, totalTurnaroundTime = 0.0;

    printf("ENTER THE NUMBER OF PROCESSES: ");
    scanf("%d", &numProcesses);

    for (i = 0; i < numProcesses; i++)
    {
        // Input process details
        printf("\nENTER DETAILS OF PROCESS %d", i + 1);
        printf("\nPROCESS NAME: ");
        scanf(" %s", processes[i].name);
        printf("ARRIVAL TIME: ");
        scanf("%d", &processes[i].arrivalTime);
        printf("BURST TIME: ");
        scanf("%d", &processes[i].burstTime);
        processes[i].status = 0;
    }

    for (i = 0, lastScheduled = 0, processCount = 0, idleFlag = 0; lastScheduled < numProcesses;)
    {
        for (j = 0, found = 0; j < numProcesses; j++)
        {
            if (lastScheduled >= processes[j].arrivalTime && processes[j].status == 0)
            {
                if (found == 0)
                {
                    minIndex = j;
                    found = 1;
                }
                else if (found != 0 && processes[minIndex].burstTime > processes[j].burstTime)
                {
                    minIndex = j;
                }
            }
        }

        if (idleFlag == 0 && found == 0)
        {
            strcpy(doneProcesses[processCount].name, "Idle");
            doneProcesses[processCount].startTime = lastScheduled;
            lastScheduled++;
            idleFlag = 1;
        }
        else if (found == 1)
        {
            if (idleFlag == 1)
            {
                doneProcesses[processCount].completionTime = lastScheduled;
                processCount++;
                idleFlag = 0;
            }

            strcpy(doneProcesses[processCount].name, processes[minIndex].name);
            processes[minIndex].status = 1;
            doneProcesses[processCount].startTime = lastScheduled;
            doneProcesses[processCount].completionTime = lastScheduled + processes[minIndex].burstTime;
            lastScheduled = doneProcesses[processCount].completionTime;

            processes[minIndex].completionTime = doneProcesses[processCount].completionTime;
            processes[minIndex].turnaroundTime = processes[minIndex].completionTime - processes[minIndex].arrivalTime;
            processes[minIndex].waitingTime = processes[minIndex].turnaroundTime - processes[minIndex].burstTime;

            processCount++;
            lastScheduled++;
            lastScheduled++;
        }
        else
        {
            lastScheduled++;
        }
    }

    printf("\nPROCESS NAME\tARRIVAL TIME\tCOMPLETION TIME (ms)\tWAITING TIME (ms)\tTURNAROUND TIME (ms)\n\n");

    for (i = 0; i < numProcesses; i++)
    {
        printf("    %s\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n", processes[i].name, processes[i].arrivalTime, processes[i].completionTime, processes[i].waitingTime, processes[i].turnaroundTime);
        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
    }

    printf("\n\nGANTT CHART ");
    printf("\n\t--------------------------------------------------------------------\n\t");

    for (i = 0; i < processCount; i++)
    {
        printf("|");
        printf("%s\t", doneProcesses[i].name);
    }

    printf(" |");
    printf("\n\t--------------------------------------------------------------------\n\t");

    for (i = 0; i < processCount; i++)
    {
        printf("%d\t", doneProcesses[i].startTime);
    }

    printf("%d\t\n", doneProcesses[processCount - 1].completionTime);
    printf("\nAVERAGE WAITING TIME : %f", (totalWaitingTime / numProcesses));
    printf("\nAVERAGE TURNAROUND TIME : %f\n", (totalTurnaroundTime / numProcesses));
}
