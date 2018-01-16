#include<stdio.h>
int main()
{
    int p,i;
    printf("Enter the no. of the processes- ");
    scanf("%d",&p);
    int b[p];
    for(i=0;i<p;i++)
    {
        printf("\nEnter the burst time(in ms) for process %d: ",i+1);
        scanf("%d",&b[i]);
    }

    printf("\nProcess\t");
    printf("\tWaiting Time\t");
    printf("\tTurnaround Time");
    int w[p],tat[p];
    w[0]=0;
    tat[0]=b[0];
    float sum_tat=tat[0];
    float sum_wt=w[0];
    for(i=1;i<p;i++)
    {
        w[i]=tat[i-1];
        tat[i]=tat[i-1]+b[i];
        sum_tat+=tat[i];
        sum_wt+=w[i];
    }
    for(i=0;i<p;i++)
    {
    printf("\nProcess %d\t",i+1);
    printf("\t%d\t",w[i]);
    printf("\t%d",tat[i]);
    }
    float avg=sum_wt/p;
    float avg2=sum_tat/p;
    printf("\nAverage Waiting Time Is: %f",avg);
    printf("\nAverage Turnaround Time Is: %f",avg2);
}
