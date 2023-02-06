all:demo

ada_c_source.o: ada_c_header.h ada_c_source.cpp ada.cpp ada.h
	c++ -std=c++17 -O3 -c ada_c_source.cpp -D ADA_HAS_ICU=0 -fno-exceptions  -Wall

demo: ada_c_source.o ada_c.h demo.c
	cc -std=c11 -O3 -o demo demo.c ada_c_source.o -D ADA_HAS_ICU=0  -lc++ -Wall

clean:
	rm -r -f demo ada_c_source.o