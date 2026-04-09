#include <iostream>

int main()
{
    int player_score = 10;
    int player_lives = 3;

    std::cout << player_score << std::endl;
    std::cout << player_lives << std::endl;
    std::cout << std::endl;

    std::cout << player_score++ << std::endl;
    std::cout << ++player_score << std::endl;
    std::cout << player_lives-- << std::endl;
    std::cout << --player_lives << std::endl;

    return 0;
}