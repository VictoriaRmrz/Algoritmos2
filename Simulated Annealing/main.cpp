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
    return sin(x) + 0.5 * cos(3 * x);
}

double simulatedAnnealing(double initialTemperature, double coolingRate, int maxIterations) {
    double currentState = getRandomNumber(-5.0, 6.0); // the initial search starts in a random number between -5 and 5
    double currentScore, nextState, nextScore, delta, probability;
    double randomNumber = getRandomNumber(0.0, 1.0);

    int k = 0;

    while (k < maxIterations) {
        currentScore = Fx(currentState); // calculate "y" of the current state
        nextState = currentState + getRandomNumber(-1.0, 1.0); //  calculate the next state with a random difference
        nextScore = Fx(nextState); // calculate "y" of the next state
        delta = nextScore - currentScore; 
        probability = exp(-delta / initialTemperature);

        if (delta <= 0) { // if delta is negative, means the next score is lower than the current state so, move to the next state
            currentState = nextState;
        } else { 
            // if the probability of accepting a worse solution is greater than a randomly generated number, move to the next sate
            if (probability > randomNumber) 
                currentState = nextState;
        }
        k++;
        // This multiplication reduces the temperature.
        // The temperatue drops over time, and the probability of adopting a worst solutions also reduces.
        initialTemperature *= coolingRate; 
    }

    return currentState;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    double initialTemperature = 100.0;
    double coolingRate = 0.95; // Precision of the calculations
    int maxIterations = 1000;

    double result = simulatedAnnealing(initialTemperature, coolingRate, maxIterations);

    cout << "Optimal X: " << result << endl;
    cout << "Optimal Y: " << Fx(result) << endl;

    return 0;
}
