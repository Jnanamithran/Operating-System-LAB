#include <stdio.h>
#include <stdlib.h>
int mutex=1,full=0,empty=3,x=0;
int main(){
	int n;
	void producer();
	void consumer();
	int wait(int);
	int signal(int);
	printf("\n1.Producer \n 2.Consumer \n 3.Exit");
	while(1){
		printf("\n\nEnter your choice : ");
		scanf("%d",&n);
		printf("%d",n);
		
		switch(n){
			case 1 : if((mutex==1)&&(empty!=0))
					producer();
				    else 
				    	printf("\n\nBuffer is FULL !");
			break;
			case 2 : if((mutex==1)&&(full!=0))
				   	consumer();
				   else 
				   	printf("\n\nBuffer is EMPTY !");
		   	break;
		   	case 3 : printf("\nExit");
	   			   exit(0);
   			break;
		}
	}
	return 0;
}

int wait(int s){
	return(--s);
}

int signal(int s){
	return(++s);
}

void producer(){
	mutex=wait(mutex);
	full=signal(full);
	empty=wait(empty);
	x++;
	printf("\n\nProducer produces the item %d",x);
	mutex=signal(mutex);
}

void consumer(){
	mutex=wait(mutex);
	full=wait(full);
	empty=signal(empty);
	printf("\n\nConsumer consumes item %d",x);
	x--;
	mutex=signal(mutex);
}				   	
