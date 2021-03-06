#include "test_stack.h"
#include "list/container/stack/stack.h"

TestStack::TestStack() {}

TestStack::~TestStack() {}

void TestStack::test_push() {
    Stack<int> stack;
    stack.push_back(1);
    stack.push_back(2);
    stack.push_back(3);
    QVERIFY(stack.get_size() == 3);
    QVERIFY(stack.back() == 3);
}

void TestStack::test_pop() {
    Stack<int> stack;
    for (int i = 1; i <= 5; i++) stack.push_back(i);
    stack.pop_back();
    stack.pop_back();
    stack.pop_back();
    QVERIFY(stack.get_size() == 2);
    QVERIFY(stack.back() == 2);
}

void TestStack::test_exceptions() {
    Stack<int> stack;
    stack.set_safety(true);
    stack.push_back(1);
    stack.clear();
    bool flag;
    flag = false;
    try { stack.pop_back(); }
    catch (...) { flag = true; }
    QVERIFY(flag);
    flag = false;
    try { stack.back(); }
    catch (...) { flag = true; }
    QVERIFY(flag);
    flag = false;
    try { stack.push_back(1).pop_back().pop_back().push_back(2); }
    catch (...) { flag = true; }
    QVERIFY(flag);
    QVERIFY(stack.get_size() == 0);
}

void TestStack::test_chaining() {
    Stack<int> stack;
    stack.push_back(1).push_back(2).push_back(3);
    QVERIFY(stack.get_size() == 3);
    QVERIFY(stack.back() == 3);
    stack.pop_back().pop_back().push_back(5);
    QVERIFY(stack.back() == 5);
    stack.pop_back();
    QVERIFY(stack.back() == 1);
    QVERIFY(stack.get_size() == 1);
}
