#include <iostream>
#include <vector>
using namespace std;
int parent[201];

int getParent(int a)
{
	if (parent[a] == 0) return a; //본인이 root
	return parent[a] = getParent(parent[a]);
}

void setUnion(int a, int b)
{
	int p1 = getParent(a);
	int p2 = getParent(b);
	if (p1 != p2) parent[p2] = p1; //b 그룹 root의 부모를 a 그룹 root로
}

int main()
{
	ios_base::sync_with_stdio();
	cin.tie(0);

	int N, M;
	cin >> N >> M; //여행 계획에 속한 도시들의 수
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int a;
			cin >> a;
			if (a > 0) setUnion(i, j); //그룹 묶기
		}
	}
	vector<int>trip(M); //여행 계획 도시
	for (int i = 0; i < M; i++)
		cin >> trip[i];
	bool flag = true;
	int root = getParent(trip[0]);
	for (int i = 1; i < M; i++) {
		//다른 그룹이 하나라도 있는 경우
		if (root != getParent(trip[i])) flag = false;
	}
	if (flag) cout << "YES";
	else cout << "NO";
	return 0;
}