// Aadrij Upadya
// October 2, 2023
// Program P4.26
// Write a program that simulates two strategies to solving the Monty Hall problem

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;
int main()
{
    srand(time(0));        // here we set a random seed each time so that we get different numbers each iteration
    int strategy1_sum = 0; // counters to keep track of number of times each strategy is successful
    int strategy2_sum = 0;

    for (int i = 0; i < 1000; i++) // running a loop to simulate 1000 iterations
    {
        int car_number = rand() % (3 - 1 + 1) + 1;        // car_number is the number of the door with car
        int first_player_pick = rand() % (3 - 1 + 1) + 1; // first_player_pick is the first door that player picks
        int first_goat_pick = rand() % (3 - 1 + 1) + 1;   // first_goat_pick is the door that the game show host reveals to you
        // generating 3 random numbers between 1 and 3 to represent each variable

        while (first_goat_pick == car_number || first_goat_pick == first_player_pick)
        {
            first_goat_pick = rand() % (3 - 1 + 1) + 1;
        }
        // making sure to change first_goat_pick until its different from door w car_number and player's first pick

        int player_1_strategy = rand() % (3 - 1 + 1) + 1;
        while (player_1_strategy == first_player_pick || player_1_strategy == first_goat_pick)
        {
            player_1_strategy = rand() % (3 - 1 + 1) + 1;
        }
        // strategy 1 is to switch, so we makre sure its different from original guess and revealed door

        int player_2_strategy = first_player_pick;
        // strategy 2 is to stick with guess, so same as original one

        // increment counter based on which strategy works
        if (player_1_strategy == car_number)
        {
            strategy1_sum++;
        }

        if (player_2_strategy == car_number)
        {
            strategy2_sum++;
        }
    }

    cout << "How many times strategy 1 was successful out of 1000 simulations: " << strategy1_sum << endl;
    cout << "How many times strategy 2 was successful out of 1000 simulations: " << strategy2_sum << endl;
    // returning to user how many times each strategy was successful out of 1000
}