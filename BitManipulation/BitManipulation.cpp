

#include <iostream>

void PrintBinary(int num);
void TurnOn(int bit);
void TurnOff(int bit);
void Toggle(int bit);
void Negate();
void LeftShift();
void RightShift();


unsigned int bitField;


int main()
{
    std::cout << "Enter a number: ";
    std::cin >> bitField;
    std::cout << "Bits: ";
    PrintBinary(bitField);

    std::cout << "\n\n";
    std::cout << "Choose operation:\n";
    std::cout << "=================\n";
    std::cout << "TurnOn = 1\n";
    std::cout << "TurnOff = 2\n";
    std::cout << "Toggle = 3\n";
    std::cout << "Negate = 4\n";
    std::cout << "Left Shift = 5\n";
    std::cout << "Right Shift = 6\n";

    std::cout << "\nEnter operation choice: ";
    int choice;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        std::cout << "Choose which bit index to turn on (1-32): ";
        int bitOnIndex;
        std::cin >> bitOnIndex;
        TurnOn(bitOnIndex);

        break;
    case 2:
        std::cout << "Choose which bit index to turn off (1-32): ";
        int bitOffIndex;
        std::cin >> bitOffIndex;
        TurnOff(bitOffIndex);

        break;
    case 3:
        std::cout << "Choose which bit index to toggle (1-32): ";
        int bitToggleIndex;
        std::cin >> bitToggleIndex;
        Toggle(bitToggleIndex);

        break;
    case 4:
        std::cout << bitField << " negated results in:\n";
        Negate();
        break;
    case 5:
        std::cout << bitField << " shifted left results in:\n";
        LeftShift();
        break;
    case 6:
        std::cout << bitField << " shifted right results in:\n";
        RightShift();
        break;
    }
}

void PrintBinary(int num) {
    for (int i = 31; i >= 0; --i) {
        int bit = (num >> i) & 1;
        std::cout << bit;
        if (i % 4 == 0) std::cout << ' '; // Add a space every 4 bits for readability
    }
}

void TurnOn(int bit)
{
    int bitIndex = bit - 1;
    bitField |= (1 << bitIndex);
    std::cout << "Turning on bit at position " << bit << " results in:\n";
    PrintBinary(bitField);
}

void TurnOff(int bit)
{
    int bitIndex = bit - 1;
    bitField &= ~(1 << bitIndex);
    std::cout << "Turning off bit at position " << bit << " results in:\n";
    PrintBinary(bitField);
}

void Toggle(int bit)
{
    int bitIndex = bit - 1;
    bitField ^= (1 << bitIndex);
    std::cout << "Toggling bit at position " << bit << " results in:\n";
    PrintBinary(bitField);
}

void Negate()
{
    PrintBinary(~bitField);
}

void LeftShift()
{
    PrintBinary(bitField << 1);
}

void RightShift()
{
    PrintBinary(bitField >> 1);
}
