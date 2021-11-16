#include "node.h"
#include "logic_operations.h"

DateComparisonNode::DateComparisonNode(const Comparison& c, const Date& d): comp(c), date(d){}

EventComparisonNode::EventComparisonNode(const Comparison& c, const string& e): comp(c), event(e){}

LogicalOperationNode::LogicalOperationNode(const LogicalOperation& lo, const shared_ptr<Node>& l,
		const shared_ptr<Node>& r): logic_op(lo),left(l),right(r) {}


bool EmptyNode::Evaluate(const Date& d, const string& e) const {
	return true;
}

bool DateComparisonNode::Evaluate(const Date& d, const string& e) const {
	return GetComparisonResult(d, date, comp);
}

bool EventComparisonNode::Evaluate(const Date& d, const string& e) const {
	return GetComparisonResult(e, event, comp);
}

bool LogicalOperationNode::Evaluate(const Date& d, const string& e) const {//?????
	return  DoLogicOp(
			logic_op,
			left->Evaluate(d, e),
			right->Evaluate(d, e));
}


