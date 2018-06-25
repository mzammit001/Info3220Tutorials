#include "EuclideanVector.h"

#include <iostream>
#include <string>
#include <vector>

using namespace Week9;

// create using value
bool createUsingSize()
{
    EuclideanVector vector(6);
    return 6 == vector.size();
}
// create using vector
bool createUsingVector()
{
    std::vector<double> first;
    first.push_back(1);
    first.push_back(2);
    first.push_back(3);

    EuclideanVector vector(first);
    return true;
}
// create using copy constructor
bool createUsingCopyConstructor()
{
    std::vector<double> first;
    first.push_back(1);
    first.push_back(2);
    first.push_back(3);

    EuclideanVector v1(first);
    EuclideanVector v2(v1);
    return v1.size() == v2.size();
}
// access using []
bool accessorTest()
{
    std::vector<double> first;
    first.push_back(1);
    first.push_back(2);
    first.push_back(3);

    EuclideanVector v1(first);

    return ((1.1 - v1[0]) < 0.11) && ((2.1 - v1[1]) < 0.11) && ((3.1 - v1[2]) < 0.11);
}
// const access using []
bool constAccessorTest()
{
    std::vector<double> first;
    first.push_back(1);
    first.push_back(2);
    first.push_back(3);

    const EuclideanVector v1(first);
    return (1.1 - v1[0]) < 0.11 && (2.1 - v1[1]) < 0.11 && (3.1 - v1[2]) < 0.11;
}

// access using []
bool invalidAccessorTest1()
{
    std::vector<double> first;
    first.push_back(1);
    first.push_back(2);
    first.push_back(3);

    EuclideanVector v1(first);

    try
    {
        double x = v1[-1];
        return false && (bool) x;
    }
    catch (VectorIndexOutOfBoundsException e)
    {
        return std::string("Index is greater than or equal to the allocated size") == std::string(e.getMessage());
    }
}

// access using []
bool invalidAccessorTest2()
{
    std::vector<double> first;
    first.push_back(1);
    first.push_back(2);
    first.push_back(3);

    EuclideanVector v1(first);

    try
    {
        double x = v1[4];
        return false && (bool) x;
    }
    catch (VectorIndexOutOfBoundsException e)
    {
        return std::string("Index is greater than or equal to the allocated size") == (e.getMessage());
    }
}

// access using []
bool invalidAccessorTest3()
{
    std::vector<double> first;
    first.push_back(1);
    first.push_back(2);
    first.push_back(3);

    EuclideanVector v1(first);

    try
    {
        double x = v1[3];
        return false && (bool) x;
    }
    catch (VectorIndexOutOfBoundsException e)
    {
        return std::string("Index is greater than or equal to the allocated size") == (e.getMessage());
    }
}

// const access using []
bool invalidConstAccessorTest1()
{
    std::vector<double> first;
    first.push_back(1);
    first.push_back(2);
    first.push_back(3);

    const EuclideanVector v1(first);

    try
    {
        double x = v1[-1];
        return false && (bool) x;
    }
    catch (VectorIndexOutOfBoundsException e)
    {
        return std::string("Index is greater than or equal to the allocated size") == (e.getMessage());
    }
}

// const access using []
bool invalidConstAccessorTest2()
{
    std::vector<double> first;
    first.push_back(1);
    first.push_back(2);
    first.push_back(3);

    const EuclideanVector v1(first);

    try
    {
        double x = v1[4];
        return false && (bool) x;
    }
    catch (VectorIndexOutOfBoundsException e)
    {
        return std::string("Index is greater than or equal to the allocated size") == (e.getMessage());
    }

    return false;
}

// const access using []
bool invalidConstAccessorTest3()
{
    std::vector<double> first;
    first.push_back(1);
    first.push_back(2);
    first.push_back(3);

    const EuclideanVector v1(first);

    try
    {
        double x = v1[4];
        return false && (bool) x;
    }
    catch (VectorIndexOutOfBoundsException e)
    {
        return std::string("Index is greater than or equal to the allocated size") == (e.getMessage());
    }

    return false;
}

