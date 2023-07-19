#include <cmath>
#include <string>
#include <vector>

using namespace std;
bool visited[300000];
long long answer = 0;
void dfs(vector<long long> &vt, vector<vector<int>> &graph, int parent) {

  visited[parent] = true;
  for (int i = 0; i < graph[parent].size(); i++) {
    if (visited[graph[parent][i]])
      continue;
    dfs(vt, graph, graph[parent][i]);
    answer += abs(vt[graph[parent][i]]);
    vt[parent] += vt[graph[parent][i]];
  }
}

long long solution(vector<int> a, vector<vector<int>> edges) {
  vector<long long> vt(a.begin(), a.end());
  vector<vector<int>> graph(a.size());

  for (int i = 0; i < edges.size(); i++) {
    graph[edges[i][0]].push_back(edges[i][1]);
    graph[edges[i][1]].push_back(edges[i][0]);
  }

  dfs(vt, graph, 0);

  if (vt[0] != 0)
    return -1;
  return answer;
}