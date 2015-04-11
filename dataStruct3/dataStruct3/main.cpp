#include <stdio.h>

int bingoCounting(int ary[][100],int n,int bingCount);

int main()
{
	int n=0;//��������� n�� ���� ����
	int ary[100][100]={0};// nxn�� �������
	int count=0;
	int result=0;

	int bingoCount=0;//������ ������ �޴� ����
	int bingoNumberTemp=0;
	scanf("%d %d",&n, &bingoCount);//n���� ���� ���� ������ �Է¹���


	for(int i=0;i<bingoCount;i++)//���� �� ���� �޾� �� ���� �ִ� �κ��� 1�� ������ش�
	{
		int row = 0,column=0;
		scanf("%d",&bingoNumberTemp);

		row = (bingoNumberTemp-1)/n;
		column = (bingoNumberTemp-1)%n;

		ary[row][column] = 1;
	}


	result = bingoCounting(ary,n,bingoCount);//���� üũ �Լ� ȣ��

	printf("%d",result);//���



	return 0;
}

int bingoCounting(int ary[][100],int n,int bingCount)
{
	int ret=0;//�����
	bool isBingo=true;//���� �ƴ��� �ȵƴ��� �Ǵ�
	
	for(int i=0;i<n;i++)//���� ���� ī��Ʈ
	{
		
		isBingo = true;//���� �Ǵ� ���� �ʱ�ȭ

		for(int j=0;j<n;j++)
		{
			if(ary[i][j] == 0)//���ι����� üũ�ϴ� ���� �ȵ����� Ȯ�εǸ� �״�� �� ������ ����
			{
				isBingo =false;
				break;
			}
		}

		if(isBingo == true)//���� ������ ���� �ϳ� ������Ŵ
		{
			ret++;
		}
	}

	for(int i=0;i<n;i++)//���� ���� ī��Ʈ
	{
		isBingo = true;

		for(int j=0;j<n;j++)
		{
			if(ary[j][i] == 0)//������ �Ǵ�
			{
				isBingo =false;
				break;
			}
		}

		if(isBingo == true)//���� ������ ���� �ϳ� ������Ŵ
		{
			ret++;
		}
	}

	
	for(int i=0;i<n;i++)//���� �Ʒ����� �밢�� ���� ī��Ʈ
	{
		isBingo = true;

		for(int j=0;j<n;j++)
		{
			int row=0,column=0;
			row = j;
			column = i+j;

			if(column >= n)//�迭 ������ ������ �밢���� ��� �ݴ�� �Ѿ��
			{
				column = column-n;
			}

			if(ary[row][column] == 0)//�밢�� �Ǵ�
			{
				isBingo = false;
				break;
			}
		}

		if(isBingo ==true)//���� ������ ���� �ϳ� ������Ŵ
		{
			ret ++;
		}
	}


	for(int i=0;i<n;i++)//������ �Ʒ����� �밢�� ���� ī��Ʈ
	{
		isBingo = true;

		for(int j=0;j<n;j++)
		{
			int row=0,column=0;
			row = j;
			column = i-j;

			if(column <0)//�迭 ������ ������ �밢���� ��� �ݴ�� �Ѿ��
			{
				column = column + n;
			}

			if(ary[row][column] == 0)//�밢�� �Ǵ�
			{
				isBingo = false;
				break;
			}
		}

		if(isBingo ==true)//���� ������ ���� �ϳ� ������Ŵ
		{
			ret ++;
		}
	}
	
	return ret;
}

