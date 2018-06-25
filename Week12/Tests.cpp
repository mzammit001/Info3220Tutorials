#include <string>

#include "Tests.h"

using namespace week12;

Tests::Tests()
    : m_testFailCounter(0)
{

}

bool Tests::runTests()
{
    Tests tests;
    if (!tests.defaultConstructorTest())
    {
        std::cout << "Failed Default Constructor Test" << std::endl;
        tests.updateFailCounter();
    }
    if (!tests.stringPassedByReferenceConstructorTest())
    {
        std::cout << "Failed Constructor passed by Reference Test" << std::endl;
        tests.updateFailCounter();
    }
    if (!tests.getTest())
    {
        std::cout << "Failed get() Test" << std::endl;
        tests.updateFailCounter();
    }
    if (!tests.dereferenceOperatorTest1())
    {
        std::cout << "Failed Dereference Operator Test 1" << std::endl;
        tests.updateFailCounter();
    }
    if (!tests.dereferenceOperatorTest2())
    {
        std::cout << "Failed Dereference Operator Test 2" << std::endl;
        tests.updateFailCounter();
    }
    if (!tests.dereferenceOperatorTest3())
    {
        std::cout << "Failed Dereference Operator Test 3" << std::endl;
        tests.updateFailCounter();
    }
    if (!tests.dereferenceObjectMemberTest1())
    {
        std::cout << "Failed Dereference Member Test" << std::endl;
        tests.updateFailCounter();
    }
    if (!tests.dereferenceObjectMemberTest2())
    {
        std::cout << "Failed Dereference Member Test" << std::endl;
        tests.updateFailCounter();
    }
    if (!tests.pointerConstructorTest())
    {
        std::cout << "Failed Pointer Constructor Test" << std::endl;
        tests.updateFailCounter();
    }
    if (!tests.simpleCopyConstructorTest())
    {
        std::cout << "Failed Simple Copy Constructor Test" << std::endl;
        tests.updateFailCounter();
    }
    if (!tests.uniqueTest1())
    {
        std::cout << "Failed Unique Pointer Test 1" << std::endl;
        tests.updateFailCounter();
    }
    if (!tests.uniqueTest2())
    {
        std::cout << "Failed Unique Pointer Test 2" << std::endl;
        tests.updateFailCounter();
    }
    if (!tests.uniqueTest3())
    {
        std::cout << "Failed Unique Pointer Test 3" << std::endl;
        tests.updateFailCounter();
    }
    if (!tests.complexCopyConstructorTest())
    {
        std::cout << "Failed Complex Copy Constructor Test" << std::endl;
        tests.updateFailCounter();
    }
    if (!tests.assignmentOperatorTest1())
    {
        std::cout << "Failed Assignment Operator Test 1" << std::endl;
        tests.updateFailCounter();
    }
    if (!tests.assignmentOperatorTest2())
    {
        std::cout << "Failed Assignment Operator Test 2" << std::endl;
        tests.updateFailCounter();
    }
    if (!tests.assignmentOperatorTest3())
    {
        std::cout << "Failed Assignment Operator Test 3" << std::endl;
        tests.updateFailCounter();
    }
    if (!tests.resetTest1())
    {
        std::cout << "Failed Reset Test 1" << std::endl;
        tests.updateFailCounter();
    }
    if (!tests.resetTest2())
    {
        std::cout << "Failed Reset Test 2" << std::endl;
        tests.updateFailCounter();
    }
    if (!tests.boolOperatorTest1())
    {
        std::cout << "Failed bool Operator Test 1" << std::endl;
        tests.updateFailCounter();
    }
    if (!tests.boolOperatorTest2())
    {
        std::cout << "Failed bool Operator Test 2" << std::endl;
        tests.updateFailCounter();
    }

    if (!tests.failedTests())
    {
        std::cout << "Well done on finishing the last coding exercise for INFO3220" << std::endl;
        return true;
    }
    return false;
}

void Tests::updateFailCounter()
{
    ++m_testFailCounter;
}

bool Tests::failedTests() const
{
    return 0 != m_testFailCounter;
}

bool Tests::defaultConstructorTest() const
{
    bool success = true;

    SharedPointer<std::string> pointer;

    return success;
}

bool Tests::stringPassedByReferenceConstructorTest() const
{
    bool success = true;

    SharedPointer<std::string> pointer("Hello World");

    return success;
}

bool Tests::getTest() const
{
    bool success = true;

    SharedPointer<std::string> pointer("Hello World");
    std::string* stringPointer = pointer.get();
    if ("Hello World" != *stringPointer)
    {
        success = false;
    }

    return success;
}

bool Tests::dereferenceOperatorTest1() const
{
    bool success = true;

    SharedPointer<std::string> pointer("Hello World");
    if ("Hello World" != *pointer)
    {
        success = false;
    }

    return success;
}

bool Tests::dereferenceOperatorTest2() const
{
    bool success = true;

    SharedPointer<std::string> pointer("Hello World");
    *pointer = "Different String";
    if ("Different String" != *pointer)
    {
        success = false;
    }

   return success;
}

