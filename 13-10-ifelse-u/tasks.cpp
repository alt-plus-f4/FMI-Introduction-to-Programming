#include <cmath>
#include <iostream>

#define S 7
#define E 7

void isEven(int num) {
  if (num % 2 == 0)
    std::cout << "Even";
  else
    std::cout << "Odd";
}

int main() {
  int num = 0, a = 0, b = 0, c = 0, year = 0, fizz = 0, x = 0, y = 0, r = 0,
      op1 = 0, op2 = 0;
  float sum = 0;
  char letter, operand;

  // 1

  if (S == 1) {
    std::cin >> num;
    isEven(num);
  }
  if (E == 1)
    return 0;

  // 2
  if (S == 2) {

    std::cin >> a >> b >> c;

    if (a + b < c || a + c < b || b + c < a)
      std::cout << "Invalid triangle!";
    else
      std::cout << "Valid trangle!";
  }

  if (E == 2)
    return 0;

  // 3
  if (S == 3) {
    std::cin >> year;
    if (!year % 4 && (year % 100 ^ !year % 400))
      std::cout << "Leap year!";
    else
      std::cout << "Not a leap year!";
  }
  if (E == 3)
    return 0;
  // 4
  if (S == 4) {
    std::cin >> letter;

    if (letter >= 'A' || letter <= 'Z')
      std::cout << "Uppercase";
  }

  if (E == 4)
    return 0;

  // 5
  if (S == 5) {
    std::cin >> fizz;

    if (!fizz % 3)
      std::cout << "Fizz";
    if (!fizz % 5)
      std::cout << "Buzz";
    if (fizz % 3 && fizz % 5)
      std::cout << fizz;
  }

  if (E == 5)
    return 0;

  // 6

  if (S == 6) {
    std::cin >> x >> y >> r;

    if (pow(x, 2) + pow(y, 2) < pow(r, 2))
      std::cout << "Inside";
    else if (pow(x, 2) + pow(y, 2) == pow(r, 2))
      std::cout << "On the border";
    else
      std::cout << "Outside";
  }
  if (E == 6)
    return 0;
  // 7

  // do{
  // }while()

  if (S == 7) {

    std::cin >> operand >> op1 >> op2;

    switch (operand) {
    case '+':
      sum = op1 + op2;
      break;
    case '-':
      sum = op1 - op2;
      break;
    case '*':
      sum = op1 * op2;
      break;
    case '/':
      if (op2 != 0)
        sum = op1 / op2;
      break;
    }

    std::cout << sum;
  }

  if (E == 7)
    return 0;

  // 8
  // \(x_{min}\le x_{p}\le x_{max}\) \(y_{min}\le y_{p}\le y_{max}\)
  if (S == 8) {
    int x1 = 0, x2 = 0, x3 = 0, y1 = 0, y2 = 0, y3 = 0;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int xMin = x2 < x3 ? x2 : x3;
    int xMax = x3 > x2 ? x3 : x2;

    int yMin = y2 < y3 ? y2 : y3;
    int yMax = y3 > y2 ? y3 : y2;

    if ((xMin < x1 && x1 < xMax) && (yMin < y1 && y1 < yMax))
      std::cout << "Inside";
    else if ((x1 < xMin || x1 > xMax) && (y1 < yMin || y1 > yMax))
      std::cout << "Outside";
    else
      std::cout << "On the border";
  }

  return 0;
}
