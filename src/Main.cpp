
#include <iostream>
#include "config.h"
#include <StaticLib.hpp>

int main()
{
    std::cout << " ~~~ Main ~~~" << '\n';
	std::cout << "compiler version: " << __cplusplus << '\n';
    std::cout << "project name: " << PROJECT_NAME << " version: " << PROJECT_VER << std::endl;
    StaticLib::StaticLib::Foo1();
    return 0;
}