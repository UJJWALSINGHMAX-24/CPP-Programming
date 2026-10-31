#include <iostream>
#include <vector>
#include <string>

using namespace std;

void showHistory(const vector<string> &history)
{
    cout << "\n--- CALCULATION HISTORY ---" << endl;
    if (history.empty())
    {
        cout << "No History Available Yet." << endl;
    }
    else
    {
        for (size_t i = 0; i < history.size(); i++)
        {
            cout << i + 1 << ". " << history[i] << endl;
        }
    }
    cout << "---------------------------" << endl;
}

int main()
{
    vector<string> calcHistory;
    bool keepRunning = true;

    cout << "--- SMART CALCULATOR ( With History & Clear Memory )---" << endl;

    while (keepRunning)
    {
        char choice;
        cout << "\nChoose option ( +, -, *, / ) | View History 'h' | Clear Memory 'c' | Exit 'q': ";
        cin >> choice;

        if (choice == 'q' || choice == 'Q')
        {
            cout << "Exiting calculator... \nThank you!" << endl;
            keepRunning = false;
        }
        else if (choice == 'h' || choice == 'H')
        {
            showHistory(calcHistory);
        }
        else if (choice == 'c' || choice == 'C')
        {
            calcHistory.clear();
            cout << "History / Memory Cleared Successfully!" << endl;
        }
        else if (choice == '+' || choice == '-' || choice == '*' || choice == '/')
        {
            double a, b;
            cout << "Enter first number: ";
            cin >> a;
            cout << "Enter second number: ";
            cin >> b;

            double result = 0;
            bool success = true;
            string record = "";

            if (choice == '+')
            {
                result = a + b;
                record = to_string(a) + " + " + to_string(b) + " = " + to_string(result);
            }
            else if (choice == '-')
            {
                result = a - b;
                record = to_string(a) + " - " + to_string(b) + " = " + to_string(result);
            }
            else if (choice == '*')
            {
                result = a * b;
                record = to_string(a) + " * " + to_string(b) + " = " + to_string(result);
            }
            else if (choice == '/')
            {
                if (b != 0)
                {
                    result = a / b;
                    record = to_string(a) + " / " + to_string(b) + " = " + to_string(result);
                }
                else
                {
                    cout << "Error: Division by zero is not allowed!" << endl;
                    success = false;
                }
            }

            if (success)
            {
                cout << "\nResult : " << result << endl;
                calcHistory.push_back(record);
            }
        }
        else
        {
            cout << "Invalid choice! Please select a valid option." << endl;
        }
    }

    cout << "Press any key to exit...";
    cin.ignore();
    cin.get();

    return 0;
}