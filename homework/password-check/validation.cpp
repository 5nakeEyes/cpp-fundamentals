#include "validation.hpp"
#include <cstdlib>
#include <ctime>


std::string getErrorMessage(ErrorCode code) {
    std::string msg = "";
    switch (code) {
    case ErrorCode::Ok: msg = "Ok\n";   
        break;
    case ErrorCode::PasswordNeedsAtLeastNineCharacters: msg = "Error: Password needs at least nine characters\n";
        break;
    case ErrorCode::PasswordNeedsAtLeastOneNumber: msg = "Error: Password needs at least one number\n";
        break;
    case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter: msg = "Error: Password needs at least one special character\n";
        break;
    case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter: msg = "Error: Password needs at least one uppercase letter\n";
        break;
    case ErrorCode::PasswordsDoNotMatch: msg = "Error: Passwords do not match\n";
        break;
    default: msg = "Unknown error!";
    };
    return msg;
}

bool doPasswordsMatch(std::string passwordLeft, std::string passwordRight) {
    if (passwordLeft == "" || passwordRight == "") return false;
    if (passwordLeft == passwordRight) return true;
    else return false;
}

ErrorCode checkPasswordRules(std::string password) {
    srand(time(0));
    int randomNumber = random() % 5;
    ErrorCode code = ErrorCode::Ok;

    switch (randomNumber) {
    case 1: code = ErrorCode::Ok;
        break;
    case 2: code = ErrorCode::PasswordNeedsAtLeastNineCharacters;
        break;
    case 3 : code = ErrorCode::PasswordNeedsAtLeastOneNumber;
        break;
    case 4 : code = ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
        break;
    case 5 : code = ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
        break;
    }
    return code;
}