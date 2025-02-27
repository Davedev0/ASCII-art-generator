#include <iostream>
#include <string>
#include <cstdlib> // For system("clear") or system("cls")
#include <thread>  // For sleep (loading simulation)
#include <chrono>  // For sleep duration
// Function to clear the screen (cross-platform)
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Function to simulate loading
void displayLoadingScreen() {
    clearScreen();
    std::cout << "Loading Please Wait";
    for (int i = 0; i < 4; i++) {
        std::cout << " ." << std::flush; // Add a dot with a space
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate loading delay
    }
    std::cout << "\n"; // Move to the next line after loading is complete
}
;
// Function to display the home screen
void displayHomeScreen() {
    clearScreen();
    std::cout << R"(
=========================================

      𝕎𝔼𝕃ℂ𝕆𝕄𝔼 𝕋𝕆 𝔼𝕄𝕆𝕁𝕀 𝔸𝕊ℂ𝕀𝕀 𝔸ℝ𝕋
      
=========================================
Press [S] to Start   
Press [A] to About 
Press [C] to Creators 
Press [Q] to Quit
=========================================
)";
}

// Function to display the about screen
void displayAboutScreen() {
    clearScreen();
    std::cout << R"(
=========================================

          𝔸𝔹𝕆𝕌𝕋 𝔼𝕄𝕆𝕁𝕀 𝔸𝕊ℂ𝕀𝕀 𝔸ℝ𝕋         
          
=========================================
This is a project program created for 
CC102. It is a simple console-based
application that generates ASCII art 
emojis based on user input.

The program allows users to:
- View different emoji reactions.
- Learn about the creators.
- Navigate through a user-friendly menu.

This project demonstrates the use of:
- Basic C++ programming.
- ASCII art design.
- Menu-driven interfaces.

Thank you for using EMOJI ASCII ART!
=========================================
Press [B] to back
=========================================
)";
}

// Function to display the creators screen
void displayCreatorsScreen() {
    clearScreen();
    std::cout << R"(
=========================================

              ℂℝ𝔼𝔸𝕋𝕆ℝ𝕊  
                              
=========================================
This program was created by:
- Jhon Dave Fuentes
- John Robert Anggit
- John Venedick Balonzo

These students are currently enrolled in 
CC102 and have collaborated to bring you
this fun and interactive project.

=========================================
Press [B] to back
=========================================
)";
}

// Function to generate ASCII art based on user input
std::string generateASCIIArt(int choice) {
    switch (choice) {
        case 1: // Happy Emoji
            return R"(
      _.-'''''-._
    .'  _     _  '.
   /   (_)   (_)   \
  |  ,           ,  |
  |  \`.       .`/  |
   \  '.`'""'"`.'  /
    '.  `'---'`  .'
      '-._____.-'
)";
        case 2: // Sad Emoji
            return R"(
     .-""""""-.
   .'          '.
  /   O      O   \
 :                :
 |                |   
 :    .------.    :
  \  '        '  /
   '.          .'
     '-......-'
)";
        case 3: // Angry Emoji
            return R"(
     .-""""""-.
   .'  \\  //  '.
  /   O      O   \
 :                :
 |                |  
 :       __       :
  \  .-"`  `"-.  /
   '.          .'
     '-......-'
)";
        case 4: // Surprised Emoji
            return R"(
      -""""""-.
   .'          '.
  /   O      O   \
 :                :
 |                |   
 :       O        :
  \              /
   '.          .'
     '-......-'
)";
        case 5: // Winking Emoji
            return R"(
     .-""""""-.
   .'          '.
  /   O    -=-   \
 :                :
 |                | 
 : ',          ,' :
  \  '-......-'  /
   '.          .'
     '-......-'
)";
        default:
            return "Unknown input!";
    }
}

// Helper function to wait for user input
void waitForUserInput() {
    std::cin.ignore(); // Ignore the previous newline character
    std::cin.get();    // Wait for the user to press Enter
}

// Main function
int main() {
    char homeInput;
    int userInput;

    // Display loading screen
    displayLoadingScreen();

    while (true) {
        // Display the home screen
        displayHomeScreen();
        std::cin >> homeInput;

        if (homeInput == 'Q' || homeInput == 'q') {
            clearScreen(); // Clear the screen before quitting
            std::cout << "Thank you for trying! Goodbye!" << std::endl;
            break; // Exit the program
        } else if (homeInput == 'S' || homeInput == 's') {
            while (true) {
                clearScreen();
                std::cout << "\n=========================================\n";
                
                std::cout << "\n        𝔼𝕄𝕆𝕁𝕀 𝔸𝕊ℂ𝕀𝕀 𝔸ℝ𝕋 𝔾𝔼ℕ𝔼ℝ𝔸𝕋𝕆ℝ\n";
                         std::cout << "\n=========================================\n";
                std::cout << "            Select an emoji:\n";
                std::cout << "=========================================\n";
                std::cout << "[1] Happy\n";
                std::cout << "[2] Sad\n";
                std::cout << "[3] Angry\n";
                std::cout << "[4] Surprised\n";
                std::cout << "[5] Winking\n";
                std::cout << "Enter your choice: ";
                std::cin >> userInput;
                
                // Generate and display the ASCII art for the selected emoji
                std::string asciiArt = generateASCIIArt(userInput);
                std::cout << asciiArt << std::endl;

                // Show options after the reaction is displayed
                std::cout << "Press [B] to back\n";
                std::cout << "Press [Q] to quit\n";
                std::cout << "Press [Enter] to continue\n";

                char backOrQuit;
                std::cin.ignore(); // Ignore the previous newline character
                backOrQuit = std::cin.get(); // Wait for the user to press a key

                if (backOrQuit == 'Q' || backOrQuit == 'q') {
                    clearScreen(); // Clear the screen before quitting
                    std::cout << "Thank you for trying! Goodbye!" << std::endl;
                    return 0; // Exit the program
                } else if (backOrQuit == 'B' || backOrQuit == 'b') {
                    break; // Go back to the home screen
                } else if (backOrQuit == '\n') {
                    // If the user presses Enter, continue the loop to select another emoji
                    continue;
                } else {
                    std::cout << "Invalid input! Please try again." << std::endl;
                    waitForUserInput();
                }
            }
        } else if (homeInput == 'A' || homeInput == 'a') {
            displayAboutScreen();
            waitForUserInput();
        } else if (homeInput == 'C' || homeInput == 'c') {
            displayCreatorsScreen();
            waitForUserInput();
        } else {
            std::cout << "Invalid input! Please try again." << std::endl;
            waitForUserInput();
        }
    }

    return 0;
}
