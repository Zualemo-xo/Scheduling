#include<stdio.h>
#include<conio.h>
int main()
{
	int n,p[50],at[50],bt[50],i=0;
	int ct[50],tat[50],wt[50];
	printf("Enter the total number of processes: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the process number: ");
		scanf("%d",&p[i]);	
		printf("Enter the burst time: ");
		scanf("%d",&bt[i]);
		printf("Enter the arrival time: ");
		scanf("%d",&at[i]);
	}
	//FCFS
	void fcfs()
	{
		int sum=0,sumtat=0,sumwt=0,i=0;
		//CompletionT
		for(i=0;i<n;i++)
		{
			//sumbt+=ct[i];
			sum+=bt[i];
			ct[i]=sum;
			//sumct+=ct[i];
		}
		//TurnaroundT
		for(i=0;i<n;i++)
		{
			tat[i]=ct[i]-at[i];
			sumtat+=tat[i];
		}
		
		//waitingT
		for(i=0;i<n;i++)
		{
			wt[i]=tat[i]-bt[i];
			sumwt+=wt[i];
		}
		printf("Process  BurstTime(BT) CompletionTime(CT) ArrivalTime(AT) TurnaroundTime(TAT) WaitingTime(WT)  \n");
		for(i=0;i<n;i++)
		{
			printf("%d \t %d \t %d \t %d \t %d \t %d \t \n",p[i],bt[i],ct[i],at[i],tat[i],wt[i]);
		}
		printf("Total Turn Around Time: %d \n",sumtat);
		printf("Total Waiting Time: %d \n",sumwt);
		printf("Total Turn Around Time: %.2f \n",sumtat/n);
		printf("Total Waiting Time: %.2f \n",sumwt/n);
	}
	fcfs();
	return 0;
}
