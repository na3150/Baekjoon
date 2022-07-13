#include <iostream>
#include <vector>
using namespace std;

vector<int>vect(1001);

int dp(int a)
{
	if (a == 1) return 1;
	if (a == 2) return 3;
	if (vect[a] != 0) return vect[a]; //�̹� ���� ���
	return vect[a] = (dp(a - 1) + 2 * dp(a - 2)) % 10007;
}

int main()
{
	int N;
	cin >> N;
	cout << dp(N);
	return 0;
}