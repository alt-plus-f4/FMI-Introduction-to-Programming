#include <iostream>

using namespace std;

// °F = (°C × 9/5) + 32

int main() {
  double a = 0;
  const double del = (double)9 / 5;

  cin >> a;

  cout << a * del + 32 << endl;

  return 0;
}
