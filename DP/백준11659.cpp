#include <iostream>
#include <vector>
using namespace std;

int main() {

	int N, M;
	cin >> N >> M;
	vector<long> dp(N + 1); //d[n] = 1 ~ n ������ ��
	dp[0] = 0;
	for (int i = 1; i <= N; i++) { //�Է¹����鼭 ������ ���ϱ�
		long num;
		cin >> num;
		dp[i] = dp[i - 1] + num;
	}
	for (int i = 0; i < M; i++) {
		int start, end;
		cin >> start >> end;
		cout << dp[end] - dp[start - 1] << endl;
	}
	return 0;
}