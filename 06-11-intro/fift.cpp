#include <iostream>

using namespace std;

unsigned GetNumberOfDigits(unsigned i) {
  return i > 0 ? (int)log10((double)i) + 1 : 1;
}

int main() {
  int a = 0;
  int sum = 0;

  do {
    cin >> a;
  } while (GetNumberOfDigits(a) == 2);

  while (a != 0) {
    sum += a % 10;
    a /= 10;
  }

  cout << sum << endl;

  return 0;
}
