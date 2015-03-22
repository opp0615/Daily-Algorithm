#include <stdio.h>
#include <vector>

using namespace std;

const int coverType[4][3][2] = {//(y,x)
	{ {0,0}, {1,0}, {0,1} }, // ¡¸
	{ {0,0}, {0,1}, {1,1} },// ¤¡
	{ {0,0}, {1,0}, {1,1} },// ¤¤
	{ {0,0}, {1,0}, {1,-1} }// ¡¹
};

bool set(vector<vector<int>>&board , int y , int x , int type, int delta);
int cover(vector<vector<int>>& board );
void InputingTestBlock(vector<vector<int>>& board,int h, int w);
void InitTestBlock(vector<vector<int>>& board);

int main()
{
	int c = 0;
	int h,w = 0;
	int result[30] = {0};

	char enter;
	vector<vector <int> > board;
	scanf_s("%d",&c);


	for(int i=0;i<c;i++)//inputing test cases
	{
		scanf_s("%d %d",&h,&w);
		scanf_s("%c",&enter,1);
		InputingTestBlock(board,h,w);

		/*
		for(int m=0;m<board.size() ;m++)
		{
		for(int n=0;n<board[m].size();n++)
		{
			printf("%d ",board[m][n]);
		}
		printf("\n");
		}
		
		*/

		result[i] = cover(board);

		board.clear();
		
	}

	
	for(int i=0;i<c;i++)//printing test cases
	{
		printf("%d\n",result[i]);
	}
	

	
	return 0;
}

bool set(vector<vector<int>>&board , int y , int x , int type, int delta)
{
	bool ok = true;

	for(int i=0;i<3;i++)
	{
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];
		
		if(ny < 0 || ny >=board.size() || nx <0 || nx>=board[0].size())
		{
			ok = false;
		}
		else if((board[ny][nx] +=delta) >1)
		{
			ok = false;
		}
	}
	return ok;
}

int cover(vector<vector<int>>& board)
{
	int y = -1,x = -1;

	for(int i =0; i<board.size();i++)
	{
		for(int j=0; j<board[i].size();j++)
		{
			if(board[i][j] == 0)//board is white
			{
				y= i;
				x= j;
				break;
			}
		}

		if(y != -1)
		{
			break;
		}
	}

	if(y == -1) return 1;

	int ret = 0;

	for(int type = 0;type<4; type++)
	{
		if(set(board,y,x,type,1))
		{
			ret +=cover(board);

		}
		set(board,y,x,type,-1);
	}

	return ret;
}


void InputingTestBlock(vector<vector<int>>& board ,int h, int w)
{
	char input ; 
	vector<int> row;

	for(int i=0;i<h;i++)
	{
		row.resize(w);
		board.push_back(row);
	}
	for(int i =0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			scanf_s("%c",&input,1);
			if(input == '#')
			{
				board[i][j] = 1;
			}
			else if(input =='.')
			{
				board[i][j] = 0;
			}
		}
		scanf_s("%c",&input,1);
	}

}
