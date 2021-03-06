#include "test_queue.h"
#include "list/container/queue/queue.h"

TestQueue::TestQueue() {}

TestQueue::~TestQueue() {}

void TestQueue::test_push() {
    Queue<int> queue;
    queue.push_back(1);
    queue.push_back(2);
    queue.push_back(3);
    QVERIFY(queue.get_size() == 3);
    QVERIFY(queue.front() == 1);
}

void TestQueue::test_pop() {
    Queue<int> queue;
    for (int i = 1; i <= 5; i++) queue.push_back(i);
    queue.pop_front();
    queue.pop_front();
    queue.pop_front();
    QVERIFY(queue.get_size() == 2);
    QVERIFY(queue.front() == 4);
}

void TestQueue::test_exceptions() {
    Queue<int> queue;
    queue.set_safety(true);
    queue.push_back(1);
    queue.clear();
    bool flag;
    flag = false;
    try { queue.pop_front(); }
    catch (...) { flag = true; }
    QVERIFY(flag);
    flag = false;
    try { queue.front(); }
    catch (...) { flag = true; }
    QVERIFY(flag);
    flag = false;
    try { queue.push_back(1).pop_front().pop_front().push_back(2); }
    catch (...) { flag = true; }
    QVERIFY(flag);
    QVERIFY(queue.get_size() == 0);
}

void TestQueue::test_chaining() {
    Queue<int> queue;
    queue.push_back(1).push_back(2).push_back(3);
    QVERIFY(queue.get_size() == 3);
    QVERIFY(queue.front() == 1);
    queue.pop_front().pop_front().push_back(5);
    QVERIFY(queue.front() == 3);
    queue.pop_front();
    QVERIFY(queue.front() == 5);
    QVERIFY(queue.get_size() == 1);
}
