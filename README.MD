# Pharse guessing network

A small C++ program that tries to guess the target pharse(which is given by user) using basic and small neural network.
At first the program doesnt know anything it expect the length and "learns" and adjusts its value,until it is equal to 
the pharse.Build as a project to learn weight,bias and training loops.I listed with comments why i made used the code.

## Requirements

- A C++17 compiler (g++, clang++, or MSVC)

## What I learned

1. I learned to use weight,bias and training loops
2. Learned to use loops,indexes,vector together
3. learned to get whole pharse from cin


## How it works

1. It asks the user for the pharse and the computer at first doesnt know anything so it produces an gibberish code
2. Each letter of the pharse has a neuron which 
3. Then it evulates the error for the letter of the pharses and adjusts it using the error to adjust a little over and over again until the letter is correct
4. when all letters is correct it stops and prints it at last

## Demo video
<video src="https://github.com/samarraichamling100-beep/Pharse-Guessing-Network/raw/main/src/Neural-network-demo.mp4" controls width="600"></video>
