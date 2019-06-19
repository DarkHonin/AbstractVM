SOURCES=$(shell find src -type f)
INCLUDE=include
GCC=clang++

make:
	$(GCC) $(SOURCES) -I $(INCLUDE) -o "Here" -std=c++11

info:
	@echo $(SOURCES)