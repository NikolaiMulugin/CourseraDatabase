#include "node.h"
#include "logic_operations.h"

bool EmptyNode::Evaluate(const Date& date, const string& event) {
	return true;
}

bool DateComparisonNode::Evaluate(const Date& date, const string& event) {
	bool ans = ((date < date_  and
			   	   (comp_ == Comparison::LessOrEqual or
			   			   comp_ == Comparison::Less or
			   			   comp_ == Comparison::NotEqual)) or
			   (date > date_ and
				   (comp_ == Comparison::Greater or
						   comp_ == Comparison::GreaterOrEqual or
						   comp_ == Comparison::NotEqual)) or
			   (date == date_ and
				   (comp_ == Comparison::Equal or
						   comp_ == Comparison::GreaterOrEqual or
				    comp_ == Comparison::LessOrEqual)));
	return ans;
}

bool EventComparisonNode::Evaluate(const Date& date, const string& event) {
	bool ans = (event_ == event  and (comp_ == Comparison::Equal or
									  comp_ == Comparison::GreaterOrEqual or
									  comp_ == Comparison::LessOrEqual) ) or
			   (event_ != event and (comp_ == Comparison::NotEqual or
					   	   	   	   	 comp_ == Comparison::Less or
									 comp_ == Comparison::Greater)) or
			   (event_ < event and (comp_ == Comparison::NotEqual or
					   	   	   	   	comp_ == Comparison::LessOrEqual or
									comp_ == Comparison::Less)) or
			   (event_ > event and (comp_ == Comparison::NotEqual or
								    comp_ == Comparison::GreaterOrEqual or
								    comp_ == Comparison::Greater ));
	return ans;
}

bool LogicalOperationNode::Evaluate(const Date& date, const string& event) {//?????
	return  DoLogicOp(
			logic_op_,
			left_->Evaluate(date, event),
			right_->Evaluate(date, event));
}


