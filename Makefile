CC					= 	gcc
CXX					= 	g++
RCC					= 	/opt/homebrew/share/qt/libexec/rcc
MOC					= 	/opt/homebrew/share/qt/libexec/moc
UIC					= 	/opt/homebrew/share/qt/libexec/uic
TARGET				=	SmartCalc
TEST_TARGET			=	test
TEST_GCOV_EXE		=	test_gcov
GCOV_TARGET			=	./coverage
GCOV_INFO			=	coverage.info
CFLAGS				=	-std=c11 -Wall -Wextra #-fsanitize=address -g #-Werror
CXXFLAGS			=	-std=c++17
GCOV_FLAGS			=	-fprofile-arcs -ftest-coverage
LIBS				=	-F/opt/homebrew/lib -framework QtWidgets -framework QtGui -framework AppKit -framework ImageIO -framework Metal -framework QtCore -framework DiskArbitration -framework IOKit -framework AGL -framework OpenGL
TEST_LIBS			=	-lcheck

TARGET_DIR			=	.
TEST_DIR			=	./tests
CALCULATOR_DIR 		= 	./calculator
OBJ_DIR				=	./objs
GCOV_OBJ_DIR		=	./gcov_objs

INCPATH				= 	-I/opt/homebrew/lib/QtWidgets.framework/Headers \
						-I/opt/homebrew/lib/QtGui.framework/Headers \
						-I/opt/homebrew/lib/QtCore.framework/Headers \
						-F/opt/homebrew/lib

BUTTONS 			=	$(shell find Buttons)

MOC_FILES			=	moc_calculator.cpp moc_qcustomplot.cpp
SRC_CXX 			:=	$(shell find . -name "*.cpp" -not -name "moc_*") $(MOC_FILES)
SRC_C 				:=	$(shell find $(CALCULATOR_DIR) -name "*.c")
TEST_SRC	 		:=	$(shell find $(TEST_DIR) -name "*.c")

OBJ_C 				=	$(addprefix $(OBJ_DIR)/, $(notdir $(SRC_C:.c=.o)))
GCOV_OBJ_C			=	$(addprefix $(GCOV_OBJ_DIR)/, $(notdir $(SRC_C:.c=.o)))
TEST_OBJ			=	$(addprefix $(OBJ_DIR)/, $(notdir $(TEST_SRC:.c=.o)))
GCOV_TEST_OBJ		= 	$(addprefix $(GCOV_OBJ_DIR)/, $(notdir $(TEST_SRC:.c=.o)))
OBJ_CXX				=	$(addprefix $(OBJ_DIR)/, $(notdir $(SRC_CXX:.cpp=.o)))

INCLUDES			=	$(shell find . -maxdepth 1 -name "*.h")
TEST_INCLUDES		=	$(shell find $(TEST_DIR) -name "*.h")
UI					=	calculator.ui
UI_HEADER			=	ui_calculator.h

RM					=	rm -f
MK					=	mkdir -p

all					:	$(TARGET) $(TEST_TARGET) gcov_report Makefile

$(TARGET)			:	$(UI_HEADER) $(MOC_FILES) $(OBJ_DIR) $(OBJ_C) $(OBJ_CXX)
	$(CXX) -o $(TARGET) $(OBJ_C) $(OBJ_CXX) $(LIBS)

$(TEST_TARGET)		:	$(OBJ_DIR) $(TEST_OBJ) $(OBJ_C)
	$(CC) -o $(TEST_TARGET) $(TEST_OBJ) $(OBJ_C) $(TEST_LIBS)
	./test

$(OBJ_C)			:	$(OBJ_DIR)%.o		:	$(CALCULATOR_DIR)%.c $(INCLUDES)
	$(CC) -c $(CFLAGS) $< -o $@

$(GCOV_OBJ_C)		:	$(GCOV_OBJ_DIR)%.o 	:	$(CALCULATOR_DIR)%.c $(INCLUDES)
	$(CC) -c $(CFLAGS) $< -o $@

$(OBJ_CXX)			:	$(OBJ_DIR)%.o		:	$(TARGET_DIR)%.cpp $(INCLUDES)
	$(CXX) -c $(CXXFLAGS) $(INCPATH) $< -o $@

$(TEST_OBJ)			:	$(OBJ_DIR)%.o		:	$(TEST_DIR)%.c $(TEST_INCLUDES)
	$(CC) -c $(CFLAGS) $< -o $@

qrc_resourses.cpp	:	resourses.qrc $(BUTTONS)
	$(RCC) -name resourses resourses.qrc -o qrc_resourses.cpp

moc_calculator.cpp	:	calculator.h \
                		qcustomplot.h \
                		$(CALCULATOR_DIR)/main.h
	$(MOC) $(INCPATH) calculator.h -o moc_calculator.cpp

moc_qcustomplot.cpp	:	qcustomplot.h
	$(MOC) $(INCPATH) qcustomplot.h -o moc_qcustomplot.cpp

$(UI_HEADER)		:	$(UI) qcustomplot.h
	$(UIC) $(UI) -o $(UI_HEADER)

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
	$(RM) -r $(OBJ_DIR)
	$(RM) -r $(GCOV_OBJ_DIR)

fclean				:	clean
	$(RM) moc_*
	$(RM) qrc_*
	$(RM) SmartCalc
	$(RM) ui_calculator.h
	$(RM) $(TEST_TARGET)
	$(RM) $(TEST_GCOV_EXE)
	$(RM) -r $(GCOV_TARGET)
	$(RM) $(GCOV_INFO)

re: fclean all