bool Tests::dereferenceOperatorTest3() const
{
    // requires copy consturctor tests to pass first
    bool success = true;

    SharedPointer<std::string> pointer1("Hello World");
    SharedPointer<std::string> pointer2(pointer1);
    *pointer2 = "Different String";
    if ("Different String" != *pointer1)
    {
        success = false;
    }

    return success;
}

bool Tests::dereferenceObjectMemberTest1() const
{
    bool success = true;

    SharedPointer<std::string> pointer("Hello World");
    if (11 != pointer->size())
    {
        success = false;
    }

    return success;
}

bool Tests::dereferenceObjectMemberTest2() const
{
    bool success = true;

    SharedPointer<std::string> pointer("Hello");
    pointer->insert(5, " World");

    if (11 != pointer->size())
    {
        success = false;
    }

    return success;
}

bool Tests::pointerConstructorTest() const
{
    bool success = true;

    std::string* stringPointer = new std::string("Hello World");

    SharedPointer<std::string> pointer(stringPointer);
    if ("Hello World" != *pointer)
    {
        success = false;
    }
    delete stringPointer;
    if ("Hello World" != *pointer)
    {
        success = false;
    }

    return success;
}

bool Tests::simpleCopyConstructorTest() const
{
    bool success = true;

    SharedPointer<std::string> pointer1("Hello World");
    {
        SharedPointer<std::string> pointer2(pointer1);
        if ("Hello World" != *pointer2)
        {
            success = false;
        }
    }

   return success;
}

bool Tests::uniqueTest1() const
{
    SharedPointer<std::string> pointer1("Hello World");
    return pointer1.unique();
}

bool Tests::uniqueTest2() const
{
    SharedPointer<std::string> pointer1("Hello World");
    SharedPointer<std::string> pointer2(pointer1);
    return(!pointer1.unique() && !pointer2.unique());
}

bool Tests::uniqueTest3() const
{
    SharedPointer<std::string> pointer1;
    return(!pointer1.unique());
}

bool Tests::complexCopyConstructorTest() const
{
    bool success = true;

    SharedPointer<std::string> pointer1("Hello World");
    {
        SharedPointer<std::string> pointer2(pointer1);
        if ("Hello World" != *pointer2)
        {
            success = false;
        }
        if (pointer1.unique())
        {
            success = false;
        }
    }
    if (!pointer1.unique())
    {
        success = false;
    }
    return success;
}

bool Tests::assignmentOperatorTest1() const
{
    bool success = true;

    SharedPointer<std::string> pointer1("Hello World");
    {
        SharedPointer<std::string> pointer2 = pointer1;
        if ("Hello World" != *pointer2)
        {
            success = false;
        }
        if (pointer1.unique())
        {
            success = false;
        }
    }
    if (!pointer1.unique())
    {
        success = false;
    }
    return success;
}

bool Tests::assignmentOperatorTest2() const
{
    bool success = true;

    SharedPointer<std::string> pointer1("Hello World");
    SharedPointer<std::string> pointer2("Hello Smaller World");
    {
        SharedPointer<std::string> pointer3 = pointer1;
        if ("Hello World" != *pointer3)
        {
            success = false;
        }
        if (pointer1.unique())
        {
            success = false;
        }
        pointer3 = pointer2;
        if ("Hello Smaller World" != *pointer3)
        {
            success = false;
        }
        if (!pointer1.unique())
        {
            success = false;
        }
    }
    if (!pointer1.unique())
    {
        success = false;
    }
    if (!pointer2.unique())
    {
        success = false;
    }
    return success;
}

bool Tests::assignmentOperatorTest3() const
{
    bool success = true;

    SharedPointer<std::string> pointer1;
    {
        SharedPointer<std::string> pointer2("Hello World");
        pointer1 = pointer2;
        {
            SharedPointer<std::string> pointer3("Hello Smaller World");
            pointer2 = pointer3;
        }
    }
    if (!pointer1.unique())
    {
        success = false;
    }
    {
        SharedPointer<std::string> pointer3;
        {
            SharedPointer<std::string> pointer4("Hello Even Smaller World");
            pointer3 = pointer4;
        }
        SharedPointer<std::string> pointer2(*pointer3);
        pointer1 = pointer2;
    }
    if (!pointer1.unique())
    {
        success = false;
    }
	
    pointer1 = pointer1;

    if (!pointer1.unique())
    {
        success = false;
    }
	
    return success;
}

bool Tests::resetTest1() const
{
    bool success = true;

    SharedPointer<std::string> pointer1("Hello World");
    SharedPointer<std::string> pointer2(pointer1);

    pointer1.reset();

    if (!pointer2.unique())
    {
        success = false;
    }
    if (pointer1.unique())
    {
        success = false;
    }

    return success;
}

bool Tests::resetTest2() const
{
    bool success = true;

    SharedPointer<std::string> pointer1("Hello World");

    pointer1.reset();

    if (pointer1.unique())
    {
        success = false;
    }

    return success;
}

bool Tests::boolOperatorTest1() const
{
    bool success = true;

    SharedPointer<std::string> pointer;
    if(pointer)
    {
        success = false;
    }

    return success;
}

bool Tests::boolOperatorTest2() const
{
    bool success = true;

    SharedPointer<std::string> pointer("Hello");
    if(!pointer)
    {
        success = false;
    }

    return success;
}
