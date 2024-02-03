cmake_minimum_required(VERSION 3.22)
project(Tic_Tac_Toe C)

set(CMAKE_C_STANDARD 11)

add_executable(Tic_Tac_Toe main.c
        gameBoard.h
        gamePlay.h
)
