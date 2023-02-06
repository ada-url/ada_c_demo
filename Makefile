all:demo

ada_c_source.o: ada_c_header.h ada_c_source.cpp ada.cpp ada.h
	c++ -std=c++17 -O3 -c ada_c_source.cpp -D ADA_HAS_ICU=0 -fno-exceptions  -Wall

demo.o: ada_c_source.o ada_c.h demo.c
	cc -std=c11 -O3 -c demo.c -D ADA_HAS_ICU=0 -Wall

demo: ada_c_source.o demo.o
	c++ -O3 -o demo demo.o ada_c_source.o


clean:
	rm -r -f demo demo.o ada_c_source.o
