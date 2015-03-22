/*#include <stdio.h>

#pragma warning(disable:4996)



struct Group
{
	int g_firstPerson;
	int g_secondPerson;
};

int Grouping(int n , int m, Group friendGroup[]);

int main()
{
	int c;//Test case number
	int n;//Student number
	int m;//friend group number;
	
	int result = 0;

	Group friendGroup[45];

	printf("Input Test Case Number : ");
	scanf("%d", &c);

	//Test case repetitive struct
	for(int i=0;i<c;i++)
	{
		scanf("%d %d",&n , &m); // input Student number & group number
		
		for(int j = 0; j< m; j++)
		{
			int firstPerson;
			int secondPerson;

			scanf("%d %d",&firstPerson,&secondPerson);

			friendGroup[j].g_firstPerson = firstPerson;
			friendGroup[j].g_secondPerson = secondPerson;

		}

	}

	result = Grouping(n,m,friendGroup);

	return 0;
}

int Grouping(int n , int m, Group friendGroup[])
{
	int result =0;

	for(int i=0;i<m;i++)
	{
		printf("%d : %d %d \n",i,friendGroup[i].g_firstPerson,friendGroup[i].g_secondPerson);

	}

	Group testGroup[5];

	for(int i=0; i<n/2 ; i++)
	{
		testGroup[i].g_firstPerson = i;
		testGroup[i].g_secondPerson = i+1;
	}


	return result;
}

*/