#pragma once
#include <iostream>
#include <cctype>
#include <string>
#include <cstdlib>
#include <vector>
#include <iomanip>

using namespace std;

class clsString
{

private:
    string _Value;
    char _Char;


public:

    clsString()
    {
        _Value = "";
    }

    clsString(string Value)
    {
        _Value = Value;
    }

    // set
    void SetValue(string Value)
    {
        _Value = Value;
    }

    // Get
    string GetValue()
    {
        return _Value;
    }


    // We make it a static func to not counts only on objects, so I can recall it without having any objects
    
    static short Length(string s1)
    {
        s1.length();
    }
    
    short Length()
    {
        return _Value.length();
    }
    
    static short CountWords(string s1)
    {   
        short counter = 0, pos = 0;
        string delimiter = " ", sword; // define a delimiter and a string variable

        // using find() fun to get the delimiter pos
        while ((pos = s1.find(delimiter)) != std::string::npos)
        {
            sword = s1.substr(0,pos);       // store the word

            if (sword != "")
            {
                counter ++;
            }

            s1.erase(0,pos+delimiter.length());
        }
        if (s1 != "")
        {
            counter ++;
        }
        
        return counter;
        }

    short CountWords()
    {
        return CountWords(_Value);
    };

    static string TrimLeft(string S1)
  {


      for (short i = 0; i < S1.length(); i++)
      {
          if (S1[i] != ' ')
          {
              return S1.substr(i, S1.length() - i);
          }
      }
      return "";
  }

   void TrimLeft()
 {
     _Value = TrimLeft(_Value);
 }

   static string TrimRight(string S1)
  {


      for (short i = S1.length() - 1; i >= 0; i--)
      {
          if (S1[i] != ' ')
          {
              return S1.substr(0, i + 1);
          }
      }
      return "";
  }
 
   void TrimRight()
  {
      _Value = TrimRight(_Value);
  }

   static string Trim(string S1)
  {
      return (TrimLeft(TrimRight(S1)));

  }

   void Trim()
  {
      _Value= Trim(_Value);
  }

    static bool CheckVowel(char c1)
    {
        return ((c1 == 'a') || (c1=='e') || (c1=='i') || (c1 == 'o') || (c1=='u'))? true : false;
    }
    
    bool CheckVowel()
    {
        return CheckVowel(_Char);
    }

    static short CountVowel(string s1)
    {
        short counter = 0;
        for (char& i: s1)
        {
            if (CheckVowel(tolower(i)))
            {
                counter++;
            }
            
        }
        return counter;
    }

    short CountVowel()
    {
        return CountVowel(_Value);
    }

    static vector <string> Split(string s1, string delimiter)
    {
        vector <string> vword;
        string sWord;
        short pos = 0;

        while ((pos = s1.find(delimiter)) != std::string::npos)     // as the delimiter has a position in S1 will enter the loop
        {
            sWord = s1.substr(0,pos);  // creating a variable with the first word in the string
            
            if (sWord != "")
            {
                vword.push_back(sWord);
            }

            s1.erase(0,pos + delimiter.length()); // reset the string after elminiating the first word
        }
        
        if (s1 != "")  // print the last word as there's no space in the last word
        {
            vword.push_back(s1);
        }
        
        return vword;
    }

    vector <string> Split()
    {
        return Split(_Value, "");
    }

    static void PrintVowels(string s1)
    {
        cout << "Vowels in your string are: ";
        for (char& i: s1)
        {
            if (CheckVowel(tolower(i)))
            {
                cout << setw(4) << i;
            }
            
        }
    }

    void PrintVowels()
    {
        PrintVowels(_Value);
    }

    static void PrintEachWordInString(string s1)
    {
        string delim = " "; // delimiter
        cout << "\nYour string words are:\n\n";
        short pos = 0;
        string sWord; // define a string variable

        // use find() func to get the position of the delimiters
        while ((pos= s1.find(delim)) != std::string::npos)  // while theres a position for delimiters in the string
        {
            sWord = s1.substr(0,pos); // store the word
            if (sWord != "")
            {
                cout << sWord << endl;
            }

            s1.erase(0,pos + delim.length()); // erase() untill the pos so we can move to the next word
        }

        if (s1 != "")       // to print the last word in the string as in the last word theres no space so will exit while loop and proceed here.

        {
            cout << s1 << endl;
        }    
    }

    void PrintEachWordInString()
    {
        PrintEachWordInString(_Value);
    }

    static string  UpperFirstLetterOfEachWord(string S1)
    {

        bool isFirstLetter = true;

        for (short i = 0; i < S1.length(); i++)
        {

            if (S1[i] != ' ' && isFirstLetter)
            {
                S1[i] = toupper(S1[i]);

            }

            isFirstLetter = (S1[i] == ' ' ? true : false);

        }

        return S1;
    }

    void  UpperFirstLetterOfEachWord()
    {
        // no need to return value , this function will directly update the object value  
       _Value = UpperFirstLetterOfEachWord(_Value);
    }

