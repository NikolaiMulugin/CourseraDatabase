#pragma once

#include <iostream>

using namespace std;



enum class LogicalOperation{
	Or,
	And,
};

bool DoLogicOp (const LogicalOperation& op, bool lhs, bool rhs);

enum class Comparison{
	Less,
	LessOrEqual,
	Greater,
	GreaterOrEqual,
	Equal,
	NotEqual,
};
