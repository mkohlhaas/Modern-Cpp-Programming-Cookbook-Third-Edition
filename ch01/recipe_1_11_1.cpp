#include "recipe_1_11_1.h"
#include "features.h"
#include <iostream>
#include <string>

using namespace std::string_literals;

namespace
{
    void
    print(std::string const &message)
    {
        std::cout << "[file1] " << message << '\n';
    }
} // namespace

namespace recipe_1_11
{
    void
    file1_run()
    {
        print("run"s);
    }
} // namespace recipe_1_11