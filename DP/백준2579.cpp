#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	vector<pair<int, int>>dp(N+1); //{n-1, n-2}
	dp[0] = { 0,0 };
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		if (i == 1) dp[i] = { num,num };
		else {
			dp[i].first = dp[i - 1].second + num;
			dp[i].second = max(dp[i - 2].first, dp[i - 2].second) + num;
		}
	}
	cout << max(dp[N].first, dp[N].second);
	return 0;
}