CXX = g++ -std=c++11


testgrid: testgrid.cpp Grid.o Game.o
	$(CXX) $^ -o $@


%.o: %.cpp
	$(CXX) -c $<

clean:
	$(RM) testgrid
	$(RM) *.o
