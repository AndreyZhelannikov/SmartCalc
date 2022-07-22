CC					= 	gcc
CXX					= 	g++
TEST_TARGET			=	test
TEST_GCOV_EXE		=	test_gcov
GCOV_TARGET			=	./coverage
GCOV_INFO			=	coverage.info
CFLAGS				=	-std=c11 -Wall -Wextra #-fsanitize=address -g #-Werror
CXXFLAGS			=	-std=c++17
GCOV_FLAGS			=	-fprofile-arcs -ftest-coverage
TEST_LIBS			=	-lcheck
QMAKEFILE			=	RealMakefile

TARGET_DIR			=	.
TEST_DIR			=	./tests
CALCULATOR_DIR 		= 	./backend
OBJ_DIR				=	./objs
GCOV_OBJ_DIR		=	./gcov_objs

SRC_C 				:=	$(shell find $(CALCULATOR_DIR) -name "*.c")
TEST_SRC	 		:=	$(shell find $(TEST_DIR) -name "*.c")

OBJ_C 				=	$(addprefix $(OBJ_DIR)/, $(notdir $(SRC_C:.c=.o)))
GCOV_OBJ_C			=	$(addprefix $(GCOV_OBJ_DIR)/, $(notdir $(SRC_C:.c=.o)))
TEST_OBJ			=	$(addprefix $(OBJ_DIR)/, $(notdir $(TEST_SRC:.c=.o)))
GCOV_TEST_OBJ		= 	$(addprefix $(GCOV_OBJ_DIR)/, $(notdir $(TEST_SRC:.c=.o)))

INCLUDES			=	$(shell find . -maxdepth 1 -name "*.h")
TEST_INCLUDES		=	$(shell find $(TEST_DIR) -name "*.h")

RM					=	rm -f
MK					=	mkdir -p
COPY_FILE     		=	cp -f

.DEFAULT_GOAL := all

all: 

%: $(OBJ_DIR)
	@$(MAKE) -f $(QMAKEFILE) $@


$(TEST_TARGET)		:	$(OBJ_DIR) $(TEST_OBJ) $(OBJ_C)
	$(CC) -o $(TEST_TARGET) $(TEST_OBJ) $(OBJ_C) $(TEST_LIBS)
	./test

$(OBJ_C)			:	$(OBJ_DIR)%.o		:	$(CALCULATOR_DIR)%.c $(INCLUDES)
	$(CC) -c $(CFLAGS) $< -o $@

$(GCOV_OBJ_C)		:	$(GCOV_OBJ_DIR)%.o 	:	$(CALCULATOR_DIR)%.c $(INCLUDES)
	$(CC) -c $(CFLAGS) $< -o $@

$(TEST_OBJ)			:	$(OBJ_DIR)%.o		:	$(TEST_DIR)%.c $(TEST_INCLUDES)
	$(CC) -c $(CFLAGS) $< -o $@

$(OBJ_DIR)			:
	$(MK) $(OBJ_DIR)

$(GCOV_OBJ_DIR)		:
	$(MK) $(GCOV_OBJ_DIR)

gcov_report			:	CFLAGS += $(GCOV_FLAGS)
gcov_report			:	$(GCOV_TARGET)

$(GCOV_TARGET)		:	$(GCOV_INFO)
	genhtml $(GCOV_INFO) -o $(GCOV_TARGET)

$(GCOV_INFO)		:	$(TEST_GCOV_EXE)
	./$(TEST_GCOV_EXE)
	geninfo $(GCOV_OBJ_DIR) -b . -o ./$(GCOV_INFO)

$(TEST_GCOV_EXE)	:	$(GCOV_OBJ_DIR) $(OBJ_DIR) $(GCOV_OBJ_C) $(TEST_OBJ) Makefile
	$(CC) $(GCOV_OBJ_C) $(TEST_OBJ) $(GCOV_FLAGS) -o $(TEST_GCOV_EXE) $(TEST_LIBS)

open				:
	open coverage/index.html


clean				:
	$(MAKE) -f $(QMAKEFILE) clean
	$(RM) -r $(GCOV_OBJ_DIR)
	$(RM) -r $(OBJ_DIR)
	$(RM) moc_*
	$(RM) qrc_*
	$(RM) -r calculator.app
	$(RM) ui_calculator.h
	$(RM) $(TEST_TARGET)
	$(RM) $(TEST_GCOV_EXE)
	$(RM) -r $(GCOV_TARGET)
	$(RM) $(GCOV_INFO)

run:
	open calculator.app/Contents/MacOS/calculator

dist:
	cat $(QMAKEFILE) | sed 's/--parents/-p/g' > /tmp/`basename $(QMAKEFILE)`
	mv -f /tmp/`basename $(QMAKEFILE)` $(QMAKEFILE)
	$(MAKE) -f $(QMAKEFILE) dist

dvi:
	latex -output-directory=./docs ./docs/docs.tex ./docs/brief.dvi
	pdflatex -output-directory=./docs ./docs/docs.tex ./docs/brief.pdf

.PHONY: test run clean dist open gcov_report all