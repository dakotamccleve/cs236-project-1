#include "Lexer.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"

Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    // TODO: need to clean up the memory in `automata` and `tokens`
}

void Lexer::CreateAutomata() {
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    // TODO: Add the other needed automata here
}

void Lexer::Run(std::string& input) {
    // TODO: convert this pseudo-code with the algorithm into actual C++ code
    int lineNumber = 1;

    while(!input.empty()) {
        int maxRead = 0;
        Automaton* maxAutomaton = automata[0];
        while(isspace(input.at(0))) {
            if (input.at(0) == '\n') {
                lineNumber++;
            }

            input.erase(0, 1);
            if (input.empty()) {
                //   Token* newToken = new Token(enumEOF, "", lineNumber); // TODO: make enum TokenType {list of token types} in Token.h for enumEOF
                tokens.push_back(newToken);
                return;
            }
        }
            for(auto & i : automata) {
                int inputRead = i->Start(input);
                if (inputRead > maxRead) {
                    maxRead = inputRead;
                    maxAutomaton = automata[i];
                }
            }

            if(maxRead > 0) {
                Token *newToken = maxAutomaton->CreateToken(input.substr(0, maxRead), lineNumber);
                lineNumber += maxAutomaton->NewLinesRead();
                tokens.push_back(newToken);
            }

            else {
                maxRead = 1;
                Token *newToken = maxAutomaton->CreateToken(input.substr(0,maxRead), lineNumber);
                tokens.push_back(newToken);
            }

            input.erase(0, maxRead);
        }

        if(input.empty()) {
            //   Token* newToken = new Token(enumEOF, "", lineNumber); // TODO: make enum TokenType {list of token types} in Token.h for enumEOF
            tokens.push_back(newToken);
            return;
        }

}
