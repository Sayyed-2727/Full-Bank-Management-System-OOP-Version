#pragma once    
#include <cstdlib>
#include <ctime>
#include <string>
#include "ClsDate.h"
#include <cmath>
using namespace std;

class ClsUtil
{

public:

    enum enCharType {small_letter = 1, Capital_letter = 2, digits = 3, special_character = 4, Mix = 5};

    static void Srand()
    {
        //Seeds the random number generator in C++, called only once
        srand((unsigned)time(NULL));
    }

    static short RandomNumber(short from, short to)
    {
        short RandomNumber = rand() % (to-from+1) + from;
        return RandomNumber;
    }

    static char GetRandomCharacter(enCharType CharType)
    {

        //updated this method to accept mixchars
        if (CharType == Mix)
        {
            //Capital/Samll/Digits only
            CharType = (enCharType)RandomNumber(1, 3);

        }

        switch (CharType)
        {

        case enCharType::small_letter:
        {
            return char(RandomNumber(97, 122));
            break;
        }
        case enCharType::Capital_letter:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        case enCharType::special_character:
        {
            return char(RandomNumber(33, 47));
            break;
        }
        case enCharType::digits:
        {
            return char(RandomNumber(48, 57));
            break;
        }
    defualt:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        }
    }
    
    static string generate_word(int length, enCharType chartype)
    {
        string key = "";
        int counter = 0;
        for (int i = 1; i<= length; i++)
        {
            key += GetRandomCharacter(chartype);
                
        }
        
        return key;
    }

    static string GenerateKey(enCharType CharType)
    {
        string key = "";
        key += generate_word(4,CharType) + "-";
        key += generate_word(4,CharType) + "-";
        key += generate_word(4,CharType) + "-";
        key += generate_word(4,CharType) ;

        return key;
    }

    static void GenerateKeys(short key_times, enCharType CharType)
    {
        for(int i =1; i<= key_times; i++)
        {
            cout << "Key [" << i << "] : " << GenerateKey(CharType) << endl ;
        }
    }

    static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = RandomNumber(From, To);
    }

    static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short Wordlength)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = generate_word(Wordlength, CharType);

    }

    static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateKey(CharType);
    }

    static  void Swap(int& A, int& B)
    {
        int Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(double& A, double& B)
    {
        double Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(bool& A, bool& B)
    {
        bool Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(char& A, char& B)
    {
        char Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(string& A, string& B)
    {
        string Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(clsDate& A, clsDate& B)
    {
        clsDate::SwapDates(A, B);

    }

    static  void ShuffleArray(int arr[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }

    }

    static  void ShuffleArray(string arr[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }

    }

    static string  Tabs(short NumberOfTabs)
    {
        string t = "";

        for (int i = 1; i < NumberOfTabs; i++)
        {
            t = t + "\t";
            cout << t;
        }
        return t;

    }

    static string  EncryptText(string Text, short EncryptionKey)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] + EncryptionKey);

        }

        return Text;

    }

    static string  DecryptText(string Text, short EncryptionKey)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] - EncryptionKey);

        }
        return Text;

    }

    static std::string NumberToText(float number)
    {
		if (number < 0) {
			return "Negative " + NumberToText(-number);
		}

		if (number == 0) {
			return "Zero";  // Return "Zero" for 0.
		}

		// Handle integer part
		int integerPart = static_cast<int>(number);
		std::string result;

		static const std::string arr1[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
											 "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen",
											 "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen",
											 "Nineteen" };

		static const std::string arr2[] = { "", "", "Twenty", "Thirty", "Forty", "Fifty",
											 "Sixty", "Seventy", "Eighty", "Ninety" };

		if (integerPart < 20) {
			result += arr1[integerPart] + " ";
		}
		else if (integerPart < 100) {
			result += arr2[integerPart / 10] + " " + arr1[integerPart % 10] + " ";
		}
		else if (integerPart < 1000) {
			result += arr1[integerPart / 100] + " Hundred " + NumberToText(static_cast<float>(integerPart % 100));
		}
		else if (integerPart < 1000000) {
			result += NumberToText(static_cast<float>(integerPart / 1000)) + " Thousand " + NumberToText(static_cast<float>(integerPart % 1000));
		}
		else if (integerPart < 1000000000) {
			result += NumberToText(static_cast<float>(integerPart / 1000000)) + " Million " + NumberToText(static_cast<float>(integerPart % 1000000));
		}
		else {
			result += NumberToText(static_cast<float>(integerPart / 1000000000)) + " Billion " + NumberToText(static_cast<float>(integerPart % 1000000000));
		}

		// Handle decimal part
		int decimalPart = static_cast<int>(std::round((number - integerPart) * 100)); // Convert to two decimal places
		if (decimalPart > 0) {
			result += "point ";
			if (decimalPart < 10) {
				result += "Zero ";  // Handle single-digit decimals
			}
			result += NumberToText(static_cast<float>(decimalPart));
		}

		return result;
	}

};