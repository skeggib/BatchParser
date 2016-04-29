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
	src/BatchParser/BatchParser.cpp\
	src/BatchParser/BatchInstruction.cpp

OBJ=\
	$(SRC:.cpp=.o)


all: test

test: $(TEXEC)
	@./$(TEXEC)

$(TEXEC): $(OBJ)
	mkdir -p $(TDIR)
	@$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	@$(CC) -o $@ -c $< $(CFLAGS)