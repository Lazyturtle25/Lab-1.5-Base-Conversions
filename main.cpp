/*
 * Author: Erick Espinoza
 * Project: Lab 1.5 Base Conversions
 * Purpose: To be able to convert an interger into the other bases of either
 *          binary,decimal, octal or hexadecimal.
 *
 */
#include <iostream>
#include <math.h>
#include "base_conversions.h"
using namespace std;


int main()
{

//when getting in input of binary if the value is over 256 then we must add four
//more bits each time.
//    string test_1;
//    string test_2;
//    string test_3;
//    int value = 234;
//    decimal_converter(value,2,test_1);
//    decimal_converter(value,8,test_2);
//    decimal_converter(value,16,test_3);
//    cout << "Starting value of: " << value << endl << endl;

//    cout << "Binary: " << test_1 << endl;
//    cout << "Octal: " << test_2 << endl;
//    cout << "Hex: " << test_3 << endl;

//    cout << "length of binary value: " << test_1.length() << endl;
//    int tst = binary_to_decimal(test_1);
//    cout << "binary to decimal: " << tst << endl;
//    int tst2 = octal_to_decimal(test_2);
//    cout << "octal to decimal: " << tst2 << endl;
//    int tst3 = hex_to_decimal(test_3);
//    cout << "hex to decimal: " << tst3 << endl;

//    cout << "binary to ocatal " << test_1 << endl;
//    cout << binary_to_octal(test_1) << endl;
//    cout << "binary to hex " << test_1 << endl;
//    cout << binary_to_hex(test_1) << endl;

//    cout << "octal to binary " << test_2 << endl;
//    cout << octal_to_binary(test_2) << endl;

//    cout << "hex to binary " << test_3 << endl;
//    cout << hex_to_binary(test_3) << endl;

//    cout << "binary's 2's complement: " << test_1 << endl;
//    cout << twos_complement(test_1) << endl;
//    cout << "---------------------------------------------------------" << endl;

   int answr;
   string integer;
   char cnt = 'y';
   while(cnt == 'y' or cnt == 'Y')
   {
    cout << "Please enter the base you are are entering" << endl;
    cout << "1 for decimal, 2 for binary, 3 for octal, and 4 for hexadecimal." << endl;
    cin >> answr;

    cout << "Please enter the integer you wish to convert." << endl;
    cin >> integer;
    switch (answr)
    {
     case 1://decimal
    {
        cout << "You entered: " << integer << endl;
        cout << "converting to binary, octal, and hexadecimal." << endl;
        int decimal = stoi(integer);
        string binry;
        decimal_converter(decimal,2,binry);

        byte_length_check(binry);
        cout << "Binary: " << binry << endl;
        cout << "Octal: " << binary_to_octal(binry) << endl;
        cout << "Hex: " << binary_to_hex(binry) << endl << endl;

        break;
    }
    case 2://binary
    {
        cout << "You entered: " << integer << endl;
        cout << "converting to decimal, octal, and hexadecimal." << endl;
        byte_length_check(integer);
        binary_to_decimal(integer);


        cout << "Decimal: " << binary_to_decimal(integer) << endl;
        if(integer[0] == '1')
        {
            string twos = twos_complement(integer);

            cout << "Negative number version: -" <<binary_to_decimal(twos) << endl;
        }
        cout << "Octal: " << binary_to_octal(integer) << endl;
        cout << "Hex: " << binary_to_hex(integer) << endl << endl;

        break;
    }
    case 3://octal
    {
        cout << "You entered: " << integer << endl;
        cout << "converting to decimal, binary, and hexadecimal." << endl;



        string bnry = octal_to_binary(integer);
        byte_length_check(bnry);
        cout << "Decimal: " << binary_to_decimal(bnry) << endl;
        cout << "binary: " << bnry << endl;
        if(bnry[0] == '1')
        {
            string twos = twos_complement(bnry);

            cout << "Negative number version: -" <<binary_to_decimal(twos) << endl;
        }
        cout << "Hex: " << binary_to_hex(bnry) << endl << endl;

        break;
    }
    case 4://hex
    {
        cout << "You entered: " << integer << endl;
        cout << "converting to decimal, binary, and octal." << endl << endl;



        string bnry = hex_to_binary(integer);
        byte_length_check(bnry);
        cout << "Decimal: " << binary_to_decimal(bnry) << endl;
        cout << "Binary: " << bnry << endl;
        if(bnry[0] == '1')
        {
            string twos = twos_complement(bnry);

            cout << "Negative number version: -" <<binary_to_decimal(twos) << endl;
        }
        cout << "Octal: " << binary_to_octal(bnry) << endl << endl;
        break;
    }
    }
    cout << "Continue conversions? (Y/N)" << endl;
    cin >> cnt;
   }





    return 0;
}
