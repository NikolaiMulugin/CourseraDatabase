#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "date.h"
#include <map>
#include <set>

using namespace std;


/*void foreach_map(const map<Date, vector<string>>& data, Container){
	for (const auto& [year, events] : data) {
		for (const auto& event : events) {
			if (predicat(year, event)) {
				//action(year, event);
				entries.push_back({year, event});
			}
		}
	}
}*/

class Database{
public:
	void Add(const Date& date, const string& event);

	void Print(ostream& os);

	template<typename Condition>
	int RemoveIf(Condition predicat) {
		int count = 0;
		for (auto current = begin(data_); current!=end(data_); ++current) {
			for (auto cur_ev = begin(current->second); cur_ev!=end(current->second); ++cur_ev) {
				if (predicat(*current, *cur_ev)) {
					current->second.erase(cur_ev);
					if (begin(current->second) == end(current->second)){
						data_.erase(current);
					}
				}
			}
		}
		return count;
	}

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
