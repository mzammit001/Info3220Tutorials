#include <iostream>
#include "student.h"

int main(int argc, char *argv[])
{
    using namespace Week4;
    auto d = Date(9,11,2001);

//    std::cout << d.dateAsString() << std::endl;

    auto p = Student("Joe", "Smith", Date(1,1,1998), "Philosophy");

    auto record = p.getRecord();

    std::cout << record << std::endl;
    std::cout << "Current age: " << p.getCurrentAge() << std::endl;

    return 0;

}
