#include "validation.hpp"

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
