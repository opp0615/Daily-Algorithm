#include<stdio.h>
#include<stdlib.h>


int searchSecondOne(int arry[],int size);

int callTimes = 0;//È£Ãâ È½¼ö
int global_n=0;

int main()
{
	int n=0;
	
	int result=0;
	scanf("%d",&n);

	int* arry = (int*)malloc(sizeof(int)*n);

	for(int i=0;i<n;i++)
	{
		scanf("%d",&arry[i]);
	}
	global_n = n;
	result = searchSecondOne(arry,n);
	

	printf("%d %d",result,callTimes);



	free(arry);

	return 0;
}

int searchSecondOne(int* arry, int size)
{
	callTimes++;

	if(size == 1)
	{
		return arry[0];
	}

	int leftOne=0,rightOne=0;
	int leftSize=0,rightSize=0;
	int i=0,j=0;

	if(size%2 == 0)//Â¦¼ö
	{
		leftSize = size/2;
		rightSize = size/2;
	}

	else//È¦¼ö
	{
		leftSize = (size+1)/2;
		rightSize = (size-1)/2;
	}

	int* leftArry = (int*)malloc(sizeof(int)*leftSize);
	int* rightArry = (int*)malloc(sizeof(int)*rightSize);



	for(i=0;i<leftSize;i++)
	{
		leftArry[i] = arry[i];
	}
	
	for(j=0;j<rightSize;j++)
	{
		rightArry[j] = arry[i+j];
	}


	leftOne = searchSecondOne(leftArry,leftSize);
	rightOne = searchSecondOne(rightArry,rightSize);

	free(leftArry);
	free(rightArry);

	if(size == global_n)
	{
		return leftOne < rightOne ? leftOne : rightOne;
	}


	return leftOne > rightOne ? leftOne : rightOne;
}