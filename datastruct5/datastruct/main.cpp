#include <stdio.h>
#include <stdlib.h>

class Node{//노드 클래스
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

class List{//리스트 클래스
private:
	Node* head;
public:
	List();
	void addAtBack(Node* insertedNode);
	int bringData(int _row,int _column);
};

int main()
{

	int n=0,m=0;//행과 열의 크기
	int c=0;//떡 또는 호랑이가 있는 위치의 개수
	int h=0;//떡의 개수
	int p=0;//봇짐장수의 이동 횟수

	int row=0,column=0;//행의 값과 열의 값을 저장할 변수

	int line[500][2]={0};//이동할 값을 저장하는 행렬

	int result=0;//결과값

	List dduckList;

	scanf("%d %d",&n,&m);//행렬의 행과 열값의 최대를 받음


	scanf("%d",&c);//위치 개수를 받음

	for(int i=0;i<c;i++)//리스트에 추가
	{

		scanf("%d %d %d",&row,&column,&h);

		Node* newNode = new Node(row,column,h);//행과 열값을 가진는 노드 추가

		dduckList.addAtBack(newNode);//리스트에 노드 추가

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

		int q=0,w=0;//어느방향으로  나아가야하는지 전행렬과 그 다음행렬을 비교함
		q = line[i+1][0] -line[i][0];
		w = line[i+1][1] - line[i][1];

		if(q == 0 && w !=0)//오른쪽으로 움직임
		{
			for(int j=0;j<w;j++)//리스트에서 경로를 따라가며 탐색
			{
				result += dduckList.bringData(line[i][0],line[i][1]+j);

				if(result < 0)//음수일 경우 더이상 비교하지않고 빠져나간다
					break;
			}

		}

		else if(q != 0 && w==0)//아래로 움직임
		{

			for(int j=0;j<q;j++)//리스트에서 경로를 따라가며 탐색
			{
				result += dduckList.bringData(line[i][0]+j,line[i][1]);

				if(result < 0)
					break;
			}
		}

		if(result < 0)
			break;
	}

	if(result >0)//목적지에 있는 행렬은 따로 비교한다
	{
		result += dduckList.bringData(line[p-1][0],line[p-1][1]);
	}


	printf("%d",result);//결과값 출력

	return 0;
}

List::List()
{
	head = NULL;
}

void List::addAtBack(Node* insertedNode)//리스트를 맨 뒤에 추가하는 함수
{
	if(head == NULL)
	{
		head = insertedNode;//리스트에 아무것도없을때는 헤더에 연결
	}

	else
	{
		Node* nowNode;
		for(nowNode = head;nowNode->getP() != NULL;nowNode=nowNode->getP())//맨끝 노드를 찾는다
		{

		}

		nowNode->setP(insertedNode);//맨끝 노드 뒤에 연결
	}
}

int List::bringData(int _row,int _column)//행과 열값으로 같을경우 떡값을 반환하는 함수
{
	Node* nowNode; 
	for(nowNode = head;nowNode->getP() !=NULL;nowNode = nowNode->getP())
	{
		if(nowNode->getRow() == _row && nowNode->getColumn() == _column)//행과 열이 같을때
		{
			return nowNode->getData();//해당 노드의 떡값을 리턴
		}

		else if(nowNode->getRow() > _row)//찾으려는 행보다 리스트내부 행이 클경우 비교할 필요가 없으므로 0을 리턴
		{
			return 0;
		}
	}

	if(nowNode->getRow() == _row && nowNode->getColumn() == _column)//for문에서 마지막 노드 비교를 못하고 나오므로 마지막 케이스는 따로 비교
	{
		return nowNode->getData();//헤당 노드의 떡값을 리턴
	}

	return 0;//아무것도 찾지못하였을때 리턴 0

}

Node::Node(int _row,int _column,int _data)//노드의 생성자로 노드를 초기화해준다
{
	row = _row;
	column = _column;
	data = _data;
	p = NULL;
}

//노드 내부 데이터의 get set 함수

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
