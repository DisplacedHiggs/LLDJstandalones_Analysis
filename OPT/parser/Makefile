CXX = $(shell root-config --cxx)
LD = $(shell root-config --ld)

INC = $(shell pwd)

CPPFLAGS := $(shell root-config --cflags) -I$(INC)/include -I$(INC)
LDFLAGS := $(LDFLAGS) $(shell root-config --glibs) -lMathMore
CPPFLAGS += -g

TARGET  = OPT.exe

SRC = include/CommandLineInput.C app/DisplacedJetOptimizationZH.cc

OBJ = $(SRC:.C=.o)

all : $(TARGET)

$(TARGET) : $(OBJ)
	$(LD) $(CPPFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)
	@echo $@
	@echo $<
	@echo $^


%.o : %.C
	$(CXX) $(CPPFLAGS) -o $@ -c $<
	@echo $@
	@echo $<
clean :
	rm -f *.o  $(TARGET) 
