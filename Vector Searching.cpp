/* Samantha Casler
Last Modified 10/11/18 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Initializing the functions as well as the size of all three arrays.
int getStudent ();
int linearSearch (vector<int> , int, int);
int binarySearch (vector<int>, int, int);
void linearResults (vector<int>, vector<string>, vector<string>, int);
void binaryResults(vector<int>,vector<string>,vector<string>, int);
void originalArray(vector<int>,vector<string>,vector<string>, int);
const int SIZE = 12;

int main()
{
    //Initializing the arrays for the students id, name and email.
    vector<int> id {139, 152, 170, 193, 230, 251, 273, 294, 362, 385, 435, 481};

    vector<string> name {"Sydney Thompson", "Michael Anthony", "Courtney Zito",
"Adam March", "Nick McIlvoy", "Melony Beli", "Brisa Robinson",
"Carloine Hagan", "Matthew Messer", "Brittany Jolly", "Josh Sinclare", "Erick Garant"};

    vector<string> email {"st139@txstate.edu", "ma152@txstate.edu", "cz170@txstate.edu", "am193@txstate.edu", "nm230@txstate.edu", "mb251@txstate.edu", "br273@txstate.edu", "ch294@txstate.edu", "mm362@txstate.edu", "bj385@txstate.edu", "js435@txstate.edu", "eg481@txstate.edu"};

    int sequential; // to hold the position of the correct linear search result
    int binary;     // to hold the position of the correct binary search result
    int studentID;  // to hold the chosen students id number
    char repeat;    // to hold the choice of the user

    originalArray(id, name, email, SIZE); // calling the function originalArray

    do
    {

    studentID = getStudent();   // calling the function getStudent and storing the result in studentID

    sequential = linearSearch (id, SIZE, studentID);    // calling the function linearSearch and storing the result in sequential
    binary = binarySearch(id, SIZE, studentID);         // calling the function binarySearch and storing the result in binary

// testing the results of the searches to see if they exist
    if (sequential == -1 && binary == -1)
        cout << "\nThat student ID does not exist in the system. \n\n";
    else
    {
        linearResults(id, name, email, sequential); // calling the function linearResults
        cout << endl;
        binaryResults(id, name, email, binary);     //calling the function binaryResults
    }
    //Prompting the user for their choice on if to look up another student
    cout << "Do you want to look up another student? (y/n) ";
    cin >> repeat;
    cout << endl << endl;
    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}

// Function that gathers user data and returns the value to the main function
int getStudent ()
{
    int studentID;

    cout << "Enter the students ID number you wish to search for: ";
    cin >> studentID;

    return studentID;
}

// Function that searches the id array through the linear search method to see if the users data
// exists and returns the position to the main function
int linearSearch (vector<int> student, int size, int choice)
{
    int index = 0;
    int position = -1;
    bool found = false;

    while (index < size && !found)
    {
        if (student [index]== choice)
        {
            found = true;
            position = index;
        }
        index++;
    }
    return position;
}

// Function that searches the id array through the binary search method to see if the users data
// exists and returns the position to the main function
int binarySearch (vector<int> student, int size, int choice)
{
    int beginning = 0;
    int last = size -1;
    int center;
    int position = -1;
    bool found = false;

    while (!found && beginning <= last)
    {
        center = (beginning + last)/2;
        if (student[center] == choice)
        {
            found = true;
            position=center;
        }
        else if (student[center]>choice)
            last = center -1;
        else
            beginning = center +1;
    }
    return position;
}

// Function that displays all student data
void originalArray (vector<int> number, vector<string> student, vector<string> mail, int size)
{
    cout << "\t\t Student List: " << endl;

    for (int index =0; index < size; index++)
    {

    cout << "Student ID: " << number[index] << endl;
    cout << "Student Name: " << student[index] << endl;
    cout << "Student Email: " << mail[index] << endl<< endl;

    }

}

// Function that displays the results of the linear search to the user
void linearResults (vector<int> number, vector<string> student, vector<string> mail, int choice)
{
    cout << "\t\t Student Found(through sequential search): \n";
    cout << "Student ID: " << number[choice] << endl;
    cout << "Student Name: " << student[choice] << endl;
    cout << "Student Email: " << mail[choice] << endl;


}

// Function that displays the results of the binary search to the user
void binaryResults (vector<int> number, vector<string> student, vector<string> mail, int choice)
{
    cout << "\t\t Student Found(through binary search): \n";
    cout << "Student ID: " << number[choice] << endl;
    cout << "Student Name: " << student[choice] << endl;
    cout << "Student Email: " << mail[choice] << endl;


}
