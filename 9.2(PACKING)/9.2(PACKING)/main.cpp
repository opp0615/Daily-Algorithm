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
	
	int c = 0;//�׽�Ʈ ���̽� 1<= c <=50
	int n = 0;//�������� ���� ������ ���� 1<= n <= 100
	int w = 0;//���� 1<= w <=1000
	int totalImp[50];
	list<product> prod[50];
	list<product>::iterator prod_iterator[50];
	list<product>::iterator maxNode;

	int idxCount[50];//setofidx�� �� ���� �� ĳ��� �־��� ������ ����
	int setOfIdx[50][100] = { -1 };//���ĵ� ����Ʈ���� ĳ��� ���� ������ �ε���
	int tempIdx = 0;//����Ʈ���� �ε����� ���° ���� �˷��ִ� ����

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
			//setofidx �� ���� ����� ����Ʈ���� ���� ū ��带 ã�� setofidx �� �߰����� 
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

					if (canInput)//������ ���� ū���̶�� �ǴܵǸ� maxnode�� idx�� ����
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


