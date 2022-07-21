#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int w[101]; //������ ����
int v[101]; //������ ��ġ
int dp[101][101]; 
//dp[i][j] = i���� ������ ���, �ִ� j ���Ա��� ���� �� ���� ���� �ִ� ��ġ

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
			//�賶�� ������ ���� �� ���� ��
			if (j - w[i] >= 0) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			//�賶�� ������ ���� �� ���� ��
			else dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[N][K];
	return 0;
}