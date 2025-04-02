# Nombre del ejecutable
EXEC = main

# Archivos fuente
SRCS = main.cpp entero.cpp real.cpp complejo.cpp

# Archivos de cabecera (no se compilan, pero los listamos por orden)
HEADERS = numero.h entero.h real.h complejo.h

# Compilador y flags
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Regla por defecto: compilar
$(EXEC): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(SRCS)

# Ejecutar el programa
run: $(EXEC)
	./$(EXEC)

# Limpiar archivos generados
clean:
	rm -f $(EXEC)