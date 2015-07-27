#include <iostream>
#include <string>
#include <list>

using namespace std;

struct product {
	string name;
	int w;
	int imp;
};

int main()
{
	
	int c = 0;//테스트 케이스 1<= c <=50
	int n = 0;//가져가고 싶은 물건의 개수 1<= n <= 100
	int w = 0;//부피 1<= w <=1000
	int totalImp[50];
	list<product> prod[50];
	list<product>::iterator prod_iterator[50];
	list<product>::iterator maxNode;

	int idxCount[50];//setofidx에 들어간 개수 즉 캐리어에 넣어진 물건의 개수
	int setOfIdx[50][100] = { -1 };//정렬된 리스트에서 캐리어에 넣을 물건의 인덱스
	int tempIdx = 0;//리스트에서 인덱스가 몇번째 인지 알려주는 변수

	bool isFull = false;

	cin >> c;

	for (int i = 0; i < c; i++)
	{
		isFull = false;
		idxCount[i] = 0;
		tempIdx = 0;
		totalImp[i] = 0;

		cin >> n;
		cin>>w;

		for (int j = 0; j < n; j++)
		{
			product temp;
			cin >> temp.name;
			cin	>> temp.w;
			cin	>> temp.imp;

			prod[i].push_back(temp);

		}
		
		while (!isFull)
		{
			
			tempIdx = 0;
			int maxImpIdx = 0;

			if (idxCount[i] != 0)
			{
				for (prod_iterator[i] = prod[i].begin(); prod_iterator[i] != prod[i].end(); prod_iterator[i]++)
				{
					bool isInSet = true;
					for (int j = 0; j < idxCount[i]; j++)
					{
						if (tempIdx == setOfIdx[i][j])
						{
							isInSet = false;
						}
					}

					if (isInSet)
					{
						maxNode = prod_iterator[i];
						break;
					}
						

					tempIdx++;
				}
				

			}
			else
			{
				maxNode = prod[i].begin();
			}
			

			tempIdx = 0;
			//setofidx 에 없는 노드중 리스트에서 제일 큰 노드를 찾고 setofidx 에 추가해줌 
			for (prod_iterator[i] = prod[i].begin(); prod_iterator[i] != prod[i].end(); prod_iterator[i]++)
			{
				
				if (maxNode->imp <= prod_iterator[i]->imp)
				{
					bool canInput = true;

					for (int j = 0; j < idxCount[i]; j++)
					{
						if (tempIdx == setOfIdx[i][j])
						{
							canInput = false;
						}
					}

					if (canInput)//기존중 가장 큰값이라고 판단되면 maxnode와 idx를 갱신
					{
						maxNode = prod_iterator[i];
						maxImpIdx = tempIdx;

					}

				}
				
				tempIdx++;
			}


			if (w >=0)
			{
				
				w -= maxNode->w;
				if (w < 0)
				{
					isFull = true;
					break;
				}
				totalImp[i] += maxNode->imp;
				setOfIdx[i][idxCount[i]] = maxImpIdx;
				idxCount[i]++;
			}

			

		}

	}


	for (int i = 0; i < c; i++)
	{
		cout << totalImp[i] << " " << idxCount[i] << "\n";

		
		tempIdx = 0;
		for (prod_iterator[i] = prod[i].begin(); prod_iterator[i] != prod[i].end(); prod_iterator[i]++)
		{
			for (int j = 0; j < idxCount[i]; j++)
			{
				if (tempIdx == setOfIdx[i][j])
				{
	
					cout << prod_iterator[i]->name << "\n";
					
					break;
				}
			}

			tempIdx++;
		}
	}

	
	return 0;
}


