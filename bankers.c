#include<stdio.h>
#include<stdlib.h>
void main(){
	int max[15][15],need[15][15],alloc[15][15],avail[15],completed[15],safeSequence[15];
	int p,r,i,j,process,count;
	count=0;
	printf("Enter the no. of process : ");
	scanf("%d",&p);
	for(i=0;i<p;i++)
		completed[i]=0;
	printf("\n\nEnter the no. of resources : ");
	scanf("%d",&r);
	printf("\n\nEnter the maxmatrix for each process : ");
	for(i=0;i<p;i++){
		printf("\nFor process %d : ",i+1);
		for(j=0;j<r;j++)
			scanf("%d",&max[i][j]);
	}
	printf("\n\nEnter the allocation for each process : ");
	for(i=0;i<p;i++){
		printf("\nFor process %d : ",i+1);
		for(j=0;j<r;j++)
			scanf("%d",&alloc[i][j]);
	}
	printf("\n\nEnter the avaialble resource : ");
	for(i=0;i<r;i++)
		scanf("%d",&avail[i]);
	for(i=0;i<p;i++){
		for(j=0;j<r;j++)
			need[i][j]=max[i][j]-alloc[i][j];
	}
	printf("\nNeed :\n");
	for(i=0;i<p;i++){
		printf(" ");
		for(j=0;j<r;j++)
			printf("%d",need[i][j]);
		printf("\n");
	}
	do{
		printf("\nMax matrix : \t Allocation matrix : \n");
		for(i=0;i<p;i++){
			printf(" ");
			for(j=0;j<r;j++)
				printf("%d",max[i][j]);
			printf("\t\t");
			for(j=0;j<r;j++){
				printf("%d",alloc[i][j]);
			}
			printf("\n");
		}
		process=-1;
		for(i=0;i<p;i++){
			if(completed[i]==0){
				process=i;
				for(j=0;j<r;j++){
					if(avail[j]<need[i][j]){
						process=-1;
						break;
					}
				}
			}
		if(process!=-1)
			break;
		}
		if(process!=-1){
			printf("process %d runs to completion !!",process+1);
			safeSequence[count]=process+1;
			count++;
			for(j=0;j<r;j++){
				avail[j]+=alloc[process][j];
				alloc[process][j]=0;
				max[process][j]=0;
				completed[process]=1;
			}
		}
	}while(count!=p&&process!=-1);
	if(count==p){
		printf("\nThe system is in a safe state !!\n");
		printf("Safe Sequence : <");
		for(i=0;i<p;i++)
			printf(" P%d ",safeSequence[i]);
		printf(">\n");
	}
	else
		printf("The system is not in a safe state!!");	
}

