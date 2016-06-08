#include<iostream>
using namespace std;
//class Complex
//{
//public:
//	Complex(double real = 0.0, double imag = 0.0);
//	Complex(const Complex& complex);
//	~Complex()
//	{
//		cout << "over\n";
//	}
//	Complex& operator=(const Complex& complex);
//	Complex operator+(const Complex& complex);
//	Complex operator-(const Complex& complex);
//	Complex operator*(const Complex& complex);
//	Complex operator/(const Complex& complex);
//
//	Complex& operator+=(const Complex& complex);
//	Complex& operator-=(const Complex& complex);
//	Complex& operator*=(const Complex& complex);
//	Complex& operator/=(const Complex& complex);
//
//	bool operator >(const Complex& complex);
//	bool operator >=(const Complex& complex);
//	bool operator <(const Complex& complex);
//	bool operator <=(const Complex& complex);
//	bool operator ==(const Complex& complex);
//	bool operator !=(const Complex& complex);
//private:
//	double _dReal;
//	double _dImage;
//};
//
//Complex::Complex(double real, double imag)
//{
//	_dReal = real;
//	_dImage = imag;
//}
//
//Complex::Complex(const Complex& complex)
//{
//	_dReal = complex._dReal;
//	_dImage = complex._dImage;
//}
//
//Complex& Complex::operator=(const Complex& complex)
//{
//	if (&complex != this)
//	{
//		_dReal = complex._dReal;
//		_dImage = complex._dImage;
//	}
//	return *this;
//}
//Complex Complex::operator+(const Complex& complex)
//{
//	return Complex(_dReal + complex._dReal, _dImage + complex._dImage);
//}
//
//Complex Complex::operator-(const Complex& complex)
//{
//	return Complex(_dReal - complex._dReal, _dImage - complex._dImage);
//}
//
//Complex Complex::operator*(const Complex& complex)
//{
//	return Complex(_dReal * complex._dReal, _dImage * complex._dImage);
//}
//
//Complex Complex::operator/(const Complex& complex)
//{
//	return Complex(_dReal / complex._dReal, _dImage / complex._dImage);
//}
//
//Complex& Complex::operator+=(const Complex& complex)
//{
//	_dReal = _dReal + complex._dReal;
//	_dImage = _dImage + complex._dImage;
//	return *this;
//}
//
//Complex& Complex::operator-=(const Complex& complex)
//{
//	_dReal = _dReal - complex._dReal;
//	_dImage = _dImage - complex._dImage;
//	return *this;
//}
//
//Complex& Complex::operator*=(const Complex& complex)
//{
//	_dReal = _dReal * complex._dReal;
//	_dImage = _dImage * complex._dImage;
//	return *this;
//}
//
//Complex& Complex::operator/=(const Complex& complex)
//{
//	_dReal = _dReal / complex._dReal;
//	_dImage = _dImage / complex._dImage;
//	return *this;
//}
//
//bool Complex::operator >(const Complex& complex)
//{
//	if (_dReal > complex._dReal)
//		return true;
//	else if (_dReal < complex._dReal)
//		return false;
//	else
//	{
//		if (_dImage>complex._dImage)
//			return true;
//		else
//			return false;
//	}
//}
//
//bool Complex::operator >=(const Complex& complex)
//{
//	if (_dReal > complex._dReal)
//		return true;
//	else if (_dReal < complex._dReal)
//		return false;
//	else
//	{
//		if (_dImage >= complex._dImage)
//			return true;
//		else
//			return false;
//	}
//}
//
//bool Complex::operator <(const Complex& complex)
//{
//	if (_dReal < complex._dReal)
//		return true;
//	else if (_dReal > complex._dReal)
//		return false;
//	else
//	{
//		if (_dImage<complex._dImage)
//			return true;
//		else
//			return false;
//	}
//}
//
//bool Complex::operator <=(const Complex& complex)
//{
//	if (_dReal < complex._dReal)
//		return true;
//	else if (_dReal > complex._dReal)
//		return false;
//	else
//	{
//		if (_dImage <= complex._dImage)
//			return true;
//		else
//			return false;
//	}
//}
//
//bool Complex::operator ==(const Complex& complex)
//{
//	if ((_dReal == complex._dReal) && (_dImage == complex._dImage))
//		return true;
//	else
//		return false;
//}
//
//bool Complex::operator !=(const Complex& complex)
//{
//	if ((_dReal == complex._dReal) && (_dImage == complex._dImage))
//		return false;
//	else
//		return true;
//}
//
//int main()
//{
//	Complex a(1.0, 2.0), b(3.0, 4.0), c;
//	Complex d(a);
//	c = a + b;
//	c = a - b;
//	c = a*b;
//	c = a / b;
//	a += b;
//	a -= b;
//	a *= b;
//	a /= b;
//	return 0;
//}



class  Date
{
public:
	Date(int y = 1900, int m = 1, int d = 1) :year(y), month(m), day(d)
	{
		if (!(year >= 1900 && (month >= 1 && month <= 12) && (day >= 1 && day <= Getmonthday(year,month))))
		{
			year = 1900;
			month = 1;
			day = 1;
		}
	}

	int operator-(const Date&d);
	Date&operator=(const Date&days);
	Date operator+(int days);
	Date operator-(int days);

	Date&operator++();
	Date operator++(int);
	Date&operator--();
	Date operator--(int);

	bool operator==(const Date&d);
	bool operator!=(const Date&d);
	bool operator>(const Date&d);
	bool operator<(const Date&d);
	bool operator>=(const Date&d);
	bool operator<=(const Date&d);

