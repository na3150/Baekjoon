#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int NOT = 999999;

int N, M, X;
vector<vector<pair<int, int>>>map; //���� ����
vector<int>result; //������
vector<int>xResult;

void dijkstra(int start)
{
	result.assign(N, NOT);
	result[start] = 0; //�����
	priority_queue<pair<int, int>>pq; //{������, ���} 
	pq.push({ start,0 });
	while (!pq.empty())
	{
		int now = pq.top().first; //���� ���(������) 
		int dist = -pq.top().second; //���
		pq.pop();
		if (result[now] < dist) continue;
		for (int i = 0; i < map[now].size(); i++)
		{
			int next = map[now][i].first;
			//��������� ������ + ���������� ������
			int a = dist + map[now][i].second;
			//���� �ִ� �Ÿ�
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
	cin >> N >> M >> X; //�����Ǽ�, ������ ��, ��Ƽ ���
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