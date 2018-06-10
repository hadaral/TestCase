#pragma once
#include <iostream>
using namespace std;

class TestCase{
    public:
        string msg;
        ostream os;
        int failed, passed, total;

        TestCase (string nameOfCheck , ostream& os):failed(0),passed(0),total(0){
            msg = nameOfCheck;
            this->os = os;
        }

        template <typename T> ‫‪check_equal ‬‬(T x, T y){
            total ++;
            if (x==y){
                passed ++;
            }
            else{
                failed ++;
                os << nameOfCheck << " Failure in test #" << total << ":" << x << " should equal " << y << "!" << endl; 
            }
            return *this;
        }

        template <typename T> ‫‪check_‫‪different‬‬ (T x, T y){
            total++;
            if (x!=y){
                passed ++;
            }
            else{
                os << nameOfCheck << " Failure in test #" << total << ":" << x << " should different " << y << "!" <<endl; 
                failed ++;
            }
            return *this;
        }
        
        template <typename T> ‫‪check_‫‪function (void* func, T x, T y){
            total ++;
            if (func(x) == y){
                passed ++;
            }
            else{
                failed ++;
                os << nameOfCheck << " Failure in test #" << total << ": Function should return " << y << " but returned " << func(x) << "!" <<endl; 

            }
            return *this;
        }

        


};