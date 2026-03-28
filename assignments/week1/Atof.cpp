#include <iostream>
#include <string>
 
bool isDigit(char character)
{
    return character >= '0' && character <= '9';
}
 
int getDigitValue(char digitCharacter)
{
    return digitCharacter - '0';
}
 
bool isSpace(char spaceCharacter) {
    
    bool isWhitespace = false;
    
    if (
        spaceCharacter == ' '  ||
        spaceCharacter == '\t' || 
        spaceCharacter == '\n'  
    )    
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

bool isExponentChar(char currentChar)
{
    return currentChar == 'e' || currentChar == 'E';
}
 
void skipLeadingSpaces(const std::string& input, int& position)
{
    while (position < input.size() && isSpace(input[position]))
    {
        position++;
    }
}
 
bool readOptionalSign(const std::string& input, int& position)
{
    bool isNegative = false;

    if (position < input.size() && isSign(input[position]))
    {
        isNegative = (input[position] == '-');
        position++;
    }

    return isNegative;
}
 
double powerOfTen(int exponent)
{
    double result = 1.0;

    while (exponent > 0)
    {
        result *= 10.0;
        exponent--;
    }

    while (exponent < 0)
    {
        result /= 10.0;
        exponent++;
    }

    return result;
}
 
double parseIntegerPart(const std::string& input, int& position, bool& hasIntegerDigits)
{
    double integerPart = 0.0;
    hasIntegerDigits = false;

    while (position < input.size() && isDigit(input[position]))
    {
        hasIntegerDigits = true;
        integerPart = integerPart * 10.0 + getDigitValue(input[position]);
        position++;
    }

    return integerPart;
}
 
double parseFractionPart(const std::string& input, int& position, bool& hasFractionDigits)
{
    double fractionNumber = 0.0;
    double scaleFactor = 1.0;
    hasFractionDigits = false;

    while (position < input.size() && isDigit(input[position]))
    {
        hasFractionDigits = true;
        fractionNumber = fractionNumber * 10.0 + getDigitValue(input[position]);
        scaleFactor *= 10.0;
        position++;
    }

    if (!hasFractionDigits)
    {
        return 0.0;
    }

    return fractionNumber / scaleFactor;
}
 
int parseExponentPart(const std::string& input, int& position, bool& hasExponent)
{
    bool isNegativeExponent = readOptionalSign(input, position);
    bool hasExponentDigits = false;
    double exponentNumber = parseIntegerPart(input, position, hasExponentDigits);

    hasExponent = hasExponentDigits;

    if (!hasExponent)
    {
        return 0;
    }

    int exponent = (int)exponentNumber;

    if (isNegativeExponent)
    {
        exponent = -exponent;
    }

    return exponent;
}
 
double parseDecimalNumber(const std::string& input, int& position)
{
    bool hasIntegerDigits = false;
    double integerPart = parseIntegerPart(input, position, hasIntegerDigits);

    bool hasFractionDigits = false;
    double fractionPart = 0.0;

    if (position < input.size() && input[position] == '.')
    {
        position++;
        fractionPart = parseFractionPart(input, position, hasFractionDigits);
    }

    if (!hasIntegerDigits && !hasFractionDigits)
    {
        return 0.0;
    }

    double numericValue = integerPart + fractionPart;

    if (position < input.size() && isExponentChar(input[position]))
    {
        int previousPosition = position;
        position++;

        bool hasExponentDigits = false;
        int exponent = parseExponentPart(input, position, hasExponentDigits);

        if (hasExponentDigits)
        {
            numericValue *= powerOfTen(exponent);
        }
        else
        {
            position = previousPosition;
        }
    }

    return numericValue;
}
 
double stringToDouble(const std::string& input)
{
    int position = 0;

    skipLeadingSpaces(input, position);

    if (position == input.size())
    {
        return 0.0;
    }

    bool isNegative = readOptionalSign(input, position);

    double parsedValue = parseDecimalNumber(input, position);

    if (isNegative)
    {
        parsedValue = -parsedValue;
    }

    return parsedValue;
}
 
bool readInputLine(std::string& inputLine)
{
    inputLine.clear();
    char currentChar;

    while (true)
    {
        if (!std::cin.get(currentChar))
        {
            return false;
        }

        if (currentChar == '\n')
        {
            break;
        }

        inputLine += currentChar;
    }

    return true;
}
 
bool isValidChoice(const std::string& choiceInput) 
{
    bool isChoiceValid = false;

    if (choiceInput.size() == 1) 
    {
        char selectedOption = choiceInput[0];

        if (selectedOption == 'y' || selectedOption == 'Y' || 
            selectedOption == 'n' || selectedOption == 'N') 
        {
            isChoiceValid = true;
        } 
        else 
        {
            isChoiceValid = false;
        }
    } 
    else 
    {
        isChoiceValid = false;
    }

    return isChoiceValid;
}
 
char readContinueChoice()
{
    while (true)
    {
        std::string choiceInput;

        std::cout << "\nDo you want to enter another value? (y/n): ";

        if (!readInputLine(choiceInput))
        {
            std::cout << "\nEOF detected. Program exiting.\n";
            return 'n';
        }

        if (isValidChoice(choiceInput))
        {
            return choiceInput[0];
        }

        std::cout << "Please enter only y or n.\n";
    }
}
 
int main()
{
    char continueChoice = 'y';

    do
    {
        std::string userInput;

        std::cout << "Enter a floating-point value: ";

        if (!readInputLine(userInput))
        {
            std::cout << "\nEOF detected. Program exiting.\n";
            break;
        }

        double convertedValue = stringToDouble(userInput);

        std::cout << "Input entered   : " << userInput << '\n';
        std::cout << "Converted value : " << convertedValue << '\n';

        continueChoice = readContinueChoice();

    } while (continueChoice == 'y' || continueChoice == 'Y');

    return 0;
}
