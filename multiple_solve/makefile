CC = g++
ROOT = $(shell pwd)
INCLUDE = $(ROOT)/include
IFLAG = -I$(INCLUDE)
DEF = polynomial
TAR = main
default : $(TAR)
OBJ = $(TAR).o $(DEF).o
$(TAR) : $(OBJ)
	$(CC) -std=c++11 -o $(TAR) $(OBJ)
$(TAR).o : $(INCLUDE)/$(DEF).h
	$(CC) -std=c++11 $(IFLAG) -c $(TAR).cpp
$(DEF).o : $(INCLUDE)/$(DEF).h
	$(CC) -std=c++11 $(IFLAG) -c $(DEF).cpp
clean:
	-rm *.o $(TAR) time.txt
