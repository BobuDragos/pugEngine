

// #include <stdio.h>
#include <iostream>

namespace core
{
class Debug
{
public:
    template <typename T>
    void log(const T& message) 
    {
        std::cout << message << std::endl;
    }
};
}


