#pragma once

#include <iostream>
#include <locale>

namespace recipe_2_05
{
    inline void
    execute()
    {
        {
            std::cout << "C++\n";
        }

        {
            std::cout << "Erling Håland\n";
            std::cout << "Thomas Müller\n";
            std::cout << "Στέφανος Τσιτσιπάς\n";

            std::string monkeys = "🙈🙉🙊";
            std::cout << monkeys << '\n';
        }

        {
            std::cout << reinterpret_cast<const char *>(u8"Στέφανος Τσιτσιπάς\n");
        }

        {
            std::locale utf8("en_US.UTF8");
            std::wcout.imbue(utf8);

            std::wcout << L"Erling Håland\n";
            std::wcout << L"Thomas Müller\n";
            std::wcout << L"Στέφανος Τσιτσιπάς\n";

            std::wstring monkeys = L"🙈🙉🙊";
            std::wcout << monkeys << '\n';
        }
    }
} // namespace recipe_2_05
