#include <iostream>
#include <string>
 
bool isDigitChar(char character)
{
    return character >= '0' && character <= '9';
}
 
int getDigitValue(char digitCharacter)
{
    return digitCharacter - '0';
}
 
bool isSpace(char spaceCharacter) {
    
    bool isWhitespace = false;
    
    if (spaceCharacter == ' '  ||
        spaceCharacter == '\t' || 
        spaceCharacter == '\n' ||  
        spaceCharacter == '\r' ||  
        spaceCharacter == '\f' ||  
        spaceCharacter == '\v')    
    {
        isWhitespace = true;
    } 
    else 
    {
        isWhitespace = false;
    }
    return isWhitespace;
}
 
bool isSign(char signcharacter)
{
    return signcharacter == '+' || signcharacter == '-';
}
 
bool isExponent(char character)
{
    return character == 'e' || character == 'E';
}
 
void skipLeadingSpaces(const std::string& inputText, int& currentPosition)
{
    while (currentPosition < (int)inputText.size() && isSpace(inputText[currentPosition]))
    {
        currentPosition++;
    }
}
 
bool readOptionalSign(const std::string& inputText, int& currentPosition)
{
    bool isNegativeNumber = false;
 
    if (currentPosition < (int)inputText.size() && isSign(inputText[currentPosition]))
    {
        isNegativeNumber = (inputText[currentPosition] == '-');
        currentPosition++;
    }
 
    return isNegativeNumber;
}
 
double powerOfTen(int exponentValue)
{
    double powerResult = 1.0;
 
    while (exponentValue > 0)
    {
        powerResult *= 10.0;
        exponentValue--;
    }
 
    while (exponentValue < 0)
    {
        powerResult /= 10.0;
        exponentValue++;
    }
 
    return powerResult;
}
 
double parseIntegerPart(const std::string& inputText, int& currentPosition, bool& hasIntegerDigits)
{
    double integerValue = 0.0;
    hasIntegerDigits = false;
 
    while (currentPosition < (int)inputText.size() && isDigitChar(inputText[currentPosition]))
    {
        hasIntegerDigits = true;
        integerValue = integerValue * 10.0 + getDigitValue(inputText[currentPosition]);
        currentPosition++;
    }
 
    return integerValue;
}
 
double parseFractionPart(const std::string& inputText, int& currentPosition, bool& hasFractionDigits)
{
    double fractionValue = 0.0;
    double fractionDivisor = 1.0;
    hasFractionDigits = false;
 
    while (currentPosition < (int)inputText.size() && isDigitChar(inputText[currentPosition]))
    {
        hasFractionDigits = true;
        fractionValue = fractionValue * 10.0 + getDigitValue(inputText[currentPosition]);
        fractionDivisor *= 10.0;
        currentPosition++;
    }
 
    if (!hasFractionDigits)
    {
        return 0.0;
    }
 
    return fractionValue / fractionDivisor;
}
 
int parseExponentPart(const std::string& inputText, int& currentPosition, bool& hasValidExponent)
{
    bool isNegativeExponent = readOptionalSign(inputText, currentPosition);
    bool hasExponentDigits = false;
    double exponentNumber = parseIntegerPart(inputText, currentPosition, hasExponentDigits);
 
    hasValidExponent = hasExponentDigits;
 
    if (!hasValidExponent)
    {
        return 0;
    }
 
    int exponentValue = (int)exponentNumber;
 
    if (isNegativeExponent)
    {
        exponentValue = -exponentValue;
    }
 
    return exponentValue;
}
 
double parseDecimalNumber(const std::string& inputText, int& currentPosition)
{
    bool hasWholeDigits = false;
    double wholeNumberPart = parseIntegerPart(inputText, currentPosition, hasWholeDigits);
 
    bool hasDecimalDigits = false;
    double decimalPart = 0.0;
 
    if (currentPosition < (int)inputText.size() && inputText[currentPosition] == '.')
    {
        currentPosition++;
        decimalPart = parseFractionPart(inputText, currentPosition, hasDecimalDigits);
    }
 
    if (!hasWholeDigits && !hasDecimalDigits)
    {
        return 0.0;
    }
 
    double finalNumber = wholeNumberPart + decimalPart;
 
    if (currentPosition < (int)inputText.size() && isExponent(inputText[currentPosition]))
    {
        int savedPosition = currentPosition;
        currentPosition++;
 
        bool hasExponentValue = false;
        int exponentValue = parseExponentPart(inputText, currentPosition, hasExponentValue);
 
        if (hasExponentValue)
        {
            finalNumber *= powerOfTen(exponentValue);
        }
        else
        {
            currentPosition = savedPosition;
        }
    }
 
    return finalNumber;
}
 
double stringToDouble(const std::string& inputText)
{
    int currentPosition = 0;
 
    skipLeadingSpaces(inputText, currentPosition);
 
    if (currentPosition == (int)inputText.size())
    {
        return 0.0;
    }
 
    bool isNegativeNumber = readOptionalSign(inputText, currentPosition);
 
    double convertedValue = parseDecimalNumber(inputText, currentPosition);
 
    if (isNegativeNumber)
    {
        convertedValue = -convertedValue;
    }
 
    return convertedValue;
}
 
bool readInputLine(std::string& enteredText)
{
    enteredText.clear();
    char currentCharacter;

    while (true)
    {
        if (!std::cin.get(currentCharacter))
        {
            return false;
        }

        if (currentCharacter == '\n')
        {
            break;
        }

        enteredText += currentCharacter;
    }

    return true;
}
 
bool isValidChoice(const std::string& choiceText) 
{
    bool isInputValid = false;

    if (choiceText.size() == 1) 
    {
        char firstChar = choiceText[0];

        if (firstChar == 'y' || firstChar == 'Y' || 
            firstChar == 'n' || firstChar == 'N') 
        {
            isInputValid = true;
        } 
        else 
        {
            isInputValid = false;
        }
    } 
    else 
    {
        isInputValid = false;
    }

    return isInputValid;
}
 
char readUserChoice()
{
    while (true)
    {
        std::string userChoiceText;

        std::cout << "\nDo you want to enter another value? (y/n): ";

        if (!readInputLine(userChoiceText))
        {
            std::cout << "\nEOF detected. Program exiting.\n";
            exit(0);
        }

        if (isValidChoice(userChoiceText))
        {
            return userChoiceText[0];
        }

        std::cout << "Please enter only y or n.\n";
    }
}
 
int main()
{
    char userChoice = 'y';

    do
    {
        std::string inputString;

        std::cout << "Enter a floating-point value: ";

        if (!readInputLine(inputString))
        {
            std::cout << "\nEOF detected. Program exiting.\n";
            break;
        }

        double Result = stringToDouble(inputString);

        std::cout << "Input entered   : " << inputString << '\n';
        std::cout << "Converted value : " << Result << '\n';

        userChoice = readUserChoice();

    } while (userChoice == 'y' || userChoice == 'Y');

    return 0;
}
