BIN_NAME = ocrf
PREFIX ?= /usr/local

$(BIN_NAME): main.cpp
	g++ main.cpp -o $(BIN_NAME)

install: $(BIN_NAME)
	install -Dm755 $(BIN_NAME) $(PREFIX)/bin/$(BIN_NAME)

.PHONY: install
