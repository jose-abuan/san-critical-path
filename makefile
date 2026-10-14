# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g -lgtest -lgtest_main -pthread

# Target executable
TARGET = SIM

# For deleting the target
TARGET_DEL = SIM.exe

# Source files
SRCS = main.cpp Simulator.cpp SANGraph.cpp

# Default rule to build and run the executable
all: $(TARGET) run

# Rule to compile source files directly into the target executeable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# Rule to compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to run the executable
run: $(TARGET)
	./$(TARGET)

# Clean rule to remove generated files
clean:
	rm -f $(TARGET)