

COMPILER=g++
STD=c++11
FLAGS=-Wall -pedantic

OUTDIR=bin

IN=*.cc

default: setup
	$(COMPILER) -o $(OUTDIR)/main $(IN) -std=$(STD) $(FLAGS)

setup:
	mkdir -p $(OUTDIR)

