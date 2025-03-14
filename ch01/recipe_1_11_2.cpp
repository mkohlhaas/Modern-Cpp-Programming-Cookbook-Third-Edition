#include "recipe_1_11_2.h"
#include "features.h"
#include <iostream>
#include <string>

using namespace std::string_literals;

namespace
{
    void
    print(std::string const &message)
    {
        std::cout << "[file2] " << message << '\n';
    }
} // namespace

namespace recipe_1_11
{
    void
    file2_run()
    {
        print("run"s);
    }
} // namespace recipe_1_11
