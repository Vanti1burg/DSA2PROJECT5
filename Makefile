CXX = g++
CXXFLAGS = -g -Wall

TARGET = main
OBJECTS = main.o similarityDetector.o LCS.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

main.o: main.cpp similarityDetector.cpp similarityDetector.hpp LCS.cpp LCS.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp


similarityDetector.o: similarityDetector.cpp similarityDetector.hpp
	$(CXX) $(CXXFLAGS) -c similarityDetector.cpp
LCS.o: LCS.cpp LCS.hpp
	$(CXX) $(CXXFLAGS) -c LCS.cpp	
run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJECTS)
