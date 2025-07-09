# Makefile for leet-learning C++23 snippets

CXX := g++
CXXFLAGS := -std=c++23 -Wall -Wextra -Wpedantic -O2 -c
LDFLAGS :=
TARGET := solution
SRC := lc122.cpp

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(TARGET)
