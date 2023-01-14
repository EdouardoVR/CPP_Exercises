#include <iostream>
#include <string>
#include <vector>
#include <array>

bool parse_params(char &op, std::vector<int> &values, int arg, char **argv);
int add(const std::vector<int> &values);
int mul(const std::vector<int> &values);
int sub(const std::vector<int> &values);
int compute_result(char op, const std::vector<int> &values);
void display_result(int result);

int main(int argc, char **argv)
{

    char op = '?';
    std::vector<int> values;

    if (!parse_params(op, values, argc, argv))
    {
        return -1;
    }

    auto result = compute_result(op, values);

    display_result(result);

    return 0;
}

bool parse_params(char &op, std::vector<int> &values, int arg, char **argv)
{
    // Parsing program parameters.

    if (arg < 2)
    {
        std::cerr << "Expected operator as first argument." << std::endl;
        return false;
    }

    std::string op_argv = argv[1];

    if (op_argv != "+" && op_argv != "*" && op_argv != "-")
    {
        std::cerr << "Expected operator to be '+', '*' or '-'." << std::endl;
        return false;
    }

    op = op_argv[0];

    for (auto arg_i = 2; arg_i < arg; ++arg_i)
    {
        auto value = std::stoi(argv[arg_i]);
        values.__emplace_back(value);
    }

    if (op == '-')
    {
        if (values.empty())
        {
            std::cerr << "Operator '-' expects at least one operand to substract from." << std::endl;
            return false;
        }
    }

    return true;
}

int add(const std::vector<int> &values)
{
    auto result = 0;
    for (auto v : values)
    {
        result += v;
    }
    return result;
}

int mul(const std::vector<int> &values)
{
    auto result = 1;
    for (auto v : values)
    {
        result *= v;
    }
    return result;
}

int sub(const std::vector<int> &values)
{
    auto result = values[0];
    for (auto i = 1u; i < values.size(); ++i)
    {
        result -= values[i];
    }
    return result;
}

int compute_result(char op, const std::vector<int> &values)
{
    // Process operation, depending on the operator.

    switch (op)
    {
    case '+':
        return add(values);
    case '*':
        return mul(values);
    case '-':
        return sub(values);
    default:
        return 0;
    }
}

void display_result(int result)
{
    // Output result.
    std::cout << "Result is " << result << std::endl;
}