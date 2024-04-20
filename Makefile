
make test:
	g++ unit_test/main_test.cpp -std=c++20 -Wextra -Wconversion -fsanitize=address,undefined  -o unit_test/unit_test -lgtest -g
	./unit_test/unit_test

%: %.cpp
	g++ -Wall -O2 -std=c++20 -Wextra -Wconversion -fsanitize=address,undefined  -o $@ $< -g
	
