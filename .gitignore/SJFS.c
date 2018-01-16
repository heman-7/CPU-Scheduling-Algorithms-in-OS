#include<stdio.h>
#include<stdlib.h>
struct Process{
int burst;
int pid;
} obj[20]={0,0};
int p;
void sel_sort()
{
    int i,t;
    int size=p;
		int small,j;
		for(i=0;i<size;i++)
		{
			small=i;
		for(j=i+1;j<size-1;j++)
		{
			if(obj[small].burst>obj[j].burst)
			{
            small=j;
			}
		}
			t=obj[i].burst;
			obj[i].burst=obj[small].burst;
			obj[small].burst=t;

			t=obj[i].pid;
			obj[i].pid=obj[small].pid;
			obj[small].pid=t;
		}
}

int main()
{
    int i;
    printf("Enter the no. of the processes- ");
    scanf("%d",&p);
        for(i=0;i<p;i++)
    {
        obj[i].pid=i+1;
    }
    for(i=0;i<p;i++)
    {
        printf("\nEnter the burst time(in ms) for process %d: ",i+1);
        scanf("%d",&obj[i].burst);
    }

    sel_sort();
    printf("\nOrder of execution of Processes is: ");
    for(i=0;i<p;i++)
        printf("\nP%d ",obj[i].pid);
    printf("\nProcess\t\tWaiting Time\t\tTurnaround Time");
    int wt[p],tat[p];
    wt[0]=0;
    tat[0]=obj[0].burst;

    float sum_tat=tat[0];
    float sum_wt=wt[0];
    for(i=1;i<p;i++)
    {
        wt[i]=tat[i-1];
        tat[i]=tat[i-1]+obj[i].burst;
        sum_tat+=tat[i];
        sum_wt+=wt[i];
    }
    for(i=0;i<p;i++)
    {
    printf("\nProcess %d\t",obj[i].pid);
    printf("\t%d\t",wt[i]);
    printf("\t%d",tat[i]);
    }
    float avg=sum_wt/p;
    float avg2=sum_tat/p;
    printf("\nAverage Waiting Time Is: %f",avg);
    printf("\nAverage Turnaround Time Is: %f",avg2);
}
