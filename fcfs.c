#include <stdio.h>
int main()
{
	// in fcfs, arrival time is given
	// implemented using FIFO
	//fcfs is a non pre emptive scheduling algo
	// fcfs suffers from convoy effect
	int n;
	scanf("%d", &n);
	int burst_time[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &burst_time[i]);
	int wt = 0;
	float wt_sum = 0;
	int tat = burst_time[0];
	float tat_sum = burst_time[0];
	printf("Processes\tBurst time\tWaiting time\tTurn around time\n");
	printf("%d\t\t%d\t\t%d\t\t%d\n", 1, burst_time[0], wt, tat);
	for(int i = 1; i < n; i++)
	{
		printf("%d\t\t%d\t\t", i+1, burst_time[i]);
		wt = wt + burst_time[i-1];
		printf("%d\t\t", wt);
		wt_sum = wt_sum + wt;
		tat = tat + burst_time[i];
		printf("%d\n", tat);
		tat_sum = tat_sum + tat;
	}
	printf("wt avg: %f\n", wt_sum/n);
	printf("tat sum: %f\n", tat_sum/n);	
	return 0;
}
