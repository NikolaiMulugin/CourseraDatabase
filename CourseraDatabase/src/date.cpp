#include "date.h"
#include <iomanip>

class Date{
public:
	Date(int y, int m, int d): _year(y),_month(m),_day(d){}

	int Year(){
		return _year;
	}

	int Month(){
		return _month;
	}

	int Day(){
		return _day;
	}

private:
	int _year;
	const int _month;
	const int _day;
};

ostream& operator << (ostream& os, const Date& date) {
	os.fill('0');
	os << setw(4) << date.Year << '-'
	   << setw(2) << date.Month << '-'
	   << setw(2) << date.Day << endl;
	return os;
}

Date ParseDate(istream& is) {
	int year, month, day;
	is >> year;
	is.get();
	is >> month;
	is.get();
	is >> day;
	return {year, month, day};
}
