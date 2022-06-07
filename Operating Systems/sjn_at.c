#include<stdio.h>
#include<string.h>
void main() {
	int ct[20], at[10], n, i, j, temp, st[10], ft[10], wt[10], tat[10], et[10];
	int tatwt = 0, totta = 0;
	float awt, ata;
	char pn[10][10], t[10];
	printf("Enter the number of process:");
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		printf("Enter process name, arrival time & exceution time");
		scanf("%s%d%d", pn[i], &at[i], &et[i]);
	}
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(et[i] < et[j]){
				temp = at[i];
				at[i] = at[j];
				at[j] = temp;
				temp = et[i];
				et[i] = et[j];
				et[j] = temp;
				strcpy(t, pn[i]);
				strcpy(pn[i], pn[j]);
				strcpy(pn[j], t);
			}
		}
	}
	for(i = 0; i < n; i++){
		if(i == 0)
			st[i] = at[i];
		else
			st[i] = ft[i - 1];
			wt[i] = st[i] - at[i];
			ft[i] = st[i] + et[i];
			at[i] = ft[i] - at[i];
			tatwt += wt[i];
			totta += at[i];
		}
	awt = (float)tatwt/n;
	ata = (float)totta/n;
	printf("\npname\tarrival\texecution time\twaiting time\ttatime");
	for(i = 0; i < n; i++){
		printf("\n%s\t%5d\t\t%5d\t\t%5d\t\t%5d", pn[i], at[i], et[i], wt[i], at[i]);
		printf("\nAverage waiting time is:%f", awt);
		printf("\n average turnaround time is%f", ata);
	}
} 
	 
