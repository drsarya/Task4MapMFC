#pragma once
#include <string>
using namespace std;
enum class   LOG_ENUM :int
{
    RESOLVE = -1,
    OK = 1
};

inline string toString(LOG_ENUM v)
{
    switch (v)
    {
    case LOG_ENUM::RESOLVE:   return "RESOLVE";
    case LOG_ENUM::OK:   return "OK";
    }
}
