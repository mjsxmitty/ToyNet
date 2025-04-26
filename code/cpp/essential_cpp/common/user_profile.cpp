
#include "user_profile.h"
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

ostream& operator<<(ostream &os, const UserProfile &rhs)
{
    os << "login: " << rhs.login_
        << "\ntimes logged: " << rhs.times_logged_
        << "\nguesses: " << rhs.guesses_
        << "\ncorrect guesses: " << rhs.correct_guesses_
        << "\nlevel: " << rhs.Level();

    return os;
}

map<string, UserProfile::ULevel> UserProfile::level_map_;
int UserProfile::id = 0;

void UserProfile::init_level_map()
{
    level_map_["Beginner"] = Beginner;
    level_map_["Intermediate"] = Intermediate;
    level_map_["Advance"] = Advance;
    level_map_["Guru"] = Guru;
}

UserProfile::UserProfile(const string login, ULevel level) :
                            login_(login), times_logged_(1),
                            guesses_(0), correct_guesses_(0), level_(level)
{
    char buffer[16] = {0};

    snprintf(buffer, 16, "%s-%d", login_.c_str(), id++);
    login_ = buffer;

    id++;
}

bool UserProfile::operator==(const UserProfile &rhs) const
{
    return ((login_ == rhs.login_) && (level_ == rhs.level_));
}
bool UserProfile::operator!=(const UserProfile &rhs) const
{
    return !(*this == rhs);
}

double UserProfile::guess_average() const
{
    return guesses_ ? (double) correct_guesses_ / guesses_ * 100 : 0.0;
}

void UserProfile::reset_login(const string &val)
{
    char buffer[16] = {0};

    // login_.substr(0, login_.find("-"));

    snprintf(buffer, 16, "%s-%d", val.c_str(), id++);
    login_ = buffer;
}

void UserProfile::reset_level(const std::string &val)
{
    if (level_map_.empty())
        init_level_map();

    map<string, ULevel>::iterator it;
    level_ = ((it = level_map_.find(val)) != level_map_.end()) ? it->second : Beginner;
}
