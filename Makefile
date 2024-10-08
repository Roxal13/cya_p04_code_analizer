# Nombre del ejecutable
EXEC = p04_analizer

# Compilador
CXX = g++

# Flags de compilación
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror

# Archivos fuente
SRC = main.cpp analizador_codigo.cc

# Archivos objeto
OBJ = $(SRC:.cpp=.o)

# Regla principal
$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ)

# Regla para compilar archivos .cpp a .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar archivos generados
clean:
	rm -f $(OBJ) $(EXEC)

# Phony targets para evitar conflictos con archivos que tengan estos nombres
.PHONY: all clean