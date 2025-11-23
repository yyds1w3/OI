#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;

    // First pass: count all "VK" pairs and mark them
    for (int i = 0; i < n - 1; ++i)
    {
        if (s[i] == 'V' && s[i + 1] == 'K')
        {
            ans++;
            s[i] = 'X'; // Mark as used
            s[i + 1] = 'X';
            i++; // Skip next character since it's already used
        }
    }

    // Second pass: look for one additional pair that can be created
    for (int i = 0; i < n - 1; ++i)
    {
        if (s[i] != 'X' && s[i + 1] != 'X')
        {
            if ((s[i] == 'V' && s[i + 1] == 'V') ||
                (s[i] == 'K' && s[i + 1] == 'K'))
            {
                ans++;
                break;
            }
        }
    }

    cout << ans << endl;
    return 0;
}