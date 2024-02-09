#include <iostream>
#include <algorithm>
#include <fstream>

#include "DSList.h"
#include "DSStack.h"

using namespace std;

int bracketTesterArray(char *argv)
{
    DSStack<char> brackets;
    DSStack<int> lineNums;
    int lineNum = 1;
    ifstream file_input(argv);

    // line buffer
    string line;

    // catch not open file
    if (!file_input.is_open())
    {
        cout << "Unable not open file!" << endl;
        return (-1);
    }

    // keep reading
    while (getline(file_input, line))
    {
        for (int i = 0; i < line.size(); i++)
        {
            // if open bracket push on stack
            if (line[i] == '{' || line[i] == '[' || line[i] == '(')
            {
                brackets.push_back(line[i]);
                lineNums.push_back(lineNum);
            }
            // if close bracket check if top of stack match
            if (line[i] == '}')
            {
                // if match then pop of top of stack
                if (brackets.top() == '{')
                {
                    brackets.pop_back();
                    lineNums.pop_back();
                }
                // if not print out error and terminate algorithm
                else
                {
                    cout << "\n<" << argv << ">: Bracket mismatch detected\n";
                    cout << "Bracket type '" << brackets.top() << "' on line " << lineNums.top() << " is not closed properly\n";
                    cout << "Please add the corresponding bracket type to close\n";
                    return -1;
                }
            }
            // different types of brackets
            if (line[i] == ']')
            {
                if (brackets.top() == '[')
                {
                    brackets.pop_back();
                    lineNums.pop_back();
                }
                else
                {
                    cout << "\n<" << argv << ">: Bracket mismatch detected\n";
                    cout << "Bracket type '" << brackets.top() << "' on line " << lineNums.top() << " is not closed properly\n";
                    cout << "Please add the corresponding bracket type to close\n";
                    return -1;
                }
            }
            // different types of brackets
            if (line[i] == ')')
            {
                if (brackets.top() == '(')
                {
                    brackets.pop_back();
                    lineNums.pop_back();
                }
                else
                {
                    cout << "\n<" << argv << ">: Bracket mismatch detected\n";
                    cout << "Bracket type '" << brackets.top() << "' on line " << lineNums.top() << " is not closed properly\n";
                    cout << "Please add the corresponding bracket type to close\n";
                    return -1;
                }
            }
        }
        // keep count of which line we are on to document open bracket location
        lineNum++;
    }
    // if in the end stack is clear then brackets are all matched
    if (brackets.empty() == true)
    {
        cout << "<" << argv << ">: OK";
    }
    cout << endl;

    file_input.close();

    return 0;
}