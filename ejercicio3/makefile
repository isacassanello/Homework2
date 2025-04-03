# nombre del ejecutable
EXEC = main

# archivos fuente
SRCS = main.cpp entero.cpp real.cpp complejo.cpp

# archivos header (no se compilan, pero los listamos por orden)
HEADERS = numero.h entero.h real.h complejo.h

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