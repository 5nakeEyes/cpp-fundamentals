#pragma once
#include <string>

std::string calculate(const std::string& command, int first, int second) {
    
    switch(command) {
  	case "add":
    	    return std::to_string(first + second);
    	    break;
  	case "subtract":
    	    return std::to_string(first - second);
    	    break;
  	case "multiply":
	    return std::to_string(first * second);
	    break;
 	case "divide":
	    if(second == 0)
            	return "Division by 0";
	    else
            	return std::to_string(first / second);    
  	default:
    		return "Invalid data";
    }
	return "Invalid data";
}
