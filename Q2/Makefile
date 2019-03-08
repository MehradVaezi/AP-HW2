CXX = g++
CXXFLAGS = -std=c++17 -Wall -c
LXXFLAGS = -std=c++17
OBJECTS = main.o libVec.o libArr.o
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp

libVec.o: libVec.h libVec.cpp
	$(CXX) $(CXXFLAGS) libVec.cpp

libArr.o: libArr.h libArr.cpp
	$(CXX) $(CXXFLAGS) libArr.cpp

clean:
	rm -f $(TARGET) $(OBJECTS)
