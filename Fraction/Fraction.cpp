#include <iostream>
#include <random>
using namespace std;

class Fraction
{
private:

	int numerator;
	int denominator;

public:

	Fraction()
	{
		numerator = 0;
		denominator = 1;
	}
	Fraction(int n, int d)
	{
		numerator = n;
		denominator = d;
	}
	void Input(int n, int d)
	{
		numerator = n;
		denominator = d;
	}
	void Print()
	{
		cout << numerator << " / " << denominator << endl;
	}
	void Input()
	{
		srand(time(0));
		numerator = rand() % 100;
		denominator = rand() % 100;
		while (denominator == 0)
		{
			denominator = rand() % 100;
		}
	}
	void SetN(int _numerator)
	{
		numerator = _numerator;
	}
	void SetD(int _denominator)
	{
		denominator = _denominator;
	}
	int GetN() {
		return numerator;
	}
	int GetD() {
		return denominator;
	}
	Fraction operator+(Fraction& obj)
	{
		Fraction temp;
		if (this->denominator == obj.denominator)
		{
			temp.numerator = this->numerator + obj.numerator;
			temp.denominator = this->denominator;
		}
		else
		{
			temp.numerator = (this->numerator * obj.denominator) + (obj.numerator * this->denominator);
			temp.denominator = this->denominator * obj.denominator;
		}
		return temp;
	}
	Fraction operator+(int obj)
	{
		Fraction temp;
		temp.numerator = numerator + (obj * denominator);
		temp.denominator = denominator;
		return temp;
	}
	Fraction operator-(Fraction& obj)
	{
		Fraction temp;
		if (this->denominator == obj.denominator)
		{
			temp.numerator = this->numerator - obj.numerator;
			temp.denominator = this->denominator;
		}
		else
		{
			temp.numerator = (this->numerator * obj.denominator) - (obj.numerator * this->denominator);
			temp.denominator = this->denominator * obj.denominator;
		}
		return temp;
	}
	Fraction operator-(int obj)
	{
		Fraction temp;
		temp.numerator = numerator - (obj * denominator);
		temp.denominator = denominator;
		return temp;
	}
	Fraction operator*(Fraction& obj)
	{
		Fraction temp(numerator * obj.numerator, denominator * obj.denominator);
		return temp;
	}
	Fraction operator*(int obj)
	{
		Fraction temp(numerator * obj, denominator);
		return temp;
	}
	Fraction operator/(Fraction& obj)
	{
		Fraction temp(numerator * obj.denominator, denominator * obj.numerator);
		return temp;
	}
	Fraction operator/(int obj)
	{
		Fraction temp(numerator, denominator * obj);
		return temp;
	}
	Fraction& operator++()
	{
		numerator += denominator;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction temp(*this);
		numerator += denominator;
		return temp;
	}
	Fraction& operator--()
	{
		numerator -= denominator;
		return *this;
	}
	Fraction operator--(int)
	{
		Fraction temp(*this);
		numerator -= denominator;
		return temp;
	}
};

int main()
{
	/*srand(time(0));
	Fraction q;
	q.Input(1, 2);
	q.Print();
	q.SetD(100);
	q.Print();
	int d = q.GetD();
	cout << d << endl;

	Fraction x;
	x.Input();
	x.Print();
	x.SetN(100);
	x.Print();
	int n = x.GetN();
	cout << n << endl;

	Fraction x;
	x.Print();
	Fraction z(1, 10);
	z.Print();*/

	Fraction a(1, 5);
	a.Print();
	++a;
	a.Print();
	Fraction obj = a + 2;
	obj.Print();

	Fraction c = --a;
	c.Print();
	a.Print();

	Fraction d = obj / c;
	d.Print();

	Fraction q(2, 5);
	Fraction z = q * 3;
	z.Print();
}