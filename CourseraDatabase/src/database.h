#pragma once

#include <algorithm>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include "date.h"
#include <map>
#include <set>

using namespace std;

void TestEmptyCondition();

class Database{
public:
	void Add(const Date& date, const string& event);

	void Print(ostream& os) const;

	template<typename Condition>
	int RemoveIf(Condition pred) {
		int count = 0;
		auto current = begin(data_);
		while (current!=end(data_)) {
			bool stop = false;
			auto cur_ev = begin(current->second);
			while (cur_ev!=end(current->second)) {
				if (pred(current->first, *cur_ev)) {
					count++;
					cur_ev = current->second.erase(cur_ev);
					if (begin(current->second) == end(current->second)){
						current = data_.erase(current);
						stop = true;
						break;
					}
					continue;
				}
				if (cur_ev != end(current->second))
					++cur_ev;
			}
			if (current != end(data_) and !stop)
				++current;
		}
		return count;
	}

	template<typename Condition>
	vector<pair<Date, string>> FindIf(Condition predicat) const {
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

	string Last(const Date& date) const;
private:
	map <Date, vector<string>> data_;
};
