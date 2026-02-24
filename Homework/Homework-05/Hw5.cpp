#include <iostream>
using namespace std;

int main() 
{
    char message[100];
//get the message from the user
    cout << "Enter a message: ";
    cin.getline(message, 100);
//set varible to count to 0
    int vowelCount = 0;
//find the number of vowels in the message
    for (int i = 0; message[i] != '\0'; i++) 
    {
        if (message[i] == 'a' || message[i] == 'e'
            || message[i] == 'i' || message[i] == 'o' || message[i] == 'u' || message[i] == 'A' || message[i] == 'E'
            || message[i] == 'I' || message[i] == 'O' || message[i] == 'U') 
        {
            vowelCount++;
        }
    }
//output the number
cout << "Number of vowels in the message: " << vowelCount << endl;

    return 0;

}