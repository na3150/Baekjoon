#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
//LIS 알고리즘 : 최장 수열 구하기
//lower_bound를 사용하여 증가하는 부분 수열을 구하면, 수열의 길이는 정확히 구해지지만
//수열은 정확하게 구해지지 않는다. 이미 답이 구해졌어도 계속 답을 확인하기 때문이다.
//LIS와 더불어 어떻게 수열을 저장해야하는 지 생각해야하는 문제이다.
//dp 배열에 lis 배열에서의 위치를 기록해놓으면 이후 dp배열을 마지막부터 돌면서 가장 큰 값을 뽑아내면 구하고자하는 LIS를 거꾸로 구할 수 있다.

int N;
vector<int>nums; //전체 입력
vector<int>lis; //최장 수열
vector<int>dp; //nums[i]의 lis 배열에서의 위치

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	nums.assign(N, 0);
	dp.assign(N, 0);
	for (int i = 0; i < N; i++)
		cin >> nums[i];

	lis.push_back(nums[0]); 
	int cnt = 0;
	for (int i = 0; i< N;i++)
	{
		if (lis[lis.size() - 1] < nums[i]) {
			lis.push_back(nums[i]);
			cnt++;
			dp[i] = cnt; //lis 배열에서의 위치
		}
		else {
			int index = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
			lis[index] = nums[i];
			dp[i] = index; //lis 배열에서의 위치
		}
	}

	vector<int>result; //정답
	cout << lis.size() << '\n';
	for (int i = N-1; i >= 0 && cnt >= 0; i--) {
		if (dp[i] == cnt) {
			result.push_back(nums[i]);
			cnt--;
		}
	}
	for (int i = result.size()-1; i >=0; i--)
		cout << result[i] << " ";

	return 0;
}