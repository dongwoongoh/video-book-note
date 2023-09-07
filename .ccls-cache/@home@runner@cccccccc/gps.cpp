#include <vector>

#define MAX 210
#define INF 2e9
using namespace std;

int Min(int A, int B) {
  if (A < B)
    return A;
  return B;
}

int solution(int n, int m, vector<vector<int>> edge_list, int k,
             vector<int> gps_log) {
  vector<int> Node[MAX];
  vector<vector<int>> DP(k, vector<int>(n + 1, INF));
  for (int i = 0; i < edge_list.size(); i++) {
    int N1 = edge_list[i][0];
    int N2 = edge_list[i][1];
    Node[N1].push_back(N2);
    Node[N2].push_back(N1);
  }
  DP[0][gps_log[0]] = 0;
  for (int i = 1; i < k; i++) {
    for (int Cur = 1; Cur <= n; Cur++) {
      if (DP[i - 1][Cur] == INF)
        continue;

      for (int j = 0; j < Node[Cur].size(); j++) {
        int Next = Node[Cur][j];
        int Alpha = 0;
        if (gps_log[i] != Next)
          Alpha++;

        DP[i][Next] = Min(DP[i][Next], DP[i - 1][Cur] + Alpha);
      }
    }
  }

  if (DP[k - 1][gps_log[k - 1]] < INF)
    return DP[k - 1][gps_log[k - 1]];
  return -1;
}
