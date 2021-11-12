#include "../node.h"
#include "../database.h"
#include "test_runner.h"

#include <sstream>
using namespace std;

void TestNode() {
  {
	 auto ecn = EventComparisonNode(Comparison::LessOrEqual, "event");
	auto condition = make_shared<EmptyNode>();
	auto predicat = [condition](const Date& date, const string& event) {
	  return condition->Evaluate(date, event);
	};
	auto en = EmptyNode();

    Database db;
    db.Add({2000,1,1}, "first event");
    db.Add({2010,3,1}, "second event");
    db.Add({2010,3,1}, "third event");
    auto entries = db.FindIf(predicat);
    Assert(en.Evaluate({2017, 1, 1}, ""), "EmptyNode.Evaluate() returns always true");
    Assert(entries.size() == 3, "FindIF empty condition with three events finds all");

    int count = db.RemoveIf(predicat);
    Assert(count == 3, "RemoveIf with empty condition removes everythin");
  }

}
