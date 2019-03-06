proj7: Airport7.o Vmara2Proj7.o
	g++ Airport7.o Vmara2Proj7.o -o proj7

Airport7.o: Airport7.cpp Airport7.h
	g++ -c -g Airport7.cpp
	
Vmara2Proj7.o: Vmara2Proj7.cpp Airport7.h
	g++ -c -g Vmara2Proj7.cpp
	
clean:
	rm Airport7.o Vmara2Proj7.o proj7
