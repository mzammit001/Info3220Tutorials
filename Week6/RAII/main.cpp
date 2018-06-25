#include <iostream>
#include "vector.h"

int main()
{
    unsigned int n = 3;
    Vector v1(n);
    Vector v2(n);

    for(unsigned int i = 0; i < n; ++i)
    {
        std::cout << v1[i] << "\t" << v2[i] << std::endl;
    }

    for(unsigned int i = 0; i < n; ++i)
    {
        v1[i] = i;
        v2[i] = 2*i;
    }

    for(unsigned int i = 0; i < n; ++i)
    {
        std::cout << v1[i] << "\t" << v2[i] << std::endl;
    }

    std::cout << v1.length() << "\t" << v2.length() << std::endl;

    Vector v3 = v1 + v2;
    Vector v4 = v3 + v3 + v3;

    for(unsigned int i = 0; i < n; ++i)
    {
        std::cout << v3[i] << "\t" << v4[i] << std::endl;
    }


    for(unsigned int i = 0; i < 10000; ++i)
    {
       v1 = v1 + v2;
    }

    Vector wiper(3);

    for(unsigned int i = 0; i < n; ++i)
    {
        std::cout << v1[i] << "\t" << wiper[i] << std::endl;
    }
    
    return 0;
}
