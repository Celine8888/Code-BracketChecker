#include <iostream>
#include <algorithm>
#include <fstream>

#include "DSList.h"
#include "DSStack.h"

using namespace std;

int bracketTesterList(char *argv)
{
    DSList<char> brackets;
    DSList<int> lineNums;
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
        // if open bracket push on stack
        for (int i = 0; i < line.size(); i++)
        {
            // if close bracket check if top of stack match
            if (line[i] == '{' || line[i] == '[' || line[i] == '(')
            {
                brackets.push_front(line[i]);
                lineNums.push_front(lineNum);
            }
            // if match then pop of top of stack
            if (line[i] == '}')
            {
                if (brackets.top() == '{')
                {
                    brackets.pop_front();
                    lineNums.pop_front();
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
                    brackets.pop_front();
                    lineNums.pop_front();
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
                    brackets.pop_front();
                    lineNums.pop_front();
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