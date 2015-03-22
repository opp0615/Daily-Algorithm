/*
#include<stdio.h>

char testBlock[20][20] = {0};

void InputingTestBlock(int h,int w);
void InitTestBlock();
int SearchingLBlock(int h,int w);


int main()
{
	int c = 0;
	int h,w = 0;
	int result[30] = {0};

	scanf_s("%d",&c);


	for(int i=0;i<c;i++)//inputing test cases
	{
		scanf_s("%d %d",&h,&w);
		InputingTestBlock(h,w);
		result[i] = SearchingLBlock(h,w);
		InitTestBlock();

	}


	for(int i=0;i<c;i++)//printing test cases
	{
		printf("%d\n",result[i]);
	}
	return 0;
}

void InputingTestBlock(int h,int w)
{
	char input ; 
	for(int i =0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			scanf_s("%c",&input,1);
			testBlock[i][j] = input  ;
		}
	}

}

void InitTestBlock()
{
	for(int i =0;i<20;i++)
	{
		for(int j=0;j<20;j++)
		{
			testBlock[i][j] = 0 ;
		}
	}
}

int SearchingLBlock(int h, int w)
{
	bool detectionSuccess = false;

	
	int ret = 0;

	for(int i =0;i<h;i++)
	{
		for(int j=0; j<w ; j++)
		{

			if(testBlock[i][j] == '.')//If Block is White Block
			{
				if(testBlock[i+1][j] == '.' && testBlock[i+1][j+1] =='.')//¤¤
				{
					testBlock[i][j] = testBlock[i+1][j] = testBlock[i+1][j+1] = '#';
					ret+=SearchingLBlock(h,w);
					testBlock[i][j] = testBlock[i+1][j] = testBlock[i+1][j+1] = '.';
				}

				if(testBlock[i][j+1] == '.' && testBlock[i+1][j+1] =='.')//¤¡
				{
					testBlock[i][j] = testBlock[i][j+1] = testBlock[i+1][j+1] = '#';
					ret+=SearchingLBlock(h,w);
					testBlock[i][j] = testBlock[i][j+1] = testBlock[i+1][j+1] = '.';
				}

				if(testBlock[i+1][j] == '.' && testBlock[i][j+1] =='.')//¡¸
				{
					testBlock[i][j] = testBlock[i+1][j] = testBlock[i][j+1] = '#';
					ret+=SearchingLBlock(h,w);
					testBlock[i][j] = testBlock[i+1][j] = testBlock[i][j+1] = '.';
				}
				if(testBlock[i+1][j] == '.' && testBlock[i+1][j-1] =='.')// ¡¹
				{
					testBlock[i][j] = testBlock[i+1][j] = testBlock[i+1][j-1] = '#';
					ret+=SearchingLBlock(h,w);
					testBlock[i][j] = testBlock[i+1][j] = testBlock[i+1][j-1] = '.';
				}

				return 0;
			}

		}
	}

	return 1;
}

*/