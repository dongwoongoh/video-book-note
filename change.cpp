#include <string>
#include <vector>

#define MODULER 1000000007
#define MAX 100010
using namespace std;

int DP[MAX];

int solution(int n, vector<int> money) {
  DP[0] = 1;
  for (int i = 0; i < money.size(); i++) {
    for (int j = money[i]; j <= n; j++) {
      DP[j] += DP[j - money[i]];
      DP[j] %= MODULER;
    }
  }
  int answer = DP[n] % MODULER;
  return answer;
}