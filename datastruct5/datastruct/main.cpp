#include <stdio.h>
#include <stdlib.h>

class Node{//��� Ŭ����
private:
	int row;
	int column;
	int data;
	Node* p;
public:
	Node(int _row,int _column,int _data);
	int getRow();
	void setRow(int _row);
	int getColumn();
	void setColumn(int _column);
	int getData();
	void setData(int _data);
	Node* getP();
	void setP(Node* _p);

};

class List{//����Ʈ Ŭ����
private:
	Node* head;
public:
	List();
	void addAtBack(Node* insertedNode);
	int bringData(int _row,int _column);
};

int main()
{

	int n=0,m=0;//��� ���� ũ��
	int c=0;//�� �Ǵ� ȣ���̰� �ִ� ��ġ�� ����
	int h=0;//���� ����
	int p=0;//��������� �̵� Ƚ��

	int row=0,column=0;//���� ���� ���� ���� ������ ����

	int line[500][2]={0};//�̵��� ���� �����ϴ� ���

	int result=0;//�����

	List dduckList;

	scanf("%d %d",&n,&m);//����� ��� ������ �ִ븦 ����


	scanf("%d",&c);//��ġ ������ ����

	for(int i=0;i<c;i++)//����Ʈ�� �߰�
	{

		scanf("%d %d %d",&row,&column,&h);

		Node* newNode = new Node(row,column,h);//��� ������ ������ ��� �߰�

		dduckList.addAtBack(newNode);//����Ʈ�� ��� �߰�

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

		int q=0,w=0;//�����������  ���ư����ϴ��� ����İ� �� ��������� ����
		q = line[i+1][0] -line[i][0];
		w = line[i+1][1] - line[i][1];

		if(q == 0 && w !=0)//���������� ������
		{
			for(int j=0;j<w;j++)//����Ʈ���� ��θ� ���󰡸� Ž��
			{
				result += dduckList.bringData(line[i][0],line[i][1]+j);

				if(result < 0)//������ ��� ���̻� �������ʰ� ����������
					break;
			}

		}

		else if(q != 0 && w==0)//�Ʒ��� ������
		{

			for(int j=0;j<q;j++)//����Ʈ���� ��θ� ���󰡸� Ž��
			{
				result += dduckList.bringData(line[i][0]+j,line[i][1]);

				if(result < 0)
					break;
			}
		}

		if(result < 0)
			break;
	}

	if(result >0)//�������� �ִ� ����� ���� ���Ѵ�
	{
		result += dduckList.bringData(line[p-1][0],line[p-1][1]);
	}


	printf("%d",result);//����� ���

	return 0;
}

List::List()
{
	head = NULL;
}

void List::addAtBack(Node* insertedNode)//����Ʈ�� �� �ڿ� �߰��ϴ� �Լ�
{
	if(head == NULL)
	{
		head = insertedNode;//����Ʈ�� �ƹ��͵��������� ����� ����
	}

	else
	{
		Node* nowNode;
		for(nowNode = head;nowNode->getP() != NULL;nowNode=nowNode->getP())//�ǳ� ��带 ã�´�
		{

		}

		nowNode->setP(insertedNode);//�ǳ� ��� �ڿ� ����
	}
}

int List::bringData(int _row,int _column)//��� �������� ������� ������ ��ȯ�ϴ� �Լ�
{
	Node* nowNode; 
	for(nowNode = head;nowNode->getP() !=NULL;nowNode = nowNode->getP())
	{
		if(nowNode->getRow() == _row && nowNode->getColumn() == _column)//��� ���� ������
		{
			return nowNode->getData();//�ش� ����� ������ ����
		}

		else if(nowNode->getRow() > _row)//ã������ �ຸ�� ����Ʈ���� ���� Ŭ��� ���� �ʿ䰡 �����Ƿ� 0�� ����
		{
			return 0;
		}
	}

	if(nowNode->getRow() == _row && nowNode->getColumn() == _column)//for������ ������ ��� �񱳸� ���ϰ� �����Ƿ� ������ ���̽��� ���� ��
	{
		return nowNode->getData();//��� ����� ������ ����
	}

	return 0;//�ƹ��͵� ã�����Ͽ����� ���� 0

}

Node::Node(int _row,int _column,int _data)//����� �����ڷ� ��带 �ʱ�ȭ���ش�
{
	row = _row;
	column = _column;
	data = _data;
	p = NULL;
}

//��� ���� �������� get set �Լ�

int Node::getRow()
{
	return row;
}

int Node::getColumn()
{
	return column;
}

int Node::getData()
{
	return data;
}

Node* Node::getP()
{
	return p;
}

void Node::setRow(int _row)
{
	row = _row;
}
void Node::setColumn(int _column)
{
	column = _column;
}
void Node::setData(int _data)
{
	data = _data;
}

void Node::setP(Node* _p)
{
	p = _p;
} 
