#include <stdio.h>
#include <math.h>



class ListNode{

public:
	ListNode();
	ListNode(int _index);
	int index;
	ListNode *p;

};


class GrapeNode{
public:
	GrapeNode();
	~GrapeNode();
	int x;
	int y;
	bool isVisited;
	ListNode* head;

};

double CalculateDistance(GrapeNode* building, int idx, int n, double result);


int main()
{

	int c = 0;
	int n = 0, m = 0;

	GrapeNode* building = NULL;

	double result[50] = { 0 };

	scanf("%d", &c);

	for (int i = 0; i < c; i++)
	{
		scanf("%d %d", &n, &m);

		building = new GrapeNode[500];

		for (int j = 0; j < n; j++)
		{
			scanf("%d", &building[j].x);
		}

		for (int j = 0; j < n; j++)
		{
			scanf("%d", &building[j].y);
		}

		//연결된 선 넣어주기
		for (int j = 0; j < m; j++)
		{
			int first = 0, second = 0;
			scanf("%d %d", &first, &second);
			//첫번째 값
			ListNode* head = building[first].head;
			if (head == NULL)
			{
				building[first].head = new ListNode(second);
			}
			else
			{
				bool isEqual = false;
				ListNode* insetedNode;
				for (insetedNode = head; insetedNode->p != NULL; insetedNode = insetedNode->p)
				{
					if (head->index == second)
					{
						isEqual = true;
						break;

					}
				}

				if (isEqual == false)
					insetedNode->p = new ListNode(first);

			}

			//두번째 값
			head = building[second].head;
			if (head == NULL)
			{
				building[second].head = new ListNode(first);
			}
			else
			{
				bool isEqual = false;

				ListNode* insetedNode;
				for (insetedNode = head; insetedNode->p != NULL; insetedNode = insetedNode->p)
				{

					if (head->index == first)
					{
						isEqual = true;
						break;

					}

				}
				if (isEqual == false)
					insetedNode->p = new ListNode(first);

			}

		}

		//연결되지 않은 선 찾아 값 더해주기
	
		result[i] = CalculateDistance(building, 0, n, 0);
		





	}



	/*
	
		for (int i = 0; i < c; i++)
	{

		printf("%.10f\n", result[i]);
	}
	*/



	//delete(building);

	return 0;
}


GrapeNode::GrapeNode()
{
	x = 0;
	y = 0;
	isVisited = false;
	head = NULL;
}

GrapeNode::~GrapeNode()
{
	while (head == NULL)
	{
		if (head->p == NULL)
		{
			delete(head);
		}

		else if (head->p->p == NULL)
		{
			delete(head->p);
		}

		else
		{
			ListNode* temp = NULL;
			for (temp = head; temp->p->p != NULL; temp = temp->p)
			{
			}

			delete(temp->p);
		}

	}
}

ListNode::ListNode()
{
	index = 0;
	p = NULL;
}


ListNode::ListNode(int _index)
{
	index = _index;
	p = NULL;
}

double CalculateDistance(GrapeNode* building, int idx, int n, double result)
{
	building[idx].isVisited = true;
	double minDistance = 4000000;
	int minIdx = 0;
	double ret = result;
	bool isMinChanged = false;

	ListNode* tempHead = NULL;

	tempHead = building[idx].head;

	if (tempHead != NULL)
	{
		for (; tempHead != NULL; tempHead = tempHead->p)
		{
			if (0 <= tempHead->index < n && building[tempHead->index].isVisited == false)
			{
				minDistance = 0;
				isMinChanged = true;
				printf("Builted : %d\n", tempHead->index);
				result += CalculateDistance(building, tempHead->index, n, result);
			}
		}
	}


	//가장 짧은 거리의 노드 찾기
	for (int k = 0; k < n; k++)
	{

		if (building[k].isVisited == false)
		{

			double defX = 0, defY = 0;
			double distance = 0;
			defX = building[k].x - building[idx].x;
			defY = building[k].y - building[idx].y;

			distance = sqrt(defX*defX + defY*defY);

			if (distance < minDistance)
			{
				minDistance = distance;
				minIdx = k;
				isMinChanged = true;
			}

		}

	}

	if (minIdx != 0)
	{
		printf("Is Not Built : %d\n", minIdx);
		result += CalculateDistance(building, minIdx, n, minDistance);

	}
	
	if (isMinChanged == false)
	{
		minDistance = 0;
	}


	return result;
}