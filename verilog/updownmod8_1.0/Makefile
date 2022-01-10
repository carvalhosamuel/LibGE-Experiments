#==============================================================
# Makefile for the libGE "Intertwined Spirals" example using 
# the GALib evolutionary library.
#==============================================================
## VARS
# --------------------------------------------------------------
EXE = GEGCC

SRC_DIR = src
OBJ_DIR = obj

SRC = $(filter-out src/testbench.cpp, $(wildcard $(SRC_DIR)/*.cpp))
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

RM = rm -rf

# Compiler options
CXX			= g++
CXXFLAGS  	= -w -g -O0 #-fkeep-inline-functions#-Wall -Wextra -Wpedantic -g
SYSTEMCFLAGS = -I. -I/usr/local/systemc-2.3.3//include -L. -L/usr/local/systemc-2.3.3//lib-linux64 -Wl,-rpath=/usr/local/systemc-2.3.3//lib-linux64

# Libraries dependencies
LDFLAGS 	= -lga -lGE

## RULES 
# --------------------------------------------------------------
.PHONY: all clean

# Make GEGCC
all: $(EXE)
	
$(EXE): $(OBJ) #$(OBJ_DIR)/testbench.o
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ) $(LDFLAGS) 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $< $(LDFLAGS) 

# Clean old build
clean:
	$(RM) $(EXE) $(OBJ)

# Clean Logs and Temporary files also
clean-all:
	$(RM) $(EXE) $(OBJ) ./log/* ./tmp/* ./tmp
