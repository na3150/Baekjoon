#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int w[101]; //물건의 무게
int v[101]; //물건의 가치
int dp[101][101]; 
//dp[i][j] = i개의 물건을 담고, 최대 j 무게까지 담을 수 있을 때의 최대 가치

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
		cin >> w[i] >> v[i];
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			//배낭에 물건을 넣을 수 있을 때
			if (j - w[i] >= 0) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			//배낭에 물건을 넣을 수 없을 때
			else dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[N][K];
	return 0;
}