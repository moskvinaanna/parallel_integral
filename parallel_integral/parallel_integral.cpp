#include <iostream>
#include <omp.h>
#include <list>
#include <exception>
#include <locale>

using namespace std;



int main()
{
	setlocale(LC_ALL, "");
	double a, b, res = 0;
	int threadCount, n;
	try
	{
		while (true)
		{
			cout << "Введите начало интервала: "; 
			cin >> a;
			cout << "Введите конец интервала: "; 
			cin >> b;
			cout << "Введите количество элементарных отрезков: "; 
			cin >> n;
			cout << "Введите количество потоков: ";
			cin >> threadCount;
			double h = (b - a) / n;

#pragma omp parallel for num_threads(threadCount) reduction(+: res)
			for (int i = 1; i <= n; i++) res += sin(2*(a + i * h));

			res *= h;
			cout << "Результат вычисления: " << res << endl;
			cout << endl;
		}
	}
	catch (exception & e)
	{	}
	return 0;
}

