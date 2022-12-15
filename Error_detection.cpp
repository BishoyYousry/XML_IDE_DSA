#include"Error detection.h"

bool error_detection()
{
    string x;
    ifstream input("validated.txt");
    stack<string> st;
    int i = 0;

    while (getline(input, x)) {

        for (i = 0; i < x.length(); i++)
        {
            if (x[i] == '<' && x[i + 1] == '/')
            {
                string poped_str;
                i += 2;
                while (x[i] != '>')
                {
                    poped_str.push_back('x[i]');
                    i++;
                }

                if ((poped_str.compare(st.top())) == 0)
                    st.pop();
                else
                {
                    cout << "0.0";
                    return false;
                }
            }

            else if (x[i] == '<' && x[i + 1] != '/')
            {
                string pushed_str;
                i++;
                while (x[i] != '>')
                {
                    pushed_str.push_back('x[i]');
                    i++;
                }
                st.push(pushed_str);
            }
        }
    }
    input.close();
        
        if (st.empty())
        {
            cout << "1";
            return true;
        }
        else
        {
            cout << "0";
            return false;
        }
}