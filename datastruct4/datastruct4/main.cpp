// 떡의 개수가 0이 아닌 위치만 저장 (표현방법 2)

#include <stdio.h>


int main()
{
	int n=0,m=0;//행과 열의 크기
	int c=0;//떡 또는 호랑이가 있는 위치의 개수
	int h=0;//떡의 개수
	int p=0;//봇짐장수의 이동 횟수

	int row=0,column=0;//행의 값과 열의 값을 저장할 변수

	int ar[3000][3]={0};//떡과 호랑이의 값을 저장하는 희소행렬
	int line[500][2]={0};//이동할 값을 저장하는 행렬
	int result=0;//결과값


	scanf("%d %d",&n,&m);//행렬의 행과 열값의 최대를 받음


	scanf("%d",&c);//위치 개수를 받음

	for(int i=0;i<c;i++)//희소행렬 입력
	{

		scanf("%d %d %d",&row,&column,&h);

		ar[i][0] = row;
		ar[i][1] = column;
		ar[i][2] = h;
	}


	scanf("%d",&p);//이동할 횟수


	for(int i=0;i<p;i++)//이동하는 배열값 입력
	{

		scanf("%d %d",&row,&column);


		line[i][0] = row;
		line[i][1] = column;
	}

	for(int i=0;i<p-1;i++)
	{
		int q=0,w=0;//어느방향으로 나아가야하는지 전행렬과 그 다음행렬을 비교함
		q = line[i+1][0] -line[i][0];
		w = line[i+1][1] - line[i][1];

		if(q == 0 && w !=0)//오른쪽으로 움직임
		{
			for(int j=0;j<w;j++)//왼쪽에서 오른쪽으로 하나씩 넘어가며 확인
			{

				for(int k=0;k<c;k++)//희소 행렬인 ar과 비교
				{
					if(ar[k][0] == line[i][0] && ar[k][1] == (line[i][1]+j) )//같으면 떡값을 결과에 더함
					{
						result += ar[k][2];

						if(result < 0)//음수일 경우 더이상 비교하지않고 빠져나간다
							break;
					}
					else if(ar[k][0] > line[i][0])//행순서 대로 입력되있기 때문에 희소행렬의 행값이 더 클때 더이상 비교할 필요가 없음 
						break;
				}
				if(result < 0)
					break;
			}
		}

		else if(q != 0 && w==0)//아래로 움직임
		{
			for(int j=0;j<q;j++)//위에서 아래로 하나씩 넘어가며 확인
			{

				for(int k=0;k<c;k++)//희소 행렬인 ar과 비교
				{
					if(ar[k][0] == (line[i][0] +j) && ar[k][1] == line[i][1])//같으면 떡값을 결과에 더함
					{
						result += ar[k][2];
						if(result < 0)
							break;
					}
					else if(ar[k][0] > (line[i][0] + j))//희소행렬의 행값이 더 클때 더이상 비교할 필요가 없음
						break;
				}
				if(result < 0)
					break;
			}
		}

		if(result < 0)
			break;
	}

	if(result !=0)//목적지에 있는 행렬은 따로 비교한다
	{
		for(int i=0;i<c;i++)
		{
			if(ar[i][0] == line[p-1][0] && ar[i][1] == line[p-1][1])
			{
				result += ar[i][2];
				if(result < 0)
					break;
			}
			else if(ar[i][0] > line[p-1][0])
				break;
		}

	}


	printf("%d",result);

	return 0;
}