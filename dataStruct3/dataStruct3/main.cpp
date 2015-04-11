#include <stdio.h>

int bingoCounting(int ary[][100],int n,int bingCount);

int main()
{
	int n=0;//정방행렬의 n을 받을 변수
	int ary[100][100]={0};// nxn의 정방행렬
	int count=0;
	int result=0;

	int bingoCount=0;//빙고의 개수를 받는 변수
	int bingoNumberTemp=0;
	scanf("%d %d",&n, &bingoCount);//n값과 빙고 개수 변수를 입력받음


	for(int i=0;i<bingoCount;i++)//빙고가 될 값을 받아 그 값이 있는 부분을 1로 만들어준다
	{
		int row = 0,column=0;
		scanf("%d",&bingoNumberTemp);

		row = (bingoNumberTemp-1)/n;
		column = (bingoNumberTemp-1)%n;

		ary[row][column] = 1;
	}


	result = bingoCounting(ary,n,bingoCount);//빙고 체크 함수 호출

	printf("%d",result);//출력



	return 0;
}

int bingoCounting(int ary[][100],int n,int bingCount)
{
	int ret=0;//결과값
	bool isBingo=true;//빙고가 됐는지 안됐는지 판단
	
	for(int i=0;i<n;i++)//세로 방향 카운트
	{
		
		isBingo = true;//빙고 판단 변수 초기화

		for(int j=0;j<n;j++)
		{
			if(ary[i][j] == 0)//세로방향을 체크하다 빙고가 안됐음이 확인되면 그대로 그 세로줄 중지
			{
				isBingo =false;
				break;
			}
		}

		if(isBingo == true)//빙고가 됐을때 값을 하나 증가시킴
		{
			ret++;
		}
	}

	for(int i=0;i<n;i++)//가로 방향 카운트
	{
		isBingo = true;

		for(int j=0;j<n;j++)
		{
			if(ary[j][i] == 0)//가로줄 판단
			{
				isBingo =false;
				break;
			}
		}

		if(isBingo == true)//빙고가 됐을때 값을 하나 증가시킴
		{
			ret++;
		}
	}

	
	for(int i=0;i<n;i++)//왼쪽 아래로의 대각선 방향 카운트
	{
		isBingo = true;

		for(int j=0;j<n;j++)
		{
			int row=0,column=0;
			row = j;
			column = i+j;

			if(column >= n)//배열 범위를 나가는 대각선의 경우 반대로 넘어간다
			{
				column = column-n;
			}

			if(ary[row][column] == 0)//대각선 판단
			{
				isBingo = false;
				break;
			}
		}

		if(isBingo ==true)//빙고가 됐을때 값을 하나 증가시킴
		{
			ret ++;
		}
	}


	for(int i=0;i<n;i++)//오른쪽 아래로의 대각선 방향 카운트
	{
		isBingo = true;

		for(int j=0;j<n;j++)
		{
			int row=0,column=0;
			row = j;
			column = i-j;

			if(column <0)//배열 범위를 나가는 대각선의 경우 반대로 넘어간다
			{
				column = column + n;
			}

			if(ary[row][column] == 0)//대각선 판단
			{
				isBingo = false;
				break;
			}
		}

		if(isBingo ==true)//빙고가 됐을때 값을 하나 증가시킴
		{
			ret ++;
		}
	}
	
	return ret;
}

