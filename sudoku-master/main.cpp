/*
Matt Olson
Alex Izydorczyk

Main driver of Sudoku game
*/
#include <iostream>
#include <regex>
#include <sstream>
#include "solver.hpp"

#include "game.hpp"
#include "tests.hpp"
#include <string>
#include <ctime>
#include <algorithm>

using namespace std;

// Helper to parse an integer argument
bool parseIntArg(int argc, char* argv[], int& i, int& value, const string& argName) {
    if (i + 1 < argc) {
        istringstream ss(argv[++i]);
        if (!(ss >> value)) {
            cerr << "Invalid number for " << argName << ": " << argv[i] << endl;
            return false;
        }
    } else {
        cerr << argName << " option requires one argument." << endl;
        return false;
    }
    return true;
}

int main(int argc, char* argv[]){

    unsigned int seed = time(NULL); //random seed
    int gamesize = 9; // default size of game
    int nobs = 10; // default number of prefilled spaces
    int sim = 0; // number of simulation runs (if running speed tests)
    bool verbose = false; // print each simulation result for speed tests
    string solver_method = "backtrace"; // default solver

    // Handle command line args
    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];
        // For case-insensitive comparison for flags that have it
        string lower_arg = arg;
        transform(lower_arg.begin(), lower_arg.end(), lower_arg.begin(), ::tolower);

        if (arg == "--seed" || arg == "-s") {
            int temp_seed;
            if (!parseIntArg(argc, argv, i, temp_seed, "--seed")) return 1;
            seed = temp_seed;
        }
        else if (arg == "--gamesize" || arg == "-g") {
            if (!parseIntArg(argc, argv, i, gamesize, "--gamesize")) return 1;
        }
        else if (arg == "--nobs" || arg == "-n") {
            if (!parseIntArg(argc, argv, i, nobs, "--nobs")) return 1;
        }
        else if (lower_arg == "--unittest" || arg == "-u") {
            if (!parseIntArg(argc, argv, i, sim, "--Unittest")) return 1;
        }
        else if (lower_arg == "--verbose" || arg == "-v") {
            verbose = true;
        }
        else if (lower_arg == "--rp") {
            // The --RP flag was present but not used.
            // This will now select the Random Projections solver.
            solver_method = "rp";
        }
        else {
            cerr << "Unknown argument: " << arg << endl;
            return 1; // Exit on unknown argument
        }
    }

    srand(seed); // set random seed

    // Welcome message
    cout << "===========================================" << endl;
    cout << "============ Welcome to Sudoku! ===========" << endl;
    cout << "===========================================" << endl;

    // Play game or run simulations
    if (sim == 0){
        playGame(gamesize, nobs, solver_method);
    } else {
        unitTest(gamesize, nobs, sim, verbose, solver_method);
    }

    return 0;
}
