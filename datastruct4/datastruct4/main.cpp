// ���� ������ 0�� �ƴ� ��ġ�� ���� (ǥ����� 2)

#include <stdio.h>


int main()
{
	int n=0,m=0;//��� ���� ũ��
	int c=0;//�� �Ǵ� ȣ���̰� �ִ� ��ġ�� ����
	int h=0;//���� ����
	int p=0;//��������� �̵� Ƚ��

	int row=0,column=0;//���� ���� ���� ���� ������ ����

	int ar[3000][3]={0};//���� ȣ������ ���� �����ϴ� ������
	int line[500][2]={0};//�̵��� ���� �����ϴ� ���
	int result=0;//�����


	scanf("%d %d",&n,&m);//����� ��� ������ �ִ븦 ����


	scanf("%d",&c);//��ġ ������ ����

	for(int i=0;i<c;i++)//������ �Է�
	{

		scanf("%d %d %d",&row,&column,&h);

		ar[i][0] = row;
		ar[i][1] = column;
		ar[i][2] = h;
	}


	scanf("%d",&p);//�̵��� Ƚ��


	for(int i=0;i<p;i++)//�̵��ϴ� �迭�� �Է�
	{

		scanf("%d %d",&row,&column);


		line[i][0] = row;
		line[i][1] = column;
	}

	for(int i=0;i<p-1;i++)
	{
		int q=0,w=0;//����������� ���ư����ϴ��� ����İ� �� ��������� ����
		q = line[i+1][0] -line[i][0];
		w = line[i+1][1] - line[i][1];

		if(q == 0 && w !=0)//���������� ������
		{
			for(int j=0;j<w;j++)//���ʿ��� ���������� �ϳ��� �Ѿ�� Ȯ��
			{

				for(int k=0;k<c;k++)//��� ����� ar�� ��
				{
					if(ar[k][0] == line[i][0] && ar[k][1] == (line[i][1]+j) )//������ ������ ����� ����
					{
						result += ar[k][2];

						if(result < 0)//������ ��� ���̻� �������ʰ� ����������
							break;
					}
					else if(ar[k][0] > line[i][0])//����� ��� �Էµ��ֱ� ������ �������� �ప�� �� Ŭ�� ���̻� ���� �ʿ䰡 ���� 
						break;
				}
				if(result < 0)
					break;
			}
		}

		else if(q != 0 && w==0)//�Ʒ��� ������
		{
			for(int j=0;j<q;j++)//������ �Ʒ��� �ϳ��� �Ѿ�� Ȯ��
			{

				for(int k=0;k<c;k++)//��� ����� ar�� ��
				{
					if(ar[k][0] == (line[i][0] +j) && ar[k][1] == line[i][1])//������ ������ ����� ����
					{
						result += ar[k][2];
						if(result < 0)
							break;
					}
					else if(ar[k][0] > (line[i][0] + j))//�������� �ప�� �� Ŭ�� ���̻� ���� �ʿ䰡 ����
						break;
				}
				if(result < 0)
					break;
			}
		}

		if(result < 0)
			break;
	}

	if(result !=0)//�������� �ִ� ����� ���� ���Ѵ�
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