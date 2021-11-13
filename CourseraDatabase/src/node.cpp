#include "node.h"
#include "logic_operations.h"

bool EmptyNode::Evaluate(const Date& date, const string& event) const {
	return true;
}

bool DateComparisonNode::Evaluate(const Date& date, const string& event) const {
	return GetComparisonResult(date, date_, comp_);
}

bool EventComparisonNode::Evaluate(const Date& date, const string& event) const {
	return GetComparisonResult(event, event_, comp_);
}

bool LogicalOperationNode::Evaluate(const Date& date, const string& event) const {//?????
	return  DoLogicOp(
			logic_op_,
			left_->Evaluate(date, event),
			right_->Evaluate(date, event));
}


