
#include <stdio.h>
#include <limits.h>
void findWaitingTime(int n, int bt[], int at[], int wt[]) {
 int rt[n];
 int complete = 0, t = 0;
 int minm = INT_MAX, shortest = 0;
 int check = 0;
 for (int i = 0; i < n; i++) {
rt[i] = bt[i];
 wt[i] = 0;
 }
 while (complete != n) {
 for (int j = 0; j < n; j++) {
 if (at[j] <= t && rt[j] < minm && rt[j] > 0) {
 minm = rt[j];
 shortest = j;
 check = 1;
 }
 }
 if (check == 0) {
 t++;
 continue;
 }
 rt[shortest]--;
 minm = rt[shortest];
 if (minm == 0) minm = INT_MAX;
 if (rt[shortest] == 0) {
 complete++;
 check = 0;
 wt[shortest] = t + 1 - bt[shortest] - at[shortest];
 if (wt[shortest] < 0) wt[shortest] = 0;
 }
 t++;
 }
}
void findTurnAroundTime(int n, int bt[], int wt[], int tat[]) {
 for (int i = 0; i < n; i++) {
 tat[i] = bt[i] + wt[i];
 }
}
void findAvgTime(int n, int bt[], int at[]) {
 int wt[n], tat[n];
 int totalWT = 0, totalTAT = 0;
 findWaitingTime(n, bt, at, wt);
 findTurnAroundTime(n, bt, wt, tat);
 printf("P\tAT\tBT\tWT\tTAT\n");
 for (int i = 0; i < n; i++) {
 totalWT += wt[i];
 totalTAT += tat[i];
 printf("%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], wt[i], tat[i]);
 }
 printf("Average Waiting Time = %.2f\n", (float)totalWT / n);
 printf("Average Turnaround Time = %.2f\n", (float)totalTAT / n);
}
int main() {
 int at[] = {1, 3, 3, 3}; 
 int bt[] = {2, 2, 4, 4}; 
 int n = sizeof(bt) / sizeof(bt[0]);
 findAvgTime(n, bt, at);