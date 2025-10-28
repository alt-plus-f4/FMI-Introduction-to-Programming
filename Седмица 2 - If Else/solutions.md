**Задача 1**  
Проста if проверка. Ако изразът в скобите след `if` се оцени като истина (`true`), ще се изпълни кода под него. Ако се оцени като лъжа (`false`), ще се изпълни кода под `else`.
``` cpp
    int number;
    std::cin >> number;
     
    if (number % 2 == 0)    //if it is divisible by 2 (if it is even)
    {
        std::cout << "Even";
    }
    else                    //else it should be odd
    {
        std::cout << "Odd";
    }
```
**Задача 2**  
Може лесно да свързваме няколко булеви израза в една if проверка, с помощта на операторите  `&&` (and) и `||` (or)
``` cpp
    int a, b, c;
    std::cin >> a >> b >> c;

    if ((a + b > c) && (a + c > b) && (b + c > a))
    {
        std::cout << "Valid triangle!";
    }
    else
    {
        std::cout << "Invalid triangle!";
    }
```
**Задача 3**  
Редът на проверките е важен, за да работи правилно логиката на програмата!  
Припомнете си кога една година е високосна и кога не е, ако не сте сигурни.
``` cpp
    int year;
    std::cin >> year;

    if (year % 400 == 0)
        std::cout << "Leap year!";
    else if (year % 100 == 0)
        std::cout << "Not a leap year!";
    else if (year % 4 == 0)
        std::cout << "Leap year!";
    else
        std::cout << "Not a leap year";
```
**Задача 4**  
Важно е да отбележим тук, че символите автоматично (имплицитно) се конвертират към числа, когато се ползват с оператори за сравняване (с аритметичните оператори също).  
Но това изобщо не значи, че е нужно да знаем ASCII кода на всеки един символ :)  
Ако не помните какво е ASCII таблицата си я припомнете задължително.
``` cpp
	char letter;
    std::cin >> letter;

    if ('a' <= letter && letter <= 'z')
        std::cout << "Lowercase";
    else if ('A' <= letter && letter <= 'Z')
        std::cout << "Uppercase";
    else
        std::cout << "Input was not a letter";
```
**Задача 5** 
Това е популярна задача, която се дава на интервюта за работа. Задачата е доста проста, но решението може да бъде много оптимизирано, зависи от езика и технологиите, които се използват. Това е едно примерно решение на C++ със знанията, взети до сега.  
Добър пример е да видим как, ако не напишем `else` преди `if`, кодът може да мине през няколко проверки една след друга. 
``` cpp
    int num;
    std::cin >> num;
    bool isDivisible = false;
    if (num % 3 == 0)
    {
        std::cout << "Fizz";
        isDivisible = true;
    }
    if (num % 5 == 0)
    {
        std::cout << "Buzz";
        isDivisible = true;
    }
    if (!isDivisible)
    {
        std::cout << num;
    }
```
**Задача 6** 
За тази задача ще ползваме вградената функция `sqrt(x)`. Тя ни връща като резултат коренът на `x`. Тази функция е дефинирана в библиотеката `cmath`, за това задължително в началото на кода трябва да напишем `#include <cmath>`.
``` cpp
#include <iostream>
#include <cmath>	//!!!

int main()
{
    int x, y, radius;
    std::cin >> x >> y >> radius;

    float distanceToPoint = sqrt(x * x + y * y);

    if (distanceToPoint < radius)
        std::cout << "Inside the circle";
    else if (distanceToPoint > radius)
        std::cout << "Outside the circle";
    else    //(distanceToPoint == radius)
        std::cout << "On the border";
}
``` 
**Задача 7**  
Хубав пример за използване на `switch`. Вместо да пишем хиляда `if`-a един след друг, може да използваме синтаксиса на `switch` за да направим кода си по-приятен за четене.
Разбира се, може да се направи и само с `if... else if...`, но колкото повече случаи има, толкова по-непрактично е.
``` cpp
    char operation;
    int a, b;
    std::cin >> operation >> a >> b;

    int result = 0;

    switch (operation)
    {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '*':
        result = a * b;
        break;
    case '/':
        result = a / b;
        break;
    default:
        std::cout << "Invalid operation!";
        break;
    }
    
    std::cout << result;
```
**Задача 8**  
``` cpp
#include <iostream>

int main() {
	int x1, x2, y1, y2, x, y;
	std::cin >> x1 >> y1 >> x2 >> y2 >> x >> y;

	if ((x > x1 && x < x2) && (y > y1 && y < y2))	//if ((x is between x1 and x2) and (y is between y1 and y2)) --> in
		std::cout << "in";
	else if ((x < x1 || x > x2) || (y < y1 || y > y2))	//if ((x is not between x1 and x2, or on them) or ((y is not between y1 and y2, or on them)
		std::cout << "out";
	else std::cout << "border";
}
```

Готино е да видим как законът на Де Морган работи тук:  
Вземаме първото условие (първия if - да е вътре) и прилагаме закона. Следвайки формулката стигаме до случая, в който точката е вън или на границата на правоъгълника. Както виждаме втората проверка (втория if - да е отвън) е почти идентична с резултата от развиването на формулата. Само трябва да махнем равното, с което и махаме случая да е на границата. Така лесно разделяме 3те различни случая на задачата.  
Първото условие развито прегледно:

```
!((x > x1 && x < x2) && (y > y1 && y < y2)) --> !(x > x1 && x < x2) || !(y > y1 && y < y2) --> (x <= x1 || x >= x2) || (y <= y1 || y >= y2)
```

Разбира се, не е нужно да си развиваме формулата за да решим правилно задачата, но ще трябва да помислим повече и сами да си измислим логиката :)