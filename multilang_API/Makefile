OUTDIR	=	.local/out

BINSRC	=	./src/cpp/main.cpp	\
			./src/cpp/LuaApi.cpp
BINOBJ	=	$(BINSRC:.cpp=.o)
BINNAME	=	a.out

LIBSRC	=	./src/cpp/api.cpp	\
			./src/cpp/LuaApi.cpp
LIBOBJ	=	$(LIBSRC:.cpp=.o)
LIBNAME	=	mylib.so


CFLAGS	+=	-Wall -Werror -fPIC -g3

%.o	:	%.cpp
		g++ -c $< -o $@ $(CFLAGS)


all: library binary
	cp src/lua/plugin.lua $(OUTDIR)


library: $(LIBOBJ)
	g++ -shared -o $(OUTDIR)/$(LIBNAME) $(LIBOBJ)


binary: $(BINOBJ)
	g++ -llua -o $(OUTDIR)/$(BINNAME) $(BINOBJ)


clean:
	rm -f $(BINOBJ) $(LIBOBJ) $(OUTDIR)/$(BINNAME) $(OUTDIR)/$(LIBNAME)