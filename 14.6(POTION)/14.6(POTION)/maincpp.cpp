#include <stdio.h>

int calGcd(int r[1000],int n,int maxR);


int main()
{
	int c=0;
	int n[50];
	int r[1000];
	int p[1000];
	int ratio[200];
	int result[50][200];
	int gcd = 0;
	int maxR=0;


	scanf("%d", &c);

	for (int i = 0; i < c; i++)
	{

		scanf("%d", &n[i]);

		//들어가야 하는 각 재료의 양
		for (int j = 0; j < n[i]; j++)
		{
			scanf("%d", &r[j]);
			if (r[j] > maxR)
				maxR = r[j];

		}

		//이미 넣어버린 재료의 양
		for (int j = 0; j < n[i]; j++)
		{
			scanf("%d", &p[j]);

		}

		gcd = calGcd(r, n[i], maxR);

		//넣어야할 비율 계산
		for (int j = 0; j < n[i]; j++)
		{
			
			ratio[j] = r[j] / gcd;

		}

		//이미 넣은양과 총 재료를 비교해서 재료에 비해 넣은양이 하나라도 부족하면 비율을 더한다

		while (1)
		{
			int uperTimes = 0;

			for (int j = 0; j < n[i]; j++)
			{
				int diffrence = r[j] - p[j];
				if (diffrence < 0)
				{
					uperTimes++;
				}
			}

			if (uperTimes != 0)
			{
				for (int j = 0; j < n[i]; j++)
				{

					r[j] += ratio[j];

				}
			}

			else if (uperTimes == 0)
			{
				for (int j = 0; j < n[i]; j++)
				{
					int howToInput = r[j] - p[j];

					result[i][j] = howToInput;

				}
				break;
			}

		}

	}
	

	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < n[i]; j++)
		{
			if (j != n[i])
				printf("%d ", result[i][j]);
			else
				printf("%d", result[i][j]);


		}
		printf("\n");
	}
	return 0;
}

int calGcd(int r[1000], int n,int maxR)
{
	int ret = 0;
	int div = 2;
	bool isDived = true;
	
	while (1)
	{
		isDived = true;

		for (int i = 0; i < n; i++)
		{
			int temp = 0;
			temp = r[i] % div;
			if (temp != 0)
				isDived = false;
		}

		if (div > maxR)
		{
			ret = 1;
			return ret;
		}

		if (isDived == true)
		{
			ret = div;
			return ret;
		}

		div++;
	}

	return ret;

}