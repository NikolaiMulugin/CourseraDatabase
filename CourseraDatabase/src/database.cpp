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
		for (auto e : events) {
			os << " " << events;
		}
		os << endl;
	}
}

