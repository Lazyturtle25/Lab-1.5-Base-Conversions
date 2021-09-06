#ifndef BASE_CONVERSIONS_H
#define BASE_CONVERSIONS_H
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
/*
 * use string and then look at each part indivually and placment to convert
 * return as a string for all of them? since hex has letters anyways
 * use a buffer to take the inputs
 *
 *
 */

//helper fucntion for decimal conversion to use recursion.

//function to check if the binary number is a proper byte length.

void byte_length_check(string &binry)
{
    int length = binry.length();
    if(length < 8)
    {
        int add = 8 - length;
        for(int i = 0; i < add; i++)
        {
            binry = '0' + binry;
        }
    }
    if(length > 8 && length < 16)
    {
        int add = 16 - length;
        for(int i = 0; i < add; i++)
        {
            binry = '0' + binry;
        }
    }
    if(length > 16 && length < 32)
    {
        int add = 32 - length;
        for(int i = 0; i < add; i++)
        {
            binry = '0' + binry;
        }
    }
    if(length > 32 && length < 64)
    {
        int add = 64 - length;
        for(int i = 0; i < add; i++)
        {
            binry = '0' + binry;
        }
    }
    if(length > 64 && length < 128)
    {
        int add = 256 - length;
        for(int i = 0; i < add; i++)
        {
            binry = '0' + binry;
        }
    }
}

/****************************************************************
*
* string hex_changer_to_alpha(int remainder)
*________________________________________________________________
* This function will convert a hex number to a letter.
*_______________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
*       remainder: int value for hex
*
*
* POST-CONDITIONS
*   This will use a switch function to return a letter the represents
*   the number passed in.
*****************************************************************/
string hex_changer_to_alpha(int remainder)
{
    switch (remainder) {
    case 10:
        return "A";
    case 11:
        return "B";
    case 12:
        return "C";
    case 13:
        return "D";
    case 14:
        return "E";
    case 15:
        return "D";
    }
    return "Something wrong happened";
}
/****************************************************************
*
* int hex_changer_to_int(char remainder)
*________________________________________________________________
* This function will convert a letter to a int value for hex
*_______________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
*       remainder: char value for hex
*
*
* POST-CONDITIONS
*   This will use a switch function to return a int the represents
*   the letter passed in.
*****************************************************************/
int hex_changer_to_int(char remainder)
{
    switch (remainder) {
    case 'A':
        return 10;
    case 'B':
        return 11;
    case 'C':
        return 12;
    case 'D':
        return 13;
    case 'E':
        return 14;
    case 'F':
        return 15;
    }
    return 0;
}
/****************************************************************
*
* int binary_to_decimal(string integer)
*________________________________________________________________
* This function will convert a binary number to decimal
*_______________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
*       integer: the binary number being converted
*
*
* POST-CONDITIONS
*   This will convert the binary number to decimal by going to each bit
*   and raising 2 the power of the current position.
*****************************************************************/
int binary_to_decimal(string integer)
{
    int tot_length = integer.length();
    int counter = 1;
    int decimal = 0;
    int digit = 0;
    int pwr = 0;
    for(int i=0; i < tot_length; i++)
    {
        digit = integer[i] - '0';
        pwr = tot_length - counter;
        decimal = decimal + (digit * (pow(2,pwr)));
        counter++;
    }
    return decimal;

}
/****************************************************************
*
* int octal_to_decimal(string integer)
*________________________________________________________________
* This function will convert am octal number to decimal
*_______________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
*       integer: the octal number
*
*
* POST-CONDITIONS
*   This will convert a octal number to decimal
*****************************************************************/
// wont be used since must use binary as a proxy
int octal_to_decimal(string integer)
{
    int tot_length = integer.length();
    int counter = 1;
    int decimal = 0;
    int digit = 0;
    int pwr = 0;
    for(int i=0; i < tot_length; i++)
    {
        digit = integer[i] - '0';
        pwr = tot_length - counter;
        decimal = decimal + (digit * (pow(8,pwr)));
        counter++;
    }
    return decimal;
}
/****************************************************************
*
* int hex_to_decimal(string integer)
*________________________________________________________________
* This function will convert a hex number to decimal
*_______________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
*       remainder: char value for hex
*
*
* POST-CONDITIONS
*   This will use a switch function to return a int the represents
*   the letter passed in.
*****************************************************************/
// wont be used since must use binary as a proxy
int hex_to_decimal(string integer)
{
    int tot_length = integer.length();
    int counter = 1;
    int decimal = 0;
    int digit = 0;
    int pwr = 0;
    for(int i=0; i < tot_length; i++)
    {
        if(integer[i] >= 'A' && integer[i] <= 'F')
            digit = hex_changer_to_int(integer[i]);
        else
            digit = integer[i] - '0';
        pwr = tot_length - counter;
        decimal = decimal + (digit * (pow(16,pwr)));
        counter++;
    }
    return decimal;
}
/****************************************************************
*
* void decimal_converter(int curr_value,int divisor,string &result)
*________________________________________________________________
* This function will convert decimal value to another base of decimal,
* octal, or hex.
*_______________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
*       curr_value: the current value in recursion
*       divisor: which base is it being converted to
*       result: the end result for the conversion
*
* POST-CONDITIONS
*   This will use recursion to divide the decimal number depending on the base.
*****************************************************************/

