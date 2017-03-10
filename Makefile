# Makefile

CMP = g++
CLASS = Board
Main = main
Exec = run

$(EXEC): $(CLASS).o $(MAIN).o
	$(CMP) -std=c++11 $(CLASS).o $(MAIN).o -o $(EXEC)

$(CLASS): $(CLASS).cpp $(CLASS).h
	$(CMP) -c -std=c++11 $(CLASS).cpp -o $(CLASS).o

$(MAIN).o: $(MAIN).cpp $(CLASS).h
	$(CMP) -c -std=c++11 $(MAIN).cpp -o $(MAIN).o

clean:
	rm *.o
	rm $(EXEC)
