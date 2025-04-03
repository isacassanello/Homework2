# nombre del ejecutable
EXEC = main

# archivos fuente
SRCS = main.cpp curso.cpp estudiante.cpp

# archivos header (no se compilan, pero los listamos por orden)
HEADERS = curso.h estudiante.h

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