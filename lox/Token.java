package com.craftinginterpreters.lox;

class Token {
  // Declare constants to be used in this class
  final TokenType type;
  final String lexeme;
  final Object literal;
  final int line;

  // Declare a constructor for this class to be called with `new`
  Token(TokenType type, String lexeme, Object literal, int line) {
    this.type = type;
    this.lexeme = lexeme;
    this.literal = literal;
    this.line = line;
  }

  // Override the `String#toString` method to
  // customize how we display the Token
  public String toString() {
    return type + " " + lexeme + " " + literal;
  }
}
