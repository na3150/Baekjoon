#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int map[1001][1001];


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++) {
            map[i][j + 1] = str[j] - '0';
        }
    }

    int result = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (map[i][j] != 0) {
                map[i][j] = min(min(map[i - 1][j], map[i][j - 1]), map[i - 1][j - 1]) + 1;
                result = max(map[i][j], result);
            }
        }
    }

    cout << result * result;

    return 0;
}