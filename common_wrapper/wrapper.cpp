#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

void assignment1Menu()
{
    int algorithm;
    string filename;

    cout << "\n===== Assignment 1 =====\n\n";

    // cout << "1. GEMM Simple\n";
    // cout << "2. GEMM Blocking\n";
    cout << "1. BFS\n";
    cout << "2. DFS\n";
    cout << "3. SSSP\n\n";

    cout << "Select Algorithm : ";
    cin >> algorithm;

    cout << "Input File : ";
    cin >> filename;

    string command =
        "~/CS509_CS1009_AI1001/bin/assignment1_driver "
        + to_string(algorithm)
        + " "
        + filename;

    system(command.c_str());
}

int main()
{
    int choice;

    while (true)
    {
        cout << "\n=====================================\n";
        cout << "       CS509 Common Wrapper\n";
        cout << "=====================================\n\n";

        cout << "1. Assignment 1\n";
        // cout << "2. Assignment 2\n";
        // cout << "3. Assignment 3\n";
        cout << "0. Exit\n\n";

        cout << "Choice : ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                assignment1Menu();
                break;

            /*case 2:
                cout << "Assignment 2 not available.\n";
                break;

            case 3:
                cout << "Assignment 3 not available.\n";
                break;*/

            case 0:
                return 0;

            default:
                cout << "Invalid choice.\n";
        }
    }
}
