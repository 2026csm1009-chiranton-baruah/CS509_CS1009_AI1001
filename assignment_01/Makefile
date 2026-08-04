CXX = g++

CXXFLAGS = -std=c++17 -Wall -Wextra -O2

INCLUDE = -Iinclude

SRC = \
src/graph_io.cpp \
src/csr.cpp \
src/bfs.cpp \
src/dfs.cpp \
src/sssp.cpp \

DRIVER = driver/assignment1_driver.cpp

TARGET = ../bin/assignment1_driver

all:
	$(CXX) $(CXXFLAGS) $(INCLUDE) \
	$(SRC) $(DRIVER) \
	-o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean
