**Задача 1**
Вместо да ползваме функцията `pow()` от библиотеката `cmath`, може да си я напишем сами :)  
```cpp
int pow(int n, int k)
{
    int result = 1;
    for (int i = 0; i < k; i++)
    {
        result *= n;
    }
    return result;
}
```
**Задача 2**
типът на връщане е `void` защото функцията не е нужно да връща някаква стойност, тя просто принтира на екрана. Параметри също не са необходими, затова осавяме скобите празни.  
```cpp
void printHello()
{
    std::cout << "Hello, world!";
}
```
**Задача 3**
Нека обърнем специално внимание на това как връщаме резултата. Ако връщаме булев израз (`true`/`false`) не е нужно да правим `if` проверка преди това. Може директно да върнем израза, който принципно бихме сложили в проверката на `if`-а. Той ще бъде пресметнат и директно ще се върне съответната стойност.  
Като rule of thumb запомнете:  
`if (...) return true; else return false;` е еквивалентно на `return (...)`. Писането на първия вариант е силно непрепоръчително и е възможно да се махат точки на контролно за такива работи. Така че го избягвайте.
```cpp
bool isUppercase(char symbol)
{
    return (symbol >= 'A' && symbol <= 'Z');
}

bool isLowercase(char symbol)
{
    return (symbol >= 'a' && symbol <= 'z');
}

//how NOT to do it!
bool isLowercase(char symbol)
{
    if (symbol >= 'a' && symbol <= 'z')
        return true;
    else
        return false;
}

```
**Задача 4**
```cpp
int calculate(int a, int b, char operation)
{
    switch (operation)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    default:
        std::cout << "Invalid operation!\n";
        return -1;
    }
}
```
**Задача 5**  
За тази задача е хубаво да работим с дробни числа. Ако подадем цяло число (`int`) типът имплицитно ще се преобразува към дробен такъв (защото няма да изгубим информация) и функцията пак ще се изпълни правилно.  
```cpp
float average(float a, float b, float c)
{
    return (a + b + c) / 3.0;
}
```
**Задача 6**  
Създаваме си променлива, която ще съхранява дължината на числото. Правим цикъл, в който при всяка итерация намаляме числото с 1 цифра и увеличаваме стойността на променливата `length` с 1. Когато числото свърши, ние сме намерили цялата му дължина и я връщаме като резултат.
```cpp
int numLength(int num)
{
    int length = 0;
    for (int i = 0; num != 0; i++)
    {
        num /= 10;
        length++;
    }
    return length;
}
```
**Задача 7**  
Нека помислим как може да решим тази задача. Един лесен начин е да вземем първото число и да сложим толкова нули след него, колкото е дължината на второто число, и накрая просто да ги съберем.  
Пример: За числа `1234` и `789` --> `1234000 + 789 = 1234789`  
За целта просто трябва да умножим първото число по 10 на степен `k`, където `k` - дължината на второто число.
```cpp
int concat(int a, int b)
{
    int copyB = b;
    for (int i = 0; b != 0; i++)
    {
        a *= 10;
        b /= 10;
    }
    return a + copyB;
}
```
Дали няма начин да стане по-лесно? Както вече трябва да знаете, идеята на функциите е да можем да преизползваме код, който вече сме написали, в различни ситуации.  
Какво правим в този код: умножаваме с 10 `повдигнато на степен` - `дължината на числото` b. Дали може да използваме някои функции, които вече сме написали? Много ясно :D  
Функциите `pow` и `numlength` правят точно каквото ни трябва!
```cpp
int concat(int a, int b)
{
    int bLen = numLength(b);
    int powOf10 = pow(10, bLen)
    return a * powOf10 + b;
    //return a * pow(10, numLength(b)) + b;         - same thing on 1 line!
}
```
Успяхме да преизползваме вече написаната от нас логика, да направим кода си по кратък и по разбираем за четене.  

**Задача 8**  
Идеята тук е да ви покажем function overloading. Тялото на функциите е еднакво, но типа на данните е различен. Ако викнем функцията с цели числа, резултатът от делението ще е цял. Ако викнем функцията с дробни числа, резултатът ще е дроб.
```cpp
int divide(int a, int b)
{
    return a / b;
}

double divide(double a, double b)
{
    return a / b;
}

int main()
{
    divide(5.5, 2.0);       //double
    divide(5.0, 2.0);       //double
    divide(5.0, 2); //2.5   //double   (2 will be implicitly converted)
    divide(5, 2); //2       //int
}
```
**Задача 9**  
Ще бъда честен, като писах задачата, си мислех че ще е смислено решението да се разбие на няколко по-малки функции, но като го написах видях, че няма смисъл. Все пак не е лоша задачка :)
```cpp
void printDivision(int a, int b)
{
    std::cout << a / b << ' ' << a % b << '/' << b << '\n';
}

int main()
{
    int a, b;
    std::cin >> a >> b;

    printDivision(a,b);
}
```
**Задача 10**  
Логическият израз, който трябва да симулираме, е (`[a,b]` обединено с `[c,d]`) без `[e,f]` `<==>` `x` е в `[a,b]` и `x` е в `[c,d]` и `х` не е в `[e,f]`.  
Отново хубав пример за преизползване на логика. Ползваме функцията `isInClosedInterval` да проверим както дали точката е вътре в интервала, така и дали е извън него. (само добавяме `!` в началото)  
Пак трябва да отбележим, че така кода става и много по-четим за програмиста.
```cpp
bool isInClosedInterval(int a, int b, int num)
{
    return num >= a && num <= b;
}

bool isIntervalValid(int a, int b)
{
    return a < b;
}

int main()
{
    int x, a, b, c, d, e, f;
    std::cin >> x >> a >> b >> c >> d >> e >> f;

    if (!isIntervalValid(a,b) || !isIntervalValid(c,d) || !isIntervalValid(e,f))
    {
        std::cout << "Invalid intervals!";
        return -1;  //we terminate the program early and signal an error
    }
    bool result  = ((isInClosedInterval(a,b,x) || isInClosedInterval(c,d,x)) && !isInClosedInterval(e,f,x));
    std::cout << std::boolalpha << result;
    return 0;
}
```