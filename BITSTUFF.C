#include<stdio.h>
int main(){
	int n,i,j=0,count=0;
	int data[100],stuffed[100],destuffed[100];
	int stuffed_length;
	printf("\nEnter number of bits:");
	scanf("%d",&n);
	printf("\nEnter the input bits:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&data[i]);
	}
	printf("Original data:\n");
	for(i=0;i<n;i++)
	{
		printf("%d",data[i]);
	}
	//bit stuffing
	for (i=0;i<n;i++)
	{
		stuffed[j]=data[i];
		if(data[i]==1)
		{
			count++;
			if(count==5)
			{
				j++;
				stuffed[j]=0;
				count=0;
			}
		}
		else{
			count=0;
		}
		j++;
	}
	stuffed_length=j;
	printf("\nStuffed data:\n");
	for(i=0;i<stuffed_length;i++)
	{
		printf("%d",stuffed[i]);
	}
	j=0;
	count=0;
	//destuffing
	for(i=0;i<stuffed_length;i++)
	{
		destuffed[j]=stuffed[i];
		if(stuffed[i]==1)
		{
			count++;
			if(count==5)
			{
				i++;
				count=0;
			}
		}
		else{
		count=0;
		}
		j++;
	}
	printf("\nDestuffed data:\n");
	for(i=0;i<j;i++)
	{
		printf("%d",destuffed[i]);
	}
	return 0;
}