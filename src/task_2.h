#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> Y(n);
  for (int i = 0; i < n; ++i) {
    cin >> Y[i];
  }
  long long initial_beauty = 0;
  for (int i = 0; i < n; ++i) {
    initial_beauty += abs(Y[i] - (i + 1));
  }
  long long max_contribution = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int contribution = abs(Y[i] - (i + 1)) + abs(Y[j] - (j + 1)) - abs(Y[i] - (j + 1)) - abs(Y[j] - (i + 1));
      max_contribution = max(max_contribution, contribution);
    }
  }
  cout << initial_beauty + max_contribution << endl;

  return 0;
}
