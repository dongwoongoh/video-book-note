#include <iostream>
#include <string>
#include <vector>

using namespace std;

string getBinary(int n) {
  string ret = "";
  while (n > 0) {
    int remain = n % 2;
    n /= 2;
    ret = to_string(remain) + ret;
  }
  return ret;
}

int countOne(string &s) {
  int ret = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '1')
      ret++;
  }
  return ret;
}

int solution(int n) {
  int answer = 0;
  string start = getBinary(n);
  int one = countOne(start);

  for (int i = n + 1;; i++) {
    string binary = getBinary(i);
    if (one == countOne(binary)) {
      answer = i;
      break;
    }
  }

  return answer;
}