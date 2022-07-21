#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long ll;

int row[503], col[503];
int DP[503][503]; //D[i][j] = i번째부터 j번째 행렬까지 곱했을 때 필요한 '최소' 곱셉 연산 수

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

    //연산 step 순서
    //D[1][2], D[2][3], D[3][4] .... D[N-1][N]
    //D[1][3], D[2][4], D[3][5] .... D[N-2][N]
    //...
    for (int step = 1; step < n; step++) {
        for (int i = 0; i < n; i++) {
            int j = i + step;
            int result = INT_MAX; //가장 큰 값 넣어두기
            for (int k = i; k < j && j < n; k++) { //곱셈을 나누는 기준 k -> i * j = i * k + (k+1) * j
                //계속 최솟값 갱신
                result = min(result, DP[i][k] + DP[k + 1][j] + row[i] * col[k] * col[j]);
            }
            DP[i][j] = result;
        }
    }
    cout << DP[0][n - 1] << '\n';

    return 0;
}