CXX = g++
CXXFLAGS = -std=c++11 -O2
exe = hw4

$(exe): %: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $(exe)

.PHONY: clean
clean:
	rm -f $(exe)
