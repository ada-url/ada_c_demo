all:demo

ifeq '$(findstring ;,$(PATH))' ';'
    detected_OS := Windows
else
    detected_OS := $(shell uname 2>/dev/null || echo Unknown)
    detected_OS := $(patsubst CYGWIN%,Cygwin,$(detected_OS))
    detected_OS := $(patsubst MSYS%,MSYS,$(detected_OS))
    detected_OS := $(patsubst MINGW%,MSYS,$(detected_OS))
endif

ifeq ($(detected_OS),Darwin)        # Mac OS X
    CPPLIB = -lc++
endif
ifeq ($(detected_OS),FreeBSD)
    CPPLIB = -lc++
endif
ifeq ($(detected_OS),NetBSD)
    CPPLIB = -lc++
endif

ifeq ($(detected_OS),Linux)
    CPPLIB = -lstdc++
endif

ada_c_source.o: ada_c_header.h ada_c_source.cpp ada.cpp ada.h
	c++ -std=c++17 -O3 -c ada_c_source.cpp -D ADA_HAS_ICU=0 -fno-exceptions  -Wall

demo: ada_c_source.o ada_c.h demo.c
	cc -std=c11 -O3 -o demo demo.c ada_c_source.o -D ADA_HAS_ICU=0  $(CPPLIB) -Wall

clean:
	rm -r -f demo ada_c_source.o
