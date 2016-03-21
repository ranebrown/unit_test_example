# unit test example makefile

# directories
SRCDIR = ../src
BUILDDIR = build
TESTDIR = ../test
INCDIR = ../inc

# Compiler to use
CC = clang

# Include paths for header files
INCLUDES = -I $(INCDIR) -I /usr/local/include

# Compiler flags
CFLAGS = -Wall -Wextra -g $(INCLUDES) -std=c11

# Paths to required libraries
LFLAGS = -L /usr/local/lib

# The specific libraries that project depends on
LIBS = -lm

# All source files
SRCS = $(wildcard $(SRCDIR)/*.c)

# All object files
OBJS := $(SRCS:$(SRCDIR)/%.c=%.o)

# name of executable
MAIN = unitT.exe

# make all
.PHONY: all
all: $(MAIN)

$(MAIN): $(OBJS)
	@echo "Compiling executable: $(MAIN)"
	@$(CC) $(CFLAGS) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)
	@echo

# Automatically builds all object files from source files
# -c option compiles but does not link (create object files)
# -o is output filename
$(OBJS): %.o : $(SRCDIR)/%.c
	@echo "Compiling object file: $@"
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo

# unit test setup
TESTFLAG = -lcheck

TESTSRCS = $(wildcard $(TESTDIR)/*.c) #add in any .c files from test dir

TESTOBJS := $(TESTSRCS:$(TESTDIR)/%.c=%.o) #convert names of all .c files to .o

MAINOBJS := $(filter-out main.o, $(OBJS)) #remove main.o from list of .o files (check doesn't use main)

$(TESTOBJS): %.o : $(TESTDIR)/%.c #compile but don't link .o files
	@echo "Compiling object file: $@"
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo

# unit test executables
TEXCS = $(TESTOBJS:%.o=%.exe)

# check target - compile the executable for each test file
$(TEXCS): %.exe: %.o $(MAINOBJS)
	@echo "Compiling unit test executable: $@"
	@$(CC) $(CFLAGS) $(TESTFLAG) $(LFLAGS) $(LIBS) -o $@ $^
	@echo

# make and run unit tests
# makefile info: structure using $TESTEX here and above so target isn't rebuilt if no changes
# this is the same way main is set up
.PHONY: check
check: $(TEXCS)
	@for test in $^;  do \
		./$${test}; \
		echo; \
	done

# phony is used in case there is a file named clean
# @ suppresses command at shell
.PHONY: clean
clean:
	@if [ `find . -name "*.exe" | head -1` ]; then rm *.exe; fi;
	@if [ `find . -name "*.o" | head -1` ]; then rm *.o; fi;
	@echo "Cleaning..."
	@echo "Operation complete :)"
	@echo
