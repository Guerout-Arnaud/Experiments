#include <iostream>

#include "../../include/LuaApi.hpp"

LuaAPI::LuaAPI()
{
    x = 0;
}

void LuaAPI::myfunction(void)
{
    x++;
    std::cout << "myfunction called " << x << " times" << std::endl;
}