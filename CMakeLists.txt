cmake_minimum_required(VERSION 3.16.3)
project(cs236-project-1)

set(CMAKE_CXX_STANDARD 14)

add_executable(project_1_main main.cpp ColonAutomaton.cpp ColonAutomaton.h ColonDashAutomaton.cpp ColonDashAutomaton.h Lexer.cpp Lexer.h Token.cpp Token.h MatcherAutomaton.cpp MatcherAutomaton.h IDAutomaton.cpp IDAutomaton.h StringAutomaton.cpp StringAutomaton.h CommentAutomaton.cpp CommentAutomaton.h)