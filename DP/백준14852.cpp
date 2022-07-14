#include <iostream>
using namespace std;

long long d[1000001][2];

long long dp(int a)
{
	d[0][0] = 0;
	d[1][0] = 2;
	d[2][0] = 7;
	d[2][1] = 1;
	for (int i = 3; i <= a; i++)
	{
		d[i][1] = (d[i-1][1] + d[i-3][0]) % 1000000007;
		d[i][0] = (d[i-2][0] * 3 + d[i-1][0] * 2 + d[i][1] * 2) % 1000000007;
	}
	return d[a][0];
}

int main() 
{
	long long N;
	cin >> N;
	cout << dp(N);
	return 0;
}