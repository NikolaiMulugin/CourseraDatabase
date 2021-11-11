#pragma once


#include <iostream>


using namespace std;

class Date{
public:
	Date(int y, int m, int d);
	int Year() const;
	int Month() const;
	int Day() const;

private:
	int _year;
	int _month;
	int _day;
};

ostream& operator << (ostream& os, const Date& date);

bool operator<(const Date& lhs_date, const Date& rhs_date);
bool operator>(const Date& lhs_date, const Date& rhs_date);
bool operator==(const Date& lhs_date, const Date& rhs_date);

Date ParseDate(istream& is);
