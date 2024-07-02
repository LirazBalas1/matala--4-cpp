CXX = g++
CXXFLAGS = -g -std=c++14 -Wall -Wextra -I.
OBJECTS = main.cpp complex.cpp
TARGET = tree
TEST_TARGET = test
TEST_OBJECTS = test.cpp complex.cpp
DRAW=-lsfml-graphics -lsfml-window -lsfml-system
OBJS = $(OBJECTS:.cpp=.o)

TEST_OBJS = $(TEST_OBJECTS:.cpp=.o)

all: $(TARGET) $(TEST_TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(DRAW)

$(TEST_TARGET): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(TEST_TARGET) $(OBJS) $(TEST_OBJS)

.PHONY: all clean run
