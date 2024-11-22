#target: dependencies
#    command

# $< is a macro representing the first dependency.
# $@ Represents the target
# -c flag generates object files. (gcc)
# -o flag generates executable files. (gcc)

CC = gcc 											# COMPILER
CFLAGS = -Wall 										# FLAGS (all Warnings)
SRC = main.c entity.c skill.c combat.c drawings.c  	# Source Files
OBJ = $(SRC:.c=.o)									# Object files. This SRC:.c=.o macro converts the .c files in SRC variable to .o files with the same name
TARGET = game 					# Target Name


#%.o: %.c 
#	$(CC) $(CFLAGS) -c $<

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)



main.o: main.c
	$(CC) $(CFLAGS) -c main.c

entity.o: entity.c
	$(CC) $(CFLAGS) -c entity.c

skill.o: skill.c
	$(CC) $(CFLAGS) -c skill.c

combat.o: combat.c
	$(CC) $(CFLAGS) -c combat.c

drawings.o: drawings.c
	$(CC) $(CFLAGS) -c drawings.c