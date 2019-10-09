FLAGS= -masm=intel -g -ggdb3 -Wpedantic -Wall -Wextra -Wconversion -Wsign-conversion -Wstrict-null-sentinel -Wold-style-cast -Wnoexcept -Wctor-dtor-privacy -Woverloaded-virtual -Wsign-promo -Wzero-as-null-pointer-constant -Wsuggest-final-types -Wsuggest-final-methods -Wsuggest-override
CXX=gcc
MAIN=kotok.c
OUT=kotok.out
KOTOK=kotok.o



all: $(OUT)

$(OUT): $(KOTOK)
	$(CXX) $(FLAG) $(KOTOK) -o $(OUT)

$(KOTOK) : $(MAIN)
	$(CXX) $(FLAG) -c $(MAIN)





.PHONY : clear
clean:
	rm *.o *.out;
