#include<stdio.h>

int main()
{

	int n=0;// �׽�Ʈ ���̽�
	int score=0;//�Է� ���� ���� ����
	int firstScore=-1, secondScore=-2,thirdScore=-3;//1�� 2�� 3���� ��� ����
	bool isFirstScoreChanged,isSecondScoreChanged,isThirdScoreChanged = false;//����� �������� �Ǵ��ϴ� ����
	int timesFirstEqual = 0, timesSecondEqual = 0, timesThirdEqual = 0;//������

	scanf("%d",&n);

	for(int i=0;i<n;i++)
	{
		isFirstScoreChanged = false;//�������� �Ǵ��ϱ� ���� �ʱ�ȭ
		isSecondScoreChanged = false;
		isThirdScoreChanged = false ;
		scanf("%d",&score);//�׽�Ʈ ���̽� �Է�

		if(score >firstScore)//1�� �Ǵ�
		{

			thirdScore = secondScore;
			timesThirdEqual = timesSecondEqual;

			secondScore = firstScore;//1��� ���Կ� ���� ���� 1���� 2������ ���� 2���� 3���� �ȴ�.
			timesSecondEqual = timesFirstEqual;

			firstScore = score;
			timesFirstEqual = 0;//������ ���Կ� ���� ������ �ʱ�ȭ

		}

		else if(score > secondScore)
		{
			thirdScore = secondScore;
			timesThirdEqual = timesSecondEqual;//2��� ���Կ� ���� ���� 2���� 3���� �ȴ�.

			secondScore = score;
			if(secondScore == firstScore)
			{
				timesSecondEqual = timesFirstEqual;//������ �ִ� ���� �𸣱� ������ 1��� ������ ������� �����ڰ� �����Ƿ� 1���� �����ڸ� �����´�.
			}

			else
			{
				timesSecondEqual = 0;//������ ���Կ� ���� ������ �ʱ�ȭ
			}


		}

		else if(score > thirdScore)
		{

			thirdScore = score;
			if(thirdScore == secondScore)
			{
				timesThirdEqual = timesFirstEqual;//������ �ִ� ���� �𸣱� ������ 2��� ������ ������� �����ڰ� �����Ƿ� 2���� �����ڸ� �����´�.
			}
			else if(thirdScore == firstScore)
			{
				timesThirdEqual = timesSecondEqual;//������ �ִ� ���� �𸣱� ������ 1��� ������ ������� �����ڰ� �����Ƿ� 1���� �����ڸ� �����´�.
			}

			else
			{
				timesThirdEqual = 0;//������ ���Կ� ���� ������ �ʱ�ȭ
			}
		}

		//�����ڸ� üũ�ϴ� �κ�
		if(score ==firstScore)
		{
			timesFirstEqual++;
		}

		if(score == secondScore)
		{
			timesSecondEqual ++;
		}

		if( score ==thirdScore)
		{
			timesThirdEqual ++;
		}



	}


	printf("%d %d",thirdScore,timesThirdEqual);//���

	return 0;
}