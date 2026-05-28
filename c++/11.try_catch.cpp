#include <iostream>
#include <stdexcept>

int main()
{

    while (1)
    {

        std::string c1;
        std::string c2;

        std::cin >> c1 >> c2;

        try
        {
            if (c1 == c2)
            {
                throw std::runtime_error("xxxx");
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            break;
        }
    }

    return 0;
}