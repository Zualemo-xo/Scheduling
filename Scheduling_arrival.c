#include<stdio.h>

float fcfs_tat,fcfs_wt;
float sjf_tat,sjf_wt;
float pr_tat,pr_wt;
void display_table(int n,int p[50],int a[50],int b[50],int pr[50],int c[50],int s)
{
	printf("\nProcess\tArrival\tBurst\tPriority\tCompletion\tTurn Around\tWaiting time\n");
	for(int i=0;i<85;i++)
		printf("-");
	int t_tat=0,t_wt=0;
	float a_tat=0,a_wt=0;
	int t,w;
	for(int i=0;i<n;i++)
	{
	   t=c[i]-a[i];
	   w=t-b[i];
       t_tat+=t;
	   t_wt+=w;
	   printf("\n%d\t %d\t %d\t %d\t\t %d\t\t %d\t\t %d",p[i],a[i],b[i],pr[i],c[i],t,w);
	}
	printf("\n\nTotal Turn Around Time: %d",t_tat);
	printf("\nTotal Waiting Time: %d",t_wt);
	a_tat=(float)t_tat/n;
	a_wt=(float)t_wt/n;
	printf("\nAverage Turn Around Time: %f",a_tat);
	printf("\nAverage Waiting Time: %f\n",a_wt);
	if(s==1)
	{
		fcfs_tat=a_tat;
		fcfs_wt=a_wt;
	}
	if(s==2)
	{
		sjf_tat=a_tat;
		sjf_wt=a_wt;
	}
	if(s==3)
	{
		pr_tat=a_tat;
		pr_wt=a_wt;
	}
}
void comparison()
{
	printf("\n\nComparison Study:-\n");
	printf("Algorithm\tTurn Around Time\tWaiting Time");
	printf("\n FCFC\t\t %f\t\t %f",fcfs_tat,fcfs_wt);
	printf("\n SJF\t\t %f\t\t %f",sjf_tat,sjf_wt);
	printf("\n Priority\t %f\t\t %f",pr_tat,pr_wt);
	printf("\n\nPreferred algorithm(based on waiting time): ");
	if(fcfs_wt<sjf_wt && fcfs_wt<pr_wt)
		printf("First Come First Served");
	else if(sjf_wt<fcfs_wt && sjf_wt<pr_wt)
		printf("Shortest Job First");
	else
		printf("Priority");
}
void fcfs_scheduling(int n,int p[50],int a[50], int b[50],int pr[50])
{
	int c[50]={0},t=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]>t)
		{
			t+=1;
			i--;
			continue;
		}
		t+=b[i];
		c[i]=t;
	}
	printf("\nFirst Come First Served Scheduling:-");
	display_table(n,p,a,b,pr,c,1);
}
void sjf_scheduling(int n,int p[50],int a[50], int b[50],int pr[50])
{
	int c[50]={0},t=0,d;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			if(b[i]>b[j])
			{
				d=p[i]; p[i]=p[j]; p[j]=d;
				d=a[i]; a[i]=a[j]; a[j]=d;
				d=b[i]; b[i]=b[j]; b[j]=d;
			}
		}
	for(int i=0;i<n;i++)
	{
		if(a[i]>t)
		{
			int f=0;
			for(int j=0;j<n;j++)
				if(a[j]<=t && c[j]==0)
				{
					i=j-1;
					f=1;
					break;
				}
			if(f==0)
			{
				t+=1;
				i--;
			}
			continue;
			
		}
		if(c[i]!=0)
			continue;
		
		t+=b[i];
		c[i]=t;
		i=-1;
	}
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			if(p[i]>p[j])
			{
				d=p[i]; p[i]=p[j]; p[j]=d;
				d=a[i]; a[i]=a[j]; a[j]=d;
				d=b[i]; b[i]=b[j]; b[j]=d;
				d=c[i]; c[i]=c[j]; c[j]=d;
			}
		}
	printf("\nShortest Job First Scheduling:-");
	display_table(n,p,a,b,pr,c,2);
}
void pr_scheduling(int n,int p[50],int a[50], int b[50],int pr[50])
{
	int c[50]={0},t=0,d;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(pr[i]>pr[j])
			{
				d=p[i]; p[i]=p[j]; p[j]=d;
				d=a[i]; a[i]=a[j]; a[j]=d;
				d=b[i]; b[i]=b[j]; b[j]=d;
				d=pr[i]; pr[i]=pr[j]; pr[j]=d;
			}
	for(int i=0;i<n;i++)
	{
		if(a[i]>t)
		{
			int f=0;
			for(int j=0;j<n;j++)
				if(a[j]<=t && c[j]==0)
				{
					i=j-1;
					f=1;
					break;
				}
			if(f==0)
			{
				t+=1;
				i--;
			}
			continue;
			
		}
		if(c[i]!=0)
			continue;
		
		t+=b[i];
		c[i]=t;
		i=-1;
	}
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			if(p[i]>p[j])
			{
				d=p[i]; p[i]=p[j]; p[j]=d;
				d=a[i]; a[i]=a[j]; a[j]=d;
				d=b[i]; b[i]=b[j]; b[j]=d;
				d=c[i]; c[i]=c[j]; c[j]=d;
				d=pr[i]; pr[i]=pr[j]; pr[j]=d;
			}
		}
	printf("\nPriority Scheduling:-");
	display_table(n,p,a,b,pr,c,3);
}

int main()
{
	int p[50],a[50],b[50],pr[50],n;
	printf("PROCESS SCHEDULING (with arrival time)\n");
	printf("\nEnter n: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("\nProcess id: ");
		scanf("%d",&p[i]);
		printf("Arrival time: ");
		scanf("%d",&a[i]);
		printf("Burst time: ");
		scanf("%d",&b[i]);
		printf("Priority: ");
		scanf("%d",&pr[i]);
	}
	fcfs_scheduling(n,p,a,b,pr);
	sjf_scheduling(n,p,a,b,pr);
	pr_scheduling(n,p,a,b,pr);
	comparison();
}
