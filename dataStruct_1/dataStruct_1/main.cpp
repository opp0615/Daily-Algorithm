#include<stdio.h>

int main()
{

	int n=0;// 테스트 케이스
	int score=0;//입력 값을 받을 변수
	int firstScore=-1, secondScore=-2,thirdScore=-3;//1등 2등 3등을 담는 변수
	bool isFirstScoreChanged,isSecondScoreChanged,isThirdScoreChanged = false;//등수가 변했음을 판단하는 변수
	int timesFirstEqual = 0, timesSecondEqual = 0, timesThirdEqual = 0;//동점자

	scanf("%d",&n);

	for(int i=0;i<n;i++)
	{
		isFirstScoreChanged = false;//변수마다 판단하기 위한 초기화
		isSecondScoreChanged = false;
		isThirdScoreChanged = false ;
		scanf("%d",&score);//테스트 케이스 입력

		if(score >firstScore)//1등 판단
		{

			thirdScore = secondScore;
			timesThirdEqual = timesSecondEqual;

			secondScore = firstScore;//1등값이 변함에 따라 기존 1등이 2등으로 기존 2등이 3등이 된다.
			timesSecondEqual = timesFirstEqual;

			firstScore = score;
			timesFirstEqual = 0;//점수가 변함에 대한 동점자 초기화

		}

		else if(score > secondScore)
		{
			thirdScore = secondScore;
			timesThirdEqual = timesSecondEqual;//2등값이 변함에 따라 기존 2등이 3등이 된다.

			secondScore = score;
			if(secondScore == firstScore)
			{
				timesSecondEqual = timesFirstEqual;//기존에 있던 값을 모르기 때문에 1등과 점수가 같을경우 동점자가 같으므로 1등의 동점자를 가져온다.
			}

			else
			{
				timesSecondEqual = 0;//점수가 변함에 대한 동점자 초기화
			}


		}

		else if(score > thirdScore)
		{

			thirdScore = score;
			if(thirdScore == secondScore)
			{
				timesThirdEqual = timesFirstEqual;//기존에 있던 값을 모르기 때문에 2등과 점수가 같을경우 동점자가 같으므로 2등의 동점자를 가져온다.
			}
			else if(thirdScore == firstScore)
			{
				timesThirdEqual = timesSecondEqual;//기존에 있던 값을 모르기 때문에 1등과 점수가 같을경우 동점자가 같으므로 1등의 동점자를 가져온다.
			}

			else
			{
				timesThirdEqual = 0;//점수가 변함에 대한 동점자 초기화
			}
		}

		//동점자를 체크하는 부분
		if(score ==firstScore)
		{
			timesFirstEqual++;
		}

		if(score == secondScore)
		{
			timesSecondEqual ++;
		}

		if( score ==thirdScore)
		{
			timesThirdEqual ++;
		}



	}


	printf("%d %d",thirdScore,timesThirdEqual);//출력

	return 0;
}