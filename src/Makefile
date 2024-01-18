CC=gcc -Wall -Wextra -Werror -std=c11
FLAGS=-lm -lcheck -lpthread
GCOV_FLAGS=-fprofile-arcs -ftest-coverage
GL_FLAGS=--coverage

LIB_NAME=s21_math.a

FUNC_FILES_C=s21_math/*.c
FUNC_FILES_O=*.o

EXEC_FILES=s21_abs_test s21_fabs_test s21_fmod_test s21_log_test s21_sin_test s21_cos_test s21_tan_test s21_acos_test s21_asin_test s21_atan_test s21_ceil_test s21_floor_test s21_exp_test s21_pow_test s21_sqrt_test

all : s21_math.a

s21_math.a :
	$(CC) -c $(FUNC_FILES_C) $(FLAGS)
	make build_library
	rm -rf *.o

gcov_report : clean build_object_files build_library test
	lcov -o tests.info -c -d .
	genhtml -o report tests.info
	open report/index.html
	make clean

clean :
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.gcov
	rm -rf *.o
	rm -rf *.a
	rm -rf *.info
	rm -rf $(EXEC_FILES)


build_object_files :
	$(CC) $(FLAGS) $(GCOV_FLAGS) $(GL_FLAGS) -c $(FUNC_FILES_C)

build_library :
	ar rcs $(LIB_NAME) $(FUNC_FILES_O)
	
test : s21_math.a
	$(CC) $(FLAGS) $(GCOV_FLAGS) $(GL_FLAGS) s21_tests/s21_abs_test.c -L. s21_math.a -o s21_abs_test
	$(CC) $(FLAGS) $(GCOV_FLAGS) $(GL_FLAGS) s21_tests/s21_acos_test.c -L. s21_math.a  -o s21_acos_test
	$(CC) $(FLAGS) $(GCOV_FLAGS) $(GL_FLAGS) s21_tests/s21_asin_test.c -L. s21_math.a  -o s21_asin_test
	$(CC) $(FLAGS) $(GCOV_FLAGS) $(GL_FLAGS) s21_tests/s21_atan_test.c -L. s21_math.a  -o s21_atan_test
	$(CC) $(FLAGS) $(GCOV_FLAGS) $(GL_FLAGS) s21_tests/s21_ceil_test.c -L. s21_math.a  -o s21_ceil_test
	$(CC) $(FLAGS) $(GCOV_FLAGS) $(GL_FLAGS) s21_tests/s21_cos_test.c -L. s21_math.a  -o s21_cos_test
	$(CC) $(FLAGS) $(GCOV_FLAGS) $(GL_FLAGS) s21_tests/s21_exp_test.c -L. s21_math.a  -o s21_exp_test
	$(CC) $(FLAGS) $(GCOV_FLAGS) $(GL_FLAGS) s21_tests/s21_fabs_test.c -L. s21_math.a  -o s21_fabs_test
	$(CC) $(FLAGS) $(GCOV_FLAGS) $(GL_FLAGS) s21_tests/s21_floor_test.c -L. s21_math.a  -o s21_floor_test
	$(CC) $(FLAGS) $(GCOV_FLAGS) $(GL_FLAGS) s21_tests/s21_fmod_test.c -L. s21_math.a  -o s21_fmod_test
	$(CC) $(FLAGS) $(GCOV_FLAGS) $(GL_FLAGS) s21_tests/s21_log_test.c -L. s21_math.a  -o s21_log_test
	$(CC) $(FLAGS) $(GCOV_FLAGS) $(GL_FLAGS) s21_tests/s21_pow_test.c -L. s21_math.a  -o s21_pow_test
	$(CC) $(FLAGS) $(GCOV_FLAGS) $(GL_FLAGS) s21_tests/s21_sin_test.c -L. s21_math.a  -o s21_sin_test
	$(CC) $(FLAGS) $(GCOV_FLAGS) $(GL_FLAGS) s21_tests/s21_sqrt_test.c -L. s21_math.a  -o s21_sqrt_test
	$(CC) $(FLAGS) $(GCOV_FLAGS) $(GL_FLAGS) s21_tests/s21_tan_test.c -L. s21_math.a  -o s21_tan_test

	./s21_abs_test
	./s21_acos_test
	./s21_asin_test
	./s21_atan_test
	./s21_ceil_test
	./s21_cos_test
	./s21_exp_test
	./s21_fabs_test
	./s21_floor_test
	./s21_fmod_test
	./s21_log_test
	./s21_pow_test
	./s21_sin_test
	./s21_sqrt_test
	./s21_tan_test
