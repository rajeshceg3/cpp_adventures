.PHONY : all
all : sampleClass driver

driver : driver.cpp sampleClass.o
	g++ -o driver driver.cpp sampleClass.o

sampleClass : sampleClass.cpp
	g++ -c  sampleClass.cpp

.PHONY : clean
clean : 
	rm -rf *.o
	rm -rf simple_class
