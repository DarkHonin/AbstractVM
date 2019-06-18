SOURCES=$(shell find src -type f)
INCLUDE=include
GCC=clang++

make:
	$(GCC) $(SOURCES) -I $(INCLUDE) -o "Here"

info:
	@echo $(SOURCES)