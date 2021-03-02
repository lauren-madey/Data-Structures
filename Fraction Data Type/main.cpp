#include <iostream>

class fraction {
public:
    int numer;
    int denom;
private:
    double val=numer/denom;
};

fraction fraction_create(int num, int dem){
    fraction n;
    n.numer=num;
    n.denom=dem;
    return n;
}

// subtract two fractions
fraction fraction_sub(fraction op1, fraction op2){
    fraction n;
    n.denom= op1.denom * op2.denom;
    n.numer=(op1.numer*op2.denom)-(op2.numer*op1.denom);
    return n;
};

// add two fractions
fraction fraction_add(fraction op1, fraction op2){
    fraction n;
    n.denom= op1.denom * op2.denom;
    n.numer=(op1.numer*op2.denom)+(op2.numer*op1.denom);
    return n;
};

// prints a fraction
void print(fraction f){
    std::cout<<f.numer<<"/"<<f.denom;
};

int main() {
    fraction fr1=fraction_create(1,2);
    fraction fr2=fraction_create(1,3);

    fraction s=fraction_sub(fr1, fr2);
    print(fr1);
    std::cout<<" "<<"-"<<" "; //change the "-" to "+" when performing addition
    print(fr2);
    std::cout<<std::endl<<"="<<" ";
    print(s);

    return 0;
}
