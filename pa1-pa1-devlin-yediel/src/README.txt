-... . .-- .- .-. . / --- ..-. / -.-- --- ..- .-. / .- ..- -.. .. --- / .. -. / .... .. --. .... ... -.-. --- .-. . -.-.--
Writer: Yediel J. Acosta
Implementations explanations:
I. Button mapping:
    A. StartUp:
       1. Now starting the game offers different modes selected by the
         colors of the buttons:
           a. GreenButton activates the original gamemode
           b. RedButton activates Record and Play
           c. BlueButton activates Multiplayer
           d. YellowButton enables Highscore settings
    B. BackButton:
       1. Will always appear and work outside of StartUp. When the button
          or the backspace key is pressed, it will return you to StartUp
           * In Record_and_Play/PlayingAnimation, it will move you to Idle
-... . .-- .- .-. . / --- ..-. / -.-- --- ..- .-. / .- ..- -.. .. --- / .. -. / .... .. --. .... ... -.-. --- .-. . -.-.--
II. Record and Play:
    A. Phases:
       1. Recording -> Allows you to save a sequence
       2. Idle -> Freeplay; allows for playing saved sequence or generate
          a new sequence
       3. PlayingAnimation -> Shows last saved sequence. Fails if no saved
          sequence
    B. Buttons:
       1. RecordButton -> When pressed, switches to Idle
       2. PlayButton -> When pressed, erases last sequence and switches to
          Recording
       3. CameraButton -> When pressed, switches to PlayingAnimation
-... . .-- .- .-. . / --- ..-. / -.-- --- ..- .-. / .- ..- -.. .. --- / .. -. / .... .. --. .... ... -.-. --- .-. . -.-.--
III. Multiplayer:
    A. Phases:
       1. playing_sequence -> Shows current player's sequence
       2. player_input -> Allows current player to insert sequence
       3. game_over -> Declares winner once a player fails
    B. Images:
       1. Turn_One/Turn_Two images will tell which player's turn it is
       2. P1Win/P2Win images will appear in game_over depending of winner

    C. Player 1 and Player 2 All-Time Highscores and Current Score:
       1.Shows player 1 and player 2 highscores, even if you xit out of the game mode.
       2.Only deletes the highscores if user closes the whole program.
       3.Shows player 1 and player 2 current scores while playing the multiplayer mode
         and resets the scores if the user exits the mode or one of the players loses.
-... . .-- .- .-. . / --- ..-. / -.-- --- ..- .-. / .- ..- -.. .. --- / .. -. / .... .. --. .... ... -.-. --- .-. . -.-.--
IV. Highscore:
    A. Implementations:
       1. Now you can play Traditional with a highscore enabled. Unless the
          program is closed, the highscore will stay saved
       2. Enables random different background music
    B. Counters:
       1. Score -> Shows current score
       2. Highscore -> Shows highest score obtained in Highscore mode
       3. These will be found at the top right of the window, besides BackButton
-... . .-- .- .-. . / --- ..-. / -.-- --- ..- .-. / .- ..- -.. .. --- / .. -. / .... .. --. .... ... -.-. --- .-. . -.-.--