void decimal_converter(int curr_value,int divisor,string &result)
{

    int remainder;
    if(curr_value >1)
    {   remainder = curr_value%divisor;
        if(remainder > 9 && remainder <= 15)
        {
            result = hex_changer_to_alpha(remainder) + result;
        }
        else
            result = to_string(remainder) + result;
        return decimal_converter(curr_value/divisor,divisor,result);
    }
    else
    {
        if(curr_value > 0)
            result = to_string(curr_value) + result;
        return;
    }
}
/****************************************************************
*
* string binary_to_octal(string binry)
*________________________________________________________________
* This function will convert a binary value to octal
*_______________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
*       binry: the binary value
*
*
* POST-CONDITIONS
*   This will covert a binary number to octal by using grouping of 3 bits
*   It will take these bits and convert it to an octal value.
*****************************************************************/
//binary to octal using grouping
string binary_to_octal(string binry)
{
     //need to read the value of binary in groups of four
    //so make a sub-string variable that holds four.
    //use a double loop??
    string result;
    int i = 0;
    while(binry.length()%3 != 0)
    {
        binry = "0" + binry;
    }
    int length = binry.length();
    string byte;
    while(i < length)
    {
        for(int j = 0; j < 3; j++)
        {
            byte = byte + binry[j+i];
        }
        int bit = binary_to_decimal(byte);
        result = result + to_string(bit);
        byte.clear();
        i+=3;
    }
    return result;
}
/****************************************************************
*
* string binary_to_hex(string binry)
*________________________________________________________________
* This function will convert a binary value to hex
*_______________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
*       binry: the binary value
*
*
* POST-CONDITIONS
*   This will covert a binary number to octal by using grouping of 4 bits
*   It will take these bits and convert it to an hex value.
*****************************************************************/
//binary to hex
string binary_to_hex(string binry)
{
    string result;
    int i = 0;
    int length = binry.length();
    string byte;
    while(i < length)
    {
        for(int j = 0; j < 4; j++)
        {
            byte = byte + binry[j+i];
        }
        int bit = binary_to_decimal(byte);
        if(bit > 9 && bit <= 15)
        {
            result = result + hex_changer_to_alpha(bit);
        }
        else
            result = result + to_string(bit);
        byte.clear();
        i+=4;
    }
    return result;
}
/****************************************************************
*
* string octal_to_binary(string oct)
*________________________________________________________________
* This function will convert an octal value to binary
*_______________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
*       oct: octal value
*
*
* POST-CONDITIONS
*   This will take the octal value by each bit to convert into a binary
*   string of 3 bits and add them into one string.
*****************************************************************/
string octal_to_binary(string oct)
{
    //take the each bit and convert to binary lengths of 3 bits
    string result;
    int length = oct.length();
    string byte;
    for(int i=0 ;i < length; i++)
    {
        int curr_value = oct[i] - '0';
        string temp_bit;
        decimal_converter(curr_value,2,temp_bit);
        if(temp_bit.length() < 3)
            temp_bit = '0' + temp_bit;
        result = result + temp_bit;
        temp_bit.clear();
    }
    if(result.length()%8 != 0)
        result.erase(result.begin());
    return result;
}


/****************************************************************
*
* string hex_to_binary(string hex)
*________________________________________________________________
* This function will convert a hex value to binary
*_______________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
*      hex: hex value
*
*
* POST-CONDITIONS
*   This will take the hex value by each bit to convert into a binary
*   string of 4 bits and add them into one string.
*****************************************************************/
string hex_to_binary(string hex)
{
    string result;
    int length = hex.length();
    string byte;
    for(int i=0; i<length; i++)
    {
        int curr_value = 0;
        if(hex[i] >= 'A' && hex[i] <= 'F')
            curr_value = hex_changer_to_int(hex[i]);
        else
            curr_value = hex[i] - '0';
        string temp_bit;
        decimal_converter(curr_value,2,temp_bit);
        result = result + temp_bit;
        temp_bit.clear();
    }
    return result;
}
/****************************************************************
*
* string twos_complement(string orgnl)
*________________________________________________________________
* This function will convert a binary value that starts with 1 into
* its two's complement.
*_______________________________________________________________
* PRE-CONDITIONS
*   The following need previously defined values:
*       orgnl: the original binary number
*
* POST-CONDITIONS
*   This will convert a binary number into its two's complement
*****************************************************************/
// 2's complement conversions
string twos_complement(string orgnl)
{
   string two_complenet;
   for(int i = 0; i< orgnl.length(); i++)
   {
       if(orgnl[i] == '1')
           two_complenet = two_complenet + '0';
       else
           two_complenet = two_complenet + '1';
   }

   //to add one to the two complement
   //three cases 1 + 1 = 0 carry 1, 1 + 0 = 1
   int remainder = 0;
   int sum;
   int curr_value;
   for(int i = 0; i < orgnl.length(); i++)
   {

       curr_value = two_complenet[orgnl.length()-i-1] - '0';
       if(i == 0)
           sum = remainder + curr_value +1;
       else
           sum = remainder + curr_value;

       if(sum == 2)//means 0 with carry of 1
       {
           two_complenet[orgnl.length()-i-1] = '0';
           remainder = 1;
       }
       if(sum == 1)
       {
           two_complenet[orgnl.length()-i-1] = '1';
           remainder = 0;

       }
       else
       {
           two_complenet[orgnl.length()-i-1] = '0';
           remainder = 0;
       }
   }

   cout << "two complement: " << two_complenet << endl;
   return two_complenet;

}

#endif // BASE_CONVERSIONS_H
