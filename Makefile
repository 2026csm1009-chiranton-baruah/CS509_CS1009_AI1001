# Compiler
CXX = g++

# Flags
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

BIN = bin

all: $(BIN) wrapper assignment1

$(BIN):
	mkdir -p $(BIN)

wrapper: $(BIN)
	$(CXX) $(CXXFLAGS) \
		common_wrapper/wrapper.cpp \
		-o $(BIN)/wrapper

assignment1:
	$(MAKE) -C assignment_01

clean:
	$(MAKE) -C assignment_01 clean
	rm -f $(BIN)/wrapper

.PHONY: all wrapper assignment1 clean
