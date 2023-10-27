#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

#include <stdlib.h>
void ft_leaks(void)
{
	system("leaks -q a.out");
}

int main(int, char**)
{
	atexit(ft_leaks);
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
	std::cout << "3 int, array[2] = 42:\n";
	Array<int> array(3);
	array[2] = 42;
	for (unsigned int i = 0; i < array.size(); i++)
		std::cout << array[i] << " ";
	std::cout << "\n";

	std::cout << "3 string, tab[1] = \"hola\":\n";
	Array<std::string> tab(3);
	tab[1] = "hola";
	for (unsigned int i = 0; i < tab.size(); i++)
		std::cout << tab[i] << ".";
	std::cout << "\n";
    return 0;
}