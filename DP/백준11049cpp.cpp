#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long ll;

int row[503], col[503];
int DP[503][503]; //D[i][j] = i��°���� j��° ��ı��� ������ �� �ʿ��� '�ּ�' ���� ���� ��

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, r, c;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> r >> c;
        row[i] = r;
        col[i] = c;
    }

    //���� step ����
    //D[1][2], D[2][3], D[3][4] .... D[N-1][N]
    //D[1][3], D[2][4], D[3][5] .... D[N-2][N]
    //...
    for (int step = 1; step < n; step++) {
        for (int i = 0; i < n; i++) {
            int j = i + step;
            int result = INT_MAX; //���� ū �� �־�α�
            for (int k = i; k < j && j < n; k++) { //������ ������ ���� k -> i * j = i * k + (k+1) * j
                //��� �ּڰ� ����
                result = min(result, DP[i][k] + DP[k + 1][j] + row[i] * col[k] * col[j]);
            }
            DP[i][j] = result;
        }
    }
    cout << DP[0][n - 1] << '\n';

    return 0;
}