# Tic Tac Toe against AI

Play a game of Tic Tac Toe against an AI!

## Example
<img src="https://github.com/EtoileScintillante/tictactoe-gui/blob/master/docs/runner.gif" width="400" height="400" alt="example gif" />

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
One of my first c++ projects was a Tic Tac Toe game that could be played from the terminal. And although it was fun to play, I really wanted to create a GUI to make it feel more like a real game. So that was the motivation for this project. And I couldn't have done it without [this](https://github.com/eXpl0it3r/cmake-sfml-project) amazing [SFML](https://github.com/SFML/SFML) project template, it helped me a lot.   
