#include <bits/stdc++.h>
using namespace std;
 
int main() {
	string str;
    cin >> str;
    
    int index = 0;
    int max = 0, count = 0;
    
    while (str[index] != '\0')
    {
        count = 1;
 
        if (index != 0)
        {
            while (str[index] != '\0' && str[index - 1] == str[index])
            {
                count++;
                index++;
            }
        }
        if (count > max)
        {
            max = count;
        }
        index++;
    }
    
    cout << max;
    return 0;
}