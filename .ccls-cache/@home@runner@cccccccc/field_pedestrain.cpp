#include <cstring>
#include <vector>

using namespace std;

int N, M;
int DP[510][510][2];
int MOD = 20170805;

int solution(int m, int n, vector<vector<int>> city_map) {
  N = m;
  M = n;
  memset(DP, 0, sizeof(DP));
  DP[1][1][0] = DP[1][1][1] = 1;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      if (city_map[i - 1][j - 1] == 0) {
        DP[i][j][0] = (DP[i][j][0] + DP[i - 1][j][0] + DP[i][j - 1][1]) % MOD;
        DP[i][j][1] = (DP[i][j][1] + DP[i - 1][j][0] + DP[i][j - 1][1]) % MOD;
      } else if (city_map[i - 1][j - 1] == 1)
        DP[i][j][0] = DP[i][j][1] = 0;
      else {
        DP[i][j][0] = DP[i - 1][j][0] % MOD;
        DP[i][j][1] = DP[i][j - 1][1] % MOD;
      }
    }
  }
  return DP[N][M][0] % MOD;
}