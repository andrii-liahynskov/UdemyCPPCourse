#include <iostream>
#include <vector>

using namespace std;


int main()
{
    vector <int> vector1;
    vector <int> vector2;

    vector1.push_back(10);
    vector1.push_back(20);

    cout << "\nVector1 elements are: " << endl;
    cout << vector1.at(0) << endl;
    cout << vector1.at(1) << endl;
    cout << "\nVector1 size is: " << vector1.size() << " elements" << endl;

    vector2.push_back(100);
    vector2.push_back(200);

    cout << "\nVector2 elements are: " << endl;
    cout << vector2.at(0) << endl;
    cout << vector2.at(1) << endl;
    cout << "\nVector2 size is: " << vector2.size() << " elements" << endl;

    vector <vector <int>> vector_2d;

    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);

    cout << "\nvector_2d elements are: " << endl;
    cout << vector_2d.at(0).at(0) << "  :: ";
    cout << vector_2d.at(0).at(1) << endl;
    cout << vector_2d.at(1).at(0) << " :: ";
    cout << vector_2d.at(1).at(1) << endl;

    vector1.at(0) = 1000;

    cout << "\nvector_2d updated elements are: " << endl;
    cout << vector_2d.at(0).at(0) << "  :: ";
    cout << vector_2d.at(0).at(1) << endl;
    cout << vector_2d.at(1).at(0) << " :: ";
    cout << vector_2d.at(1).at(1) << endl;

    cout << "\nVector1 updated elements are: " << endl;
    cout << vector1.at(0) << endl;
    cout << vector1.at(1) << endl;

    return 0;
}
