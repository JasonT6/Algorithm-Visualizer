# # Compiler
# CXX := g++
# # Compiler flags
# CXXFLAGS := -Wall -Wextra -std=c++17 -g

# #LINKER_FLAGS specifies the libraries we're linking against
# LINKER_FLAGS = -lSDL2

# # Source files
# SRCS := main.cpp node.cpp x_y_position.cpp board.cpp algorithms.cpp
# # Object files
# OBJS := $(SRCS:.cpp=.o)
# # Target executable
# TARGET := program

# .PHONY: all clean

# all: $(TARGET)

# $(TARGET): $(OBJS)
# 	$(CXX) $(CXXFLAGS) $(OBJS) $(LINKER_FLAGS) -o $(TARGET)

# %.o: %.cpp
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

# clean:
# 	del -f $(OBJS) $(TARGET)
# 	del /F $(OBJS) $(TARGET).exe



# # Compiler
# CXX := g++

# # Compiler flags
# CXXFLAGS := -Wall -Wextra -std=c++17 -g -Isrc/include -Isrc/include/sdl2

# # LINKER_FLAGS specifies the libraries we're linking against
# LINKER_FLAGS = -Lsrc/lib -lSDL2

# # Source files directory
# SRCDIR := src

# # Source files
# SRCS := $(wildcard $(SRCDIR)/*.cpp)

# # Object files
# OBJS := $(SRCS:.cpp=.o)

# # Target executable
# TARGET := program

# .PHONY: all clean

# all: $(TARGET)

# $(TARGET): $(OBJS)
# 	$(CXX) $(CXXFLAGS) $(OBJS) $(LINKER_FLAGS) -o $(TARGET)

# %.o: $(SRCDIR)/%.cpp
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

# clean:
# 	del -f $(OBJS) $(TARGET)
# 	del /F $(OBJS) $(TARGET).exe


#closest to working
# # Compiler
# CXX := g++

# # Compiler flags
# CXXFLAGS := -Wall -Wextra -std=c++17 -g -Isrc/include -Isrc/include/sdl2

# # Source files directory
# SRCDIR := src

# # Source files
# SRCS := $(wildcard $(SRCDIR)/*.cpp)

# # Object files
# OBJS := $(SRCS:.cpp=.o)

# # Target executable
# TARGET := program

# # Linker flags
# LDFLAGS := -Lsrc/lib -lmingw32 -lSDL2main -lSDL2 -mwindows

# .PHONY: all clean

# all: $(TARGET)

# $(TARGET): $(OBJS)
# 	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET) $(LDFLAGS)

# %.o: $(SRCDIR)/%.cpp
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

# clean:
# 	del -f $(OBJS) $(TARGET)



# # Compiler
# CXX := g++

# # Compiler flags
# CXXFLAGS := -Wall -Wextra -std=c++17 -g -Isrc/include -Isrc/include/sdl2

# # Source files directory
# SRCDIR := src

# # Source files
# SRCS := $(wildcard $(SRCDIR)/*.cpp)

# # Object files
# OBJS := $(SRCS:.cpp=.o)

# # Target executable
# TARGET := program

# # Linker flags
# LDFLAGS := -Lsrc/lib -lmingw32 -lSDL2 -mwindows

# .PHONY: all clean

# all: $(TARGET)

# $(TARGET): $(OBJS)
# 	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

# %.o: $(SRCDIR)/%.cpp
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

# clean:
# 	del -f $(OBJS) $(TARGET)

all:
	g++ -Isrc/Include -Lsrc/lib -o main main.cpp algorithms.cpp board.cpp node.cpp x_y_position.cpp UIclass.cpp -lmingw32 -lSDL2main -lSDL2

# clean:
	
	

# # Compiler
# CXX := g++

# # Compiler flags
# CXXFLAGS := -Wall -Wextra -std=c++17 -g -Isrc/Include -Lsrc/lib

# # Source files directory
# SRCDIR := src

# # Source files
# SRCS := $(wildcard $(SRCDIR)/*.cpp)

# # Object files
# OBJS := $(SRCS:.cpp=.o)

# # Target executable
# TARGET := main

# # Linker flags
# LDFLAGS := -lmingw32 -lSDL2main -lSDL2

# .PHONY: all clean

# all: $(TARGET)

# $(TARGET): $(OBJS)
# 	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

# %.o: $(SRCDIR)/%.cpp
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

# clean:
# 	del -f $(OBJS) $(TARGET)
# 	del /F $(OBJS) $(TARGET).exe
