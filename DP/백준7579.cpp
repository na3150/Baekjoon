#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int N, M;
vector<int>m; //�޸�
vector<int>c; //���
int dp[101][100001]; 
//dp[i][j] = i��° �� ���� Ž������ ��, �ִ� j ����� �Ҹ��ؼ� ���� �� �ִ� �ִ� �޸�
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
			//i��° �� �����ϱ�
			if (j >= c[i]) dp[i][j] = max(dp[i][j], dp[i-1][j - c[i]] + m[i]);
			//i��° �� ���� ���ϱ�
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