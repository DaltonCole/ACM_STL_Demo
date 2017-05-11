#include <algorithm>  // Sort
#include <ctime>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

int main() {
  vector<int> temp(10, 0);
  vector<vector<int> > random_vector(10, temp);

  // Bad lambda
  auto print = [&random_vector]() {
    for (auto i : random_vector) {
      for (auto j : i) {
        cout << j << " ";
      }
      cout << endl;
    }
    cout << endl;
  };

  srand(time(NULL));

  for (auto& i : random_vector) {
    for (auto& j : i) {
      j = rand() % 10;
    }
  }

  print();

  // range_based_for_loop way
  for (auto& it : random_vector) {
    sort(it.begin(), it.end());
  }

  print();

  return 0;
}