# ==========================================================
# Common Wrapper Makefile
# ==========================================================

CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2

TARGET := ../bin/wrapper

all:
	@mkdir -p ../bin
	$(CXX) $(CXXFLAGS) wrapper.cpp -o $(TARGET)

clean:
	rm -f $(TARGET)

rebuild: clean all

run:
	$(TARGET)

.PHONY: all clean rebuild run
