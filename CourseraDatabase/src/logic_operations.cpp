#include "logic_operations.h"

bool DoLogicOp(const LogicalOperation& op, bool lhs, bool rhs) {
	bool res = (op == LogicalOperation::And) ? (lhs && rhs) : (lhs || rhs);
	return res;
}


