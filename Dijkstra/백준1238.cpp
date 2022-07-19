#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int NOT = 999999;

int N, M, X;
vector<vector<pair<int, int>>>map; //간선 정보
vector<vector<int>>result; //전광판

void dijkstra(int start)
{
	result[start][start] = 0; //출발지
	priority_queue<pair<int, int>>pq; //{현재노드, 비용} 
	pq.push({ start,0 });
	while (!pq.empty())
	{
		int now = pq.top().first; //현재 노드(경유지) 
		int dist = -pq.top().second; //비용
		pq.pop();
		if (result[start][now] < dist) continue;
		for (int i = 0; i < map[now].size(); i++)
		{
			int next = map[now][i].first;
			//출발지에서 경유지 + 경유지에서 도착지
			int a = dist + map[now][i].second;
			//기존 최단 거리
			int b = result[start][next];
			if (a < b)
			{
				result[start][next] = a;
				pq.push({ next, -a });
			}
		}
	}
}

int main()
{
	cin >> N >> M >> X; //마을의수, 간선의 수, 파티 장소
	X--;
	result.assign(N, vector<int>(N, NOT));
	map.assign(N, vector<pair<int, int>>(0));
	for (int i = 0; i < M; i++) {
		int n1, n2, val;
		cin >> n1 >> n2 >> val;
		map[n1-1].push_back({ n2-1,val });
	}

	for (int i = 0; i < N; i++)
		dijkstra(i);

	int Max = -21e8;
	for (int i = 0; i < N; i++)
	{
		int Sum = result[i][X] + result[X][i];
		if (Max < Sum) Max = Sum;
	}
	cout << Max;
	return 0;
}