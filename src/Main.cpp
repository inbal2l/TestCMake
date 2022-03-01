
#include <iostream>
#include "config.h"
#include <HeaderLib.hpp>

int main()
{
    std::cout << " ~~~ Main ~~~" << '\n';
	std::cout << "compiler version: " << __cplusplus << '\n';
    std::cout << "project name: " << PROJECT_NAME << " version: " << PROJECT_VER << std::endl;
    HeaderLib::HeaderLib::Foo1();
    return 0;
}