
#ifndef __ESSENTIAL_CPP_USER_PROFILE_H__
#define __ESSENTIAL_CPP_USER_PROFILE_H__

#include <string>
#include <iostream>
#include <map>

class UserProfile
{
    friend std::ostream& operator<<(std::ostream &os, const UserProfile &rhs);
public:
    enum ULevel
    {
        Beginner = 0,
        Intermediate,
        Advance,
        Guru
    };
public:
    UserProfile(const std::string login = "guest", ULevel level = Beginner);
    ~UserProfile() {}
public:
    bool operator==(const UserProfile &rhs) const;
    bool operator!=(const UserProfile &rhs) const;

    inline std::string Level() const
    {
        static std::string level_table[] = {
            "Beginner", "Intermediate", "Advance", "Guru"
        };

        return level_table[level_];
    }

    std::string login() const { return login_; }
    int times_logged() const { return times_logged_; }
    int guesses() const { return guesses_; }
    int correct_guesses() const { return correct_guesses_; }
    double guess_average() const;

    void reset_login(const std::string &val);
    void reset_login_count(int val) { times_logged_ = val; }
    void reset_guess_count(int val) { guesses_ = val; }
    void reset_guess_correct(int val) { correct_guesses_ = val; }
    void reset_level(ULevel level) {level_ = level; }
    void reset_level(const std::string &val);

    void bump_login_count(int val) { times_logged_ += val; }
    void bump_guess_count(int val) { guesses_ += val; }
    void bump_guess_correct(int val) { correct_guesses_ += val; }
private:
    static void init_level_map();
private:
    std::string login_;
    int         times_logged_;
    int         guesses_;
    int         correct_guesses_;
    ULevel      level_;

    static int id;
    static std::map<std::string, ULevel> level_map_;
};

std::ostream& operator<<(std::ostream &os, const UserProfile &rhs);

#endif //__ESSENTIAL_CPP_USER_PROFILE_H__
