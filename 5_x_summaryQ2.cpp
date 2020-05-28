// Simple HiLo game created for c++ tutorial answer

#include <iostream>
#include <random>
#include <ctime>

constexpr int min{ 1 };
constexpr int max{ 100 };
constexpr int attempts{ 7 };

//Random integer generator following tutorial course example
namespace MyRandom
{
    std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
}
int getRandomNumber(int min, int max)
{
    std::uniform_int_distribution<> die{ min, max };
    return die(MyRandom::mersenne);
}

//Core game function
void playHiLo(int x, int attempts)
{
    std::cout << "Let's play a game.  I'm thinking of a number.  You have " << attempts << 
        " tries to guess what it is.\n";
    for (int count{ 1 }; count <= attempts; ++count)
    {
        std::cout << "Geuss #" << count << ": ";
        int guess{};
        std::cin >> guess;
        
        if (guess == x)
        {
            std::cout << "Correct!\n";
            return;
        }
        else if (guess < x)
            std::cout << "Your guess is too low.\n";
        else
            std::cout << "Your guess is too high\n";
    }
    std::cout << "Sorry, you lose. The correct number was " << x << ".\n";
}

//Does the player want to play again
bool playAgain()
{
    while(true)
    {
        std::cout << "Would you like to play again (y/n)? ";
        char c{};
        std::cin >> c;
        switch (c)
        {
            case 'y':
                return true;
            case 'n':
                return false;
            default:    //Checks for valid input y/n
                break;
        }
    }
}

int main()
{
    do
    {
        playHiLo(getRandomNumber(min, max), attempts);
    }
    while (playAgain());

    return 0;
}
