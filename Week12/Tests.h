#ifndef TESTS_H
#define TESTS_H

#include "SharedPointer.h"
#include <iostream>

class Tests
{
public:
    static bool runTests();

private:
    Tests();
    bool defaultConstructorTest() const;
    bool stringPassedByReferenceConstructorTest() const;
    bool getTest() const;
    bool dereferenceOperatorTest1() const;
    bool dereferenceOperatorTest2() const;
    bool dereferenceOperatorTest3() const;
    bool dereferenceObjectMemberTest1() const;
    bool dereferenceObjectMemberTest2() const;
    bool pointerConstructorTest() const;
    bool simpleCopyConstructorTest() const;
    bool uniqueTest1() const;
    bool uniqueTest2() const;
    bool uniqueTest3() const;
    bool complexCopyConstructorTest() const;
    bool assignmentOperatorTest1() const;
    bool assignmentOperatorTest2() const;
    bool assignmentOperatorTest3() const;
    bool resetTest1() const;
    bool resetTest2() const;
    bool boolOperatorTest1() const;
    bool boolOperatorTest2() const;

    inline void updateFailCounter();
    inline bool failedTests() const;

    unsigned int m_testFailCounter;
};

#endif // TESTS_H
