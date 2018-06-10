#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <sstream>
using namespace std;

class TestCase{
    public:
        string msg;
        ostream& out;

        int failed, passed, total;

        TestCase (string nameOfCheck , ostream& os): out(os),failed(0),passed(0),total(0){
            msg = nameOfCheck;
        }

        template <typename T> void check_equal(T x, T y){
            total ++;
            if (x==y){
                passed ++;
            }
            else{
                failed ++;
                out << msg << " Failure in test #" << total << ":" << x << " should equal " << y << "!" << endl;
            }
            // return *this;
        }

        template <typename T> void check_different(T x, T y){
            total++;
            if (x!=y){
                passed ++;
            }
            else{
                out << msg << " Failure in test #" << total << ":" << x << " should different " << y << "!" <<endl; 
                failed ++;
            }
            // return *this;
        }
        
        template <typename T, typename Fun> void check_function (Fun func, T x, int y){
            total ++;
            if (func(x) == y){
                passed ++;
            }
            else{
                failed ++;
                out << msg << " Failure in test #" << total << ": Function should return " << y << " but returned " << func(x) << "!" <<endl; 

            }
            // return *this;
        }

        template <typename T> void check_output( T a, string y){
            total++;
            ostringstream ss;
            ss<<a;
            if(ss.str()==y){
                passed++;
            }
            else{
                failed++;
                out << msg << " Failure in test #" << total << ": string value should be " << y << " but is " << ss.str() << endl;
            }
            // return *this;
        }


        void print(){
            out << msg << failed << " failed, " << passed << " passed, " << total << "total." << endl;
        }



};