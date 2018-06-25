#include <iostream>
#include "MyTime.h"

using namespace Week07;

void test_add_time_equals() {
    Time t1(10,30,0);
    Time t2(2,30,0);
    Time t3(13,0,0);

    if (t1 + t2 == t3)
        std::cout << "Passed test: ";
    else
        std::cout << "Failed test: ";

    std::cout << t1.getTimeAsString() << " + " << t2.getTimeAsString() << " == " << t3.getTimeAsString() << std::endl;
}

void test_sub_time_equals() {
    Time t1(10,30,0);
    Time t2(2,30,0);
    Time t3(8,0,0);

    if (t1 - t2 == t3)
        std::cout << "Passed test: ";
    else
        std::cout << "Failed test: ";

    std::cout << t1.getTimeAsString() << " - " << t2.getTimeAsString() << " == " << t3.getTimeAsString() << std::endl;
}

void test_add_time_notequals() {
    Time t1(10,0,0);
    Time t2(2,0,0);
    Time t3(12,0,1);

    if (t1 + t2 != t3)
        std::cout << "Passed test: ";
    else
        std::cout << "Failed test: ";

    std::cout << t1.getTimeAsString() << " + " << t2.getTimeAsString() << " != " << t3.getTimeAsString() << std::endl;
}

void test_sub_time_notequals() {
    Time t1(10,0,0);
    Time t2(2,0,0);
    Time t3(8,0,1);

    if (t1 - t2 != t3)
        std::cout << "Passed test: ";
    else
        std::cout << "Failed test: ";

    std::cout << t1.getTimeAsString() << " - " << t2.getTimeAsString() << " != " << t3.getTimeAsString() << std::endl;
}

void test_time_equals() {
    Time t1(12,0,0);
    Time t2(12,0,0);

    if (t1 == t2)
        std::cout << "Passed test: ";
    else
        std::cout << "Failed test: ";

    std::cout << t1.getTimeAsString() << " == " << t2.getTimeAsString() << std::endl;
}

void test_time_notequals() {
    Time t1(12,0,0);
    Time t2(12,0,1);

    if (t1 != t2)
        std::cout << "Passed test: ";
    else
        std::cout << "Failed test: ";

    std::cout << t1.getTimeAsString() << " != " << t2.getTimeAsString() << std::endl;
}

void test_time_lessthan() {
    Time t1(12,0,0);
    Time t2(12,0,1);

    if (t1 < t2)
        std::cout << "Passed test: ";
    else
        std::cout << "Failed test: ";

    std::cout << t1.getTimeAsString() << " < " << t2.getTimeAsString() << std::endl;
}

void test_time_greaterthan() {
    Time t1(12,0,0);
    Time t2(12,0,1);

    if (t2 > t1)
        std::cout << "Passed test: ";
    else
        std::cout << "Failed test: ";

    std::cout << t2.getTimeAsString() << " > " << t1.getTimeAsString() << std::endl;
}

void test_time_greaterequals() {
    Time t1(12,0,0);
    Time t2(12,0,1);
    Time t3(12,0,0);

    if (t3 >= t1 && t2 >= t3)
        std::cout << "Passed test: ";
    else
        std::cout << "Failed test: ";

    std::cout << t3.getTimeAsString() << " >= " << t1.getTimeAsString() << " && " << t2.getTimeAsString() << " >= " << t3.getTimeAsString() << std::endl;
}

void test_time_lessequals() {
    Time t1(12,0,0);
    Time t2(12,0,1);
    Time t3(12,0,0);

    if (t3 <= t1 && t1 <= t2)
        std::cout << "Passed test: ";
    else
        std::cout << "Failed test: ";

    std::cout << t3.getTimeAsString() << " <= " << t1.getTimeAsString() << " && " << t1.getTimeAsString() << " <= " << t2.getTimeAsString() << std::endl;
}

void test_time_add_seconds() {
    Time t1(12,0,0);
    Time t2(12,30,0);
    int s1 = 1800;

    if (t1 + 1800 == t2)
        std::cout << "Passed test: ";
    else
        std::cout << "Failed test: ";

    std::cout << t1.getTimeAsString() << " + " << s1 << " = " << t2.getTimeAsString() << std::endl;
}

void test_time_numhours() {
    Time t1(12,30,0);
    double expected = 12.5;

    if (t1.numberOfHours() == expected)
        std::cout << "Passed test: ";
    else
        std::cout << "Failed test: ";

    std::cout << t1.getTimeAsString() << " number of hours: " << expected << std::endl;
}

void test_time_nummins() {
    Time t1(12,30,30);
    double expected = 750.5;

    if (t1.numberOfMinutes() == expected)
        std::cout << "Passed test: ";
    else
        std::cout << "Failed test: ";

    std::cout << t1.getTimeAsString() << " number of mins: " << expected << std::endl;
}

void test_time_numsecs() {
    Time t1(12,30,30);
    int expected = (12 * 3600) + (30 * 60) + 30;

    if (t1.numberOfSeconds() == expected)
        std::cout << "Passed test: ";
    else
        std::cout << "Failed test: ";

    std::cout << t1.getTimeAsString() << " number of secs: " << expected << std::endl;
}

int main(void) {
    Time t(19,31,40);

    std::cout << "Time as string: " << t.getTimeAsString() << std::endl;

    test_add_time_equals();
    test_add_time_notequals();
    test_sub_time_equals();
    test_sub_time_notequals();
    test_time_equals();
    test_time_notequals();
    test_time_lessthan();
    test_time_lessequals();
    test_time_greaterthan();
    test_time_greaterequals();
    test_time_add_seconds();
    test_time_numhours();
    test_time_nummins();
    test_time_numsecs();

    return 0;
}