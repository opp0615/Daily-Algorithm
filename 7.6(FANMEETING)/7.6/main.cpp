#include <stdio.h>

int main()
{
	
	int c=0;// test case

	int result[20];

	char singer[200000];
	char fan[200000];
	
	char tempEnter;

	scanf("%d",&c);
	getchar(); // input 'Enter'

	for(int i=0;i<c;i++)
	{
		gets(singer);
		gets(fan);

		result[i] = FindHowHuging(singer,fan);

	}

	for(int i=0;singer[i]!='\0';i++)
	{
		printf("%c",singer[i]);
	}

	printf("\n");

	for(int i=0;fan[i]!='\0';i++)
	{
		printf("%c",fan[i]);
	}

	return 0;
}

int FindHowHuging(char singer[], char fan[])
{
	int countHug;

}