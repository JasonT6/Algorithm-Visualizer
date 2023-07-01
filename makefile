# Compiler
CXX := g++
# Compiler flags
CXXFLAGS := -Wall -Wextra -std=c++17

# Source files
SRCS := main.cpp node.cpp x_y_position.cpp board.cpp algorithms.cpp
# Object files
OBJS := $(SRCS:.cpp=.o)
# Target executable
TARGET := program

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del -f $(OBJS) $(TARGET)
	del /F $(OBJS) $(TARGET).exe

