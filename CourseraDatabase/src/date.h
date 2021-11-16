#pragma once


#include <iostream>


using namespace std;

struct Date{
	Date(int y, int m, int d);
	int year;
	int month;
	int day;
};

ostream& operator << (ostream& os, const Date& date);

bool operator<(const Date& lhs_date, const Date& rhs_date);
bool operator<=(const Date& lhs_date, const Date& rhs_date);
bool operator>(const Date& lhs_date, const Date& rhs_date);
bool operator>=(const Date& lhs_date, const Date& rhs_date);
bool operator==(const Date& lhs_date, const Date& rhs_date);
bool operator!=(const Date& lhs_date, const Date& rhs_date);

Date ParseDate(istream& is);
/*
template <class T, class V>
ostream& operator << (ostream& os, const pair<T,V>& s) {
  //os << "{";
  os << s.first << " " << s.second;
  return os;//"}";
}*/

