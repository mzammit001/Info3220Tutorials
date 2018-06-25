#include "Computer.h"
#include "OfficeComputerBuilder.h"
#include "ServerBuilder.h"
#include "GamingComputerBuilder.h"
#include <iostream>

int main()
{
    {
        OfficeComputerBuilder builder;
        builder.createComputer();
        Computer * computer = builder.getResult();
        std::cout << computer->getComputerSpecifications() <<"\n"<<std::endl;
        delete computer;
    }
    {
        ServerBuilder builder;
        builder.createComputer();
        Computer * computer = builder.getResult();
        std::cout << computer->getComputerSpecifications() <<"\n"<<std::endl;
        delete computer;
    }
    {
        GamingComputerBuilder builder;
        builder.createComputer();
        Computer * computer = builder.getResult();
        std::cout << computer->getComputerSpecifications() <<"\n"<<std::endl;
        delete computer;
    }

    std::cout << "building a million computers" <<std::endl;
    for(int i = 0; i < 1000000;++i)
    {

        GamingComputerBuilder b;
        b.createComputer();
        Computer * c = b.getResult();
        delete c;
        if(i%10000==0)
        {
            std::cout << i/1000 << "k computers built " << c <<std::endl;
        }
    }
    std::cout << "1 million computers built. If the address at the end increased continuously you have a memory leak" <<std::endl;
	return 0;
}

