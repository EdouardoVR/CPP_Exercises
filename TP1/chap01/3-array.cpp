#include <iostream>
#include <array>
#include <vector>

int main(int argc, char **argv)
{
    /*
    if (argc < 2)
    {
        std::cerr << "Erreur ! Manque un argument !" << std::endl;
        return -1;
    }
    */
    /*int array[] = {0, 1, 2, 3};*/

    // int array[50] = {};

    /*for (int i = 0; i < 4; ++i)
    {
        std::cout << array[i] << std::endl;
    }*/
    /*
    for (int i = 0; i < 50; i++)
    {
        array[i] = i + 1;
    }

    for (int i : array)
    {
        std::cout << i << std::endl;
    }
    */
    /*
     int number = std::stoi(argv[1]);
     if (number <= 0)
     {
         std::cerr << "number <= 0" << std::endl;
         return -1;
     }
     std::cout << "Voici votre argument : " << number << std::endl;
     */

    std::vector<int> array;
    for (int i = 0; i < 50; i++)
    {
        array.__emplace_back(i + 1);
    }

    for (int i : array)
    {
        std::cout << i << std::endl;
    }
    return 0;
}
