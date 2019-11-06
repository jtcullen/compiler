/*!re2c re2c:flags:i = 1; */

#include <iostream>
#include "Lexer.h"

/*!re2c
// Commonly used expressions
letter = [a-zA-Z];
digit  = [0-9];
*/

Lexer::Lexer(std::string &input) : input(input), cursor(input.begin()), limit(input.end()) {}

Lexer::Token Lexer::nextToken() {
    std::string::iterator marker;
loop:
    /*!re2c
    re2c:define:YYCURSOR = cursor;
    re2c:define:YYLIMIT = limit;
    re2c:define:YYMARKER = marker;
    re2c:define:YYCTYPE = "unsigned char";
    re2c:yyfill:enable = 0;
    re2c:eof = 0;

    // EOF
    $ { return Lexer::Token::END_OF_FILE; }

    // Default matcher
    * { return Lexer::Token::UNKNOWN; }
    
    // Types
    "INTEGER" { return Lexer::Token::INTEGER; }

    // Keywords
    "PRINT" { return Lexer::Token::PRINT; }
    "BEGIN" { return Lexer::Token::BEGIN; }
    "END" { return Lexer::Token::END; }
    "RETURN" { return Lexer::Token::RETURN; }

    // Special Characters
    "(" { return Lexer::Token::L_PAREN; }
    ")" { return Lexer::Token::R_PAREN; }
    ";" { return Lexer::Token::SEMICOLON; }

    // Constants
    digit+ { return Lexer::Token::INTEGER_LITERAL; }
    '"'('\\'. | [^"\\])*'"' { return Lexer::Token::STRING_LITERAL; }

    // User Defined Identifier
    ("_" | letter)("_" | letter | digit)* { return Lexer::Token::IDENTIFIER; }

    // Ignore whitespace
    [ \f\n\r\t\v] { goto loop; }
    */
}