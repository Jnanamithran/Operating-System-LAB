#include<stdio.h>
#define max 25
void main(){
	int frag[max],b[max],f[max],i,j,nb,nf,temp,highest=0;
	static int bf[max],ff[max];
	printf("\nMemorry management scheme - WORST FIT.....");
	printf("\nEnter the number of block : ");
	scanf("%d",&nb);
	printf("\nEnter the number of files :");
	scanf("%d",&nf);
	printf("\nEnter the size of the blocks : \n");
	for(i=1;i<=nb;i++){
		printf("Block %d :",i);
		scanf("%d",&b[i]);
	}
	printf("\nEnter the size of the files : \n");
	for(i=1;i<=nf;i++){
		printf("File %d : ",i);
		scanf("%d",&f[i]);
	}
	for(i=1;i<=nf;i++){
		for(j=1;j<=nb;j++){
			if(bf[j]!=1){
				temp=b[j]-f[i];
				if(temp>=0){
					if(highest<temp){
						ff[i]=j;
						highest=temp;
					}
				}
			}
		}
		frag[i]=highest;
		bf[ff[i]]=1;
		highest=0;
	}
	printf("\nFile_no. : \t File_size : \t Block_no. : \t Block_size: \tFragment :");
	for(i=1;i<=nf;i++){
		if(ff[i]!=0)
			printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,f[i],ff[i],b[ff[i]],frag[i]);
		else 
			printf("\n%d\t\t%d\t\tNot Allocated",i,f[i]);
	}
	printf("\n");
}
			
