#pragma once
#ifndef CLSutil_H
#define CLSutil_H
#include <iostream>
#include <string>
using namespace std;

class clsUtil
{
public:

 static string  EncryptText(string Text, short EncryptionKey=2)
    {


      //  Text+=EncryptionKey;
        //return Text;


        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] + EncryptionKey);

        }

        return Text;

    }

    static string  DecryptText(string Text, short EncryptionKey=2)
    {


         //Text-=EncryptionKey;
        //return Text;


        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] - EncryptionKey);

        }
        return Text;

    }



};

#endif