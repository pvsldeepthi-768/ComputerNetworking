#include<stdio.h>
#include<math.h>
int isPowerOfTwo(int x){
	return x&&!(x&(x-1));
}
int main()
{
	int data[20],hamming[30];
	int dataBits,parityBits=0,totalBits,i,j																																																																																																																											;
	printf("Enter no.of data its:");
	scanf("%d",&dataBits);
	printf("enter data bits(LSB to MSB):");
	for(i=dataBits-1;i>=0;i--)
	{
		scanf("%d",&data[i]);
	}
	while((1<<parityBits)<(dataBits+parityBits+1))
	{
		parityBits++;
	}
	totalBits=dataBits+parityBits;
	j=0;
	for(i=1;i<=totalBits;i++)
	{
		if(isPowerOfTwo(i)){
			hamming[i]=0;
		}
		else{
		hamming[i]=data[j++];
		}
	}
	for(i=0;i<parityBits;i++)
	{
		int p=1<<i;
		int parity=0;
		for(j=1;j<=totalBits;j++)
		{
			if(j&p)
			{
				parity^=hamming[j];
			}
		}
		hamming[p]=parity;
	}
	printf("hamming code (MSB to LSB):");
	for(i=totalBits;i>=1;i--)
	{
		printf("%d",hamming[i]);
	}
	printf("\n");
	return 0;
}