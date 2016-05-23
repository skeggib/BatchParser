CC=g++
CFLAGS=-std=c++11 -w -g
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
	tests/BatchParser/TestStrHelper.cpp\
	tests/BatchParser/TestBatchScript.cpp\
	tests/BatchParser/TestBatchInstruction.cpp\
	src/BatchParser/StrHelper.cpp\
	src/BatchParser/BatchScript.cpp\
	src/BatchParser/BatchInstruction.cpp\
	src/BatchParser/BatchArgument.cpp

OBJ=\
	$(SRC:.cpp=.o)


all: $(TEXEC)

test: $(TEXEC)
	@./$(TEXEC)

$(TEXEC): $(OBJ)
	mkdir -p $(TDIR)
	@$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	@echo $<
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf $(OBJ)

mrproper: clean
	@rm -rf $(EXEC)
	@rm -rf $(TEXEC)