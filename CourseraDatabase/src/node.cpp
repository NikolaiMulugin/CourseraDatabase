#include "node.h"
#include "logic_operations.h"

bool EmptyNode::Evaluate(const Date& date, const string& event) {
	return false;
}

bool DateComparisonNode::Evaluate(const Date& date, const string& event) {
	//cout << comp_ << date_ << endl;
	bool ans = ((date < date_  and
			   	   (comp_ == Comparison::LessOrEqual or comp_ == Comparison::Less)) or
			   (date > date_ and
				   (comp_ == Comparison::Greater or comp_ == Comparison::GreaterOrEqual)) or
			   (date == date_ and
				   (comp_ == Comparison::Equal or comp_ == Comparison::GreaterOrEqual or
				    comp_ == Comparison::LessOrEqual)));
	return ans;
}

bool EventComparisonNode::Evaluate(const Date& date, const string& event) {
	//cout << comp_ << date_ << endl;
	bool ans = (event_ == event  and comp_ == Comparison::Equal ) or
			   (event_ != event and comp_ == Comparison::NotEqual );
	return ans;
}

bool LogicalOperationNode::Evaluate(const Date& date, const string& event) {//?????
	return  DoLogicOp(
			logic_op_,
			left_->Evaluate(date, event),
			right_->Evaluate(date, event));
}


