#include <algorithm>
#include <cctype>
#include <gtest/gtest.h>
#include <iterator>
#include <string>
#include <vector>

bool is_all_upper(const std::string &name) {
    bool status{true};
    for (char ch : name) {
        if (islower(ch)) {
            status = false;
            break;
        }
    }
    return status;
}

void split(std::string name, std::vector<std::string> &names_upper, std::vector<std::string> &names_lower) {
    std::string delimiter{", "};
    std::size_t pos{0};
    std::string token;
    while ((pos = name.find(delimiter)) != std::string::npos) {
        token = name.substr(0, pos);
        is_all_upper(token) ? names_upper.push_back(token) : names_lower.push_back(token);
        name.erase(0, pos + delimiter.length());
    }
    is_all_upper(name) ? names_upper.push_back(name) : names_lower.push_back(name);
}

std::string greet(std::vector<std::string> &names) {
    std::string greeting = "Hello";
    for (auto s : names) {
        greeting += ", " + s;
    }
    greeting += ".";
    if (names.size() > 1) {
        size_t pos = greeting.find_last_of(",");
        greeting.replace(pos, 1UL, " and");
    }
    return greeting;
}

std::string greet_toupper(std::string greeting) {
    std::transform(std::begin(greeting), std::end(greeting), std::begin(greeting), ::toupper);
    size_t pos = greeting.find(".");
    greeting.replace(pos, 1UL, "!");
    return greeting;
}

const std::string &greet(const std::string &name) {
    static std::string fullGreeting;
    std::vector<std::string> names_upper;
    std::vector<std::string> names_lower;
    if (name.length() == 0) names_lower.push_back("my friend");
    else split(name, names_upper, names_lower);

    if (names_lower.size() > 0) {
        fullGreeting = greet(names_lower);

        if (names_upper.size() > 0) {
            fullGreeting += " AND ";
            auto upper = greet_toupper(greet(names_upper));
            size_t pos = upper.find(",");
            upper.erase(pos, 1);
            fullGreeting += upper;
        }
    } else if (names_upper.size() > 0) {
        fullGreeting = greet_toupper(greet(names_upper));
    }

    return fullGreeting;
}

TEST(greetSuite, Empty) {
    EXPECT_EQ("Hello, my friend.", greet(""));
}

TEST(greetSuite, UpperCase) {
    EXPECT_EQ("HELLO, BOB!", greet("BOB"));
}

TEST(greetSuite, OneName) {
    EXPECT_EQ("Hello, Bob.", greet("Bob"));
}

TEST(greetSuite, TwoNames) {
    EXPECT_EQ("Hello, Adam and Bob.", greet("Adam, Bob"));
}

TEST(greetSuite, MoreNames) {
    EXPECT_EQ("Hello, Adam, Bob and Charlie.", greet("Adam, Bob, Charlie"));
    EXPECT_EQ("Hello, Adam, Bob, Charlie and Dan.", greet("Adam, Bob, Charlie, Dan"));
}

TEST(greetSuite, MixedNamed) {
    EXPECT_EQ("Hello, Adam and Charlie. AND HELLO BOB!", greet("Adam, BOB, Charlie"));
}
