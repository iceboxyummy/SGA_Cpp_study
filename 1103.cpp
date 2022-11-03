#include <iostream>
using namespace std;

class Milli_Second;
class Second;
class Minute;

class Hour
{
public:
	Hour(double hour): hour(hour){}

	friend ostream& operator<<(ostream& out, const Hour&hour)
	{
		out << hour.hour;
		return out;
	}

	operator Minute();
	operator Second();
	operator Milli_Second();

private:
	double hour;
};

class Minute
{
public:
	Minute(double minute) : minute(minute) {}

	friend ostream& operator<<(ostream& out, const  Minute& minute)
	{
		out << minute.minute;
		return out;
	}

	operator Hour();
	operator Second();
	operator Milli_Second();

private:
	double  minute;
};

class Second
{
public:
	Second(double second) : second(second) {}

	friend ostream& operator<<(ostream& out, const Second& second)
	{
		out << second.second;
		return out;
	}

	operator Hour();
	operator Minute();
	operator Milli_Second();

private:
	double second;
};

class Milli_Second
{
public:
	Milli_Second(double milli_second) : milli_second(milli_second) {}

	friend ostream& operator<<(ostream& out, const Milli_Second& milli_second)
	{
		out << milli_second.milli_second;
		return out;
	}

	operator Hour();
	operator Minute();
	operator Second();

private:
	double milli_second;
};;

Hour::operator Minute() { return hour * 60; }
Hour::operator Second() { return hour * 3600; }
Hour::operator Milli_Second() { return hour * 3600 * 1000; }

Minute::operator Hour() { return minute / 60; }
Minute::operator Second() { return minute * 60; }
Minute::operator Milli_Second() { return minute * 1000; }

Second::operator Hour() { return second / 60 / 60; }
Second::operator Minute() { return second / 60; }
Second::operator Milli_Second() { return second * 1000; }

Milli_Second::operator Hour() { return milli_second / 1000 / 60 / 60; }
Milli_Second::operator Minute() { return milli_second / 1000 / 60; }
Milli_Second::operator Second() { return milli_second / 1000; }

int main() {
	Hour h(2);
	Minute min(30);
	Second sec(3600);
	Milli_Second mil_sec(3600000);

	cout << h << "H = " << static_cast<Minute>(h) << "Min" << endl;
	cout << h << "H = " << static_cast<Second>(h) << "Sec" << endl;
	cout << h << "H = " << static_cast<Milli_Second>(h) << "Mil_Sec" << endl << endl;

	cout << min << "Min = " << static_cast<Hour>(min) << "H" << endl;
	cout << min << "Min = " << static_cast<Second>(min) << "Sec" << endl;
	cout << min << "Min = " << static_cast<Milli_Second>(min) << "Mil_Sec" << endl << endl;

	cout << sec << "Sec = " << static_cast<Hour>(sec) << "H" << endl;
	cout << sec << "Sec = " << static_cast<Minute>(sec) << "Min" << endl;
	cout << sec << "Sec = " << static_cast<Milli_Second>(sec) << "Mil_Sec" << endl << endl;

	cout << mil_sec << "mil_sec = " << static_cast<Hour>(mil_sec) << " H" << endl;
	cout << mil_sec << "mil_sec = " << static_cast<Minute>(mil_sec) << "Min" << endl;
	cout << mil_sec << "mil_sec = " << static_cast<Second>(mil_sec) << "Sec" << endl;

	return 0;
}