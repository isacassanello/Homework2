# Nombre del ejecutable
TARGET = main

# Compilador
CXX = g++

# Opciones de compilación
CXXFLAGS = -Wall -std=c++11

# Archivos fuente
SRCS = main.cpp Banco.cpp CajaDeAhorro.cpp CuentaCorriente.cpp

# Archivos objeto
OBJS = $(SRCS:.cpp=.o)

# Regla principal para compilar el ejecutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Regla para compilar archivos fuente a objeto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para ejecutar el programa
run: $(TARGET)
	./$(TARGET)

# Regla para limpiar archivos objeto y ejecutable
clean:
	rm -f $(OBJS) $(TARGET)