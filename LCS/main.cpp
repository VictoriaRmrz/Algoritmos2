#include <iostream>
#include <vector>
using namespace std;

int lcs(vector<string> X, vector<string> Y, int m, int n) // X and Y are the input strings, m and n their lenghts
{

    if (m == 0 || n == 0)
        return 0;
    if (X[m-1] == Y[n-1]) // checks if the last letter are the same
        return 1 + lcs(X, Y, m-1, n-1); // sums when a coincidence is found
    else
        return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));  // iterates between the last letter of a vector and compare it between
                                                           // each letter of the other vector, and when there is a coincidence
                                                           // it sums 1 to a counter, then checks the maximum of coincidences in between 
                                                           // the two vectors

}
int main() {

    vector<string> Q = {"a", "b", "c", "d", "x", "y", "z"};
    vector<string> R = {"x", "y", "z", "a", "b", "c", "d"};
    int m = Q.size();
    int n = R.size();
    cout << "The length of the LCS is " << lcs(R, Q, m, n) << endl;
    return 0;
}