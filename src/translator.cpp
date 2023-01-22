#include <iostream>
#include <string>
#include <set>
#include <sstream>
#include <map>

std::set<std::string> make_exit_commands()
{
    return std::set<std::string>{"q", "quit", "e", "exit"};
}

int main()
{
    std::string enterKey;
    const auto options_exit = make_exit_commands();
    auto dico = std::map<std::string, std::pair<std::string, std::string>>{};
    while (true)
    {
        // std::cout << "This is a translator, but it does nothing for now..." << std::endl;
        std::cin >> enterKey;
        if (options_exit.count(enterKey))
        {
            break;
        }
        else if (enterKey == "add")
        {
            std::string un, deux;
            std::cin >> un;
            std::cin >> deux;
            std::cout << un << " => " << deux << std::endl;
            dico.insert(un, (un, deux));
        }
        else if (enterKey == "translate")
        {
            ;
        }

        /*
        std::string line;
        std::getline(std::cin, line);
        std::stringstream line_stream{};
        line_stream << line;
        std::string mot;
        while (!line_stream.eof())
        {
            line_stream >> mot;
            std::cout << mot << std::endl;
        }
        */
    }
    return 0;
}