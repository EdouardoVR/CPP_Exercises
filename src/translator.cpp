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
/*

#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using Dictionary = std::map<std::string, std::string>;
using History = std::vector<std::string>;
using Context = std::pair<Dictionary, History>;
using Languages = std::pair<std::string, std::string>;
using Translator = std::map<Languages, Context>;

std::set<std::string> make_exit_commands()
{
    return {"q", "e", "exit", "quit"};
}

bool execute_instruction(std::istream &input,
                         Translator &translator,
                         Languages &languages)
{
    const auto exit_commands = make_exit_commands();
    auto &[dictionary, history] = translator[languages];

    auto command = std::string{};
    input >> command;

    if (exit_commands.count(command) != 0)
    {
        return false;
    }
    else if (command == "add")
    {
        auto key = std::string{};
        input >> key;

        auto &value = dictionary[key];
        input >> value;

        std::cout << key << " => " << value << std::endl;
        history.push_back("add " + key + " " + value);
    }
    else if (command == "translate")
    {
        auto line = std::string{};
        std::getline(input, line);

        auto words = std::stringstream{};
        words << line;

        while (!words.eof())
        {
            auto key = std::string{};
            words >> key;

            const auto it = dictionary.find(key);
            std::cout << (it == dictionary.end() ? "???" : it->second) << " ";
        }

        std::cout << std::endl;
    }
    else if (command == "print")
    {
        for (const auto &[key, value] : dictionary)
        {
            std::cout << key << " => " << value << std::endl;
        }
    }
    else if (command == "save")
    {
        auto name = std::string{};
        input >> name;

        auto file = std::ofstream{name};
        for (const auto &command : history)
        {
            file << command << "\n";
        }
    }
    else if (command == "load")
    {
        auto name = std::string{};
        input >> name;

        auto file = std::ifstream{name};
        while (!file.eof())
        {
            execute_instruction(file, translator, languages);
        }
    }
    else if (command == "clear")
    {
        dictionary.clear();
        history.clear();
    }
    else if (command == "remove")
    {
        auto word = std::string{};
        input >> word;

        for (auto it = dictionary.begin(); it != dictionary.end();)
        {
            if (it->first == word || it->second == word)
            {
                std::cout << it->first << " x " << it->second << std::endl;
                it = dictionary.erase(it);
            }
            else
            {
                ++it;
            }
        }

        history.push_back("remove " + word);
    }
    else if (command == "from")
    {
        std::cin >> languages.first;
    }
    else if (command == "to")
    {
        std::cin >> languages.second;
    }

    return true;
}

int main(int argc, char **argv)
{
    auto languages = argc == 3 ? Languages{argv[1], argv[2]} : Languages{"fr", "en"};

    auto translator = Translator{};

    while (true)
    {
        std::cout << "Enter a command: " << std::endl;

        if (!execute_instruction(std::cin, translator, languages))
        {
            break;
        }

        std::cout << std::endl;
    }

    return 0;
}
*/