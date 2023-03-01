mkdir build
cd build
g++ ../area_function/test/test_area.cpp ../area_function/src/area.cpp -I../area_function/include -g -lgtest -ftest-coverage -fprofile-arcs -o test_area
./test_area
lcov --capture --directory . --output-file lcov.info
genhtml lcov.info --output-directory out