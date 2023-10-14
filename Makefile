# Makefile

# Definindo as pastas
SRCDIR   := .
INCDIR   := include
BINDIR   := bin
OBJDIR   := obj

# Obtendo a lista de arquivos .cpp no diretório src
SOURCES  := $(wildcard $(SRCDIR)/*.cpp)

# Convertendo a lista de fontes para a lista de objetos no diretório obj
OBJECTS  := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

# Compilador
CC       := g++
CFLAGS   := -std=c++11 -Wall -I$(INCDIR)

# Nome do executável
TARGET   := $(BINDIR)/tp1.out

# Regra padrão para construir o executável
all: $(TARGET)

# Regra para construir o executável
$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CC) $^ -o $@

# Regra para construir os objetos
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpar arquivos gerados
clean:
	rm -rf $(BINDIR) $(OBJDIR)

# Fazer a limpeza e reconstruir
rebuild: clean all

# Não tratar os alvos como arquivos
.PHONY: all clean rebuild
