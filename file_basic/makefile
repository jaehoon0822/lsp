.SUFFIXIES = .o .c
CC = gcc
FLAGS = -W -Wall -g
FILE = fwrite.c 
OBJECT =  fwrite.o 
TARGET = all
RM = rm -rdf

$(TARGET): .c.o
	$(CC) -o $(TARGET) $(OBJECT) 

.c.o: $(FILE)
	$(CC) $(FLAGS) -c $<	

clean:
	$(RM) $(TARGET) *.o *.txt


