#ifndef LUA_API_HPP
#define LUA_API_HPP

class LuaAPI
{
public:
	LuaAPI();
	void myfunction(void);

private:
    int x;
};

#endif




extern LuaAPI *luaApi;