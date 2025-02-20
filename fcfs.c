#include <stdio.h>
//#include <conio.h>
void main()
{
	int bt[20],wt[20],tat[20],i,n;
	float wtavg,tatavg;
	printf("\nEter the number of process : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter Burst time for process %d : ",i);
		scanf("%d",&bt[i]);
	}
	wt[0]=wtavg=0;
	tat[0]=tatavg=bt[0];
	for(i=1;i<n;i++)
	{
		wt[i]=wt[i-1]+bt[i-1];
		tat[i]=tat[i-1]+bt[i];
		wtavg=wtavg+wt[i];
		tatavg=tatavg+tat[i];
	}
	printf("\tPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
	wtavg=wtavg/n;
	tatavg=tatavg/n;
	//to print the table
	for(i=0;i<n;i++)
	{
		printf("\n\tP%d\t\t%d\t\t%d\t\t%d",i,bt[i],wt[i],tat[i]);
	}
	printf("\n Average Waiting Time : %f",wtavg);
	printf("\n Average Turnaround Time : %f",tatavg);
	getchar();
}
