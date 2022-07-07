cmake_minimum_required(VERSION 3.5)

project(SmartCalc VERSION 0.1 LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_C_COMPILER /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

enable_testing()
add_subdirectory(tests)

set(PROJECT_SOURCES
	buttons_text_add_on_click.cpp
	calculator.cpp	
	calculator.h
	main.cpp
	qcustomplot.cpp
	qcustomplot.h
	calculator/calc.c
	calculator/converting.c
	calculator/main.h
	calculator/smartcalc.c
	calculator/validate.c
	calculator.ui
	resourses.qrc
)

add_executable(SmartCalc
    ${PROJECT_SOURCES}
)

target_link_libraries(SmartCalc PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(SmartCalc PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

find_program(LCOV lcov)
find_program(GENHTML genhtml)
if(NOT GCOV)
  message(FATAL_ERROR "gcov not found!")
endif()
if(NOT LCOV)
  message(FATAL_ERROR "lcov not found!")
endif()
if(NOT GENHTML)
  message(FATAL_ERROR "genhtml not found!")
endif()

add_custom_target(gcov_report
  COMMAND mkdir -p Coverage
  DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/Testing
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

add_custom_command(TARGET gcov_report POST_BUILD
  COMMAND ${LCOV} --directory .. --capture --output-file lcov.info
  COMMAND ${GENHTML} -o . lcov.info
  COMMAND echo "Coverage reports generated."
  COMMAND echo "You can find them on ${CMAKE_BINARY_DIR}/Coverage"
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/Coverage
  COMMENT "Coverage Reports Generated"
)

add_custom_target(open
	COMMAND open Coverage/calculator/index.html
)

set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES Coverage)