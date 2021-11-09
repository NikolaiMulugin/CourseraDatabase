#pragma once;

#include <iostream>

using namespace std;



enum class LogicalOperation{
	Or,
	And,
};

bool DoLogicOp (LogicalOperation& op, bool lhs, bool rhs) const;

enum class Comparison{
	Less,
	LessOrEqual,
	Greater,
	GreaterOrEqual,
	Equal,
	NotEqual,
};
