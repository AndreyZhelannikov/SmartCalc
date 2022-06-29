
CC=gcc
TARGET=SmartCalc
TEST_TARGET=test
CFLAGS=-std=c11 -g -Wall -Wextra $(GTK_CFLAGS) #-Werror

TARGET_DIR=.
TEST_DIR=./tests
OBJ_DIR=./objs
SRCS=$(shell find . -maxdepth 1 -name "*.c")
TEST_SRCS=$(shell find $(TEST_DIR) -name "*.c")
INCLUDES=$(shell find . -maxdepth 1 -name "*.h")
TEST_INCLUDES=$(shell find $(TEST_DIR) -name "*.h")
OBJS:=$(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))
TEST_OBJS:=$(addprefix $(OBJ_DIR)/, $(notdir $(TEST_SRCS:.c=.o)))
TEST_LIBS=-lcheck

RM=rm -f
MK=mkdir -p

all: $(TEST_TARGET) #$(TARGET)

$(TARGET) : $(OBJ_DIR) $(OBJS) $(INCLUDES) Makefile
	$(CC) -o $(TARGET) $(OBJS)
	./SmartCalc

$(TEST_TARGET) : $(OBJ_DIR) $(OBJS) $(TEST_OBJS) $(INCLUDES) $(TEST_INCLUDES) Makefile
	$(CC) -o $(TEST_TARGET) $(OBJS) $(TEST_OBJS) $(TEST_LIBS) 

$(OBJS) : $(OBJ_DIR)%.o : $(TARGET_DIR)%.c
	$(CC) -c $(CFLAGS) $< -o $@

$(TEST_OBJS) : $(OBJ_DIR)%.o : $(TEST_DIR)%.c
	$(CC) -c $(CFLAGS) $< -o $@

$(OBJ_DIR) :
	$(MK) objs

clean:
	$(RM) -r $(OBJ_DIR)

re: clean all