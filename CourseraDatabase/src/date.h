#pragma once


#include <iostream>


using namespace std;

class Date{
public:
	Date(int y, int m, int d);
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator << (ostream& os, const Date& date);

Date ParseDate(istream& is);
