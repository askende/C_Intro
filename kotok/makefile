FLAGS= -masm=intel -std=c11 -Wall -Werror -Wpedantic -g -ggdb3 -Wextra -Wconversion -Wsign-conversion -Wstrict-null-sentinel -Wold-style-cast -Wnoexcept -Wctor-dtor-privacy -Woverloaded-virtual -Wsign-promo -Wzero-as-null-pointer-constant -Wsuggest-final-types -Wsuggest-final-methods -Wsuggest-override
CXX=gcc
SOURCES=kotok.c
OUT=kotok.out
OBJ=kotok.o
LIB=libtableau.a
OBJTAB=tableau.o



all: $(LIB) $(OUT)

$(OUT): $(OBJ) $(SOURCES)
		$(CXX) $(FLAG) $(SOURCES) -L. -ltableau -o $(OUT) 

$(OBJ) : $(SOURCES)
		$(CXX) $(FLAG) -c $(SOURCES)

$(LIB) : tableau.o
		ar -rv $(LIB) $(OBJTAB)

$(OBJTAB) : tableau.c tableau.h
		$(CXX) $(FLAG) -c tableau.c


.PHONY : clear
clean:
	rm *.o *.out;
