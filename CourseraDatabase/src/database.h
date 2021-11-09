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
	vector<pair<Date, string>> FindIf(Condition predicat){
		vector<pair<Date, string>> entries;
		for (const auto& [year, events] : data_) {
			for (const auto& event : events) {
				if (predicat(year, event)) {
					entries.push_back({year, event});
				}
			}
		}
		return entries;
	}

	string Last(const Date& date);//???
private:
	map <Date, vector<string>> data_;
};
