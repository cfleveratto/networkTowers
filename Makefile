objects = LColouring.o helpers.o Tower.o

colorTowers: $(objects)
	g++ $(objects) -o colorTowers

LColouring.o: helpers.h List.h Graph.h Tower.h LColouring.cpp
	g++ -c LColouring.cpp

helpers.o: helpers.h List.h Graph.h Tower.h helpers.cpp
	g++ -c helpers.cpp

Tower.o: Tower.h Tower.cpp
	g++ -c Tower.cpp

clean:
	rm $(objects) *~ colorTowers
