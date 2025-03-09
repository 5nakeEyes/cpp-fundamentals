#include "validation.hpp"
#include <algorithm>

bool isspecial(char character) {
    std::string specialCharacters = "!@#$%^&*-_+=";
    for (int i = 0; i < specialCharacters.size(); i++)
        if (character == specialCharacters[i])
            return true;
    return false;
}

std::string getErrorMessage(ErrorCode code) {
    std::string msg = "";
    switch (code) {
    case ErrorCode::Ok:
        msg = "Ok";
        break;
    case ErrorCode::PasswordNeedsAtLeastNineCharacters:
        msg = "Password needs to have at least nine characters";
        break;
    case ErrorCode::PasswordNeedsAtLeastOneNumber:
        msg = "Password needs to have at least one number";
        break;
    case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
        msg = "Password needs to have at least one special character";
        break;
    case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
        msg = "Password needs to have at least one uppercase letter";
        break;
    case ErrorCode::PasswordsDoNotMatch:
        msg = "Passwords do not match";
        break;
    default:
        msg = "Unknown error!";
    };
    return msg;
}

bool doPasswordsMatch(std::string passwordLeft, std::string passwordRight) {
    if (passwordLeft.length() == passwordRight.length()) {
        if (passwordLeft == "")
            return true;
        for (int i = 0; i < passwordLeft.length(); i++) {
            if (passwordLeft[i] != passwordRight[i])
                return false;
            else
                return true;
        }
    }
    return false;
}

ErrorCode checkPasswordRules(std::string password) {
    ErrorCode code = ErrorCode::Ok;
    if (password.length() < 9)
        code = ErrorCode::PasswordNeedsAtLeastNineCharacters;
    else if (std::none_of(password.begin(), password.end(), isdigit))
        code = ErrorCode::PasswordNeedsAtLeastOneNumber;
    else if (std::none_of(password.begin(), password.end(), isspecial))
        code = ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    else if (std::none_of(password.begin(), password.end(), isupper))
        code = ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    return code;
}

ErrorCode checkPassword(std::string password, std::string secondPassword) {
    ErrorCode resultCode = ErrorCode::PasswordsDoNotMatch;
    if (!doPasswordsMatch(password, secondPassword))
        resultCode = ErrorCode::PasswordsDoNotMatch;
    else
        resultCode = checkPasswordRules(password);
    return resultCode;
}