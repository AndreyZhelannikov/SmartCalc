
CC=gcc
TARGET=SmartCalc
GTK_LIBS=`pkg-config --libs gtk+-3.0`
GTK_CFLAGS=`pkg-config --cflags gtk+-3.0`
CFLAGS=-std=c11 -g -Wall -Wextra $(GTK_CFLAGS) #-Werror

TARGET_DIR=.
OBJ_DIR=./objs
SRCS=$(shell find . -maxdepth 1 -name "*.c")
INCLUDES=$(shell find . -maxdepth 1 -name "*.h")
OBJS:=$(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

RM=rm -f
MK=mkdir -p

all: $(TARGET)
$(TARGET) : $(OBJ_DIR) $(OBJS) $(INCLUDES) Makefile
	$(CC) -o $(TARGET) $(OBJS) $(GTK_LIBS)
	./SmartCalc

$(OBJS) : $(OBJ_DIR)%.o : $(TARGET_DIR)%.c
	$(CC) -c $(CFLAGS) $< -o $@

$(OBJ_DIR) :
	$(MK) objs

clean:
	$(RM) -r $(OBJ_DIR)

re: clean all