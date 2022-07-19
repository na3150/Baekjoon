#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int NOT = 999999;

int N, M, X;
vector<vector<pair<int, int>>>map; //간선 정보
vector<int>result; //전광판
vector<int>xResult;

void dijkstra(int start)
{
	result.assign(N, NOT);
	result[start] = 0; //출발지
	priority_queue<pair<int, int>>pq; //{현재노드, 비용} 
	pq.push({ start,0 });
	while (!pq.empty())
	{
		int now = pq.top().first; //현재 노드(경유지) 
		int dist = -pq.top().second; //비용
		pq.pop();
		if (result[now] < dist) continue;
		for (int i = 0; i < map[now].size(); i++)
		{
			int next = map[now][i].first;
			//출발지에서 경유지 + 경유지에서 도착지
			int a = dist + map[now][i].second;
			//기존 최단 거리
			int b = result[next];
			if (a < b)
			{
				result[next] = a;
				pq.push({ next, -a });
			}
		}
	}
}

int main()
{
	cin >> N >> M >> X; //마을의수, 간선의 수, 파티 장소
	X--;
	map.assign(N, vector<pair<int, int>>(0));
	for (int i = 0; i < M; i++) {
		int n1, n2, val;
		cin >> n1 >> n2 >> val;
		map[n1-1].push_back({ n2-1,val });
	}
	
	dijkstra(X);
	xResult = result;

	int answer = -21e8;
	for (int i = 0; i < N; i++)
	{
		if (i == X) continue;
		dijkstra(i);
		answer = max(answer, xResult[i] + result[X]);
	}

	cout << answer;
	return 0;
}