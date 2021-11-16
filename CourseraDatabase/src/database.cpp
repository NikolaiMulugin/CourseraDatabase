#include "database.h"


void Database::Add(const Date& date, const string& event) {
	if (data_.count(date) < 1) {
		data_.insert({date,{event}});
		event_count_.insert({{date, event}, 1});
	} else {
		if (event_count_.count({date,event}) == 0 ){
			event_count_.insert({{date,event},1});
			data_.at(date).push_back(event);
		} else {
			if (event_count_.at({date,event}) == 0 ){
				event_count_.at({date,event}) = 1;
				data_.at(date).push_back(event);
			}
		}
	}
}

void Database::Print(ostream& os) const {
	for (const auto& [date, events] : data_){
		for (auto event : events) {
			os << date << " " << event << endl;
		}
	}
}

Entry Database::Last(const Date& date) const {
	auto it = data_.upper_bound(date);
	if (it == begin(data_))
		throw invalid_argument("");
	--it;
	return {it->first, it->second[it->second.size() - 1]};
}

Entry::Entry(const Date& d, const string& e): date(d), event(e){}

ostream& operator<< (ostream& os, const Entry& entry) {
	os << entry.date << " " << entry.event;
	return os;
};

bool operator== (const Entry& lhs_en, const Entry& rhs_en) {
	return tie(lhs_en.date, lhs_en.event) == tie(rhs_en.date, rhs_en.event);
}

bool operator!= (const Entry& lhs_en, const Entry& rhs_en) {
	return !(lhs_en == rhs_en);
}

bool operator< (const Entry& lhs_en, const Entry& rhs_en) {
	return tie(lhs_en.date, lhs_en.event) < tie(rhs_en.date, rhs_en.event);
}



