#include<stdio.h>
#include<string.h>
#include<math.h>
int binaryToDecimal(char *bin){
int i,value=0;
for(i=0;bin[i]!='\0';i++)
{
value=value*2+(bin[i]-'0');
}
return value;
}
int main(){
	int checksum,n,sum=0,i;
	char binary[10];
	int data[100];
	printf("Enter no.of binary data bytes:");
	scanf("%d",&n);
	printf("Enter each byte(8-binary,e.g,10110111):\n");
	for(i=0;i<n;i++)
	{
		printf("Byte %d:",i+1);
		scanf("%s",binary);
		data[i]=binaryToDecimal(binary);
		sum+=data[i];
	}
	while(sum>255){
		sum=(sum & 0xFF)+(sum>>8);
	}
	checksum=~sum&0xFF ;
	printf("\n Checksum (Decimal):%d\n",checksum);
	printf("checksum(binary):");
	for(i=7;i>=0;i--)
	{
		printf("%d",(checksum>>i)&1);
	}
	printf("\n");
	sum+=checksum;
	while(sum>255)
	{
		sum=(sum&0xFF)+(sum>>8);
	}
	if(sum==0xFF)
		printf("Data is correct\n");
	else
		printf("Data is incorrect\n");
	return 0;
}