#include <iostream>
#include <bitset>
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <string>

class MotorStatus {
private:
    uint8_t motorState;             
    // Every bit represents a motor (1 = ON, 0 = OFF) //
    uint8_t overheatingMotors = 0;  
    // Finds which motors are overheating //
    int turnCount;

    void initialize() {
        std::srand(static_cast<unsigned int>(time(0)));

        do {
            motorState = static_cast<uint8_t>(std::rand() % 256);
        } while (motorState == 0);  
        // Make sure at least one motor is spinning //

        turnCount = 0;
        updateOverheating();
        displayStatus();
    }

    void updateOverheating() {
        if ((motorState & static_cast<uint8_t>(~overheatingMotors)) == 0) {
            // ON motors are overheating //
            turnCount++;
            return;
        }

        int newMotor = 0;
        do {
            newMotor = std::rand() % 8;
        } while (((static_cast<uint8_t>(1u << newMotor) & motorState) == 0) ||
                 ((static_cast<uint8_t>(1u << newMotor) & overheatingMotors) != 0));

        overheatingMotors |= static_cast<uint8_t>(1u << newMotor);
        turnCount++;
    }

    void displayStatus() const {
        std::cout << "Motor State (ON/OFF): " << std::bitset<8>(motorState) << '\n';
        std::cout << "Overheating Motors: " << std::bitset<8>(overheatingMotors) << '\n';
        std::cout << "Turn Count: " << turnCount << '\n';
    }

public:
    MotorStatus() {
        initialize();
    }

    bool turnOff(uint8_t guess) {
        bool correctGuess = (guess == overheatingMotors);

        // Only turn off motors that are both guessed AND overheating //
        uint8_t motorsToTurnOff = static_cast<uint8_t>(guess & overheatingMotors);

        motorState = static_cast<uint8_t>(motorState & ~motorsToTurnOff);
        overheatingMotors = static_cast<uint8_t>(overheatingMotors & ~motorsToTurnOff);

        if (correctGuess) {
            std::cout << "Success! All overheating motors have been turned off: "
                      << std::bitset<8>(motorsToTurnOff) << '\n';
            return true;
        }

        std::cout << "Incorrect guess. Some motors are still overheating.\n";
        updateOverheating();
        return false;
    }

    void showMotorState() const {
        std::cout << "Motor State (ON/OFF): " << std::bitset<8>(motorState) << '\n';
        std::cout << "Turn Count: " << turnCount << '\n';
    }
};

int checkInput(const std::string& s) {
    int value = 0;
    bool ok = true;

    if (s.size() == 8 && s.find_first_not_of("01") == std::string::npos) {
        for (char c : s) {
            value = (value << 1) | (c - '0');
        }
        return value;
    }
    else if (s.size() >= 3 && (s.rfind("0x", 0) == 0 || s.rfind("0X", 0) == 0)) {
        try {
            value = static_cast<int>(std::stoul(s, nullptr, 16));
            if (value > 255) {
                ok = false;
            }
        }
        catch (...) {
            ok = false;
        }

        if (ok) {
            return value;
        }
    }

    std::cout << "Invalid input. Use 8-bit binary (00101000) or hex (0x28).\n";
    return -1;
}

void printWelcome() {
    std::cout << "\nOpening the Motor Control Interface.\n";
    std::cout << "This is not a game.\n\n";
}

void printMenu() {
    std::cout
        << "Commands:\n"
        << "  on n      -> set bit n\n"
        << "  off n     -> clear bit n\n"
        << "  toggle n  -> flip bit n\n"
        << "  reset     -> clear current guess\n"
        << "  show      -> show current guess\n"
        << "  status    -> check motor ON/OFF status\n"
        << "  submit    -> submit current guess\n"
        << "  binary    -> enter an 8-bit binary guess\n"
        << "  hex       -> enter a hex guess\n"
        << "  q         -> quit\n\n";
}

void printGuess(uint8_t guess) {
    std::cout << "Current Guess: " << std::bitset<8>(guess)
              << " (0x" << std::hex << static_cast<int>(guess) << std::dec << ")\n";
}

bool editGuessByBitCommand(const std::string& command, uint8_t& guess) {
    int bit;
    std::cin >> bit;

    if (!std::cin || bit < 0 || bit > 7) {
        std::cout << "Bit number must be from 0 to 7.\n";
        return false;
    }

    uint8_t mask = static_cast<uint8_t>(1u << bit);

    if (command == "on") {
        guess = static_cast<uint8_t>(guess | mask);
    }
    else if (command == "off") {
        guess = static_cast<uint8_t>(guess & ~mask);
    }
    else {
        guess = static_cast<uint8_t>(guess ^ mask);
    }

    printGuess(guess);
    return true;
}

bool readFullGuess(uint8_t& guess) {
    std::string input;
    std::cout << "Enter value: ";
    std::cin >> input;

    int value = checkInput(input);
    if (value == -1) {
        return false;
    }

    guess = static_cast<uint8_t>(value);
    printGuess(guess);
    return true;
}

int main() {
    MotorStatus motorStatus;
    uint8_t guess = 0;
    std::string command;

    printWelcome();
    printMenu();
    printGuess(guess);

    while (true) {
        std::cout << "\nCommand: ";
        std::cin >> command;

        if (!std::cin || command == "q" || command == "Q") {
            break;
        }
        else if (command == "show") {
            printGuess(guess);
        }
        else if (command == "reset") {
            guess = 0;
            printGuess(guess);
        }
        else if (command == "status") {
            motorStatus.showMotorState();
        }
        else if (command == "submit") {
            if (motorStatus.turnOff(guess)) {
                std::cout << "Congratulations! You've stabilized the system.\n";
                break;
            }
        }
        else if (command == "binary" || command == "hex") {
            readFullGuess(guess);
        }
        else if (command == "on" || command == "off" || command == "toggle") {
            editGuessByBitCommand(command, guess);
        }
        else {
            int value = checkInput(command);
            if (value != -1) {
                guess = static_cast<uint8_t>(value);
                printGuess(guess);
            }
        }
    }

    return 0;
}