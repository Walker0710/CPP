#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s)
{

    stack<char> std;

    for (int i = 0; i < s.size(); i++)
    {

        char yo = s[i];

        if (yo == '(' || yo == '{' || yo == '[')
        {
            std.push(yo);
        }

        else
        {
            if (!std.empty())
            {
                char top = std.top();

                if (s[i] == ')' && top == '(' || s[i] == '}' && top == '{' || s[i] == ']' && top == '[')
                {

                    std.pop();
                }

                else
                {

                    return false;
                }
            }

            else
            {
                return false;
            }
        }
    }

    if (std.empty())
    {

        return true;
    }

    else
    {

        return false;
    }
}