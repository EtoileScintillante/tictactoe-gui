# Tic Tac Toe against AI

Play a game of Tic Tac Toe against an AI!

## Example
<img src="https://github.com/EtoileScintillante/tictactoe-gui/blob/master/docs/example.gif" width="400" height="400" alt="example gif" />

## Configure and build
#### Single-configuration generator (typically the case on Linux and macOS)
   ```
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```
#### Multi-configuration generator (typically the case on Windows)
  ```
cmake -S . -B build
cmake --build build --config Release
```
## Run
  ```
  cd build && ./TicTacToe
```
## About
One of my first c++ projects was a Tic Tac Toe game that could be played from the terminal. And although it was fun to play, I really wanted to create a GUI to make it feel more like a real game. So that was the motivation for this project. In fact, this was my first time ever creating a GUI application in c++ and also my first time using the [SFML](https://github.com/SFML/SFML) library.  

There are certainly a lot of better, more simpler ways to make a Tic Tac Toe game and my code may not be the most ideal, but the game works and I had fun creating it, leanring all kinds of new stuff along the way.

One more thing: I couldn't have made this project possible without [this](https://github.com/eXpl0it3r/cmake-sfml-project) amazing template.
