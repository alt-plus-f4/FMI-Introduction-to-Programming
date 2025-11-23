**Задача 1**  
Ползваме `std::cout` заедно с оператора `<<` за да принтираме нещо в конзолата.
``` cpp
#include <iostream>

int main()
{
    std::cout << "Hello world";
}
```

**Задача 2** 
Ползваме `std::cin` заедно с оператора `>>` за да прочетем нещо от конзолата. По този начин получаваме данни, въведени от потребителя на програмата.  
За момента може да смятаме, че `std::endl` и `'\n'` правят едно и също - слагат нов ред в конзолата. 
```cpp

#include <iostream>

int main()
{
    int a, b;
    std::cin >> a >> b;

    int perimeter = (a + b) * 2;
    int area = a * b;

    std::cout << "Perimeter: " << perimeter << std::endl;
    std::cout << "Area: " << area << '\n';  // both work
}
```
**Задача 3**  
```cpp
#include <iostream>

int main()
{
    float celsius;
    std::cin >> celsius;

    float fahrenheit = 32 + celsius * (9 / 5.0);

    std::cout << fahrenheit;
}
```
**Задача 4**  
Естествено втория вариант работи само с числа и не е много приложим :)
```cpp
    //1 variant
    int temp = a;
    a = b;
    b = temp;

    //2 variant
    a = a + b;
    b = a - b;
    a = a - b;
```
**Задача 5**  
С операцията `number % 10` вземаме остатъка при деление на `number` на 10. Математически е логично, че това винаги е равно на последната цифра от числото `number`.  
След това с операцията `number /= 10` (еквивалентна на `number = number / 10`) делим `number` на 10 и записваме само цялата част (защото работим с int - цяло число) от резултата обратно в `number`. Отново, математически е логично това винаги да ни дава `number` без последната му цифра.  
Редувайки тези две операции, лесно може да вземем всички цифри от едно число и да ги ползваме поотделно.
```cpp
#include <iostream>

int main()
{
    int number;
    std::cin >> number;
     
    int a = number % 10;    //take the last digit
    number /= 10;
    int b = number % 10;    //take the second-last digit
    number /= 10;
    int c = number;         //take the first digit

    std::cout << (a + b + c);   //print the sum
}
```