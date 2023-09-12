#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int K;
bool isgo(int n, vector<int> &stones) {
  int count = 0;
  for (int i = 0; i < stones.size(); i++) {
    if (stones[i] - n <= 0)
      count++;
    else
      count = 0;
    if (count >= K)
      return true;
  }
  return false;
}

int solution(vector<int> stones, int k) {
  int answer = 0;
  K = k;
  int start = 0, end = *max_element(stones.begin(), stones.end());
  int mid;
  while (start <= end) {
    mid = (start + end) / 2;
    if (isgo(mid, stones)) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return start;
}