   static string  LowerFirstLetterOfEachWord(string S1)
    {

        bool isFirstLetter = true;

        for (short i = 0; i < S1.length(); i++)
        {

            if (S1[i] != ' ' && isFirstLetter)
            {
                S1[i] = tolower(S1[i]);

            }

            isFirstLetter = (S1[i] == ' ' ? true : false);

        }

        return S1;
    }

    void  LowerFirstLetterOfEachWord()
    {

       
        // no need to return value , this function will directly update the object value  
        _Value = LowerFirstLetterOfEachWord(_Value);
    }
    
   static string  UpperAllString(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            S1[i] = toupper(S1[i]);
        }
        return S1;
    }

   void  UpperAllString()
   {
       _Value = UpperAllString(_Value);
   }

   static string  LowerAllString(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            S1[i] = tolower(S1[i]);
        }
        return S1;
    }

   void  LowerAllString()
    {
        _Value = LowerAllString(_Value);
    }

   static char  InvertLetterCase(char char1)
    {
        return isupper(char1) ? tolower(char1) : toupper(char1);
    }

   static string  InvertAllLettersCase(string S1)
   {
       for (short i = 0; i < S1.length(); i++)
       {
           S1[i] = InvertLetterCase(S1[i]);
       }
       return S1;
   }

   void  InvertAllLettersCase()
   {
       _Value = InvertAllLettersCase(_Value);
   }

   enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };

   static short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
   {


       if (WhatToCount == enWhatToCount::All)
       {
           return S1.length();
       }

       short Counter = 0;

       for (short i = 0; i < S1.length(); i++)
       {

           if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
               Counter++;


           if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
               Counter++;


       }

       return Counter;

   }
  
   static short  CountCapitalLetters(string S1)
   {

       short Counter = 0;

       for (short i = 0; i < S1.length(); i++)
       {

           if (isupper(S1[i]))
               Counter++;

       }

       return Counter;
   }

   short  CountCapitalLetters()
   {
       return CountCapitalLetters(_Value);
   }

   static short  CountSmallLetters(string S1)
   {

       short Counter = 0;

       for (short i = 0; i < S1.length(); i++)
       {

           if (islower(S1[i]))
               Counter++;

       }

       return Counter;
   }

   short  CountSmallLetters()
   {
       return CountSmallLetters(_Value);
   }
   
   static short  CountSpecificLetter(string S1, char Letter, bool MatchCase = true)
   {

       short Counter = 0;

       for (short i = 0; i < S1.length(); i++)
       {

           if (MatchCase)
           {
               if (S1[i] == Letter)
                   Counter++;
           }
           else
           {
               if (tolower(S1[i]) == tolower(Letter))
                   Counter++;
           }

       }

       return Counter;
   }

   short  CountSpecificLetter( char Letter, bool MatchCase = true)
  {
      return CountSpecificLetter(_Value,Letter, MatchCase);
  }

   static bool IsVowel(char Ch1)
  {
      Ch1 = tolower(Ch1);

      return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));

  }
  
   static string JoinString(vector<string> vString, string Delim)
  {

      string S1 = "";

      for (string& s : vString)
      {
          S1 = S1 + s + Delim;
      }

      return S1.substr(0, S1.length() - Delim.length());


  }

   static string JoinString(string arrString[], short Length, string Delim)
  {

      string S1 = "";

      for (short i = 0; i < Length; i++)
      {
          S1 = S1 + arrString[i] + Delim;
      }

      return S1.substr(0, S1.length() - Delim.length());

  }

   static string ReverseWordsInString(string S1)
  {

      vector<string> vString;
      string S2 = "";

      vString = Split(S1, " ");

      // declare iterator
      vector<string>::iterator iter = vString.end();

      while (iter != vString.begin())
      {

          --iter;

          S2 += *iter + " ";

      }

      S2 = S2.substr(0, S2.length() - 1); //remove last space.

      return S2;
  }

   void ReverseWordsInString()
  {
      _Value = ReverseWordsInString(_Value);
  }

     static string ReplaceWord(string S1, string StringToReplace, string sRepalceTo, bool MatchCase = true)
  {

      vector<string> vString = Split(S1, " ");

      for (string& s : vString)
      {

          if (MatchCase)
          {
              if (s == StringToReplace)
              {
                  s = sRepalceTo;
              }

          }
          else
          {
              if (LowerAllString(s) == LowerAllString(StringToReplace))
              {
                  s = sRepalceTo;
              }

          }

      }

      return JoinString(vString, " ");
  }

   string ReplaceWord(string StringToReplace, string sRepalceTo)
 {
     return ReplaceWord(_Value, StringToReplace, sRepalceTo);
 }

   static string RemovePunctuations(string S1)
 {

     string S2 = "";

     for (short i = 0; i < S1.length(); i++)
     {
         if (!ispunct(S1[i]))
         {
             S2 += S1[i];
         }
     }

     return S2;

 }

   void RemovePunctuations()
 {
     _Value = RemovePunctuations(_Value);
 }

};