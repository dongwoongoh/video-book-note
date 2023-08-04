#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<string> answer;
bool visited[100000001];
bool flag = false;
int cnt = 0;

void dfs(string cur, vector<vector<string>> tickets) {
  if (cnt == (int)tickets.size())
    flag = true;
  answer.push_back(cur);
  for (unsigned int i = 0; i < tickets.size(); i++) {
    if (!visited[i] && tickets[i][0] == cur) {
      visited[i] = true;
      cnt++;
      dfs(tickets[i][1], tickets);
      if (!flag) {
        answer.pop_back();
        visited[i] = false;
      }
    }
  }
}

vector<string> solution(vector<vector<string>> tickets) {
  sort(tickets.begin(), tickets.end());
  dfs("ICN", tickets);
  return answer;
}