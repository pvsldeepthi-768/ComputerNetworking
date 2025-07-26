#include<stdio.h>
#include<string.h>
unsigned short computeCRC(const char *data,int poly, int crcWidth){
	unsigned short crc=0;
	int i,j;
	for(i=0;data[i];i++){
		crc^=(data[i]<<(crcWidth-8));
		for(j=0;j<8;j++)
		{
			if(crc&(1<<(crcWidth-1)))
				crc=(crc<<1)^poly;
			else
				crc<<=1;
		}
	}
	return crc&((1<<crcWidth)-1);
}
int main()
{
	unsigned short crc12,crc16,crcccit;
	char input[100];
	printf("enter input data:");
	scanf("%s",input);
	crc12=computeCRC(input,0x180F,12);
	crc16=computeCRC(input,0x8005,16);
	crcccit=computeCRC(input,0x1021,16);
	printf("CRC-12=%03X\n",crc12);
	printf("CRC-16=%04X\n",crc16);
	printf("CRC-CCIT=%04x\n",crcccit);
	return 0;
}