#include<stdio.h>

int main()
{
	int p[50],a[50],b[50],pr[50],quant,n,i,j;
	float sjf_tat,sjf_wt;
	float p_tat,p_wt;
	float rr_tat,rr_wt;
	
	printf("\nEnter n: ");
	scanf("%d",&n);	
	for(i=0;i<n;i++)
	{
		printf("\n Enter Process id: ");
		scanf("%d",&p[i]);
		printf("Enter Arrival time: ");
		scanf("%d",&a[i]);
		printf("Enter Burst time: ");
		scanf("%d",&b[i]);
		printf("Enter Priority: ");
		scanf("%d",&pr[i]);
	}
	printf("\n\n Enter Quantam:");
	scanf("%d",&quant);

	
	void shortestjobfirst_scheduling(int n,int p[50],int a[50], int b[50],int pr[50])
	{
	int c[50]={0},t=0,d,r[50]={0};
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			//sort
			if(b[i]>b[j])
			{
				d=p[i]; p[i]=p[j]; p[j]=d;
				d=a[i]; a[i]=a[j]; a[j]=d;
				d=b[i]; b[i]=b[j]; b[j]=d;
			}
		}
	for(int i=0;i<n;i++)
	{
		//at
		if(a[i]>t)
		{
			int f=0;
			for(int j=0;j<n;j++)
				if(a[j]<=t && b[j]!=r[j])
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
		if(r[i]==b[i])
			continue;
		
		t+=1;
		if(c[i]==0)
		{
			c[i]=t;
			r[i]+=1;	
		}
		else
		{
			r[i]+=1;
		}
		if(r[i]==b[i])
		{
			c[i]=t;
		}
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
		printf("\n Shortest Job First \n");
		printf("\nProcess\tArrival\tBurst\tPriority\tCompletion\tTurn Around\tWaiting time\n");
		int t_tat=0,t_wt=0;
		float a_tat=0,a_wt=0;
		int w;
		//TAT,WT
		for(i=0;i<n;i++)
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
		printf("\nAverage Turn Around Time: %.2f",a_tat);
		printf("\nAverage Waiting Time: %.2f\n",a_wt);
		sjf_tat=a_tat;
		sjf_wt=a_wt;
	}
	
	void priority_scheduling(int n,int p[50],int a[50], int b[50],int pr[50])
{
	int c[50]={0},t=0,d,r[50]={0},i,j;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if(pr[i]>pr[j])
			{
				d=p[i]; p[i]=p[j]; p[j]=d;
				d=a[i]; a[i]=a[j]; a[j]=d;
				d=b[i]; b[i]=b[j]; b[j]=d;
				d=pr[i]; pr[i]=pr[j]; pr[j]=d;
			}
	for(i=0;i<n;i++)
	{
		//at
		if(a[i]>t)
		{
			int f=0;
			for(j=0;j<n;j++)
				if(a[j]<=t && b[j]!=r[j])
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
		if(r[i]==b[i])
			continue;
		
		t+=1;
		if(c[i]==0)
		{
			c[i]=t;
			r[i]+=1;	
		}
		else
		{
			r[i]+=1;
		}
		if(r[i]==b[i])
		{
			c[i]=t;
		}
		i=-1;
	}
	//sort
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
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
		printf("\nPriority Scheduling");
		printf("\nProcess\tArrival\tBurst\tPriority\tCompletion\tTurn Around\tWaiting time\n");
		int t_tat=0,t_wt=0;
		float a_tat=0,a_wt=0;
		int w;
		//TAT,WT
		for(i=0;i<n;i++)
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
		printf("\nAverage Turn Around Time: %.2f",a_tat);
		printf("\nAverage Waiting Time: %.2f\n",a_wt);
		p_tat=a_tat;
		p_wt=a_wt;
}
	
	void roundrobin_scheduling(int n,int pid[50],int arr[50], int burst[50],int pr[50],int quant)
	{
		int queue[50][50],pid_temp[50],burst_temp[50],arr_temp[50],temp=0;
		
		for(i=0;i<n;i++)
		{
			pid_temp[i]=pid[i];
			burst_temp[i]=burst[i];
			arr_temp[i]=arr[i];
		}
		
		//sort
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(arr_temp[j]<arr_temp[i])
				{
					temp=arr_temp[i];
					arr_temp[i]=arr_temp[j];
					arr_temp[j]=temp;
					
					/*temp=burst[i];
					burst[i]=burst[j];
					burst[j]=temp;*/
					
					temp=pid_temp[i];
					pid_temp[i]=pid_temp[j];
					pid_temp[j]=temp;
					
					
				}
			}
		}
		int sizec=0,sizec1=0,sizer=0;
		int notadded=0;
		for(i=0;i<n;i++)
		{
			if(quant>arr_temp[i])
			{
				queue[sizer][sizec++]=pid_temp[i];
			}
			//incase quant lt arrtime should not add immediately
			else{
				notadded=i;
				break;
			}
			//printf("%d\n",queue[sizer][sizec-1]);
		}
		
		sizer++;
		int ttime=0,queue_empty=0;
		int comp_t[50],flag=1;
		while(flag!=0)
		{
			for(i=0;i<sizec;i++)
			{
				//printf("\nInteraion:\n");
				if(burst_temp[i]-quant<=0)
				{
					
					ttime+=burst_temp[i];
					burst_temp[i]=0;
					comp_t[queue[sizer-1][i]]=ttime;
					//has proces id of compleged process
					
					//incase arrival time greater than time quantam add now

					if(ttime>arr_temp[notadded] && notadded<n)
					{
						queue[sizer][sizec1++]=pid_temp[notadded];
						notadded++;
					}
				}
				else
				{
					ttime+=quant;
					burst_temp[queue[sizer-1][i]]-=quant;
					
					//printf("Process:%d\n",queue[sizer-1][i]);
					//printf("BT:%d\n",burst_temp[queue[sizer-1][i]]);
					//incase arrival time greater than time quantam add now
					if(ttime>arr_temp[notadded] && notadded<n)
					{
						queue[sizer][sizec1++]=pid_temp[notadded];
						notadded++;
					}
					
					queue[sizer][sizec1++]=queue[sizer-1][i];
					

					
					queue_empty++;
				}

			}
				sizec=sizec1;
				sizec1=0;
				sizer++;
			if(queue_empty==0)
			{
				flag=0;
				break;
			}
			queue_empty=0;
		}
		
		
	//display
			printf("\n ROUND ROBIN \n");
		printf("\nProcess\tArrival\tBurst\tCompletion\tTurn Around\tWaiting time\n");
		int t_tat=0,t_wt=0;
		float a_tat=0,a_wt=0;
		int t;
		int w;
		//TAT,WT
		for(i=0;i<n;i++)
		{
		   t=comp_t[i]-arr[i];
		   w=t-burst[i];
	       t_tat+=t;
		   t_wt+=w;
		   printf("\n%d\t %d\t %d\t %d\t\t %d\t\t %d",pid[i],arr[i],burst[i],comp_t[i],t,w);
		}
		printf("\n\nTotal Turn Around Time: %d",t_tat);
		printf("\nTotal Waiting Time: %d",t_wt);
		a_tat=(float)t_tat/n;
		a_wt=(float)t_wt/n;
		printf("\nAverage Turn Around Time: %.2f",a_tat);
		printf("\nAverage Waiting Time: %.2f\n",a_wt);
		rr_tat=a_tat;
		rr_wt=a_wt;
	}
	
	void compare()
	{
		printf("\n\nComparison:\n");
		printf("Algorithm\tTurn Around Time\tWaiting Time");
		printf("\n SJF\t\t %f\t\t %f",sjf_tat,sjf_wt);
		printf("\n Priority\t %f\t\t %f",p_tat,p_wt);
		printf("\n Round Robin\t %f\t\t %f",rr_tat,rr_wt);
		printf("\n\nPreferred algorithm(based on waiting time): ");
		if(rr_wt<sjf_wt && rr_wt<p_wt)
			printf("Round Robin");
		else if(sjf_wt<rr_wt && sjf_wt<p_wt)
			printf("Shortest Job First");
		else
			printf("Priority");
	}
	
	priority_scheduling(n,p,a,b,pr);
	shortestjobfirst_scheduling(n,p,a,b,pr);
	roundrobin_scheduling(n,p,a,b,pr,quant);
	compare();

}
