#include <queue>
#include <vector>

using namespace std;

int nodes[50010];
int intensity[50010];
vector<vector<pair<int, int>>> graph(50010);

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates,
                     vector<int> summits) {
  for (int i = 1; i <= n; ++i)
    intensity[i] = 1e8;
  for (auto s : summits)
    nodes[s] = 2;
  for (auto p : paths) {
    graph[p[0]].push_back({p[2], p[1]});
    graph[p[1]].push_back({p[2], p[0]});
  }

  priority_queue<pair<int, int>> pq;
  for (auto g : gates) {
    intensity[g] = -1;
    pq.push({0, g});
  }

  int ans_intensity = 1e9;
  int summit = 1e9;

  while (!pq.empty()) {
    auto [max_intensity, cur_node] = pq.top();
    pq.pop();

    if (max_intensity > ans_intensity)
      continue;
    if (nodes[cur_node] == 2) {
      if (max_intensity < ans_intensity) {
        ans_intensity = max_intensity;
        summit = cur_node;
      } else if (max_intensity == ans_intensity && cur_node < summit) {
        summit = cur_node;
      }
      continue;
    }

    for (auto next : graph[cur_node]) {
      if (intensity[next.second] > max(max_intensity, next.first)) {
        intensity[next.second] = max(max_intensity, next.first);

        pq.push({intensity[next.second], next.second});
      }
    }
  }

  return {summit, ans_intensity};
}