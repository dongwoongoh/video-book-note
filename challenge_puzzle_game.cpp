#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
  int answer = 0;

  int high = 100000;
  int low = 1;
  int mid;
  long long int totalTime;

  while (high >= low) {
    mid = (high + low) / 2;
    totalTime = 0;
    for (int i = 0; i < diffs.size(); i++) {
      totalTime += times[i];
      if (mid < diffs[i]) {
        totalTime += (times[i - 1] + times[i]) * (diffs[i] - mid);
      }

      if (totalTime > limit) {
        break;
      }
    }

    if (totalTime > limit) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  answer = low;

  return answer;
}