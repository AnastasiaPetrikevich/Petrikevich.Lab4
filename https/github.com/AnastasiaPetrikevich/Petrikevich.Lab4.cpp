#include <iostream>
#include <math.h>

using namespace std;

double Trapezium(double , double , int );
double Simpson(double , double , int);
double Exponent(double);
bool IsDataValid(double, double, int, double);
int PartitionsInTrapezium(double, double, int, double);
int PartitionsInSimpson(double, double, int, double);

int main()
{
	while (true)
	{
		double a, b;
		
		cout << "Enter the lower limit a: " << endl;
		cin >> a;
		cout << "Enter the upper limit b: " << endl;
		cin >> b;
		double n, eps;
		cout << "Enter the epsilon:"<<endl;
		cin >> eps;
		cout << "Enter the number of partitions: "<<endl;
		cin >> n;
		if (IsDataValid(a, b, n, eps) != 0)
		{
			system("cls");
			n = PartitionsInTrapezium(a, b, n, eps);
			cout << "Component formula of Trapezium: " << Trapezium(a, b, n) << endl;
			n = PartitionsInSimpson(a, b, n, eps);
			cout << "Component formula of Simpson: " << Simpson(a, b, n) << endl;
			break;
		}
		system("pause");
		system("cls");
	}
	system("pause");
	return 0;
}

double Trapezium(double a, double b, int n)
{
	double step = (b - a) / n;
	double t = a;
	double integral = Exponent(t);
	while (t < b)
	{
		t += step;
		integral += 2 * Exponent(t);
	}
	integral += Exponent(b);
	integral = step *integral/2;
	return integral;
}

double Simpson(double a, double b, int n)
{
	double step = (b - a) / n;
	double t = a;
	double integral = Exponent(t);
	while (t < b)
	{
		t += 2 * step;
		integral += 2 * Exponent(t);
	}
	while (t < b)
	{
		t += step;
		integral += 4 * Exponent(t);
	}
	integral += Exponent(b);
	integral = step * integral ;
	return integral;
}

double Exponent(double x)
{
	return exp(-x*x);
}

bool IsDataValid(double a, double b, int n, double eps)
{
	if (eps < 0 || eps >= 1) return false;
	if (a > b) return false;
	if (n < 0) return false;
	return true;
}

int PartitionsInTrapezium(double a, double b, int n, double eps)
{
	double previous = 0, next = 1;
	while (fabs(previous - next) > eps)
	{
		previous = Trapezium(a, b, n);
		next = Trapezium(a, b, 2 * n);
		n = 2 * n;
	}
	return n;
}

int PartitionsInSimpson(double a, double b, int n, double eps)
{
	double previous = 0, next = 1;
	while (fabs(previous - next) > eps)
	{
		previous = Simpson(a, b, n);
		next = Simpson(a, b, 2 * n);
		n = 2 * n;
	}
	return n;
}
