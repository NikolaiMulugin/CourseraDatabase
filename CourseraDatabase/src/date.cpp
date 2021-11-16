#include "date.h"
#include <iomanip>


Date::Date(int y, int m, int d) : year(y), month(m), day(d) {}

ostream& operator << (ostream& os, const Date& date) {
	os << setw(4) << setfill('0') << date.year << '-'
	   << setfill('0') << setw(2) << date.month << '-'
	   << setfill('0') << setw(2) << date.day;
	return os;
}

bool operator<(const Date& lhs_date, const Date& rhs_date){
	return tie(lhs_date.year,lhs_date.month, lhs_date.day) <
			tie(rhs_date.year,rhs_date.month, rhs_date.day);
}

bool operator==(const Date& lhs_date, const Date& rhs_date){
	return lhs_date.year == rhs_date.year and
			lhs_date.month == rhs_date.month and
			lhs_date.day == rhs_date.day;
}

bool operator>(const Date& lhs_date, const Date& rhs_date){
	return ( !(lhs_date < rhs_date)) && (!(lhs_date == rhs_date));
}


bool operator>=(const Date& lhs_date, const Date& rhs_date){
	return lhs_date > rhs_date || lhs_date == rhs_date;
}

bool operator<=(const Date& lhs_date, const Date& rhs_date){
	return lhs_date < rhs_date || lhs_date == rhs_date;
}

bool operator!=(const Date& lhs_date, const Date& rhs_date){
	return !(lhs_date == rhs_date);
}


Date ParseDate(istream& is) {
	int year, month, day;
	is >> year;
	is.ignore();
	is >> month;
	is.ignore();
	is >> day;
	return {year, month, day};
}