// modify using []
bool elementModificationTest()
{
    EuclideanVector v1(100);
    for (int i = 0; i < 100; ++i)
    {
        v1[i] = i+1;
    }
    return (1.1 - v1[0]) < 0.11 && (2.1 - v1[1]) < 0.11 && (100.1 - v1[99]) < 0.11;
}

// size method test
bool sizeTest()
{
    EuclideanVector v1(100);
    return 100 == v1.size();
}

// valid assignment operator test
bool validAssignmentTest1()
{
    EuclideanVector v1(100);
    for (int i = 0; i < 100; ++i)
    {
        v1[i] = i+1;
    }
    EuclideanVector v2(100);
    v2 = v1;
    return (1.1 - v2[0]) < 0.11 && (2.1 - v2[1]) < 0.11 && (100.1 - v2[99]) < 0.11;
}

// valid assignment operator test
bool validAssignmentTest2()
{
    EuclideanVector v1(100);
    for (int i = 0; i < 100; ++i)
    {
        v1[i] = i+1;
    }

    EuclideanVector v2 = v1;
    return (1.1 - v2[0]) < 0.11 && (2.1 - v2[1]) < 0.11 && (100.1 - v2[99]) < 0.11;
}

// invalid assignment operator test
bool invalidAssignmentTest1()
{
    EuclideanVector v1(100);
    for (int i = 0; i < 100; ++i)
    {
        v1[i] = i+1;
    }

    EuclideanVector v2(50);

    try
    {
        v2 = v1;
    }
    catch(VectorAssignmentException e)
    {
        return std::string("Incompatible Vector Sizes") == std::string(e.getMessage());
    }
    return false;
}

// invalid assignment operator test
bool invalidAssignmentTest2()
{
    EuclideanVector v1(100);
    for (int i = 0; i < 100; ++i)
    {
        v1[i] = i+1;
    }
    EuclideanVector v2(1000);

    try
    {
        v2 = v1;
    }
    catch(VectorAssignmentException e)
    {
        return std::string("Incompatible Vector Sizes") == std::string(e.getMessage());
    }
    return false;
}

