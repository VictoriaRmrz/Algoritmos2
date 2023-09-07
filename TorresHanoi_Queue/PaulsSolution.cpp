#include <cstdlib>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;
void printQueue(queue<pair<char, char>>& q)
{
    while (!q.empty()) {
        pair<char, char> p = q.front();
        cout << "(" << p.first << ", " << p.second << ")\n";
        q.pop();
    }
}

void move(char c1, char c2, queue<pair<char, char>>& q)
{
    q.push({c1, c2});
}

void hanoi(int n, char A, char C, char B, queue<pair<char, char>>& q)
{
    if (n == 1) {
        move(A, C, q);
    }
    else {
        hanoi(n - 1, A, B, C, q);
        move(A, C, q);
        hanoi(n - 1, B, C, A, q);
    }
}

int main()
{
    queue<pair<char, char>> q;
    
    hanoi(2, 'A', 'C', 'B', q);
    
    printQueue(q);

    return EXIT_SUCCESS;
}