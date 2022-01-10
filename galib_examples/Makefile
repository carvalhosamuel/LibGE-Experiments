#==============================================================
# Makefile for the libGE "Intertwined Spirals" example using 
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
TARGET		= ex1.o

# Libraries dependencies
LDFLAGS 	= -lga -lGE



## RULES 
# --------------------------------------------------------------

# Make GEGCC
GEGCC:	$(TARGET)
	$(CXX) $(CXXFLAGS) $(CXX_VECT) -o $@ $(TARGET) $(LDFLAGS) $(CC_OPENMP)


# Make clean
.PHONY: clean
clean:
	rm -rf *~ *.o a.out individual.c cc-output.dat stats result GEGCC
