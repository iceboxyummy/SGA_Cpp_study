#include<iostream>
using namespace std;

class Won
{
public:
	Won(int value)
		:value(value)
	{

	}

	int GetValue() const
	{
		return value;
	}
	
	int operator+(const Won& rhs) const
	{
		return value + rhs.value;
	}

	int operator-(const Won& rhs) const
	{
		return value - rhs.value;
	}

	int operator*(const Won& rhs) const
	{
		return value * rhs.value;
	}

	int operator/(const Won& rhs) const
	{
		return value / rhs.value;
	}

	int operator%(const Won& rhs) const
	{
		return value % rhs.value;
	}

	int operator+=(const Won& rhs)
	{
		value = value + rhs.value;
		return value;
	}

	int operator-=(const Won& rhs)
	{
		value = value-rhs.value;
		return value;
	}

	int operator*=(const Won& rhs)
	{
		value = value * rhs.value;
		return value;
	}

	int operator/=(const Won& rhs)
	{
		value = value / rhs.value;
		return value;
	}

	int operator%=(const Won& rhs)
	{
		value = value % rhs.value;
		return value;
	}

	friend ostream& operator<<(ostream& out, const Won& val)
	{
		out << val.value;
		return out;
	}

private:

	int value;
};

int main() {
	Won l(30), r(7);

	int result1= l + r;
	int result2= l - r;
	int result3= l * r;
	int result4= l / r;
	int result5= l % r;

	cout << Won(30) << " + " << Won(7) << " = " << result1 << endl;
	cout << Won(30) << " - " << Won(7) << " = " << result2 << endl;
	cout << Won(30) << " * " << Won(7) << " = " << result3 << endl;
	cout << Won(30) << " / " << Won(7) << " = " << result4 << endl;
	cout << Won(30) << " % " << Won(7) << " = " << result5 << endl << endl;

	cout << l << " += " << r << " : ";
	int result = l += r;
	cout << result << endl;
	cout << "l : " << l << endl << endl;

	cout << l << " -= " << r << " : ";
	result= l -= r;
	cout << result << endl;
	cout << "l : " << l << endl << endl;

	cout << l << " *= " << r << " : ";
	result = l *= r;
	cout << result << endl;
	cout << "l : " << l << endl << endl;

	cout << l << " /= " << r << " : ";
	result = l /= r;
	cout << result << endl;
	cout << "l : " << l << endl << endl;

	cout << l << " %= " << r << " : ";
	result = l %= r;
	cout << result << endl;
	cout << "l : " << l << endl << endl;

	return 0;
} 
