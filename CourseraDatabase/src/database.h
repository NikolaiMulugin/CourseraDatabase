#pragma once

#include <algorithm>
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
	vector<string> FindIf(Condition predicat){
		auto it = find_if(begin(data_), end(data_),
				[auto pair](){
			return predicat(pair.first(),event);
		});
	}

	string Last(const Date& date);//???
private:
	map <Date, vector<string>> data_;
};
