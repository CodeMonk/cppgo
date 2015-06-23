
CFLAGS=-Wall -fPIC

all: libtc.a testclass

testclass: main.cpp libtc.a
	$(CXX) $(CFLAGS) main.cpp -o $@ -L. -ltc

libtc.a: testclass.o cbind.o
	$(AR) rcv $@ $^

testclass.o: testclass.cpp testclass.hpp
	$(CXX) $(CFLAGS) -o $@ -c $<

cbind.o: cbind.cpp cbind.h
	$(CXX) $(CFLAGS) -o $@ -c $<


clean:
	$(RM) libtc.a testclass.o testclass cbind.o
