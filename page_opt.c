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
	int t[3];
	for(int i=0;i<15;i++)
	{
		int f=0,g=0,ind;
		for(int j=0;j<3;j++)
		{
			if(b[j]==0)
			{
				g=1;
				ind=j;
				break;
			}
		}
		if(g==1)				//empty page available
		{
			for(int j=0;j<3;j++)
			{
				if(b[j]==a[i])
				{
					f=1;
				}
			}
			if(f==0)
			{
				b[ind]=a[i];
				for(int j=0;j<3;j++)
				{
					printf("%d ",b[j]);
				}printf("\n");
				sleep(1);
				cnt++;
			}
		}
		else					//all pages filled
		{
			for(int j=0;j<3;j++)
			{
				if(b[j]==a[i])
				{
					f=1;
				}
			}
			if(f==0)			//f=1 means page already exists else page replacement
			{
				cnt++;
				for(int j=0;j<3;j++)
				{
					t[j]=100;
				}
				for(int j=i+1;j<15;j++)
				{
					if(a[j]==b[0])
					{
						t[0]=j;
						break;
					}
				}
				for(int j=i+1;j<15;j++)
				{
					if(a[j]==b[1])
					{
						t[1]=j;
						break;
					}
				}
				for(int j=i+1;j<15;j++)
				{
					if(a[j]==b[2])
					{
						t[2]=j;
						break;
					}
				}
				int index,max=t[0];
				for(int j=0;j<3;j++)
				{
					if(t[j]>=max)
					{
						max=t[j];
						index=j;
					}
				}
				b[index]=a[i];
			}
			for(int j=0;j<3;j++)
			{
				printf("%d ",b[j]);
			}printf("\n");
			sleep(1);
		}
	}
	printf("Number of page faults occured - %d\n",cnt);
	return 0;
}