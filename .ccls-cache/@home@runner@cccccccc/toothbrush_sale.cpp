#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, string> m;
map<string, int> cost;
vector<int> answer;

void dfs(string name, int money) {
  if (name == "center") {
    return;
  }

  if (money < 1) {
    cost[name] += money;

    return;
  }

  cost[name] += money - floor(money * 0.1);
  dfs(m[name], floor(money * 0.1));
}

vector<int> solution(vector<string> enroll, vector<string> referral,
                     vector<string> seller, vector<int> amount) {
  for (int i = 0; i < enroll.size(); i++) {
    string e = enroll[i];
    string r = referral[i];

    if (r == "-") {
      m.insert({e, "center"});
    } else {
      m.insert({e, r});
    }

    cost.insert({e, 0});
  }

  for (int i = 0; i < seller.size(); i++) {
    string s = seller[i];
    int money = amount[i] * 100;

    dfs(s, money);
  }

  for (int i = 0; i < enroll.size(); i++) {
    answer.push_back(cost[enroll[i]]);
  }

  return answer;
}