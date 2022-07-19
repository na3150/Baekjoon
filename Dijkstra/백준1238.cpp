#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int NOT = 999999;

int N, M, X;
vector<vector<pair<int, int>>>map; //���� ����
vector<vector<int>>result; //������

void dijkstra(int start)
{
	result[start][start] = 0; //�����
	priority_queue<pair<int, int>>pq; //{������, ���} 
	pq.push({ start,0 });
	while (!pq.empty())
	{
		int now = pq.top().first; //���� ���(������) 
		int dist = -pq.top().second; //���
		pq.pop();
		if (result[start][now] < dist) continue;
		for (int i = 0; i < map[now].size(); i++)
		{
			int next = map[now][i].first;
			//��������� ������ + ���������� ������
			int a = dist + map[now][i].second;
			//���� �ִ� �Ÿ�
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
	cin >> N >> M >> X; //�����Ǽ�, ������ ��, ��Ƽ ���
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