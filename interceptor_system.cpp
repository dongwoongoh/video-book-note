#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool cmp(vector<int> a, vector<int> b) {
  if (a[0] == b[0]) {
    return a[1] < b[1];
  }
  return a[0] < b[0];
}

int solution(vector<vector<int>> targets) {
  int answer = 1;

  sort(targets.begin(), targets.end(), cmp);
  int now = targets[0][1];
  int max_tmp = targets[0][1];

  for (int i = 1; i < targets.size(); i++) {
    if (targets[i][0] >= now) {
      answer += 1;
      now = targets[i][1];
    } else {
      now = min(now, targets[i][1]);
    }
  }

  return answer;
}
