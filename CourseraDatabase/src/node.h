#pragma once

#include <iostream>
#include "date.h"

using namespace std;

class Node{
public:
	bool Evaluate(const Date& date, const string& event);//???
};
class EmptyNode: public Node{};
class DateComparisonNode: public Node{};
class EventComparisonNode: public Node{};
class LogicalOperationNode: public Node{};
