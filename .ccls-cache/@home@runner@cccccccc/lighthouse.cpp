#include <string>
#include <vector>
#define MAX 100001

using namespace std;

int answer = 0;
bool isLightOn[MAX] = {0};
void dfs(int node, int parent, vector<vector<int>> &info) {
  for (int i = 0; i < info[node].size(); i++) {
    if (info[node][i] != parent) {
      dfs(info[node][i], node, info);
      if (!isLightOn[info[node][i]] && !isLightOn[node]) {
        isLightOn[node] = true;
        answer++;
      }
    }
  }
}

int solution(int n, vector<vector<int>> lighthouse) {
  vector<vector<int>> info(n + 1);
  for (int i = 0; i < lighthouse.size(); i++) {
    info[lighthouse[i][0]].push_back(lighthouse[i][1]);
    info[lighthouse[i][1]].push_back(lighthouse[i][0]);
  }
  dfs(1, 1, info);

  return answer;
}