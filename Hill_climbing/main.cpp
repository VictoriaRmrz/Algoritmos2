// Victoria Ramírez Castro A01640824
//Andrea Valeria Pintor Valencia  A01067424
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// Create a random number between 2 numbers
double getRandomNumber(double min, double max) {
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return min + ((max - min) * (rand() * fraction));
}

// The objective function to be maximized
double Fx(double x) {
    return -(x*x);  
}

double hillClimbing(double initialGuess, double stepSize, int maxIterations) {
    double currentState = initialGuess; // the current state takes the value of the random number
    double currentScore, nextState, previousState, previousScore, nextScore;

    for (int i = 0; i < maxIterations; ++i) {
        nextState = currentState + stepSize; // create a "bigger" neighbor
        previousState = currentState - stepSize; // create a "smaller" neighbor

        currentScore = Fx(currentState); // calculate "y" of the current state
        nextScore = Fx(nextState); // calculate "y" of the next state
        previousScore = Fx(previousState); // calculate "y" of the previous state

        // If the next score is bigger than the previous score and than the current score, accept the next state
        if (nextScore > currentScore && nextScore >= previousScore) {
            currentState = nextState;
        } else if (previousScore > currentScore && previousScore >= nextScore) {  //If the previous score is bigger than the next score and than the current score, accept the previous state
            currentState = previousState;
        } 
        
    }

    return currentState; 
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    double initialGuess = getRandomNumber(-4, 4); // the searching scope is in a range of -4 from 4
    double stepSize = 0.001;
    int maxIterations = 10000;

    double result = hillClimbing(initialGuess, stepSize, maxIterations);
    
    cout << "Optimal solution: " << result << endl;

    return 0;
}