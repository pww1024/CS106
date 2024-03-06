#include<iostream>
#include<string>
#include<sstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int string2Integer(const string& s)
{
    int result;


    return result;
}

int getInteger(const string &prompt)
{
    int result;

    return result;
}

void badWelcomeProgram()
{
    string name,response,second_name;
    int age;

    cout << "What is your name? ";
    cin >> name;

    cout << "How old are you? ";
    cin >> age;
    cout << "Hello " << name << ". You are " << age << " years old." << endl;

    cout << "Do you want to try again? ";
    cin >> response;

    cout << "you said " << response << endl;
}

void weirdExample()
{
    std::istringstream iss("166.9\n 24");
    double value;
    string line;

    iss >> value; // value = 166.9
    // iss.ignore(); // ignore one character
    std::getline(iss,line); // line = ""
    cout << "first line = " << line << endl;
    std::getline(iss,line); // line = "24"
    cout << "second line = " << line << endl;

    return;
}

string chopBothEnds(const string& s) //buggy fuction
{
    // if s is empty string,wrong
    string result = "";

    for(int i = 1; i < s.size()-1; i++)
        result += s[i];

    return result;
}

int main()
{
    // badWelcomeProgram();
    weirdExample();

    return 0;
}