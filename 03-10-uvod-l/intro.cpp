#include <cmath>
#include <iostream>

using namespace std;

int sum() {
  int a = 0, b = 0, c = 0;

  cout << "Enter a: ";
  cin >> a;
  cout << "Enter b: ";
  cin >> b;

  return a + b;
}

int calc() {
  int x = 0;

  cout << "Enter x: ";
  cin >> x;

  return (sqrt(2 * (pow(x, 3))) + sin(2 * x)) /
         (abs((sin(x) + pow(cos(x), 2))) + (1 / 2));
}

int main() {
  int result = sum();
  cout << "Result: " << result << "\n";

  int result2 = calc();
  cout << "Result: " << result2 << "\n";

  if (result > result2)
    cout << "Result 1 is greater than Result 2\n";
  else if (result < result2)
    cout << "Result 1 is less than Result 2\n";
  else
    cout << "Result 1 is equal to Result 2\n";

  cout << "Size of int: " << sizeof(int) << "\n";
  cout << "Size of long int: " << sizeof(long int) << "\n";
  cout << "Size of long long int: " << sizeof(long long int) << "\n";
  cout << "Size of short int: " << sizeof(short int) << "\n";
  cout << "Size of char: " << sizeof(char) << "\n";
  cout << "Size of double: " << sizeof(double) << "\n";
  cout << "Size of float: " << sizeof(float) << "\n";
  cout << "Size of bool: " << sizeof(bool) << "\n";

  return 0;
}
