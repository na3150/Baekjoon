#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	vector<vector<int>>dp(N+1, vector<int>(N+1, 0));
	for (int i =1;i<=N;i++)
		for (int j = 1; j <= N; j++)
		{
			int num;
			cin >> num;
			dp[i][j] = dp[i][j - 1] + num;
		}
	for (int i = 0; i < M; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int result = 0;
		for (int j = x1; j <= x2; j++)
			result += (dp[j][y2] - dp[j][y1 - 1]);
		cout << result << '\n';
	}
	return 0;
}