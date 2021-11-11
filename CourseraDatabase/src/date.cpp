#include "date.h"
#include <iomanip>



Date::Date(int y, int m, int d): _year(y),_month(m),_day(d){}

int Date::Year() const {
	return _year;
}

int Date::Month() const {
	return _month;
}

int Date::Day() const {
	return _day;
}

ostream& operator << (ostream& os, const Date& date) {
	os.fill('0');
	os << setw(4) << date.Year() << '-'
	   << setw(2) << date.Month() << '-'
	   << setw(2) << date.Day() << endl;
	return os;
}

bool operator<(const Date& lhs_date, const Date& rhs_date){
	return lhs_date.Year() < rhs_date.Year() or
			(lhs_date.Year() == rhs_date.Year() and (
					lhs_date.Month() < rhs_date.Month() or
					(lhs_date.Month() == rhs_date.Month() and lhs_date.Day() < rhs_date.Day())));
}
bool operator>(const Date& lhs_date, const Date& rhs_date){
	return (not (lhs_date < rhs_date)) and (not (lhs_date == rhs_date));
}
bool operator==(const Date& lhs_date, const Date& rhs_date){
	return lhs_date.Year() == rhs_date.Year() and
			lhs_date.Month() == rhs_date.Month() and
			lhs_date.Day() == rhs_date.Day();
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
