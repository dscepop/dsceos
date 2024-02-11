#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n, m;
    printf("Enter number of Processes: ");
    scanf("%d", &n);
    
    int burst[n], priority[n], index[n];
    
    for (int i = 0; i < n; i++) {
        printf("Enter burst time & priority value for process %d: ", i + 1);
        scanf("%d %d", &burst[i], &priority[i]);
        index[i] = i + 1;
    }
    
    // Sort processes based on priority (higher number indicates lower priority)
    for (int i = 0; i < n; i++) {
        int temp = priority[i];
        m = i;
        for (int j = i; j < n; j++) {
            if (priority[j] < temp) { // Lower value of priority[j] should be the one that runs first
                temp = priority[j];
                m = j;
            }
        }
        swap(&priority[i], &priority[m]);
        swap(&burst[i], &burst[m]);
        swap(&index[i], &index[m]);
    }
    
    int t = 0;
    printf("Order of process execution is:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d is executed from %d to %d\n", index[i], t, t + burst[i]);
        t += burst[i];
    }
    
    printf("\nProcess Id\tBurst time\tWait Time\n");
    int wait_time = 0;
    int total_wait_time = 0;
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\n", index[i], burst[i], wait_time);
        total_wait_time += wait_time;
        wait_time += burst[i];
    }
    
    float avg_wait_time = (float)total_wait_time / n;
    printf("Average waiting time is %f\n", avg_wait_time);
    
    int total_Turn_Around = 0;
    for (int i = 0; i < n; i++) {
        total_Turn_Around += wait_time + burst[i]; // Accumulate the total turnaround time
    }
    
    // Average Turnaround Time calculation corrected
    float avg_Turn_Around = (float)total_Turn_Around / n;
    printf("Average Turn Around Time is %f\n", avg_Turn_Around);
    
    return 0;
}