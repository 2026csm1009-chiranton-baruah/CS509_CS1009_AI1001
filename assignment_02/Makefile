CXX ?= g++
CXXFLAGS ?= -std=c++17 -O2 -Wall -Wextra -pedantic
INCLUDES = -Iinclude
COMMON_SRC = src/graph.cpp src/algorithms.cpp

.PHONY: all clean triangle bc cc
all: triangle bc cc

triangle:
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(COMMON_SRC) drivers/triangle_driver.cpp -o triangle_driver

bc:
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(COMMON_SRC) drivers/bc_driver.cpp -o bc_driver

cc:
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(COMMON_SRC) drivers/cc_driver.cpp -o cc_driver

clean:
	rm -f triangle_driver bc_driver cc_driver
