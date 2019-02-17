DEP=Star
DEPP=Planet
TARGET=lab3
FLAGS=-Wall -Wextra -DDEBUG -g -std=c++14

all: $(TARGET)

$(TARGET): $(TARGET).o $(DEP).o $(DEPP).o
	g++ $(FLAGS) $(TARGET).o $(DEP).o $(DEPP).o -o $(TARGET)

$(TARGET).o: $(TARGET).cpp $(DEP).h
	g++ $(FLAGS) -c $(TARGET).cpp

$(DEP).o: $(DEP).cpp $(DEPP).h $(DEP).h
	g++ $(FLAGS) -c $(DEP).cpp

$(DEPP).o: $(DEPP).cpp $(DEPP).h
	g++ $(FLAGS) -c $(DEPP).cpp

run: all
	./$(TARGET)

memcheck: all
	valgrind ./$(TARGET) --leak-check=full

clean:
	rm -f $(TARGET)
	rm -f $(TARGET).o
	rm -f $(DEPP).o
	rm -f $(DEP).o
