# nombre del ejecutable
EXEC = main

# archivos fuente
SRCS = main.cpp tiempo.cpp 

# archivos header (no se compilan, pero los listamos por orden)
HEADERS = tiempo.h 

# compilador y flags
CXX = g++
CXXFLAGS = -Wall -std=c++17

# compilar
$(EXEC): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(SRCS)

# ejecutar el programa
run: $(EXEC)
	./$(EXEC)

# limpiar archivos generados
clean:
	rm -f $(EXEC)