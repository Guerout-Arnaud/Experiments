extern "C" {

#include "lua5.2/lua.h"
#include "lua5.2/lauxlib.h"
#include "lua5.2/lualib.h"
}

#include "../../include/LuaApi.hpp"


int l_myfunction(lua_State *L)
{
    printf("l_myfunction called\n");

    lua_getglobal(L, "myApi");
    LuaAPI *luaApi = (LuaAPI *)lua_touserdata(L, -1);
    // printf("luaApi->x = %d\n", luaApi->x);
    luaApi->myfunction();
    return (0);
}


extern "C" {

int luaopen_mylib(lua_State *L)
{
    static const struct luaL_Reg mylib[] = {
        {"myfunction", l_myfunction},
        // {"sum", l_sum},
        {NULL, NULL} /* sentinel */
    };

    printf("luaopen_mylib\n");

    luaL_newlib(L, mylib);

    // lua_newlibtable(L);
    // luaL_setfuncs(L, mylib, 0);

    // luaL_openlib(L, "mylib", mylib, 0);
    return 1;
}

}


// static int l_sum(lua_State *L)
// {
//     int n = lua_gettop(L); /* number of arguments */
//     lua_Number sum = 0;
//     int i;
//     for (i = 1; i <= n; i++)
//     {
//         if (!lua_isnumber(L, i))
//         {
//             lua_pushstring(L, "incorrect argument");
//             lua_error(L);
//         }
//         sum += lua_tonumber(L, i);
//     }
//     lua_pushnumber(L, sum / n); /* first result */
//     lua_pushnumber(L, sum);     /* second result */
//     return 2;                   /* number of results */
// }







