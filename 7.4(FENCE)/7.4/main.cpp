#include <stdio.h>
#include <vector>

using namespace std;

int SearchingBox(int left,int right, int fenceLenth[20000]);

int main()
{
	int c=0;
	int fenceNumber=0;
	int fenceLenth[20000]={0};
	int maxLenth=0;
	int result[50];

	scanf("%d",&c);

	for(int i=0;i<c;i++)
	{
		scanf("%d",&fenceNumber);

		for(int j=0;j<fenceNumber;j++)
		{
			scanf("%d",&fenceLenth[j]);
			if(fenceLenth[j] > maxLenth)
			{
				maxLenth = fenceLenth[j];
			}

			int halfMaxLenth = maxLenth/2;

			result[i] = SearchingBox(0,fenceNumber,fenceLenth);

		}
	}


	for(int i=0;i<c;i++)
	{
		printf("%d\n",result[i]);
	}

	return 0;
}

int SearchingBox(int left,int right, int fenceLenth[20000])
{
	if(left == right) return fenceLenth[left];

	int mid = (left + right)/2;
	
	int ret = max(fenceLenth[left],fenceLenth[right]);

	int lo = mid , hi = mid +1;
	int heigh = min(fenceLenth[lo],fenceLenth[hi]);

	ret = max(ret,heigh*2);

	while(lo<left || hi <right)
	{
		if(hi<right && (lo == left || fenceLenth[lo-1] < fenceLenth[hi+1]))
		{

			hi++;
			heigh = min(heigh,fenceLenth[hi]);
		}

		else
		{
			lo--;
			heigh = min(heigh,fenceLenth[lo]);
		}

		ret = max(ret,heigh*(hi-lo+1));
	}

	return ret;
}