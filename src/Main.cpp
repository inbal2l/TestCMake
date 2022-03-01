
#include <iostream>
#include "config.h"
#ifdef USE_STATICLIB
#include <StaticLib.hpp>
#endif

int main()
{
    std::cout << " ~~~ Main ~~~" << '\n';
	std::cout << "compiler version: " << __cplusplus << '\n';
    std::cout << "project name: " << PROJECT_NAME << " version: " << PROJECT_VER << std::endl;
#ifdef USE_STATICLIB
    StaticLib::StaticLib::Foo1();
#endif
    return 0;
}