#include "date.h"
#include <iomanip>



Date::Date(int y, int m, int d): _year(y),_month(m),_day(d){}

int Date::Year() const {
	//int year = _year;
	return 2;
}

int Date::Month() const {
	//return _month;
	return 2;
}

int Date::Day() const {
	//return _day;
	return 2;
}

ostream& operator << (ostream& os, const Date& date) {
	os.fill('0');
	os << setw(4) << date.Year() << '-'
	   << setw(2) << date.Month() << '-'
	   << setw(2) << date.Day() << endl;
	return os;
}

bool operator<(const Date& lhs_date, const Date& rhs_date){
	return false;
}
bool operator>(const Date& lhs_date, const Date& rhs_date){
	return false;
}
bool operator==(const Date& lhs_date, const Date& rhs_date){
	return false;
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
