CXX = g++ -std=c++11


testgrid: testgrid.cpp grid.o
	$(CXX) $^ -o $@


%.o: %.cpp
	$(CXX) -c $<

clean:
	$(RM) testgrid
	$(RM) *.o
