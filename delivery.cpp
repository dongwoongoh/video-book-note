#include  < queue>
#include  < vector>
using namespace std;

vector<pair<int, int>> V[55];
vector<int> Dist;

int Min(int A, int B) {
   if  (A < B) return A;
   return B;
   
}

void Dijkstra(int N) {
  priority_queue<pair<int, int>> PQ;
  PQ.push(make_pair(0, 1));
  Dist[1] = 0;

  while
     (PQ.empty() == 0) {
      int Cost = - PQ.top().first;
      int Cur = PQ.top().second;
      PQ.pop();

for
   (int i = 0; i < V[Cur].size(); i++) {
    int Next = V[Cur][i].first;
    int nCost = V[Cur][i].second;

    if
       (Dist[Next] > Cost + nCost) {
        Dist[Next] = Cost + nCost;
        PQ.push(make_pair(-Dist[Next], Next));
      }
  }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
  Dist.resize(N + 1, 2e9);
for
   (int i = 0; i < road.size(); i++) {
    int N1 = road[i][0];
    int N2 = road[i][1];
    int Dist = road[i][2];

    V[N1].push_back(make_pair(N2, Dist));
    V[N2].push_back(make_pair(N1, Dist));
  }

Dijkstra(N);
int answer = 0;
for
   (int i = 1; i <= N; i++) {
    if
       (Dist[i] <= K) answer++;
  }

return answer;
}