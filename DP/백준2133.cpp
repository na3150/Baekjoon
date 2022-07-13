#include <iostream>
#include <vector>
using namespace std;

vector<int>vect(1001);

int dp(int a)
{
	if (a == 0) return 1;
	if (a == 1) return 0;
	if (a == 2) return 3;
	if (vect[a] != 0) return vect[a];
	int result = 3 * dp(a - 2);
	for (int i = 4; i <= a; i++)
		if (i % 2 == 0) result += 2 * dp(a-i);
	return vect[a] = result;
}

int main()
{
	int N;
	cin >> N;
	cout << dp(N);
	return 0;
}