// equality test
bool equalityTest()
{
    EuclideanVector v1(4);
    v1[0] = 1/3.0;
    v1[1] = 2/3.0;
    v1[2] = 3/3.0;
    v1[3] = 4/3.0;

    EuclideanVector v2(4);
    v2[0] = 0.333;
    v2[1] = 0.666;
    v2[2] = 1.000;
    v2[3] = 1.333;

    return v1 == v2;
}
// inequality test
bool inequalityTest()
{
    EuclideanVector v1(4);
    v1[0] = 1/3.0;
    v1[1] = 2/3.0;
    v1[2] = 3/3.0;
    v1[3] = 4/3.0;

    EuclideanVector v2(4);
    v2[0] = 1.333;
    v2[1] = 1.666;
    v2[2] = 2.000;
    v2[3] = 2.333;

    return v1 != v2;
}
// length test
bool lengthTest()
{
    EuclideanVector v1(3);
    v1[0] = 1;
    v1[1] = -2;
    v1[2] = 3;

    double length = v1.length();

    return length > 3.7 && length < 3.8;
}
bool unitVectorTest()
{
    EuclideanVector v1(3);
    v1[0] = 1;
    v1[1] = -2;
    v1[2] = 2;

    EuclideanVector unitVector = v1.unitVector();

    return 0.34 > unitVector[0] && 0.32 < unitVector[0]
        && -0.67 < unitVector[1] && -0.65 > unitVector[1]
        && 0.67 > unitVector[2] && 0.65 < unitVector[2];
}
// dot product test
bool dotProductTest()
{
    EuclideanVector v1(3);
    v1[0] = 1;
    v1[1] = 3;
    v1[2] = -5;

    EuclideanVector v2(3);
    v2[0] = 4;
    v2[1] = -2;
    v2[2] = -1;

    return 3.1 - v1.dotProduct(v2) < 0.2;
}
// addition test
bool additionTest()
{
    EuclideanVector v1(2);
    v1[0] = 1;
    v1[1] = 0;

    EuclideanVector v2(2);
    v2[0] = 0;
    v2[1] = 1;

    EuclideanVector expected(2);
    expected[0] = 1;
    expected[1] = 1;

    EuclideanVector result = v1 + v2;

    return expected == result;
}
// addition chain test
bool additionChainTest()
{
    EuclideanVector v1(3);
    v1[0] = 1;
    v1[1] = 0;
    v1[2] = 0;

    EuclideanVector v2(3);
    v2[0] = 0;
    v2[1] = 1;
    v2[2] = 0;

    EuclideanVector v3(3);
    v3[0] = 0;
    v3[1] = 0;
    v3[2] = 1;

    EuclideanVector expected(3);
    expected[0] = 1;
    expected[1] = 1;
    expected[2] = 1;

    EuclideanVector result = v1 + v2 + v3;

    return expected == result;
}
// subtration test
bool subtractionTest()
{
    EuclideanVector v1(2);
    v1[0] = 1;
    v1[1] = 0;

    EuclideanVector v2(2);
    v2[0] = 1;
    v2[1] = 1;

    EuclideanVector expected(2);
    expected[0] = 0;
    expected[1] = -1;

    EuclideanVector result = v1 - v2;

    return expected == result;
}
// subtration chain test
bool subtractionChainTest()
{
    EuclideanVector v1(3);
    v1[0] = 1;
    v1[1] = 1;
    v1[2] = 1;

    EuclideanVector v2(3);
    v2[0] = 1;
    v2[1] = 0;
    v2[2] = 0;

    EuclideanVector v3(3);
    v3[0] = 0;
    v3[1] = 1;
    v3[2] = 0;

    EuclideanVector v4(3);
    v4[0] = 0;
    v4[1] = 0;
    v4[2] = 1;

    EuclideanVector expected(3);
    expected[0] = 0;
    expected[1] = 0;
    expected[2] = 0;

    EuclideanVector result = v1 - v2 - v3 - v4;

    return expected == result;
}
// += test
bool cumlativeAdditionTest()
{
    EuclideanVector v1(2);
    v1[0] = 1;
    v1[1] = 0;

    EuclideanVector v2(2);
    v2[0] = 0;
    v2[1] = 1;

    v1 += v2;

    EuclideanVector expected(2);
    expected[0] = 1;
    expected[1] = 1;

    return expected == v1;
}
// -= test
bool cumlativeSubtractionTest()
{
    EuclideanVector v1(2);
    v1[0] = 1;
    v1[1] = 0;

    EuclideanVector v2(2);
    v2[0] = 0;
    v2[1] = 1;

    v1 -= v2;

    EuclideanVector expected(2);
    expected[0] = 1;
    expected[1] = -1;

    return expected == v1;
}
// *= test
bool cumlativeMultiplicationTest()
{
    EuclideanVector v1(2);
    v1[0] = 4;
    v1[1] = 2;

    v1 *= 2.5;

    EuclideanVector expected(2);
    expected[0] = 10.0;
    expected[1] = 5.0;

    return expected == v1;
}
// /= test
bool cumlativeDivisionTest()
{
    EuclideanVector v1(2);
    v1[0] = 4;
    v1[1] = 2;

    v1 /= 8.0;

    EuclideanVector expected(2);
    expected[0] = 0.5;
    expected[1] = 0.25;

    return expected == v1;
}
// invalid mathamatics test
bool invalidMathamaticsTest()
{
    int numberOfExceptionsThrown = 0;
    EuclideanVector v1(2);
    v1[0] = 1;
    v1[1] = 0;

    EuclideanVector v2(3);
    v2[0] = 0;
    v2[1] = 1;
    v2[2] = 2;

    try
    {
        EuclideanVector v3 = v1 + v2;
        return false && bool (v3.size());
    }
    catch (VectorArithmeticException e)
    {
        if (std::string("Vectors are not the same size") == std::string(e.getMessage()))
        {
            ++numberOfExceptionsThrown;
        }
    }
    try
    {
        EuclideanVector v3 = v1 - v2;
        return false && bool (v3.size());
    }
    catch (VectorArithmeticException e)
    {
        if (std::string("Vectors are not the same size") == std::string(e.getMessage()))
        {
            ++numberOfExceptionsThrown;
        }
    }
    try
    {
        EuclideanVector v3 = v2 + v1;
        return false && bool (v3.size());
    }
    catch (VectorArithmeticException e)
    {
        if (std::string("Vectors are not the same size") == std::string(e.getMessage()))
        {
            ++numberOfExceptionsThrown;
        }
    }
    try
    {
        EuclideanVector v3 = v2 - v1;
        return false && bool (v3.size());
    }
    catch (VectorArithmeticException e)
    {
        if (std::string("Vectors are not the same size") == std::string(e.getMessage()))
        {
            ++numberOfExceptionsThrown;
        }
    }
    try
    {
        EuclideanVector v3(v1);
        EuclideanVector v4(v2);

        v4 += v3;
        return false && bool (v3.size()) &&  bool (v4.size());
    }
    catch (VectorArithmeticException e)
    {
        if (std::string("Vectors are not the same size") == std::string(e.getMessage()))
        {
            ++numberOfExceptionsThrown;
        }
    }
    try
    {
        EuclideanVector v3(v1);
        EuclideanVector v4(v2);

        v3 += v4;
        return false && bool (v3.size()) &&  bool (v4.size());
    }
    catch (VectorArithmeticException e)
    {
        if (std::string("Vectors are not the same size") == std::string(e.getMessage()))
        {
            ++numberOfExceptionsThrown;
        }
    }
    try
    {
        EuclideanVector v3(v1);
        EuclideanVector v4(v2);

        v4 -= v3;
        return false && bool (v3.size()) &&  bool (v4.size());
    }
    catch (VectorArithmeticException e)
    {
        if (std::string("Vectors are not the same size") == std::string(e.getMessage()))
        {
            ++numberOfExceptionsThrown;
        }
    }
    try
    {
        EuclideanVector v3(v1);
        EuclideanVector v4(v2);

        v3 -= v4;
        return false && bool (v3.size()) &&  bool (v4.size());
    }
    catch (VectorArithmeticException e)
    {
        if (std::string("Vectors are not the same size") == std::string(e.getMessage()))
        {
            ++numberOfExceptionsThrown;
        }
    }
    try
    {
        double result = v1.dotProduct(v2);
        return false && bool (result);
    }
    catch (VectorArithmeticException e)
    {
        if (std::string("Vectors are not the same size") == std::string(e.getMessage()))
        {
            ++numberOfExceptionsThrown;
        }
    }
    try
    {
        double result = v2.dotProduct(v1);
        return false && bool (result);
    }
    catch (VectorArithmeticException e)
    {
        if (std::string("Vectors are not the same size") == std::string(e.getMessage()))
        {
            ++numberOfExceptionsThrown;
        }
    }

    return 10 == numberOfExceptionsThrown;
}

