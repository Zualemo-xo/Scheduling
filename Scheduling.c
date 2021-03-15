#include<stdio.h>
#include<conio.h>
int main()
{
	int n,p[50],p1[50],at[50],at1[50],bt[50],bt1[50],i=0;
	int ct[50],tat[50],wt[50];
	float globaltat[50],globalwt[50];
	int size=0;
	
	printf("Enter the total number of processes: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the process number: ");
		scanf("%d",&p[i]);
		p1[i]=p[i];	
		printf("Enter the burst time: ");
		scanf("%d",&bt[i]);
		bt1[i]=bt[i];
		printf("Enter the arrival time: ");
		scanf("%d",&at[i]);
		at1[i]=at[i];
	}
	//FCFS
	void fcfs()
	{
		printf("\n FCFS \n");
		int sum=0,i=0;
		float sumtat=0,sumwt=0;
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
		//printf("Process  BurstTime(BT) CompletionTime(CT) ArrivalTime(AT) TurnaroundTime(TAT) WaitingTime(WT)  \n");
		printf("Process	(BT)	(CT)	(AT)	(TAT)	(WT)  \n");
		for(i=0;i<n;i++)
		{
			printf("P%d \t %d \t %d \t %d \t %d \t %d \t \n",p[i],bt[i],ct[i],at[i],tat[i],wt[i]);
		}
		printf("Total Turn Around Time: %.0f \n",sumtat);
		printf("Total Waiting Time: %.0f \n",sumwt);
		float avgtat=sumtat/n;
		printf("Average Turn Around Time: %.2f \n",avgtat);
		float avgwt=sumwt/n;
		printf("Average Waiting Time: %.2f \n",avgwt);
		globalwt[size]=avgwt;
		globaltat[size++]=avgtat;
	}
	
	void sjf(int bt[50],int at[50])
	{
				printf("\n SJF \n");
		int sum=0,i=0,j=0,temp;
		float sumtat=0,sumwt=0;
		//sort based on shortest time
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(bt[i]>bt[j])
				{
							//add for at
					temp=bt[i];
					bt[i]=bt[j];
					bt[j]=temp;
					temp=p[i];
					p[i]=p[j];
					p[j]=temp;
				}
			}
		}
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
		//printf("Process  BurstTime(BT) CompletionTime(CT) ArrivalTime(AT) TurnaroundTime(TAT) WaitingTime(WT)  \n");
		printf("Process	(BT)	(CT)	(AT)	(TAT)	(WT)  \n");

		for(i=0;i<n;i++)
		{
			printf("P%d \t %d \t %d \t %d \t %d \t %d \t \n",p[i],bt[i],ct[i],at[i],tat[i],wt[i]);
		}
		printf("Total Turn Around Time: %.0f \n",sumtat);
		printf("Total Waiting Time: %.0f \n",sumwt);
		float avgtat=sumtat/n;
		printf("Average Turn Around Time: %.2f \n",avgtat);
		float avgwt=sumwt/n;
		printf("Average Waiting Time: %.2f \n",avgwt);
		globalwt[size]=avgwt;
		globaltat[size++]=avgtat;
	}
	
		void priority(int bt[50],int at[50],int p[50])
	{
		printf("\n Priority \n");
		int sum=0,i=0,j=0,temp;
		float sumtat=0,sumwt=0;
		int pr[50];
		for(i=0;i<n;i++)
		{
			printf("Enter the priority for process %d: ",i);
			scanf("%d",&pr[i]);
		}
		//sort based on shortest time
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(pr[i]>pr[j])
				{
					temp=bt[i];
					bt[i]=bt[j];
					bt[j]=temp;
					
					temp=p[i];
					p[i]=p[j];
					p[j]=temp;
					
					temp=pr[i];
					pr[i]=pr[j];
					pr[j]=temp;
				}
			}
		}
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
		//printf("Process  BurstTime(BT) CompletionTime(CT) ArrivalTime(AT) TurnaroundTime(TAT) WaitingTime(WT)  \n");
		printf("Process	(BT)	(CT)	(AT)	(TAT)	(WT)	Priority	\n");
		for(i=0;i<n;i++)
		{
			printf("P%d \t %d \t %d \t %d \t %d \t %d \t %d \t \n",p[i],bt[i],ct[i],at[i],tat[i],wt[i],pr[i]);
		}
		printf("Total Turn Around Time: %.0f \n",sumtat);
		printf("Total Waiting Time: %.0f \n",sumwt);

		float avgtat=sumtat/n;
		printf("Average Turn Around Time: %.2f \n",avgtat);
		float avgwt=sumwt/n;
		printf("Average Waiting Time: %.2f \n",avgwt);
		globalwt[size]=avgwt;
		globaltat[size++]=avgtat;

	}
	
	void compare()
	{
			printf("\nComparison\n");
			printf("Algorithm\tTAT \t WT");
			printf("\n FCFS\t %f\t %f",globaltat[0],globalwt[0]);
			printf("\n SJF\t %f\t %f",globaltat[1],globalwt[1]);
			printf("\n Priority\t %f\t %f",globaltat[2],globalwt[2]);
			printf("\nPreferred algorithm: ");
			if(globalwt[0]<globalwt[1] && globalwt[0]<globalwt[2])
				printf("First Come First Served");
			else if(globalwt[1]<globalwt[0] && globalwt[1]<globalwt[2])
				printf("Shortest Job First");
			else
				printf("Priority");
	}
	
	fcfs();
	sjf(bt,at);
	priority(bt1,at1,p1);
	compare();
	return 0;
}
