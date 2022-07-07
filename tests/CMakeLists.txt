# set(TEST_SRCS
	# calc_test.h
	# calc_test.c
	# colors.h
	# polish_test.c
	# ../calculator/calc.c
	# ../calculator/converting.c
	# ../calculator/main.h
	# ../calculator/smartcalc.c
	# ../calculator/validate.c
# )

file(GLOB_RECURSE SRCS
	 LIST_DIRECTORIES	true CONFIGURE_DEPENDS
	 ../calculator/*.c
	 ../calculator/*.h
)
file(GLOB_RECURSE TEST_SRCS
	 LIST_DIRECTORIES	true CONFIGURE_DEPENDS
	 ./*.c
	 ./*.h
)

set(ALL_SRCS ${SRCS} ${TEST_SRCS})
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage -O0")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_THREAD_SAFE -I/opt/homebrew/Cellar/check/0.15.2/include")
set_source_files_properties(${SRCS} PROPERTIES COMPILE_FLAGS -fprofile-arcs -ftest-coverage -O0)

add_executable(test_exe
	${ALL_SRCS})

target_link_libraries(test_exe -L/opt/homebrew/Cellar/check/0.15.2/lib -lcheck --coverage)

add_test(NAME polish_test COMMAND test_exe WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/Testing)

set_tests_properties(polish_test PROPERTIES TIMEOUT 30) 