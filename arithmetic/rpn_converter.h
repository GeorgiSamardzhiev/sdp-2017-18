#ifndef _RPN_CONVERTER
#define _RPN_CONVERTER
#include <iostream>
#include "lstack.cpp"

template <typename StreamType = std::ostream>
class RPNConverter {
private:
  using OpStack     = LinkedStack<char>;

  OpStack opstack;
  StreamType& rpns;

  int priority(char op) {
    switch (op) {
    case '+':
    case '-':return 1;
    case '*':
    case '/':return 2;
    case '^':return 3;
    }
    return 0;
  }

  void consumeChar(char c);

  friend RPNConverter& operator<<(RPNConverter& rpnc, char c) {
    rpnc.consumeChar(c);
    return rpnc;
  }

public:
  RPNConverter(StreamType& _rpns = std::cout) : rpns(_rpns) { }

  void flush();

};

#endif
