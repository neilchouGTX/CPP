#include <iostream>  
#include <string>  
 
using namespace std;  
class HugeInt  
{  
   friend ostream &operator<<(ostream &, const HugeInt &);  
   friend istream &operator>>(istream &, HugeInt &);  
 
public:  
   static const int digits = 40; // maximum digits in a HugeInt  
 
   //助教:constructor prototype  
   HugeInt(long = 0); // conversion/default constructor  
 
   //助教:constructor prototype  
   HugeInt(const string &); // conversion constructor  
 
   // addition operator; HugeInt + HugeInt  
   //助教:+的operator overloading,與class HugeInt和class HugeInt有關的  
   HugeInt operator+(const HugeInt &) const;  
   HugeInt operator-(const HugeInt &) const;  
 
   // addition operator; HugeInt + int,助教:+的operator overloading,與class HugeInt和int有關的  
   HugeInt operator+(int) const;  
   HugeInt operator-(int) const;  
 
   // addition operator;  
   // HugeInt + string that represents large integer value,助教:+的operator overloading,與class HugeInt和string有關的  
   HugeInt operator+(const string &) const;  
   HugeInt operator-(const string &) const;  
 
   void output_h() {  
 
       cout << integer[0] << endl;  
   }  
 
private:  
   short integer[digits];  
 
};  
 
// 助教:constructor  
HugeInt::HugeInt(long value)  
{  
   // initialize array to zero  
   for (int i = 0; i < digits; ++i)  
   {  
       integer[i] = 0;  
   }  
 
   // place digits of argument into array  
   for (int j = digits - 1; value != 0 && j >= 0; --j)  
   {  
       integer[j] = value % 10;  
       value = value / 10;  
   }   // end for  
 
}   // end HugeInt default/conversion constructor  
 
// conversion constructor that converts a character string  
// representing a large integer into a HugeInt object  
// 助教:constructor  
HugeInt::HugeInt(const string &number)  
{  
   // initialize array to zero  
   for (int i = 0; i < digits; ++i)  
   {  
       integer[i] = 0;  
   }  
 
   int length = number.size();  
 
   // place digits of argument into array  
   for (int j = digits - length, k = 0; j < digits; ++j, ++k)  
   {  
       if (isdigit(number[k]))  
       {  
           integer[j] = number[k] - '0';  
       }  
   }   // ensure that character is a digit  
 
 
}   // end HugeInt conversion constructor  
 
 
// addition operator; HugeInt + HugeInt  
// 助教:+的operator overloading,與class HugeInt和class HugeInt有關的  
HugeInt HugeInt::operator+(const HugeInt &op2) const  
{  
   HugeInt temp; // temporary result  
 
   int carry = 0;  
 
   for (int i = digits - 1; i >= 0; i--)  
   {  
       // determine whether to carry a 1  
       temp.integer[i] = integer[i] + op2.integer[i] + carry; //相加後 = 數字1 + 數字2 + 進位數.  
 
       if (temp.integer[i] > 9)  
       {  
           temp.integer[i] = temp.integer[i] % 10;  
           carry = 1;  
       }  
       else  
       {  
           carry = 0;  
       }   // no carry  
 
   }   // end for  
 
   return temp;    // return copy of temporary object  
 
}   // end function operator+  
 
// addition operator; HugeInt + int  
//助教:+的operator overloading,與class HugeInt和Int有關的  
HugeInt HugeInt::operator+(int op2) const  
{  
   // convert op2 to a HugeInt, then invoke  
   // operator+ for two HugeInt objects  
   return *this + HugeInt(op2);  
 
} // end function operator+  
 
// addition operator;  
// HugeInt + string that represents large integer value  
//助教:+的operator overloading,與class HugeInt和string有關的  
HugeInt HugeInt::operator+(const string &op2) const  
{  
   // convert op2 to a HugeInt, then invoke  
   // operator+ for two HugeInt objects  
   return *this + HugeInt(op2);  
} // end operator+  
 
 
HugeInt HugeInt::operator-(const HugeInt &minus) const  
{  
   HugeInt temp1, borrow; // temporary result  
 
   for (int i = 0; i <= digits - 1; ++i)  
   {  
       borrow.integer[i] = integer[i];  
   }  
 
   for (int i = digits - 1; i >= 0; --i)  
   {  
       temp1.integer[i] = borrow.integer[i] - minus.integer[i];  
 
       if (temp1.integer[i] < 0)  
       {  
           temp1.integer[i] = temp1.integer[i] + 10;  
           borrow.integer[i - 1] = borrow.integer[i - 1] - 1;  
       }  
   }   // end for  
 
   return temp1;   // return copy of temporary object  
 
}   // end function operator-  
 
HugeInt HugeInt::operator-(int minus) const  
{  
   return *this - HugeInt(minus);  
} // end function operator-  
 
HugeInt HugeInt::operator-(const string &minus) const  
{  
   return *this - HugeInt(minus);  
} // end operator-  
 
// overloaded output operator  
//輸出的operator overloading  
ostream& operator<<(ostream &output, const HugeInt &num)  
{  
   int i;  
 
   for (i = 0 ; ((num.integer[i] == 0) && (i <= HugeInt::digits - 1)); i++)  
   {  
       ;// skip leading zeros  
   }  
 
   if (i >= HugeInt::digits)  
   {  
       output << 0;  
   }  
   else  
   {  
       for (; i < HugeInt::digits; ++i)  
       {  
           output << num.integer[i];  
       }  
   }  
 
   return output;  
}  
int main()  
{  
   char symbol;  
   string number1,number2;  
 
   cin >> symbol;  
 
   while (true)  
   {  
       cin >> number1;  
 
       if (number1 == "-1")  
       {  
           break;  
       }  
 
       cin >> symbol;  
       cin >> number2;  
 
       if (number1 != "-1")  
       {  
           HugeInt no1(number1);  
           HugeInt no2(number2);  
           HugeInt resault;  
 
           if (symbol == '+')  
           {  
               resault = no1 + no2;  
           }  
 
           if(symbol == '-')  
           {  
               resault = no1 - no2;  
           }  
 
           cout << resault << endl;  
       }  
   }  
}  
