#include<stdio.h>
void main(){
	int track[20],n,head,i,s=0;
	float avg;
	printf("\n Enter num of tracks : ");
	scanf("%d",&n);
	printf("\nEnter tracks : ");
	for(i=1;i<=n;i++){
		scanf("%d",&track[i]);
	}
	printf("\nEnter the inital head position : ");
	scanf("%d",&head);
	track[0]=head;
	printf("\ntrack\t\thead movement");
	for(i=0;i<=n-1;i++){
		track[i]=(track[i+1]-track[i]);
		if(track[i]<0)
			track[i]*=(-1);
		printf("\n%d\t\t%d",track[i+1],track[i]);
		s+=track[i];
	}
	printf("\nTotal head movement : %d ",s);
	avg=s/(float)n;
	printf("\nAverage head movement : %f",avg);
}
	
