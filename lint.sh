# cp ../materials/linters/CPPLINT.cfg .

find backend -type f -name "*.c" | xargs python3 cpplint.py --extensions=c
find test -type f -name "*.c" | xargs python3 cpplint.py --extensions=c
find backend -type f -name "*.h" | xargs python3 cpplint.py --extensions=c
find test -type f -name "*.h" | xargs python3 cpplint.py --extensions=c

#find . -type f -name "*.c" | xargs ~/homebrew/bin/cppcheck
#find . -type f -name "*.c" | xargs ~/homebrew/bin/cppcheck --enable=all --suppress=missingIncludeSystem
#find . -type f -name "*.c" | xargs cppcheck
find backend -type f -name "*.c" | xargs cppcheck --enable=all --suppress=missingIncludeSystem
find test -type f -name "*.c" | xargs cppcheck --enable=all --suppress=missingIncludeSystem

# rm -f CPPLINT.cfg
