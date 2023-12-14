


#include <iostream>
#include <vector>
#include <algorithm>

#include "user_profile.h"

using namespace std;

int main()
{
    UserProfile up1;
    UserProfile up2;
    cout << (up1 == up2 ? "equal" : "not equal") << endl;
    cout << up1 << endl;
    cout << up2 << endl;

    UserProfile up("gao", UserProfile::ULevel(1));
    cout << up << endl;

    up.reset_login("test");
    up.reset_level("Guru");
    up.bump_guess_count(10);
    cout << up << endl;

    return 0;
}
