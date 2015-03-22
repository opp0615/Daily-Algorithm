#include <stdio.h>

#pragma warning(disable:4996)

bool areFriend[10][10] = {0};

int countPairings(int n , bool taken[10]);
void areFriendInit();
int main ()
{
	int c;//Test case number
	int n;//Student number
	int m;//friend group number;
	
	int result[50] = {0};

	bool taken[10] = {0};
	

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
			//input is must to be ascending order
			scanf("%d %d",&firstPerson,&secondPerson);

			areFriend[firstPerson][secondPerson] = 1;

		}

		result[i] = countPairings(n,taken);

		areFriendInit();
		

	}


	for(int i=0;i<c;i++)
	{
		printf("%d\n", result[i]);
	}

	return 0;
}


int countPairings(int n, bool taken[10])
{
	int firstFree = -1; 

	for(int i=0;i<n;i++)
	{
		if(!taken[i])
		{
			firstFree = i;
			break;
		}
	}

	if(firstFree == -1)
	{
		return 1;
	}

	int ret =0;


	for(int pairWith = firstFree +1; pairWith < n; pairWith++)
	{
		if(!taken[pairWith] && areFriend[firstFree][pairWith])
		{
			taken[firstFree] = true;
			taken[pairWith] = true;
			ret += countPairings(n,taken);
			taken[firstFree] = false;
			taken[pairWith] = false;

		}
	}
	return ret;

}


void areFriendInit()
{
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			areFriend[i][j] = 0;
		}
	}
}