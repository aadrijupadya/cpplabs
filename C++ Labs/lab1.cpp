// Aadrij Upadya
// August 22, 2023
// Program P1.9
// Attempt to print out a face using various symbols, similar to the one provided in the book.
#include <iostream>
using namespace std;
int main()
{
    cout << "/\\/\\/\\/\\/\\/\\/\\/\\" << endl; // using forward and back slashes to represent hair
    cout << "/\\/\\/\\/\\/\\/\\/\\/\\" << endl;
    cout << "(|   *     *   |)" << endl; // parentheses for ears, asterisks for eyes
    cout << " |   |         | " << endl; // the rectangle represents a tear falling down
    cout << " |      ^      | " << endl; // caret for a nose
    cout << " |   _______   | " << endl; // Using underscores and apostrophes to show a frowning/sad face, different from the book
    cout << " |  '       '  | " << endl;
    cout << " \\/\\/\\/\\/\\/\\/\\/\\/ " << endl; // Backslashes and forward slashes to resemble a beard
    cout << " --------------- " << endl;          // These symbols are used to indicate the end of the face and start of the torso

    return 0;
}