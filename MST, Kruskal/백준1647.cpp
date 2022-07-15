#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int h1, h2; //집1, 집2
	int val; //길 유지비
};

bool compare(Node n1, Node n2) //유지비를 기준으로 오름차순 정렬
{
	return n1.val < n2.val;
}

//Union Find
int parent[100001];

int getParent(int a)
{
	if (parent[a] == 0) return a; //본인이 root인 경우
	return parent[a] = getParent(parent[a]);
}

bool setUnion(int a, int b)
{
	int p1 = getParent(a);
	int p2 = getParent(b);
	if (p1 != p2) { //다른 그룹인 경우
		parent[p2] = p1;
		return true;
	}
	return false;
}

int main()
{
	int N, M; //집의 개수, 길의 개수
	cin >> N >> M;
	vector<Node>map(M);
	int cnt = 0; //연결된 간선의 수
	int sum = 0; //길 유지비의 합
	int Max = -21e8;
	for (int i = 0; i < M; i++)
		cin >> map[i].h1 >> map[i].h2 >> map[i].val;
	sort(map.begin(), map.end(), compare);
	for (int i = 0; i < M; i++)
	{
		if (setUnion(map[i].h1, map[i].h2)) {
			sum += map[i].val;
			if (Max < map[i].val) Max = map[i].val;
			cnt++;
		}
		if (cnt == N - 1) break;
	}
	cout << sum - Max;
	return 0;
}