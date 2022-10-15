// Section 9
// Challenge
/*
    This challenge is about using a collection (list) of integers and allowing the user
    to select options from a menu to perform operations on the list.

    Your program should display a menu options to the user as follows:

    P - Print numbers
    A - Add a number
    M - Display mean of the numbers
    S - Display the smallest number
    L - Display the largest number
    Q - Quit

    Enter your choice:

The program should only accept valid choices from the user, both upper and lowercase selections should be allowed.
If an illegal choice is made, you should display, "Unknown selection, please try again" and the menu options should be
displayed again.


If the user enters 'P' or 'p', you should display all of the elements (ints) in the list.
If the list is empty you should display "[] - the list is empty"
If the list is not empty then all the list element should be displayed inside square brackets separated by a space.
For example, [ 1 2 3 4 5 ]

If the user enters 'A' or 'a' then you should prompt the user for an integer to add to the list
which you will add to the list and then display it was added. For example, if the user enters 5
You should display, "5 added".
Duplicate list entries are OK

If the user enters 'M' or 'm'  you should calculate the mean or average of the elements in the list and display it.
If the list is empty you should display, "Unable to calculate the mean - no data"

If the user enters 'S' or 's' you should display the smallest element in the list.
For example, if the list contains [2 4 5 1],  you should display, "The smallest number is 1"
If the list is empty you should display, "Unable to determine the smallest number - list is empty"

If the user enters 'L' or 'l' you should display the largest element in the list
For example, if the list contains [2 4 5 1], you should display, "The largest number is 5"
If the list is empty you should display, "Unable to determine the largest number - list is empty"

Additional functionality if you wish to extend this program.

- search for a number in the list and if found display the number of times it occurs in the list
- clearing out the list (make it empty again) (Hint: the vector class has a .clear() method)
- don't allow duplicate entries
- come up with your own ideas!

Good luck!

*/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;
int add_number();
bool check_number(string);
int main()
{
    char entered_letter{};
    vector <int> numbers_list{};
    vector <int> redo_undo{};

    while (entered_letter != 'q' && entered_letter != 'Q')
    {
        cout << "P - Print numbers" << endl;
        cout << "A - Add number to the list" << endl;
        cout << "M - Display mean of the number" << endl;
        cout << "S - Display smallest number in the list" << endl;
        cout << "L - Display largest number in the list" << endl;
        cout << "U - Undo last number input" << endl;
        cout << "R - Redo last number input" << endl;
        cout << "F - Search the number" << endl;
        cout << "C - Clear the list" << endl;
        cout << "Q - Quit the program" << endl;
        cout << "\nEnter your choice: ";

        cin >> entered_letter;

        switch (entered_letter)
        {
        case 'p':
        case 'P':
            system("cls");
            if (numbers_list.size() == 0)
            {
                cout << "\n[ ] - the list is empty!" << endl;
            }
            else
            {
                cout << "\nYour numbers list is: [ ";
                for (int number : numbers_list)
                {
                    cout << number << " ";
                }
                cout << "]" << endl;
            }

            break;

        case 'a':
        case 'A': // Adding number to list
            system("cls");
            {
                char y_n_char{};
                numbers_list.push_back(add_number());
                while (y_n_char != 'n' && y_n_char != 'N')
                {
                    cout << "Do you want to add another number? ( Y/N ): ";
                    cin >> y_n_char;
                    if (y_n_char == 'y')
                    {
                        numbers_list.push_back(add_number());
                    }
                }
                system("cls");
            }
            break;
        case 'm':
        case 'M':
            system("cls");
            if (numbers_list.size() == 0)
            {
                cout << "\nUnable to calculate the mean? no data!" << endl;
            }
            else
            {
                double numbers_sum{ 0 };
                double numbers_average{ 0.0 };
                for (size_t i = 0; i < numbers_list.size(); i++)
                {
                    numbers_sum += numbers_list.at(i);
                }
                numbers_average = numbers_sum / numbers_list.size();
                cout << "\nAverage of the list is: " << numbers_average << endl;
            }
            break;
        case 's':
        case 'S':
            system("cls");
            if (numbers_list.size() == 0)
            {
                cout << "\nUnable to determine the smallest number - list is empty!" << endl;
            }
            else
            {
                int min_number{ INT_MAX };
                for (int number : numbers_list)
                {
                    if (number < min_number)
                    {
                        min_number = number;
                    }
                }
                cout << "\nThe smallest number is: " << min_number << endl;
            }
            break;
        case 'l':
        case 'L':
            system("cls");
            if (numbers_list.size() == 0)
            {
                cout << "\nUnable to determine the largest number - list is empty!" << endl;
            }
            else
            {
                int max_number{ INT_MIN };
                for (int number : numbers_list)
                {
                    if (number > max_number)
                    {
                        max_number = number;
                    }
                }
                cout << "\nThe largest number is: " << max_number << endl;
            }
            break;
        case 'u':
        case 'U':
            system("cls");
            if (numbers_list.size() == 0)
            {
                cout << "\nYour list is empty! Nothing to undo!" << endl;
                break;
            }
            else
            {
                redo_undo.push_back(numbers_list.back());
                numbers_list.pop_back();
                cout << "Done! Last number was removed from the list" << endl;
            }
            break;
        case 'r':
        case 'R':
            system("cls");
            if (redo_undo.size() == 0)
            {
                cout << "\nNothing to redo!" << endl;
                break;
            }
            else
            {
                numbers_list.push_back(redo_undo.back());
                redo_undo.pop_back();
                cout << "Done! Last number was recovered in the list" << endl;
            }
            break;

        case 'f':
        case 'F':
            system("cls");
            {
                cout << "Please enter the number to search in the list: ";
                int number_to_search{ 0 };
                int number_count{ 0 };
                vector <int> number_index{};
                cin >> number_to_search;
                for (int i = 0; i < numbers_list.size(); ++i)
                {
                    if (numbers_list.at(i) == number_to_search)
                    {
                        number_index.push_back(i);
                        ++number_count;
                    }
                }
                cout << "\nThe searched number: " << number_to_search << " is " << number_count << " times in the list." << endl;
                cout << "Indexes of this number is: [ ";
                for (int number : number_index)
                {
                    cout << number << " ";
                }
                cout << "]" << endl;
            }
            break;

        case 'c':
        case 'C':
            system("cls");
            {
                char y_n_char{};
                while (y_n_char != 'n' && y_n_char != 'N')
                {
                    cout << "You realy want to clear data in the list? Y/N: ";
                    cin >> y_n_char;
                    if (y_n_char == 'y')
                    {
                        numbers_list.clear();
                        cout << "The list is cleared" << endl;
                        break;
                    }
                }
                system("cls");
            }
            break;

        case 'q':
        case 'Q':
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Unknown selection, please try again!" << endl;
            break;
        }
        cout << endl;
    }

    return 0;
}

int add_number()
{
    string added_number{};
    char char_yes{};
    cout << "\nFor add number press 'Y', for return to selection press any key: ";
    cin >> char_yes;

    while (char_yes == 'y' || char_yes == 'Y')
    {
        cout << "\nPlease enter an Integer number to add: ";
        cin >> added_number;
        while (!check_number(added_number))
        {
            cout << "Please, enter only Integer number: ";
            cin >> added_number;
        }
        cout << "\n" << added_number << " is added" << endl;
        return stoi(added_number);
        break;
    }

}

bool check_number(string str) {
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}

