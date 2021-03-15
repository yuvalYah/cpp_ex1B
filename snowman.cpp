#include <iostream>
#include <string>

#include "snowman.hpp"
#include <array>
#include <stdexcept>
using namespace std;

const int MinNumber=11111111;
const int MaxNumber=44444444;
const int LenOfNum = 8;
const int ten =10;
const int five = 5;
const int six = 6;
const int seven = 7;

class argument_must_be_positive {};


namespace ariel {
    /*
    this strings function how return string in difrent parts in the snowman
    in place 1 -->hat , place 2 -->nose/mouth ...place 8 -->base
    */
    string hat(int x) //1
    {
        if(x==1){ return "      \n _===_ \n";}

        if(x==2) {return "  ___  \n ..... \n";}
        
        if(x==3) {return "   _   \n  /_\\  \n";}
        
        if(x==4) {return "  ___  \n (_*_) \n"; }

        return "";
        
    }
    string nose_mouth(int x)//2
    {
        if(x==1) {return ",";}

        if(x==2){ return ".";}
        
        if(x==3) {return "_";}

        if(x==4){return " ";}

        return "";
    }
    string Leye(int x)//3
    {
        if(x==1) {return ".";}

        if(x==2) {return "o";}
        
        if(x==3) {return "O";}

        if(x==4){return "-";}

        return "";
    }

    string Reye(int x)//4
    {
        if(x==1) {return ".";}

        if(x==2) {return "o";}
        
        if(x==3) {return "O";}

        if(x==4) {return "-";}

        return "";
    }

    string Lhend(int x)//5
    {
        if(x==1) {return "<";}

        if(x==2) {return "\\";}
        
        if(x==3) {return "/";}

        if(x==4) {return " ";}
        
        return "";
    }
    string Rhend(int x)//6
    {
        if(x==1) {return ">";}

        if(x==2) {return "/";}
        
        if(x==3) {return "\\";}

        if(x==4){return " ";}

        return "";
    }

    string torso(int x)//7
    {
        if(x==1) {return " : ";}

        if(x==2) {return "] [";}
        
        if(x==3) {return "> <";}

        if(x==4){ return "   ";}
    
        return "";
    }
    string base(int x)//8
    {
        if(x==1) {return " : ";}

        if(x==2) {return "\" \"";}
        
        if(x==3) {return"___";}

        if(x==4){ return "   ";}
    
        return "";
    }
    /* this function help me to discover if ther is hand up, and if there is : Which hand..
    if there is some hands up -so the print shuld be next to the face of the snowman else next to torso
    */
    bool hendsUp(int x , int y){
        return x == y && x == 2;
    }
    bool LhendUp(int x , int y){
        return x == 2 && y != 2 ;
    }
    bool RhendUp(int x , int y){
        return x !=2 && y == 2;
    }
    bool hendsdown(int x , int y){
        return x != 2 && y != 2;
    }

    //main functin of the snowman
    string snowman(int x){
    	if(x < 0) {throw argument_must_be_positive{};}
        if(x< MinNumber || x>MaxNumber) {throw std::out_of_range{"x must be in length 8!"};}

        std::string s = " ";
        std::array<int,LenOfNum> arr={};

        for(int i = LenOfNum-1 ; i >= 0 ; i--)
        {
            int j = x % ten;
            if(j>4 || j < 1) {throw std::out_of_range{"The number must to be in range 1-4!"};}
            arr.at(i) = j;
            x = x / ten;
        }
        s+= hat(arr.at(0));
        // this if else loop for to add to the string the Right string
        if(hendsUp(arr.at(4),arr.at(five))){
            s+= Lhend(arr.at(4)) + "("+Leye(arr.at(2))+nose_mouth(arr.at(1))+Reye(arr.at(3))+")"+Rhend(arr.at(five))+"\n ("+torso(arr.at(six))+") \n";
        }
        else if(LhendUp(arr.at(4),arr.at(five))){
            s+= Lhend(arr.at(4)) + "("+Leye(arr.at(2))+nose_mouth(arr.at(1))+Reye(arr.at(3))+") \n (" + torso(arr.at(six))+")"+Rhend(arr.at(five))+"\n";
        }
        else if(RhendUp(arr.at(4),arr.at(five))){
            s+= " ("+Leye(arr.at(2))+nose_mouth(arr.at(1))+Reye(arr.at(3))+")"+Rhend(arr.at(five))+"\n" +Lhend(arr.at(4))+"("+torso(arr.at(six))+") \n";

        }
        else{
            s+= " (" + Leye(arr.at(2)) + nose_mouth(arr.at(1)) + Reye(arr.at(3)) + ") \n"+Lhend(arr.at(4))+ "(" +torso(arr.at(six))+")"+Rhend(arr.at(five))+"\n";

        }
        s+=" ("+base(arr.at(seven))+") \n";
        return s;
    }

}
