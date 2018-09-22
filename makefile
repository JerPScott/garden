DIR_PROJECT=.
DIR_BIN=$(DIR_PROJECT)/bin
DIR_OBJ=$(DIR_PROJECT)/obj
DIR_INC=$(DIR_PROJECT)/inc
DIR_SRC=$(DIR_PROJECT)/src

CPP_DEBUG_FLAGS=-D__DEBUG__ -g
CPP_ERROR_FLAGS=-Wall -Werror
CPP_INC_FLAGS=-I$(DIR_INC)
CPP_FLAGS=$(CPP_DEBUG_FLAGS) $(CPP_ERROR_FLAGS) $(CPP_INC_FLAGS)

LD_DEBUG_FLAGS=-g
LD_FLAGS=$(LD_DEBUG_FLAGS)

OUT=$(DIR_BIN)/garden.exe

_DEPS = plant.h map.h
DEPS = $(patsubst %,$(DIR_INC)/%,$(_DEPS))

_OBJS = garden.o plant.o map.o
OBJS = $(patsubst %,$(DIR_OBJ)/%,$(_OBJS))

all: $(OUT)

###########
## build ##
###########

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.cpp $(DEPS) | $(DIR_OBJ)
	g++ -c -o $@ $< $(CPP_FLAGS)

$(OUT): $(OBJS) | $(DIR_BIN)
	g++ -o $@ $^ $(LD_FLAGS)

###########
## phony ##
###########

.PHONY: clean directories

#############
## cleanup ##
#############

clean:
	rm -f $(DIR_OBJ)/*.o $(OUT)

###############################
## create output directories ##
###############################

directories: $(DIR_BIN) $(DIR_OBJ)

$(DIR_BIN):
	mkdir -p $(DIR_BIN)

$(DIR_OBJ):
	mkdir -p $(DIR_OBJ)
