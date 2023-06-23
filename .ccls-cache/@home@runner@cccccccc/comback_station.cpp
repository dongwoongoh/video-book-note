#include <queue>
#include <string>
#include <vector>
using namespace std;

vector<int> edge[100001];

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources,
                     int destination) {
  vector<int> answer(sources.size());

  vector<int> costFromDestination(n + 1, -1);

  for (int i = 0; i < roads.size(); i++) {
    edge[roads[i][0]].push_back(roads[i][1]);
    edge[roads[i][1]].push_back(roads[i][0]);
  }

  queue<pair<int, int>> q;
  q.push({destination, 0});
  costFromDestination[destination] = 0;

  while (!q.empty()) {
    auto curPos = q.front().first;
    auto curCount = q.front().second;
    q.pop();

    for (int i = 0; i < edge[curPos].size(); i++) {
      int nextPos = edge[curPos][i];

      if (costFromDestination[nextPos] == -1 ||
          costFromDestination[nextPos] > curCount + 1) {
        q.push({nextPos, curCount + 1});
        costFromDestination[nextPos] = curCount + 1;
      }
    }
  }

  for (int i = 0; i < sources.size(); i++) {
    answer[i] = costFromDestination[sources[i]];
  }

  return answer;
}