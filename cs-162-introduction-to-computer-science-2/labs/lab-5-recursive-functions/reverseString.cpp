/****************************************************
This is the definition file for my reverseString 
function. A string is passed in and it is outputted
to the user screen in reverse.
***************************************************/

#include "reverseString.h"

void reverseString(string s)
{
   if(s.size() == 1)
    {
       cout << s << endl;;
    }
    else
    {
       cout << s[s.size() - 1];
       reverseString(s.substr(0, s.size() - 1));
    }
}
