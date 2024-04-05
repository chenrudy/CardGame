TARGET = $(shell basename $(CURDIR))
SRCDIR = ../src
BUILDDIR = .

SRCS = $(wildcard $(SRCDIR)/*.cpp) 
OBJS = $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SRCS))

LIBS_DIR = ../libs
OBJ_DIR = ../obj

DEBUG_LIBSDIR = $(LIBS_DIR)/debug
RELEASE_LIBSDIR = $(LIBS_DIR)/release

DEBUG_OBJDIR = $(OBJ_DIR)/debug
RELEASE_OBJDIR = $(OBJ_DIR)/release

CC = g++
VERSION = -std=c++11
DEBUG_FLAGS = -g -Wall -Wextra
RELEASE_FLAGS = -O3
OBJ_FLAGS = -c -fpic
LD_FLAGS = -L$(DEBUG_LIBSDIR) -Wl,-rpath=$(DEBUG_LIBSDIR)
INCLUDE_FLAG = -I../include

.PHONY: all test release debug clean

all: test

test: $(OBJS)
	$(CC) $(LD_FLAGS) $(DEBUG_FLAGS) $(VERSION) $^ $(INCLUDE_FLAG) main.cpp -o $(TARGET).out 
	mkdir -p $(OBJ_DIR)
	mv *.o $(OBJ_DIR)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p $(BUILDDIR)
	$(CC) $(OBJ_FLAGS) $(DEBUG_FLAGS) $(VERSION) $(INCLUDE_FLAG) -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET).out
	rm -f $(OBJ_DIR)/*.o
