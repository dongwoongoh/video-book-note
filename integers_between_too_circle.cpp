#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long solution(int r1, int r2) {
  long long answer = 0;

  for (int i = 1; i < r2; ++i) {
    int BR = 0;
    int SR = 0;

    BR = (int)floor(sqrt(pow(r2, 2) - pow(i, 2)));

    if (i < r1) {
      SR = (int)ceil(sqrt(pow(r1, 2) - pow(i, 2)));
    } else {
      SR = 1;
    }

    answer += (BR - SR + 1);
  }

  return 4 * (answer + r2 - r1 + 1);
}