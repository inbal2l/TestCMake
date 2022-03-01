
#include <StaticLib.hpp>  // CMakeLists defines "StaticLib/include" in target_include_directories
#include <iostream>

namespace StaticLib {


void StaticLib::Foo1()
{
    std::cout << "Public StaticLib Foo1!\n";
}

void StaticLib::Foo2()
{
    std::cout << "Private StaticLib Foo2!\n";
}

}