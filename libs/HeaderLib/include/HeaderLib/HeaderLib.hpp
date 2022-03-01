#ifndef __HEADER_LIB_HPP__
#define __HEADER_LIB_HPP__

#include <iostream>


namespace HeaderLib {

class HeaderLib
{
public:
    static void Foo1()
    {
        std::cout << "Public Foo1 header only lib\n";
    }
private:
    static void Foo2()
    {
        std::cout << "Private Foo2 header only lib\n";
    }
};



}


#endif // __HEADER_LIB_HPP__