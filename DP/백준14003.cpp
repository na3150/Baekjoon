#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
//LIS �˰��� : ���� ���� ���ϱ�
//lower_bound�� ����Ͽ� �����ϴ� �κ� ������ ���ϸ�, ������ ���̴� ��Ȯ�� ����������
//������ ��Ȯ�ϰ� �������� �ʴ´�. �̹� ���� ������� ��� ���� Ȯ���ϱ� �����̴�.
//LIS�� ���Ҿ� ��� ������ �����ؾ��ϴ� �� �����ؾ��ϴ� �����̴�.
//dp �迭�� lis �迭������ ��ġ�� ����س����� ���� dp�迭�� ���������� ���鼭 ���� ū ���� �̾Ƴ��� ���ϰ����ϴ� LIS�� �Ųٷ� ���� �� �ִ�.

int N;
vector<int>nums; //��ü �Է�
vector<int>lis; //���� ����
vector<int>dp; //nums[i]�� lis �迭������ ��ġ

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
			dp[i] = cnt; //lis �迭������ ��ġ
		}
		else {
			int index = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
			lis[index] = nums[i];
			dp[i] = index; //lis �迭������ ��ġ
		}
	}

	vector<int>result; //����
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