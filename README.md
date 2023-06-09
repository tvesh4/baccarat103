# Presenting ✨Baccarat_103✨

tvesh4 - Name: Kumar Tvesha Sanjay UID: 3036065551
uchralenkh - Name: Enkhbayar Uchral UID: 3035958579
KarmaYY22 - Name: Yang Yin UID: 3035919743
ethbtcc - Name: Chen Chi UID: 3035835650
dalight-luckyw - Name: Wang Yam Yuk UID: 3036066012

We are Group 103 of ENGG1340 and COMP2113! We hope you enjoy our text-based C++ project.

**Warning:**
Gambling addiction and financial and personal issues might result from playing games like Baccarat_103. Never wager more than you can afford to lose, and never try to make up for lost funds by placing additional bets. It's crucial to take breaks and avoid letting gambling interfere with your regular activities and obligations. Keep in mind that playing this game is purely for fun and not as a means of earning money. Consult a specialist or a support group if you need assistance overcoming a gambling addiction.

**Introduction:**

1. A conventional 52-card deck is used for the game, and two hands are dealt: the player's hand and the banker's hand. You can wager on a tie or either hand winning.

2. To have a hand that is closest to nine is the goal of the game. Aces are represent 1, tens and face cards are worth 0, while all other cards are worth their respective face values.

3. The player and banker both receive two cards at the start of each game. A "natural" is when either hand has a total of 8 or 9 and no further cards are dealt.

4. The player must draw another card if the total of their hands is less than 6. The player stands if their hand total is 6 or 7.

5. If the player stand (hand < 6), the banker will stand if their own hand is also less than 6, or else draw another card. If the player draw another card, the banker will draw another card based on a more complex rule. Briefly, the banker stands if their hand total is 7. If the player's third card is a 6 or 7, and the banker's hand total is 6, the banker draws another card. The detailed drawing rule can be seen at this website https://en.wikipedia.org/wiki/Baccarat

6. The hand with the closest sum to 9 is the one that wins. The player wins and is paid even money if their hand is closer to 9. The banker wins and receives even money less a commission if their hand is closer to 9 than any other hand.

7. The player wins and are rewarded 8 to 1 if you bet on a tie and both hands have the same total. This is an uncommon event, so it's not advised to use it as a regular betting strategy.

**Reward:**

If you place a bet and you win, 1-to-1 even money will be paid. You will receive two times of your initial bet.
For example, if you initially bet $100 and you win, you would receive your $100 bet back plus an additional $100, for a total of $200. Hence, the amount you would receive if you win is equal to your initial bet multiplied by 2.
If you place a bet on either player or banker, and the outcome is a tie, you will receive your money back.

**Detailed Compilation & Execution Instructions:**

1. After download and unzipping, open the terminal and move to the directory containing the files
2. Type "make Baccarat103" in the terminal to compile and produce an executable file "Baccarat103"
3. Type "./Baccarat103" to start playing the game
4. Follow the easy-to-understand instructions on the UI of the game i.e. Press 1 to start.

**Demonstration Video Link:**
https://youtu.be/4NVKsn5PDpk

**Features**
• Generation of random game sets or events

The code generates random card distribution for playing the game of Baccarat.
"random_device" from the standard library <random> is used to generate random numbers.
    
• Data structures for storing game status

The code contains various data structures such as array and vector to store the game status needed. 
For exmaple, an array called "game_status" is used to store various data determining the status of the game, including the player's initial money, current money, total money won/lost, the number of games won, and the winning rate.
    
• Dynamic memory management

The code contains many instances of using vector to store game data.
For example, a vector called "deck" is used to store randomly shuffled cards for gameplay.
Besides, memory is released after usage by ".clear" and swapping with an empty dummy vector.
For example, the memory of the vector "names" used for loading games in load_game.cpp is released afterwards.
    
• File input/output

The code provides file input/output operations for loading/saving game status to a file.
For example, data contained in the array "game_status" are written into game files for saving, then the data in the game files are read for loading.
    
• Program codes in multiple files

The code is organized into multiple files such as card.h, detect_invalid_input.h, new_game.h, load_game.h, and save_game.h.
    
• Proper indentation and naming styles
    Variable names are easy to understand.
    
• In-code documentation
    Comments are provided.

Other features include proper indentation and naming styles for variable names, in-code documentation through comments, and multiple functions to display messages, declare winners, check for wins, draw cards, and play the game.


*All libraries used are standard C/C++ libraries.







