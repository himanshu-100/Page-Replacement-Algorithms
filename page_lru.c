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
	int t[6];
	for(int i=0;i<6;i++)
	{
		t[i]=0;
	}
	t[0]=-1;
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
			//b[i%3]=a[i];
			cnt++;
			int index;
			int min=100;
			for(int j=0;j<3;j++)
			{
				if(t[b[j]]<min)
				{
					min=t[b[j]];
					index=j;
				}
			}
			b[index]=a[i];
			t[a[i]]=i;
		}
		for(int j=0;j<3;j++)
		{
			printf("%d ",b[j]);
		}printf("\n");
		sleep(1);
	}
	printf("Number of page faults occured - %d\n",cnt);
	return 0;
}