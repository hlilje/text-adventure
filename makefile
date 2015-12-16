CXX = g++-4.9
CFLAGS = -g -Wall -Wextra -std=c++11
TARGET = game

.PHONY: default all clean

default: $(TARGET)
all: default

OBJECTS = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
HEADERS = $(wildcard *.h)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) $(CFLAGS) -o $@

clean:
	-rm -f *.o
	-rm -f $(TARGET)
	-rm -f *.out
	-rm -r -f *.dSYM
