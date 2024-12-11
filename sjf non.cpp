include <stdio.h>

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int arrivalTime[n], burstTime[n], waitingTime[n], turnAroundTime[n];
    int completionTime[n], isCompleted[n];
    int currentTime = 0, completed = 0;
    float totalWaitingTime = 0, totalTurnAroundTime = 0;

    // Initialize all processes as incomplete
    for (int i = 0; i < n; i++) {
        isCompleted[i] = 0;
    }

    // Input arrival and burst times
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &arrivalTime[i]);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
    }

    // SJF Scheduling calculations
    while (completed < n) {
        int minBurstTime = 1e9; // large initial value
        int shortestJob = -1;

        // Find the process with the minimum burst time that has arrived and is not completed
        for (int i = 0; i < n; i++) {
            if (arrivalTime[i] <= currentTime && !isCompleted[i] && burstTime[i] < minBurstTime) {
                minBurstTime = burstTime[i];
                shortestJob = i;
            }
        }

        if (shortestJob == -1) {
            currentTime++; // if no process has arrived, increment time
        } else {
            // Process found with shortest burst time
            currentTime += burstTime[shortestJob];
            completionTime[shortestJob] = currentTime;
            turnAroundTime[shortestJob] = completionTime[shortestJob] - arrivalTime[shortestJob];
            waitingTime[shortestJob] = turnAroundTime[shortestJob] - burstTime[shortestJob];

            totalWaitingTime += waitingTime[shortestJob];
            totalTurnAroundTime += turnAroundTime[shortestJob];
            isCompleted[shortestJob] = 1;
            completed++;
        }
    }
y
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, arrivalTime[i], burstTime[i], waitingTime[i], turnAroundTime[i]);
    }

    printf("\nAverage Waiting Time: %.2f", totalWaitingTime / n);
    printf("\nAverage Turnaround Time: %.2f\n", totalTurnAroundTime / n);

    return 0;
}
