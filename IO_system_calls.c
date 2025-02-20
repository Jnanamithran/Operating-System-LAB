#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
struct dirent*dptr;
int main(int age,char *argv[])
{
	char buff[256];
	DIR*dirp;
	printf("\n\nEnter directory name :");
	scanf("%s",buff);
	if((dirp=opendir(buff))==NULL)
	{
		printf("Error");
		exit(1);
	}
	while(dptr=readdir(dirp))
	{
		printf("%s\n",dptr->d_name);
	}
	closedir(dirp);
	printf("Show the present working directory : \n");
	execlp("/bin/pwd","pwd",NULL);
}
