#pragma once

#include "logic_operations.h"
#include <iostream>
#include <algorithm>
#include "date.h"
#include <memory>

using namespace std;

class Node{
public:
	Node(){}
	virtual bool Evaluate(const Date& date, const string& event) = 0;//???
};
class EmptyNode: public Node{
public:
	EmptyNode(): Node(){}
	bool Evaluate(const Date& date, const string& event) override;
};

class DateComparisonNode: public Node{
public:
	DateComparisonNode(const Comparison& c, const Date& d): Node(), comp_(c), date_(d){}
	bool Evaluate(const Date& date, const string& event);
private:
	const Comparison comp_;
	const Date date_;
};

class EventComparisonNode: public Node{
public:
	EventComparisonNode(const Comparison& c, const string& e): Node(), comp_(c), event_(e){}
	bool Evaluate(const Date& date, const string& event) override;
private:
	const Comparison comp_;
	const string event_;
};

class LogicalOperationNode: public Node{
public:
	bool Evaluate(const Date& date, const string& event) override;
	LogicalOperationNode(const LogicalOperation& lo, const shared_ptr<Node>& l,
			const shared_ptr<Node>& r): Node(), logic_op_(lo),left_(l),right_(r) {}
private:
	const LogicalOperation logic_op_;
	const shared_ptr<Node> left_;
	const shared_ptr<Node> right_;

};
