#include <stdio.h>
#include <vector>

using namespace std;

void InitSwitchSet(vector <vector<int>>&switchSet);
void Test(vector <vector<int>>&switchSet , int clockSet[][4]);
int SearchingButtonNumber(vector <vector<int>>&switchSet , int clockSet[][4],int switchNumber);
void pushSwitch(vector <vector<int>>&switchSet ,int clockSet[][4],int switchNumber);

const int INF = 9999;

int main()
{
	int c;//test case
	int clockSet[4][4] ={0}; //clock set
	int logicBox[10] = {0};
	int result[30];
	vector<vector<int>> switchSet;

	InitSwitchSet(switchSet);

	/*
	for(int i=0;i<switchSet.size();i++)
	{
	for(int j=0;j<switchSet[i].size();j++)
	{
	printf("%d ",switchSet[i][j]);
	}
	printf("\n");
	}
	*/

	scanf_s("%d",&c);

	for(int m=0;m<c;m++)//test case repetitive struct
	{
		for(int i=0;i<4;i++)//inputing clock data
		{
			for(int j=0;j<4;j++)
			{
				scanf_s("%d",&clockSet[i][j]);
			}
		}

		result[m] = SearchingButtonNumber(switchSet,clockSet,0);

	}

	for(int i=0;i<c;i++)
	{
		if(result[i]>=10000)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n",result[i]);
		}
	}

	return 0;
}

void InitSwitchSet(vector <vector<int>>&switchSet)
{
	vector<int> row;
	int clockNumber[10] = {3,4,4,5,5,4,3,5,5,5};

	for(int i=0;i<10;i++)
	{
		row.clear();
		row.resize(clockNumber[i]);

		switch (i)
		{
		case 0:
			row[0] = 0;
			row[1] = 1;
			row[2] = 2;
			break;
		case 1:
			row[0] = 3;
			row[1] = 7;
			row[2] = 9;
			row[3] = 11;
			break;
		case 2:
			row[0] = 4;
			row[1] = 10;
			row[2] = 14;
			row[3] = 15;
			break;
		case 3:
			row[0] = 0;
			row[1] = 4;
			row[2] = 5;
			row[3] = 6;
			row[4] = 7;
			break;
		case 4:
			row[0] = 6;
			row[1] = 7;
			row[2] = 8;
			row[3] = 10;
			row[4] = 12;
			break;
		case 5:
			row[0] = 0;
			row[1] = 2;
			row[2] = 14;
			row[3] = 15;
			break;
		case 6:
			row[0] = 3;
			row[1] = 14;
			row[2] = 15;
			break;
		case 7:
			row[0] = 4;
			row[1] = 5;
			row[2] = 7;
			row[3] = 14;
			row[4] = 15;
			break;
		case 8:
			row[0] = 1;
			row[1] = 2;
			row[2] = 3;
			row[3] = 4;
			row[4] = 5;
			break;
		case 9:
			row[0] = 3;
			row[1] = 4;
			row[2] = 5;
			row[3] = 9;
			row[4] = 13;
			break;


		}
		switchSet.push_back(row);
	}


}

void Test(vector <vector<int>>&switchSet , int clockSet[][4])
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			clockSet[i][j] ;
		}
	}
}

int SearchingButtonNumber(vector <vector<int>>&switchSet , int clockSet[][4] ,int switchNumber)
{
	int maxBox = 12;
	int maxIdx = 0;
	int temp = 0;
	int tempResult = 0;

	if(switchNumber == 9)
	{
		for(int i=0;i<16;i++)
		{
			if(maxBox >clockSet[i/4][i%4])
			{
				maxBox =clockSet[i/4][i%4];
			}
			
		}

		if(maxBox != 12)
		{
			return INF;
		}

		else
		{
			return 0;
		}
	}


	int ret = INF;
	for(int i=0;i<4;i++)
	{
		ret = min(ret, i + SearchingButtonNumber(switchSet,clockSet,switchNumber +1));
		pushSwitch(switchSet , clockSet , switchNumber);
	}

	return ret;

	/*
	int temp = 0;
	int tempResult = 0;
	int maxBox = 0;
	int maxIdx = 0;
	int isThree[10] = {0};
	int isSix[10] = {0};
	int isNine[10] = {0};
	int isTwleve[10] = {0};
	for(int i=0;i<switchSet.size();i++)//making logic box
	{
		for(int j=0;j<switchSet[i].size();j++)
		{
			temp = switchSet[i][j];
			if(clockSet[temp/4][temp%4] == 3)
			{
				tempResult+=10;
				
				isThree[i] ++;
			}
			else if(clockSet[temp/4][temp%4] == 6)
			{
				tempResult+=2;
				isSix[i]++;
				
			}
			else if(clockSet[temp/4][temp%4] == 9)
			{
				tempResult+=1;
				isNine[i]++;
				
			}
			else if(clockSet[temp/4][temp%4] ==12)
			{
				isTwleve[i]++;
			}

			//tempResult += (12 -  clockSet[temp/4][temp%4])/3;
		}
		if(tempResult > maxBox)
		{
			maxBox = tempResult;
			maxIdx = i;
		}
		logicBox[i] = tempResult;
		tempResult = 0;
		int fortemp=0;
		fortemp = isTwleve[i];
		fortemp =(switchSet[i].size() - fortemp);
		isTwleve[i]= fortemp;
	}

	if(maxBox == 0)
	{
		return 0;
	}

	int ret = 0;
	int button;

	
	printf("Logic Box : ");
	for(int i=0;i<10;i++)//print logic box
	{
		printf("%d ",logicBox[i]);
	}

	printf("\n");
	for(int i=0;i<10;i++)//print isThree
	{
		printf("%d ",isThree[i]);
	}
	printf("\n");

	for(int i=0;i<10;i++)//print isThree
	{
		printf("%d ",isSix[i]);
	}
	printf("\n");

	for(int i=0;i<10;i++)//print isThree
	{
		printf("%d ",isNine[i]);
	}
	printf("\n");
	for(int i=0;i<10;i++)//print isThree
	{
		printf("%d ",isTwleve[i]);
	}
	printf("\n");
	printf("\n");


	printf("Swithch the Button : ");
	scanf_s("%d",&button);

	for(int i=0;i<switchSet[button].size();i++)
	{
		temp = switchSet[button][i];
		clockSet[temp/4][temp%4] = clockSet[temp/4][temp%4]%12 + 3;
	}


	for(int i=0;i<4;i++)//print clock set
	{
		for(int j=0;j<4;j++)
		{
			printf("%d ",clockSet[i][j]);
		}
		
	}
	printf("\n");


	ret +=1;

	ret += SearchingButtonNumber(switchSet,clockSet,logicBox);
	
	return ret;
	*/
}

void pushSwitch(vector <vector<int>>&switchSet ,int clockSet[][4],int switchNumber)
{
	int temp=0;

	for(int i=0;i<switchSet[switchNumber].size();i++)
	{
		temp = switchSet[switchNumber][i];
		clockSet[temp/4][temp%4] = clockSet[temp/4][temp%4]%12 + 3;
	}

}