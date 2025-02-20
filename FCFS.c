#include <stdio.h>

void main() {
    int bt[20], wt[20], tat[20], at[20], ct[20];
    int i, n;
    float wtavg = 0, tatavg = 0;

    printf("\nEnter the number of processes: ");
    scanf("%d", &n);

    // Input arrival times (assuming 0 for simplicity)
    for(i = 0; i < n; i++) {
        at[i] = 0; // Assuming arrival time is 0 for all processes
        printf("\nEnter burst time for process %d: ", i);
        scanf("%d", &bt[i]);
    }

    // Calculate Completion Time, Waiting Time, and Turnaround Time
    ct[0] = bt[0]; // Completion time for the first process is its burst time
    for(i = 1; i < n; i++) {
        ct[i] = ct[i-1] + bt[i]; // Completion time of next process
    }

    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i]; // Turnaround Time = Completion Time - Arrival Time
        wt[i] = tat[i] - bt[i]; // Waiting Time = Turnaround Time - Burst Time
        wtavg += wt[i];
        tatavg += tat[i];
    }

    printf("\n\tPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\tCOMPLETION TIME\n");
    for(i = 0; i < n; i++) {
        printf("\tP%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, bt[i], wt[i], tat[i],ct[i]);
    }

    // Calculate average waiting and turnaround times
    wtavg /= n;
    tatavg /= n;

    printf("\nAverage Waiting Time: %f", wtavg);
    printf("\nAverage Turnaround Time: %f", tatavg);
}

