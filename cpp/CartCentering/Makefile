#==============================================================
# Makefile for the libGE "Cart Centering" example using 
# the GALib evolutionary library.
#==============================================================



## VARS
# --------------------------------------------------------------

# Compiler options
CC 				= gcc
CXX				= g++
CFLAGS  	= -Wall -Wextra -Wpedantic -g
CXXFLAGS  = -Wall -Wextra -Wpedantic -g
# CXX_VECT added for vectorization, May 2019
CC_VECT		= -O3 -fopt-info-loop-optimized
CXX_VECT	= -O3 -fopt-info-loop-optimized
# CC_OPENMP added for parallelization, June 2019
CC_OPENMP	= -fopenmp

# Object files
TARGET		= main.o
DEPEND		=	cartcenter-gcc.o gcc_GEcart.o

# Libraries dependencies
LDFLAGS 	= -lga -lGE



## RULES 
# --------------------------------------------------------------

# Make GEGCC
GEGCC:	$(TARGET) $(DEPEND)
	$(CXX) $(CXXFLAGS) $(CXX_VECT) -o $@ $(TARGET) $(DEPEND) $(LDFLAGS) $(CC_OPENMP)

# Dependencies
cartcenter-gcc.o: cartcenter-gcc.cpp
	$(CXX) $(CXXFLAGS) $(CXX_VECT) -o $@ -c $<

gcc_GEcart.o: GEcart.c
	$(CC) $(CFLAGS) $(CC_VECT) -o $@ -c $<

# Make clean
.PHONY: clean
clean:
	rm -rf *~ *.o a.out individual.c cc-output.dat stats result GEGCC


