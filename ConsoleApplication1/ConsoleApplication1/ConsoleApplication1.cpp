// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#define collection cin.tie(NULL);ios_base::sync_with_stdio(false);
using namespace std;
int DP[501][501], M, N, H[501][501];
int Depth(int i, int j)
{
	if (i == N && j == M)
	{
		return 1;
	}
	int indexi = i - 1;
	int indexj = j;
	if (DP[i][j] == -1)
	{

		DP[i][j] = 0;
		if (DP[indexi][indexj] != 0)
		{
			if (H[indexi][indexj] < H[i][j])
			{
				DP[i][j] += Depth(indexi, indexj);
			}
		}
		indexi = i;
		indexj = j - 1;
		if (DP[indexi][indexj] != 0)
		{
			if (H[indexi][indexj] < H[i][j])
			{
				DP[i][j] += Depth(indexi, indexj);
			}
		}
		indexi = i + 1;
		indexj = j;
		if (indexi <= N)
		{
			if (DP[indexi][indexj] != 0)
			{
				if (H[indexi][indexj] < H[i][j])
				{
					DP[i][j] += Depth(indexi, indexj);
				}
			}
		}
		indexi = i;
		indexj = j + 1;
		if (indexj <= M)
		{
			if (DP[indexi][indexj] != 0)
			{
				if (H[indexi][indexj] < H[i][j])
				{
					DP[i][j] += Depth(indexi, indexj);
				}
			}
		}
	}
	return DP[i][j];
}
int main()
{
	cin >> N >> M;
	int indexi, indexj;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> H[i][j];
			DP[i][j] = -1;
		}
	}
	cout << Depth(1, 1);
}