	bool IsLeap(int year)//判断是否为闰年
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			return true;
		return false;
	}

	friend ostream&operator<<(ostream&_cout, const Date&days);
private:
	int Getmonthday(int year,int month)//注意参数，要把当前年加进去，否则下面-会出错
	{
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (IsLeap(year) && 2 == month)
		{
			return days[month - 1]+1;
		}
		return days[month - 1];
	}
	int year;
	int month;
	int day;
};

int Date::operator-(const Date&d)
{
	int dayleft = 0, dayright = 0;
	int monthday = 0;
	int i = 0;
	int countleft = 0, countright = 0;
	Date temp(d);
	if (*this < temp)
	{
		std::swap(temp,*this);
	}
	for (i = 1990; i<year; i++)
	{
		if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
			countleft++;
	}
	for (i = 1; i < month; i++)
	{
		monthday += Getmonthday(year,i);
	}
	dayleft = (year - 1990) * 365 + monthday + day + countleft;
	monthday = 0;
	for (i = 1990; i<d.year; i++)
	{
		if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
			countright++;
	}
	for (i = 1; i < d.month; i++)
	{
		monthday += Getmonthday(d.year,i);
	}
	dayright = (d.year - 1990) * 365 + monthday + d.day + countright;
	return dayleft - dayright;
}


Date&Date::operator=(const Date&days)
{
	if (this != &days)
	{
		year = days.year;
		month = days.month;
		day = days.day;
	}
	return *this;
}


Date Date::operator+(int days)
{
	if (days<0)//输入的天数小于0，调用-重载
	{
		return *this - (0 - days);
	}
	int curday = days + day;
	int curmonth = month;
	int curyear = year;
	while (curday > Getmonthday(curyear,curmonth))
	{
		curday -= Getmonthday(curyear,curmonth);
		curmonth++;
		if (curmonth > 12)
		{
			curmonth -= 12;
			curyear++;
		}
	}
	return Date(curyear, curmonth, curday);
}

Date Date::operator-(int days)
{
	if (days < 0)
	{
		return *this + (0 - days);
	}
	int curday = day - days;
	int curmonth = month;
	int curyear = year;
	while (curday <1)
	{
		if (curmonth>1)
		{
			curday += Getmonthday(curyear,curmonth - 1);
			curmonth -= 1;
		}
		else
		{
			curmonth = 12;
			curday += Getmonthday(curyear,curmonth);
			curyear -= 1;
		}
	}
	return Date(curyear, curmonth, curday);
}

Date&Date::operator++()
{
	day++;
	if (day > Getmonthday(year,month))
	{
		day = 1;
		month++;
	}
	if (month > 12)
	{
		month = 1;
	}
	year++;
	return *this;
}
Date Date::operator++(int)
{
	Date date(year, month, day);
	day++;
	if (day > Getmonthday(year,month))
	{
		day = 1;
		month++;
	}
	if (month > 12)
	{
		month = 1;
	}
	year++;
	return date;
}
Date&Date::operator--()
{
	day -= 1;
	if (day < 1)
	{
		if (month>1)
		{
			day = Getmonthday(year,month - 1);
			month -= 1;
		}
		else
		{
			month = 12;
			day = Getmonthday(year,month);
			year--;
		}
	}
	return *this;
}
Date Date::operator--(int)
{
	int _year = year;
	int _month = month;
	int _day = day;
	Date date(_year, _month, _day);
	day -= 1;
	if (day < 1)
	{
		if (month>1)
		{
			day = Getmonthday(year,month - 1);
			month -= 1;
		}
		else
		{
			month = 12;
			day = Getmonthday(year,month);
			year--;
		}
	}
	return date;
}

bool Date::operator==(const Date&d)
{
	if (day == d.day&&month == d.month&&year == d.year)
		return true;
	return false;
}
bool Date::operator!=(const Date&d)
{
	if (day == d.day&&month == d.month&&year == d.year)
		return false;
	return true;
}
bool Date::operator>(const Date&d)
{
	if (year > d.year)
		return true;
	else if (year < d.year)
		return false;
	else
	{
		if (month>d.month)
			return true;
		else if (month < d.month)
			return false;
		else
		{
			if (day>d.day)
				return true;
			return false;
		}
	}
}


bool Date::operator<(const Date&d)
{
	if (year > d.year)
		return false;
	else if (year < d.year)
		return true;
	else
	{
		if (month>d.month)
			return false;
		else if (month < d.month)
			return true;
		else
		{
			if (day >= d.day)
				return false;
			return true;
		}
	}
}
bool Date::operator>=(const Date&d)
{
	if (year > d.year)
		return true;
	else if (year < d.year)
		return false;
	else
	{
		if (month>d.month)
			return true;
		else if (month < d.month)
			return false;
		else
		{
			if (day >= d.day)
				return true;
			return false;
		}
	}
}
bool Date::operator<=(const Date&d)
{
	if (year > d.year)
		return false;
	else if (year < d.year)
		return true;
	else
	{
		if (month>d.month)
			return false;
		else if (month < d.month)
			return true;
		else
		{
			if (day>d.day)
				return false;
			return true;
		}
	}
}

ostream&operator<<(ostream&_cout, const Date&days)
{
	_cout << days.year << " " << days.month << " " << days.day;
	return _cout;
}

int main()
{
	Date a(1989, 4, 26), b(2016, 9, 11);
	cout << (a + 10000)<<endl;
	cout << b - 10000<<endl;
	cout << b - a<<endl;
	cout << a - (-10000)<<endl;
	cout << b + (-10000);
	return 0;
}