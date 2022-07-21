#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int N, M;
vector<int>m; //메모리
vector<int>c; //비용
int dp[101][100001]; 
//dp[i][j] = i번째 앱 까지 탐색했을 때, 최대 j 비용을 소모해서 얻을 수 있는 최대 메모리
int Sum;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	m.assign(N+1, 0);
	c.assign(N+1, 0);
	for (int i = 1; i <= N; i++)
		cin >> m[i];
	for (int i = 1; i <= N; i++)
	{
		cin >> c[i];
		Sum += c[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= Sum; j++) {
			//i번째 앱 제거하기
			if (j >= c[i]) dp[i][j] = max(dp[i][j], dp[i-1][j - c[i]] + m[i]);
			//i번째 앱 제거 안하기
			dp[i][j] = max(dp[i][j], dp[i-1][j]);
		}
	}

	for (int i = 0 ;i <= Sum; i++)
		if (dp[N][i] >= M) {
			cout << i;
			break;
		}

	return 0;
}