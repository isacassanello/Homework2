# nombre del ejecutable
TARGET = main

# compilador y flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g

# archivos fuente y objetos
SRCS = main.cpp curso.cpp estudiante.cpp
OBJS = $(SRCS:.cpp=.o)

# compilar el ejecutable
all: $(TARGET)

# enlazar obejtos
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# compilar archivos .cpp a .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# limpiar archivos generados
clean:
	rm -f $(OBJS) $(TARGET)

# compilar y ejecutar
run: all
	./$(TARGET)