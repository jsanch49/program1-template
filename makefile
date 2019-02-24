DEP1=Star
DEP2=Planet
DEP3=Vector
DEP4=List
TARGET=test
FLAGS=-Wall -Wextra -DDEBUG -g -std=c++14

all: $(TARGET)

$(TARGET): $(TARGET).o $(DEP1).o $(DEP2).o $(DEP3).o $(DEP4).o
	g++ $(FLAGS) $(TARGET).o $(DEP1).o $(DEP2).o $(DEP3).o $(DEP4).o -o $(TARGET)

$(TARGET).o: $(TARGET).cpp $(DEP1).h
	g++ $(FLAGS) -c $(TARGET).cpp

$(DEP1).o: $(DEP1).cpp $(DEP2).h $(DEP1).h
	g++ $(FLAGS) -c $(DEP1).cpp

$(DEP2).o: $(DEP2).cpp $(DEP2).h
	g++ $(FLAGS) -c $(DEP2).cpp

$(DEP3).o: $(DEP3).cpp $(DEP3).h $(DEP2).h
	g++ $(FLAGS) -c $(DEP3).cpp

$(DEP4).o: $(DEP4).cpp $(DEP4).h $(DEP2).h
	g++ $(FLAGS) -c $(DEP4).cpp

run: all
	./$(TARGET)

memcheck: all
	valgrind ./$(TARGET) --leak-check=full

clean:
	rm -f $(TARGET)
	rm -f $(TARGET).o
	rm -f $(DEP1).o
	rm -f $(DEP2).o $(DEP3).o $(DEP4).o

