#include <iostream>

#ifdef __cplusplus
extern "C" {
#endif
	#include <lua5.2/lua.h>
	#include <lua5.2/lauxlib.h>
	#include <lua5.2/lualib.h>
#ifdef __cplusplus
}
#endif

#include "../../include/LuaApi.hpp"


int main(int argc, char **argv) {
	lua_State *L = luaL_newstate();

	if (L == nullptr) {
		std::cout << "Failed to create Lua state" << std::endl;
		return (-1);
	}
	luaL_openlibs(L);

	// int nb = 42;
	// int *nb_ptr = &nb;

	LuaAPI *api = new LuaAPI();
	// api->x = 42;

	lua_pushlightuserdata(L, api);
	lua_setglobal(L, "myApi");

	if (luaL_dofile(L, argv[1])) {
		std::cout << "Some error occured" << std::endl;
		return (-1);
	}

	// luaL_loadfile(L, );
	// lua_pcall(L, 0, LUA_MULTRET, 0);

	delete api;

	lua_close(L);
	return (0);
}

