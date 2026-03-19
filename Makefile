CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = program
SRCDIR = src
OBJDIR = obj
DATADIR = data

SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(DATADIR):
	mkdir -p $(DATADIR)

run: $(TARGET) $(DATADIR)
	./$(TARGET)

clean:
	rm -rf $(OBJDIR) $(TARGET)

cleanall: clean
	rm -rf $(DATADIR)

.PHONY: clean cleanall run
