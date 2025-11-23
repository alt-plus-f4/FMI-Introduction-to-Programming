**Задача 1**  
```cpp
	int n, k;
	std::cin >> n >> k;

	int result = 1;

	for (int i = 0; i < k; i++)
	{
		result *= n;
	}

	std::cout << result;
```
**Задача 2**  
```cpp
	int number;
	std::cin >> number;
	int sum = 0;
	while (number != 0)
	{
		int lastDigit = number % 10;
		sum += lastDigit;
		number /= 10;
	}
	std::cout << sum;
```
**Задача 3**  
Обърнете внимание как задаваме начална стойност на isPrime на true. Идеята е да проверим дали number се дели на всяко число по-малко от него и ако се раздели дори само на едно от тях, то number не е просто. Ако мине целия цикъл без влезем в if-а, значи числото не се дели на нищо освен 1 и себе си, следователно е просто.  
Математически и логично да съкратим проверката до i*i <= number, за да извършим по малко стъпки, но i < number също върши работа. Важно е да започнем от i = 2, защото всяко число се дели на 1 :)

std::boolalpha ползваме за да отпечатваме на конзолата true или false, вместо 1 и 0.
```cpp
	int number;
	std::cin >> number;
	bool isPrime = true;	//!

	for (int  i = 2; i*i <= number; i++)	//!
	{
		if (number % i == 0)	//ako number se deli na i (bez ostatuk)
		{
			isPrime = false;
			break;
		}
	}
	std::cout << std::boolalpha <<isPrime;
```
**Задача 4**
Алгоритъмът е следният - делим числото на 2 и записваме остатъка в обратен ред. Продължаваме да делим числото отново и отново докато не стане 0. Тогава двоичното число са остатъците, записани в **обратен** ред.  
За да стане това (с обратния ред) всеки остатък, който получим, умножаваме по степен на 10-ката, за да изместим числото по-напред от миналото.  
Пример: `1011 = 1*10^0 + 1*10^1 + 0*10^2 + 1*10^3`

Припомням, че n^k (n на степен k) в с++ става с `pow(n,k)`  
`pow()` е вградена функция от библиотеката `cmath`, така че не забравяйте `#include <cmath>` в началото на кода!
```cpp
	int decimalNum;
	std::cin >> decimalNum;
	long long binaryRes = 0;

	for (int i = 0; decimalNum != 0; i++)
	{
		int remainder = decimalNum % 2;
		binaryRes += remainder * pow(10,i);
		decimalNum /= 2;
	}
	std::cout << binaryRes;
```

Ето и от двоична към десетична. Припомнете си и двата алгоритъма ако ви е нужно, има хиляди полезни ресурси в интернет :)  
```cpp
	int binaryNum;
	std::cin >> binaryNum;
	int decimalRes = 0;

	for (int i = 0; binaryNum != 0; i++)
	{
		int lastDigit = binaryNum % 10;
		decimalRes += lastDigit * pow(2, i);
		binaryNum /= 10;
	}
	std::cout << decimalRes;
```
Забележете как кода на двете задачи е абсолютно еднакъв. (имената на променливите нямат реално значение за компилатора) Единствената разлика е, че от 10-->2 константата с която делим е 2 а от 2-->10 константата е 10. Като разберете единия, би трябвало да може да докарате и другия :)   
**Задача 5**  
Потърсете си алгоритъма на Евклид за намиране на НОД ако не ви е ясен.
```cpp
	int a, b;
	std::cin >> a >> b;
	int result;
	while (true)
	{
		int remainder = a % b;
		if (remainder == 0)		//ako ostatukut e 0, b e nashiq otgovor, spirame loopa
		{
			result = b;
			break;
		}
		else
		{
			a = b;
			b = remainder;
		}
	}
	std::cout << result;
```
**Задача 6**  
```cpp
	//chetem chislata
	int a, b;
	std::cin >> a >> b;	
	
	//tuk zapazvame rezultata
	int sum = 0;
	int product = 1;

	//suma na a
	while (a != 0)
	{
		int lastDigit = a % 10;
		sum += lastDigit;
		a /= 10;
	}

	//proizvedenie na b
	while (b != 0)
	{
		int lastDigit = b % 10;
		product *= lastDigit;
		b /= 10;
	}
	//ako sa ravni shte printira true, ako ne - false
	std::cout << std::boolalpha << (sum == product);
```
**Задача 7**  
```cpp
	int num;
	std::cin >> num;
	int input;
	do
	{
		std::cin >> input;
		if (input == num)
		{
			std::cout << "You guessed the number!";
			break;
		}
		else if (input < num)
			std::cout << "Go higher!\n";	//	\n direktno mozhe da vleze v kraq na teksta
		else if (input > num)	//if-a realno ne e nuzhen, mozhe samo else
			std::cout << "Go lower\n";
	} while (true);
```
**Задача 8**  
```cpp
	int n;
	std::cin >> n;
	bool areAllOdd = true;
	for (int i = 0; i < n; i++)
	{
		int number;
		std::cin >> number;
		if (number % 2 == 0)
		{
			areAllOdd = false;
			break;		//mozhe i da nqma break, zavisi dali iskame
		}				//da ostavim potrebitelq da dovurshi vuvezhdaneto na n broi chisla
	}
	std::cout << std::boolalpha << areAllOdd;
```
**Задача 9**
Силно се надявам, че вече сте разбрали номера с num % 10 и num / 10, но ето го още един път:
num % 10 - взема последната цифра от числото.
num / 10 - маха последната цифра от числото, за да може loop-a като завърти пак num % 10 да вземе предпоследната и така...  
За да го обърнем, умножаваме числото по 10 за да може всяка нова добавена цифра да отива по в дясно от предходната. Така последната от num (най-лявата) вече ще е най-дясната в reversedNum.  

Най-лесния начин да проверим дали едно число е палиндром е да го обърнем и да го сравним със себе си :)
```cpp
	int num;
	std::cin >> num;
	int numCopy = num;

	int reversedNum = 0;
	//reversing
	while (numCopy != 0)
	{
		reversedNum *= 10;
		reversedNum += numCopy % 10;
		numCopy /= 10;
	}

	std::cout << std::boolalpha << (num == reversedNum);
```
**Задача 10**  
Ако не знаете как работи редицата на фибоначи я погледнете преди това. Тук идеята е че пишем ръчно първите 2 числа и после при всяка итерация на цикъла извеждаме числото и след това променяме последните стойността на последните 2 числа от редицата, за да може в следващата итерация сметките пак да са верни. 
```cpp
	int n;
	std::cin >> n;

	int last = 1;
	int secondLast = 1;
	std::cout << secondLast << ' ' << last << ' ';

	for (int i = 2; i < n; i++)
	{
		int fibNum = last + secondLast;
		std::cout << fibNum << ' ';
		secondLast = last;
		last = fibNum;
	}
```