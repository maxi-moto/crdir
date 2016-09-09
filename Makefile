SRCDIR = ./src
OBJDIR = ./obj

SRCFILES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(addprefix $(OBJDIR)/, $(notdir $(SRCFILES:.cpp=.o)))

CC = g++
CFLAGS = -g -Wall

all: create_directories crdir

crdir:  $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) -c -o $@ $<

create_directories:
	mkdir -p $(OBJDIR)

clean:
	-rm -r $(OBJDIR)
	-rm crdir
