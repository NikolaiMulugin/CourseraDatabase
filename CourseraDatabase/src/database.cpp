#include "database.h"



void Database::Add(const Date& date, const string& event) {
	if (data_.count(date) < 1) {
		data_.insert({date,{event}});
	} else {
		vector<string>& events = data_.at(date);
		auto entry = find(events.begin(), events.end(), event);
		if (entry == events.end()) {
			data_.at(date).push_back(event);
		}
	}
}

void Database::Print(ostream& os) {
	for (const auto& [date, events] : data_){
		os << date;
		for (auto event : events) {
			os << " " << event;
		}
		os << endl;
	}
}

string Database::Last(const Date& date){
	auto it = --data_.upper_bound(date);
	return it->second[it->second.size() - 1];
}


