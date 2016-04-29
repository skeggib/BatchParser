CC=g++
CFLAGS=-std=c++11
LDFLAGS=

ifeq ($(OS),Windows_NT)
	TDIR=build/windows/
	TEXEC=$(TDIR)BatchParserTests.exe
else
	TDIR=build/linux/
	TEXEC=$(TDIR)BatchParserTests
endif

SRC=\
	$(wildcard cpptest/*.cpp)\
	tests/tests.cpp\
	src/BatchParser/BatchScript.cpp\
	src/BatchParser/BatchInstruction.cpp\
	src/BatchParser/BatchArgument.cpp

OBJ=\
	$(SRC:.cpp=.o)


all: test

test: cleantests $(TEXEC)
	@./$(TEXEC)

$(TEXEC): $(OBJ)
	mkdir -p $(TDIR)
	@$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper cleantests

clean:
	@rm -rf $(OBJ)

mrproper: clean
	@rm -rf $(EXEC)
	@rm -rf $(TEXEC)

cleantests:
	@rm -rf tests/tests.o