int main()
{
    int numberOfTestsFailed = 0;
    if (!createUsingSize())
    {
        std::cout << "Creating Using Size Value Test Failed" << std::endl;
        ++numberOfTestsFailed;
    }
    if (!createUsingVector())
    {
        std::cout << "Creating Using std::vector<double> Test Failed" << std::endl;
        ++numberOfTestsFailed;
    }
    if (!createUsingCopyConstructor())
    {
        std::cout << "Creating Using Copy Constructor Test Failed" << std::endl;
        ++numberOfTestsFailed;
    }
    if (!accessorTest())
    {
        std::cout << "operator[] Test Failed" << std::endl;
        ++numberOfTestsFailed;
    }
    if (!constAccessorTest())
    {
        std::cout << "const operator[] Test Failed" << std::endl;
        ++numberOfTestsFailed;
    }
    if (!invalidAccessorTest1())
    {
        std::cout << "invalid operator[] Test 1 Failed" << std::endl;
        ++numberOfTestsFailed;
    }
    if (!invalidAccessorTest2())
    {
        std::cout << "invalid operator[] Test 2 Failed" << std::endl;
        ++numberOfTestsFailed;
    }
    if (!invalidAccessorTest3())
    {
        std::cout << "invalid operator[] Test 3 Failed" << std::endl;
        ++numberOfTestsFailed;
    }
    if (!invalidConstAccessorTest1())
    {
        std::cout << "invalid const operator[] Test 1 Failed" << std::endl;
        ++numberOfTestsFailed;
    }
    if (!invalidConstAccessorTest2())
    {
        std::cout << "invalid const operator[] Test 2 Failed" << std::endl;
        ++numberOfTestsFailed;
    }
    if (!invalidConstAccessorTest3())
    {
        std::cout << "invalid const operator[] Test 3 Failed" << std::endl;
        ++numberOfTestsFailed;
    }
    if (!elementModificationTest())
    {
        std::cout << "operator[] modification Test Failed" << std::endl;
        ++numberOfTestsFailed;
    }
    if (!sizeTest())
    {
        std::cout << "Size Test Failed" << std::endl;
        ++numberOfTestsFailed;
    }
    if (!validAssignmentTest1())
    {
        std::cout << "Valid Assignment Test 1 Failed" << std::endl;
        ++numberOfTestsFailed;
    }
    if (!validAssignmentTest2())
    {
        std::cout << "Valid Assignment Test 2 Failed" << std::endl;
        ++numberOfTestsFailed;
    }
    if (!invalidAssignmentTest1())
    {
        std::cout << "Invalid Assignment Test 1 Failed" << std::endl;
        ++numberOfTestsFailed;
    }
    if (!invalidAssignmentTest2())
    {
        std::cout << "Invalid Assignment Test 2 Failed" << std::endl;
        ++numberOfTestsFailed;
    }
    if (!equalityTest())
    {
        std::cout << "Equality Test Failed" << std::endl;
        ++numberOfTestsFailed;
    }
    if (!inequalityTest())
    {
        std::cout << "Inequality Test Failed" << std::endl;
        ++numberOfTestsFailed;
    }
    if (!lengthTest())
    {
        std::cout << "Vector Length Test Failed" << std::endl;
        ++numberOfTestsFailed;
    }
    if (!dotProductTest())
    {
        std::cout << "Dot Product Test Failed" << std::endl;
        ++numberOfTestsFailed;
    }
    if (!unitVectorTest())
    {
        std::cout << "Unit Vector Test Failed" << std::endl;
        ++numberOfTestsFailed;
    }
    if (!additionTest())
    {
        std::cout << "Addition Test Failed" << std::endl;
        ++numberOfTestsFailed;
    }
    if (!additionChainTest())
    {
        std::cout << "Addition Chain Test Failed" << std::endl;
        ++numberOfTestsFailed;
    }
    if (!subtractionTest())
    {
        std::cout << "Subtraction Test Failed" << std::endl;
        ++numberOfTestsFailed;
    }
    if (!subtractionChainTest())
    {
        std::cout << "Subtraction Chain Test Failed" << std::endl;
        ++numberOfTestsFailed;
    };
    if (!cumlativeAdditionTest())
    {
        std::cout << "Cumlative Addition Test Failed" << std::endl;
        ++numberOfTestsFailed;
    }
    if (!cumlativeSubtractionTest())
    {
        std::cout << "Cumlative Subtraction Test Failed" << std::endl;
        ++numberOfTestsFailed;
    }
    if (!cumlativeMultiplicationTest())
    {
        std::cout << "Multiply Scaling Test Failed" << std::endl;
        ++numberOfTestsFailed;
    }
    if (!cumlativeDivisionTest())
    {
        std::cout << "Division Scaling Test Failed" << std::endl;
        ++numberOfTestsFailed;
    }
    if (!invalidMathamaticsTest())
    {
        std::cout << "Different size vectors used for math operations Test Failed" << std::endl;
        ++numberOfTestsFailed;
    }

    if (0 == numberOfTestsFailed)
    {
        std::cout << "Congratulations all tests passed!!!" << std::endl;
    }
    else
    {
        std::cout << numberOfTestsFailed << " Tests Failed" << std::endl;
    }
}
