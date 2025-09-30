# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -g -Wno-constant-conversion -Wno-c++11-extensions

# Automatically gather all source files and create object list
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)

# Default target name (main executable)
TARGET = TestingMain

# Default build
all: $(TARGET)

# Linking step
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

# Compiling step (generic rule for any .cpp → .o)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run normally
run: $(TARGET)
	./$(TARGET)

# Run with ASan (Address Sanitizer)
asan: CXXFLAGS += -fsanitize=address
asan: clean $(TARGET)

asan-run: asan
	./$(TARGET)

# Run with macOS 'leaks' (if available)
leaks: $(TARGET)
	leaks --atExit -- ./$(TARGET)

# Cleanup
clean:
	rm -f $(TARGET) $(OBJS)
