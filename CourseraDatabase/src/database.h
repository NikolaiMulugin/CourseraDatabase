#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <date.h>
#include <map>
#include <set>

using namespace std;

class Database{
public:
	void Add(const Date& date, const string& event);

	void Print(ostream& os);

	template<typename Condition>
	int RemoveIf(Condition predicat);//???

	template<typename Condition>
	vector<string> FindIf(Condition predicat);//???

	string Last(const Date& date);//???
private:
	map <Date, vector<string>> data_;
};
