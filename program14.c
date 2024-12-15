#include<stdio.h>
int main()
{
 	int n,m;
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	printf("Enter the number of resources: ");
	scanf("%d",&m);
	int available[m];
	printf("Enter the quantity of %d resources:\n",m);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&available[i]);
	}
	int allocation[n][m];
	printf("Enter the quantity of  each resource allocated to each process:\n");
	for(int i=0;i<n;i++)
	{
		printf("For Process %d:\n",i);
		for(int j=0;j<m;j++)
		{
			scanf("%d",&allocation[i][j]);
		}
	}
	int max[n][m];
	printf("Enter the quantity of maximum number of each resource to be allocated to each process:\n");
	for(int i=0;i<n;i++)
	{
		printf("For Process %d:\n",i);
		for(int j=0;j<m;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
	int need[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			need[i][j]=max[i][j]-allocation[i][j];
		}
	}
	int demo[m];
	for(int j=0;j<m;j++)
	{
		demo[j]=0;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			demo[j]+=allocation[i][j];
		}
	}
	for(int j=0;j<m;j++)
	{
		available[j]=available[j]-demo[j];
	}
	int finish[n];
	int ind=0;
	int ans[n];
	for (int k = 0; k < 5; k++) {
        for (int i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int flag = 0;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > available[j]){
                        flag = 1;
                         break;
                    }
                }

                if (flag == 0) {
                    ans[ind++] = i;
                   for (int y = 0; y < m; y++)
                        available[y] += allocation[i][y];
                    finish[i] = 1;
                }
            }
        }
    }
      int flag = 1; 
      for(int i=0;i<n;i++)
    {
      if(finish[i]==0)
      {
        flag=0;
         printf("The following system is not safe");
        break;
      }
    }
      if(flag==1)
    {
      printf("Following is the SAFE Sequence\n");
      for (int i = 0; i < n - 1; i++)
        printf(" P%d ->", ans[i]);
      printf(" P%d", ans[n - 1]);
    }
}
