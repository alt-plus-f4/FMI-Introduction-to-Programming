#include <iostream>
// #include <stdbool.h>

// void reverse(char str[], int length) {
//   int start = 0;
//   int end = length - 1;
//   while (start < end) {
//     char temp = str[start];
//     str[start] = str[end];
//     str[end] = temp;
//     end--;
//     start++;
//   }
// }

// char *itoa(int num, char *str, int base) {
//   int i = 0;
//   bool isNegative = false;

//   if (num == 0) {
//     str[i++] = '0';
//     str[i] = '\0';
//     return str;
//   }
//   if (num < 0 && base == 10) {
//     isNegative = true;
//     num = -num;
//   }

//   while (num != 0) {
//     int rem = num % base;
//     str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
//     num = num / base;
//   }

//   if (isNegative)
//     str[i++] = '-';

//   str[i] = '\0';

//   reverse(str, i);

//   return str;
// }

void first(int number1) {
  for (int i = 0; i < number1; i++) {
    for (int k = 0; k <= i; k++) {
      std::cout << k + 1 << " ";
    }
    std::cout << "\n";
  }
}

void second(int number2) {
  for (int i = 0; i < number2; i++) {
    for (int j = 0; j < number2; j++) {
      if (i == 0 || i == number2 - 1)
        std::cout << "* ";
      else if (j == 0 || j == number2 - 1)
        std::cout << "* ";
      else
        std::cout << "  ";
    }
    std::cout << "\n";
  }
}

void third(int number3) {
  for (int i = 0; i < number3; i++) {
    for (int k = 0; k < number3; k++) {
      if (k < i)
        std::cout << "-";
      else if (k == i)
        std::cout << "o";
      else
        std::cout << "+";
    }
    std::cout << "\n";
  }
}

void forth(int number4) { // ik its fourth inside joke
  for (int i = 1; i <= number4; i++) {
    for (int k = 1; k <= number4; k++) {
      std::cout << i * k << " ";
    }
    std::cout << "\n";
  }
}

void fifth(int number5) { // murzi me
  for (int i = 0; i < number5; i++) {
    for (int k = 0; k < number5; k++) {
      // if(k <=)
    }
    std::cout << "\n";
  }
}

// char *getTime(int number) {
//   char *strHour = new char[2];

//   if (number < 10) {
//     itoa(number, strHour, 10);
//     return "0%s", strHour;
//   }

//   return itoa(number, strHour, 10);
// }

void sixth() {
  for (int i = 0; i < 24; i++) {
    for (int k = 0; k < 60; k++) {
      if (i < 10)
        std::cout << "0";

      std::cout << i << ":";

      if (k < 10)
        std::cout << "0";

      std::cout << k << "\n";
    }
  }
}

void seventh(int n, int x, int y) { // murzi me
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (j == x && i == y)
        std::cout << "*";
    }
    std::cout << '\n';
  }
}

int main(void) {
  int n1 = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0;
  int n = 0, x = 0, y = 0;

  // std::cin >> n1;
  // first(n1);

  // std::cin >> n2;
  // second(n2);

  // std::cin >> n3;
  // third(n3);

  // std::cin >> n4;
  // forth(n4);

  // std::cin >> n5;
  // fifth(n5);

  // sixth();

  std::cin >> n >> x >> y;
  seventh(x, x, y);

  return 0;
}