// Section 11
// Challenge 
/*
     Recall the challenge from Section 9 below.
    Your challenge for section 11 is to modularize your solution to the Section 9
    challenge by refactoring your solution so that it uses functions.

    You decide how to modularize the program.
    you can use my solution which is included in this file, or modularize your solution.

    Here are a few hints:
        - Create functions for each major function
        - Keep the functions small
        - Remember the Boss/Worker analogy
        - Keep the vector declaration in the main function and pass the vector object
          to any function that requires it

        DO NOT move the vector object outside main and make it a global variable.

        - You can start by defining a function that displays the menu
        - You can then define a function that reads the selection from the user and returns it in uppercase
        - Create functions for each menu option
        - Create functions that display the list of numbers, calculates the mean and so forth

    Take it one function at a time and take your time.
    If you get frustrated, take a break -- this isn't as easy as it looks the first time you do it!

    Finally,  don't forget to use function prototypes!

    Good luck -- I know you can do it!
*/
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

If the user enters 'Q' or 'q' then you should display 'Goodbye" and the program should terminate.

Before you begin. Write out the steps you need to take and decide in what order they should be done.
Think about what loops you should use as well as what you will use for your selection logic.

This exercise can be challenging! It may likely take a few attempts before you complete it -- that's OK!

Finally, be sure to test your program as you go and at the end.

Hint: Use a vector!

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
#include <cctype>

using namespace std;

void display_menu();
char input_menu_item_to_uppercase(char);
void print_vector(vector <int> numbers_list);
void add_number(vector <int>& numbers_list);
void mean_number(vector <int>& numbers_list);
void determine_smallest_num(vector <int>& numbers_list);
void determine_largest_num(vector <int>& numbers_list);
void undo(vector <int>& numbers_list, vector <int>& redo_undo_buffer_vector);
void redo(vector <int>& redo_undo_buffer_vector, vector <int>& numbers_list);
void search_num(vector <int>& numbers_list);
void clear_numbers_list(vector <int>& numbers_list);
bool check_number(string);

int main()
{
    char selected_menu_item{};
    vector <int> numbers_list{};
    vector <int> redo_undo_buffer_vector{};

    while (selected_menu_item != 'Q')
    {
        display_menu();

        selected_menu_item = input_menu_item_to_uppercase(selected_menu_item);

        switch (selected_menu_item)
        {
        case 'P': //Print vector
            system("cls");
            print_vector(numbers_list);
            break;

        case 'A': // Adding number to list
            add_number(numbers_list);
            break;

        case 'M': //Calculate mean of the vector numbers
            mean_number(numbers_list);
            break;

        case 'S': //Determine and print smallest number in the number_list vector
            determine_smallest_num(numbers_list);
            break;

        case 'L': //Determine and print largest number in the number_list vector
            determine_largest_num(numbers_list);
            break;

        case 'U': //Undo the input of the last number added to the numbers_list vector
            undo(numbers_list, redo_undo_buffer_vector);
            break;

        case 'R': //Redo the undo operation of the last number added to the numbers_list vector
            redo(redo_undo_buffer_vector, numbers_list);
            break;

        case 'F': //Search the number
            search_num(numbers_list);
            break;

        case 'C': //Delete numbers_list vector
            clear_numbers_list(numbers_list);
            break;

        case 'Q': //Quit program
            system ("cls");
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

//Display main menu list
void display_menu()
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
}

//Convert inputted char menu item to uppercase
char input_menu_item_to_uppercase(char input_menu_item)
{
    cin >> input_menu_item;
    return (char)toupper(input_menu_item);
}

//Print vector
void print_vector(vector <int> numbers_list)
{
    if (numbers_list.size() == 0)
    {
        cout << "\n[ ] - the list is empty!" << endl;
        cout << "----------" << endl;
    }
    else
    {
        cout << "\nYour numbers list is: [ ";
        for (int number : numbers_list)
        {
            cout << number << " ";
        }
        cout << "]" << endl;
        cout << "----------" << endl;
    }
}

//Add number to vector
void add_number(vector <int>& numbers_list)
{
    system("cls");
    cout << "Please, enter an integer for adding to the vector." << endl;
    cout << "For exit, enter char or non integer symbol and press ENTER" << endl;
    int input_number;
    while (cin >> input_number)
    {
        numbers_list.push_back(input_number);
        cout << input_number << " :was added to the vector" << endl;
    }  
    cin.clear();
    cin.ignore(1000, '\n');
    system("cls");
}

//Calculate mean of the vector numbers
void mean_number(vector<int>& numbers_list)
{
    system("cls");
    if (numbers_list.size() == 0)
    {
        cout << "\nUnable to calculate the mean, no data!" << endl;
        cout << "----------" << endl;
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
        cout << "----------" << endl;
    }
}

//Determine and print smallest number in the number_list vector
void determine_smallest_num(vector<int>& numbers_list)
{
    system("cls");
    if (numbers_list.size() == 0)
    {
        cout << "\nUnable to determine the smallest number - list is empty!" << endl;
        cout << "----------" << endl;
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
        cout << "----------" << endl;
    }
}

//Determine and print largest number in the number_list vector
void determine_largest_num(vector<int>& numbers_list)
{
    system("cls");
    if (numbers_list.size() == 0)
    {
        cout << "\nUnable to determine the largest number - list is empty!" << endl;
        cout << "----------" << endl;
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
        cout << "----------" << endl;
    }
}

//Undo the input of the last number added to the numbers_list vector
void undo(vector<int>& numbers_list, vector<int>& redo_undo_buffer_vector)
{
    system("cls");
    if (numbers_list.size() == 0)
    {
        cout << "\nYour list is empty! Nothing to undo!" << endl;
        cout << "----------" << endl;
    }
    else
    {
        redo_undo_buffer_vector.push_back(numbers_list.back());
        numbers_list.pop_back();
        cout << "Done! Last number was removed from the list" << endl;
        cout << "----------" << endl;
    }
}

//Redo the undo operation of the last number added to the numbers_list vector
void redo(vector<int>& redo_undo_buffer_vector, vector<int>& numbers_list)
{
    system("cls");
    if (redo_undo_buffer_vector.size() == 0)
    {
        cout << "\nNothing to redo!" << endl;
        cout << "----------" << endl;
    }
    else
    {
        numbers_list.push_back(redo_undo_buffer_vector.back());
        redo_undo_buffer_vector.pop_back();
        cout << "Done! Last number was recovered in the list" << endl;
        cout << "----------" << endl;
    }
}

//Search the number, indexes of the number and count quantity of the number
//in the numbers list
void search_num(vector<int>& numbers_list)
{
    system("cls");
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
    cout << "----------" << endl;
    
}

//Delete numbers_list vector
void clear_numbers_list(vector<int>& numbers_list)
{
    system("cls");
    char y_n_char{};
    while (y_n_char != 'n' && y_n_char != 'N')
    {
        if (numbers_list.size() == 0)
        {
            cout << "The list is empty, nothing to delete" << endl;
            cout << "----------" << endl;
        }
        else
        {
            cout << "You really want to clear data in the list? Y/N: ";
            cout << "\n----------" << endl;
            cin >> y_n_char;

            if (y_n_char == 'y')
            {
                system("cls");
                cout << "The list is cleared" << endl;
                cout << "----------" << endl;
                numbers_list.clear();
            }
        }
        break;
    }
}

//Check input numbers for int
bool check_number(string str) {
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}
