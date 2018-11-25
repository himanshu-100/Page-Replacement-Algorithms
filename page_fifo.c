#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
int main()
{
	srand(time(NULL));
	int a[15];
	for(int i=0;i<15;i++)
	{
		a[i]=1+rand()%5;
	}
	printf("Reference string is-\n");
	for(int i=0;i<15;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	int b[3];
	for(int i=0;i<3;i++)
	{
		b[i]=0;
	}
	int cnt=0;
	for(int i=0;i<15;i++)
	{
		int f=0;
		for(int j=0;j<3;j++)
		{
			if(b[j]==a[i])
			{
				f=1;
			}
		}
		if(f==0)
		{
			b[i%3]=a[i];
			cnt++;
		}
		for(int j=0;j<3;j++)
		{
			printf("%d ",b[j]);
		}printf("\n");
		sleep(0.5);
	}
	printf("Number of page faults occured - %d\n",cnt);
	return 0;
}