#include<stdio.h>
int main()
{
int n;
printf("Enter the number of processes: ");
scanf("%d",&n);
int p[n],bt[n],wt[n],tat[n],pr[n];
printf("Enter the priority of  %d processes: ", n);
for(int i=1;i<=n;i++)
{
scanf("%d",&pr[i]);
}
printf("Enter the burt time of  %d processes: ", n);
for(int i=1;i<=n;i++)
{
p[i]=i;
scanf("%d",&bt[i]);
}

int temp;
for(int i=1;i<=n;i++)
{
for(int k=i+1;k<=n;k++)
{
if(pr[i]>pr[k])
{
temp=pr[i];
pr[i]=pr[k];
pr[k]=temp;
temp=bt[i];
bt[i]=bt[k];
bt[k]=temp;
temp=p[i];
p[i]=p[k];
p[k]=temp;
}
}
}
wt[1]=0;
for(int i=2;i<=n;i++)
{
wt[i] = wt[i-1] +bt[i-1];
}

for(int i=1;i<=n;i++)
{
tat[i] = wt[i] +bt[i];
}
for (int  i=1; i<=n; i++)
{
printf("Process %d   %d   %d   %d\n",p[i],bt[i],wt[i],tat[i]);
}
}
