/*
Matt Olson
Alex Izydorczyk

Implement unit testing functions
*/

#include <iostream>
#include <regex>
#include <sstream>
#include "solver.hpp"

#include "game.hpp"
#include "tests.hpp"
#include <ctime>
#include <ratio>
#include <chrono>

using namespace std;

// Unit test for comparing functions
// Specify size of puzzle, numbers of filled in values (number of observations
// Number of repeats and whether verbose
void unitTest(int size, int nobs, int ntimes, bool verbose, const std::string& solver_method){

    long long total_bt = 0;
    long long total_rp = 0;

    //generate puzzle and solve ntimes
    for (int i = 0; i < ntimes; ++i)
    {
        Board board = generatePuzzle(size,nobs);

        if (solver_method == "backtrace") {
            auto t = measure<std::chrono::nanoseconds>::execution(solve, board, 0, 0);
            if (verbose) cout << "Backtrace solved in " << t << " ns." << endl;
            total_bt += t;
        } else if (solver_method == "rp") {
            // auto t2 = measure<std::chrono::nanoseconds>::execution(DR, board);
            if (verbose) cout << "Random projections solver is unavailable in this build." << endl;
            // total_rp += t2;
        } else { // Fallback to run both if method is somehow different
            Board board_for_bt = board; // Use a copy for the first solver
            auto t = measure<std::chrono::nanoseconds>::execution(solve, board_for_bt, 0, 0);
            if (verbose) cout << "Backtrace solved in " << t << " ns. Random projections solver is unavailable in this build." << endl;
            total_bt += t;
        }
    }

    if (total_bt > 0) {
        cout << "Average time for Backtrace: " << total_bt/ntimes << " ns" << endl;
    }
    if (total_rp > 0) {
        cout << "Average time for Random projections: " << total_rp/ntimes << " ns" << endl;
    }
}
