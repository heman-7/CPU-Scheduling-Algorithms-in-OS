#include<stdio.h>
#include<stdlib.h>
struct process{
int burst,wt,tat;
int start_time,end_time;
} proc[20]={0,0};
int p;

void input()
{
int i;
for(i=0;i<p;i++)
{
printf("Enter the burst time of process %d:",i+1);
scanf("%d",&proc[i].burst);
}
for(i=0;i<p;i++)
{
printf("Process %d\t",i+1);
}
printf("\n");
for(i=0;i<p;i++)
{
printf("%d\t\t",proc[i].burst);
}
printf("\n");
}

void calculate(int timeq)
{
int i,j;
int total_time=0;
//initialise
for(i=0;i<p;i++)
{
proc[i].wt=0;
proc[i].tat=0;
proc[i].end_time=0;
proc[i].start_time=0;
}
for(i=0;i<p;i++)
{
proc[i].tat+=proc[i].burst;
}
//
//displaying iteration
for(j=0;j<2*p;j++)
{
printf("\nIteration %d\n",j+1);

for(i=0;i<p;i++)
{
/*if(proc[i].burst==0)
{

}*/
if(proc[i].burst==0)
{
continue;
}
else if(proc[i].burst>=timeq)
{
proc[i].burst=proc[i].burst-timeq;
printf("Process %d:%d",i+1,proc[i].burst);
printf("\t");
proc[i].wt=total_time-proc[i].end_time;
proc[i].start_time=total_time;
proc[i].end_time+=timeq;
total_time+=timeq;
}
else
{
proc[i].wt=total_time-proc[i].end_time;
proc[i].start_time=total_time;
proc[i].end_time+=proc[i].burst;
total_time+=proc[i].burst;
proc[i].burst=0;
printf("Process %d:%d",i+1,proc[i].burst);
printf("\t");
}
}
//terminating condition
int flag=0;
for(i=0;i<p;i++)
{
if(proc[i].burst==0)
flag++;
}
if(flag==p)
{
printf("\nAll processes have Completed their burst time Exiting....\n");
printf("\nTotal Time Is:%d\n",total_time);
//exit(0);
break;
}
//
}
for(i=0;i<p;i++)
{
    proc[i].tat+=proc[i].wt;
}
}

void output()
{
int i;
int sumWaiting=0;
int avgWaiting=0;
int sumTurn=0;
int avgTurn=0;
printf("\nWaiting Time\n");
for(i=0;i<p;i++)
printf("Process %d:%d \t",i+1,proc[i].wt);
for(i=0;i<p;i++)
sumWaiting+=proc[i].wt;
printf("\nSum Waiting Time:%d",sumWaiting);
avgWaiting=sumWaiting/p;
printf("\nAverage Waiting Time:%d",avgWaiting);
printf("\nTurnaround Time\n");
for(i=0;i<p;i++)
printf("Process %d:%d \t",i+1,proc[i].tat);
for(i=0;i<p;i++)
sumTurn+=proc[i].tat;
printf("\nSum TA Time:%d",sumTurn);
avgTurn=sumTurn/p;
printf("\nAverage Turnaround Time:%d",avgTurn);
}

void main()
{
printf("Enter the no. of process:");
scanf("%d",&p);
input();
int timeq;
printf("Enter the time quantum\n");
scanf("%d",&timeq);
calculate(timeq);
output();
}
