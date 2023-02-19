CC = gcc
CFLAGS = -Wall
LDFLAGS =
OBJFILES = arbre.o dico.o main.o
TARGET = app 
all: $(TARGET)
$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)
clean:
	rm -f $(OBJFILES) $(TARGET) *~