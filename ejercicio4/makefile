# nombre del ejecutable
EXEC = main

# archivos fuente
SRCS = main.cpp Banco.cpp CajaDeAhorro.cpp CuentaCorriente.cpp

# archivos header (no se compilan, pero los listamos por orden)
HEADERS = Banco.h CajaDeAhorro.h CuentaCorriente.h

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