# Compilador e flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2

# Nome do executável
TARGET = main

# Pasta dos testes
TEST_DIR = CasosDeTeste

# Regra padrão: compila o programa
$(TARGET): main.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.cpp

run: $(TARGET)
	@if [ "$(filter %.in,$(MAKECMDGOALS))" ]; then \
		INPUT_FILE=$(filter %.in,$(MAKECMDGOALS)); \
		FILE_PATH="$(TEST_DIR)/$$INPUT_FILE"; \
		if [ -f $$FILE_PATH ]; then \
			# echo "🔹 Rodando caso de teste: $$FILE_PATH"; \
			./$(TARGET) < $$FILE_PATH; \
		else \
			echo "❌ Arquivo $$FILE_PATH não encontrado."; \
		fi \
	else \
		echo "⚠️  Use: make run 1.in (ou outro arquivo .in)"; \
	fi

clean:
	rm -f $(TARGET)

# Impede erro por alvo "1.in", "2.in" etc.
%.in:
	@:
