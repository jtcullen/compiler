#include "Token.h"

Token::Token(Type type, std::string::iterator begin, std::string::iterator end) : type(type), value(std::string(begin, end)) {}


Token::void ValidCheck(){
    if(type == INTEGER){
       if(std::stoi(value) > 2147483647){
            isValidInt = false;
       }else if(std::stoi(value) < -2147483647){
            isValidInt = false;
       }else{
            isValidInt = true;
       }
    
    }
}


Token::Type Token::getType(){
    return type;
}

std::string Token::getValue(){
    return value;
}

std::ostream& operator<<(std::ostream& os, const Token& tk){
    os << tk.type << " " << tk.value;

    return os;
}
