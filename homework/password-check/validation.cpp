#include "validation.hpp"
#include <cstdlib>
#include <ctime>

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
    srand(time(0));
    int randomNumber = random() % 5;
    ErrorCode code = ErrorCode::Ok;

    switch (randomNumber) {
    case 1:
        code = ErrorCode::Ok;
        break;
    case 2:
        code = ErrorCode::PasswordNeedsAtLeastNineCharacters;
        break;
    case 3:
        code = ErrorCode::PasswordNeedsAtLeastOneNumber;
        break;
    case 4:
        code = ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
        break;
    case 5:
        code = ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
        break;
    }
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