#include <stdio.h>

class Node{
private:
	char mValue;
	Node* mPoint[4];
public:
	Node();
	char getValue();
	void setValue(char value);
	Node* getPoint(int idx);
	void setPoint(int idx,Node* point);
};

class QuardTree{
private:
	Node head;
public:
	void pushData(char input[1000], Node* nextPushNode);
	void printData(Node* nextPushNode);
	void turnOverTree(Node* nextPushNode);
	Node* getHeadPoint();
};

int inputIdx = 0;

int main()
{
	int c=0;
	char temp;
	char input[1000];
	QuardTree quardTreeSet[50];
	scanf_s("%d",&c);
	scanf_s("%c",&temp,1);

	for(int i=0;i<c;i++)
	{
		gets_s(input);

		quardTreeSet[i].pushData(input,quardTreeSet[i].getHeadPoint());
		quardTreeSet[i].turnOverTree(quardTreeSet[i].getHeadPoint());
		inputIdx = 0;

	}

	for(int i=0;i<c;i++)
	{
		quardTreeSet[i].printData(quardTreeSet[i].getHeadPoint());
		printf("\n");
	}


	return 0;
}

Node::Node()
{
	mValue = NULL;
	for(int i=0;i<4;i++)
	{
		mPoint[i] = NULL;
	}
}

char Node::getValue()
{
	return mValue;
}

void Node::setValue(char value)
{
	mValue = value;
}

Node* Node::getPoint(int idx)
{
	return mPoint[idx];
}

void Node::setPoint(int idx,Node* point)
{
	mPoint[idx] = point;
}

Node* QuardTree::getHeadPoint()
{
	return &head;
}

void QuardTree::pushData(char input[1000], Node* nextPushNode)
{
	if(nextPushNode == &head)
	{
		if(input[inputIdx] == '\0') return;

		else if(input[inputIdx] == 'x')
		{

			head.setValue(input[inputIdx]);
			inputIdx++;

			for(int i=0;i<4;i++)
			{
				Node* temp = new Node();
				head.setPoint(i,temp);
				pushData(input,head.getPoint(i));
			}
		}

		else
		{
			head.setValue(input[inputIdx]);
			inputIdx++;

			return;
		}
	}

	else
	{
		if(nextPushNode->getValue() == NULL)
		{

			if(input[inputIdx] == '\0') return;

			else if(input[inputIdx] == 'x')
			{
				nextPushNode->setValue(input[inputIdx]);
				inputIdx++;

				for(int i=0;i<4;i++)
				{
					Node* temp = new Node();
					nextPushNode->setPoint(i,temp);
					pushData(input,nextPushNode->getPoint(i));
				}
				
			}
			
			else
			{
				nextPushNode->setValue(input[inputIdx]);
				inputIdx++;
				return ;
			}
		}

		else
		{
			return ;
		}
	}
}


void QuardTree::printData(Node* nextPushNode)
{
	if(nextPushNode == &head)
	{
		if(head.getValue() == NULL)
		{
			return ;
		}

		else if(head.getValue() == 'x')
		{
			printf("%c",head.getValue());
			for(int i=0;i<4;i++)
			{
				printData(head.getPoint(i));
			}	
		}

		else
		{
			printf("%c",head.getValue());
			return;
		}
	}

	else
	{
		if(nextPushNode->getValue() == NULL)
		{
			return;
		}

		else if(nextPushNode->getValue() == 'x')
		{
			printf("%c",nextPushNode->getValue());
			for(int i=0;i<4;i++)
			{
				printData(nextPushNode->getPoint(i));
			}
		}

		else
		{
			printf("%c",nextPushNode->getValue());
			return;
		}
	}
}

void QuardTree::turnOverTree(Node* nextPushNode)
{
	if(nextPushNode == &head)
	{
		if(head.getValue() == 'x')
		{
			for(int i=0;i<4;i++)
			{
				if(head.getPoint(i)->getValue() == 'x')
				{
					turnOverTree(head.getPoint(i));
				}
			}

			Node* temp = head.getPoint(0);
			head.setPoint(0,head.getPoint(2));//0번째 포인트에 2번째 노드 연결
			head.setPoint(2,temp);//2번째 포인트에 0번째 노드 연결

			Node* temp2 = head.getPoint(1);
			head.setPoint(1,head.getPoint(3));//1번째 포인트에 3번째 노드 연결
			head.setPoint(3,temp2);//3번째 포인트에 1번째 노드 연결
		}
	}

	else
	{
		for(int i=0;i<4;i++)
		{
			if(nextPushNode->getPoint(i)->getValue() == 'x')
			{
				turnOverTree(nextPushNode->getPoint(i));
			}
		}

		Node* temp = nextPushNode->getPoint(0);
		nextPushNode->setPoint(0,nextPushNode->getPoint(2));
		nextPushNode->setPoint(2,temp);

		Node* temp2 = nextPushNode->getPoint(1);
		nextPushNode->setPoint(1,nextPushNode->getPoint(3));
		nextPushNode->setPoint(3,temp2);
	}
}