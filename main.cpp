//******************************
// Program Name : Simple Substitution Cipher.cpp
//Last Modification date : 3/3/2018
//Author : Amr Osama
//ID : 20170185
//Teaching Assistant : Eng/Ibrahim Zeidan
//Purpose : This program is assigned to exchanging each character in your plain text
//with new characters in cipher text.
//******************************




#include <iostream>
#include <iomanip>
#include <string>
//the first array to take a word from this characters and remove the used characters it from list
//the second array for your sentence that you want to cipher
//the third empty array is used to reserve your key word

using namespace std;
char alpha[30] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'};
char alphaN[30] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'};
char key[26];
int choices;
int main()
{
    cout<<"ahlan ya user ya habebyy"<<endl;
    //let user to input a word that he want to use as a key
    cout<<"enter a word"<<endl;
    string input;
    int temp;
    cin >> input;

    //make a for loop that count each character in your input word
    for (int i = 0; i < input.length(); i++)
    {
        //make a for loop see the total size of your list (it reserve a space of elements in memory) of alphabets
        // compared to the first element of your list(the size of only one element in memory) to calculate how
        // many elements in your array
        for (int j = 0; j < (sizeof(alpha)/sizeof(alpha[0])); j++)
        {
        //if you found letter in alpha is found in input word remove it from list
            if (alpha[j] == input[i])
                alpha[j] = ' ';
        }
        //put the input word in the key array
        key[i] = input[i];
        temp = i;
    }
    int counter1 = 0;
    for (int x = temp + 1 ; x < 26;x++)
    {
        //skip the spaces so it's not considered in the array
        if (alpha[counter1] == ' ')
        {
            counter1++;
            x--;
            continue;
        }
        key[x] = alpha[counter1];
        counter1++;
    }
    cout<<"choose a number from 1 , 2"<<endl;
    cin>>choices;
    if(choices==1){
        cout<<"cipher the message"<<endl;
        // begin to enter the string you want to cipher
        string your_sentence;
        int counter = 0;
        int length_of_sentence;

        cout<<"plain text: ";
        getline(cin , your_sentence);
        getline(cin , your_sentence);
        length_of_sentence = your_sentence.length();
        for (counter = 0 ;counter < length_of_sentence; ++counter )
        {
            //  check the string that contains all characters
            if (isalpha(your_sentence[counter]))
            {
                your_sentence[counter]=tolower(your_sentence[counter]);
                for (int index = 0; index < 26; index++)
                {
                    if (your_sentence[counter] == alphaN[index])
                    {
                        your_sentence[counter] = key[index];
                        break;
                    }
                }
            }
        }
        cout<<"cipher text: "<<your_sentence<<endl;
    }
    else
    {
        string your_sentence;
        int counter = 0;
        int length_of_sentence;
        cout<<"decipher the message"<<endl;
        cout<<"plain text: ";
        cin.ignore();
        getline(cin , your_sentence);
        length_of_sentence = your_sentence.length();
        for (counter = 0 ;counter < length_of_sentence; ++counter )
        {
            if (isalpha(your_sentence[counter]))
            {
                your_sentence[counter]=tolower(your_sentence[counter]);
                for (int index = 0; index < 26; index++)
                {
                    if (your_sentence[counter] == key[index])
                    {
                        your_sentence[counter] = alphaN[index];
                        break;
                    }
                }
            }
        }
        cout<<"decipher text: "<<your_sentence<<endl;
    }
}
