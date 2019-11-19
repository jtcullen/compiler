/*!re2c re2c:flags:i = 1; */

#include <iostream>
#include "Lexer.h"

/*!re2c
// Commonly used expressions
letter = [a-zA-Z];
digit  = [0-9];
*/

Lexer::Lexer(std::string &input) : input(input), cursor(input.begin()), limit(input.end()) {}

Token Lexer::nextToken()
{
    std::string::iterator marker;
loop:
    std::string::iterator start = cursor;
    /*!re2c
    re2c:define:YYCURSOR = cursor;
    re2c:define:YYLIMIT = limit;
    re2c:define:YYMARKER = marker;
    re2c:define:YYCTYPE = "unsigned char";
    re2c:yyfill:enable = 0;
    re2c:eof = 0;

    // EOF
    $ { return Token(Token::Type::END_OF_FILE, start, cursor); }

    // Default matcher
    * { return Token(Token::Type::UNKNOWN, start, cursor); }
    
    // Types
    "INTEGER" { return Token(Token::Type::INTEGER, start, cursor); }

    // Keywords
    "PRINT" { return Token(Token::Type::PRINT, start, cursor); }
    "BEGIN" { return Token(Token::Type::BEGIN, start, cursor); }
    "END" { return Token(Token::Type::END, start, cursor); }
    "RETURN" { return Token(Token::Type::RETURN, start, cursor); }
    "IF" { return Token(Token::Type::IF, start, cursor); }
    "ELSE" { return Token(Token::Type::ELSE, start, cursor); }
    "FOR" { return Token(Token::Type::FOR, start, cursor); }
    "WHILE" { return Token(Token::Type::WHILE, start, cursor); }
    "DO" { return Token(Token::Type::DO, start, cursor); }
    "BREAK" { return Token(Token::Type::BREAK, start, cursor); }
    "CONTINUE" { return Token(Token::Type::CONTINUE, start, cursor); }

    // Special Characters
    "(" { return Token(Token::Type::L_PAREN, start, cursor); }
    ")" { return Token(Token::Type::R_PAREN, start, cursor); }
    ":" { return Token(Token::Type::COLON, start, cursor); }
    "?" { return Token(Token::Type::Q_MARK, start, cursor); }
    ";" { return Token(Token::Type::SEMICOLON, start, cursor); }

    // Operators
    "~" { return Token(Token::Type::SQUIGLY, start, cursor); }
    "!" { return Token(Token::Type::EXCLAMATION, start, cursor); }
    "+" { return Token(Token::Type::PLUS, start, cursor); }
    "-" { return Token(Token::Type::MINUS, start, cursor); }
    "*" { return Token(Token::Type::STAR, start, cursor); }
    "/" { return Token(Token::Type::SLASH, start, cursor); }
    "&&" { return Token(Token::Type::LOGICAL_AND, start, cursor); }
    "||" { return Token(Token::Type::LOGICAL_OR, start, cursor); }
    "==" { return Token(Token::Type::EQUAL, start, cursor); }
    "!=" { return Token(Token::Type::NOT_EQUAL, start, cursor); }
    "<" { return Token(Token::Type::LESS_THAN, start, cursor); }
    "<=" { return Token(Token::Type::LESS_THAN_EQUAL, start, cursor); }
    ">" { return Token(Token::Type::GREATER_THAN, start, cursor); }
    ">=" { return Token(Token::Type::GREATER_THAN_EQUAL, start, cursor); }
    "=" { return Token(Token::Type::ASSIGNMENT, start, cursor); }

    // Constants
    digit+ { return Token(Token::Type::INTEGER_LITERAL, start, cursor); }
    '"'('\\'. | [^"\\])*'"' { return Token(Token::Type::STRING_LITERAL, start, cursor); }

    // User Defined Identifier
    ("_" | letter)("_" | letter | digit)* { return Token(Token::Type::IDENTIFIER, start, cursor); }

    // Ignore whitespace
    [ \f\n\r\t\v] { goto loop; }
    */
}
