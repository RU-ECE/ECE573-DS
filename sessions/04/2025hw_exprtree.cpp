#include <iostream>
#include <cmath>
using namespace std;

const double NaN = 0.0 / 0.0;

class Expr {
public:
    virtual double eval() const = 0; // compute the value (NaN if undefined)
    virtual void print() const = 0; // print the expression INORDER
    virtual void simplify(); // rewrite the expression as efficiently as possible
    friend ostream& operator <<(ostream& s, const Expr& e) { 
        e.print();
    }
};

class BinOp : public Expr {
protected:
    Expr* a;
    Expr* b;
public:
    BinOp(Expr* a, Expr* b) : a(a), b(b) {}
};

class UnOp : public Expr {

};

class Add : BinOp {
public:
    double eval() const override {
        return a->eval() + b->eval();
    }
    void print() const override {
        a->print();
        cout << " + ";
        b->print();
    }
};

class Const : public Expr {
private:
    double val;
public:
    Const(double val) : val(val) {}
};

class Var : public Expr {
private:
    string name;
    double val;
public:
    Var(const string& name, double val = NaN) : name(name), val(val) {}
};


/*
    const + const ==> const         ex: 3 + 4  ==> 7
    const - const ==> const
    x - x   ==> 0
    x * 1   ==> x
    x * 0   ==> 0
    x + 0   ==> x
    x - 0   ==> x


    x*2 + x*3 ==> x*5
*/

int main() {
    Expr* e1 = new Const(5.0);
    cout << e1->eval() << endl;
    cout << *e1;

    Expr* e2 = new Sub(new Var("x"), new Var("x")); // x - x
    cout << e2->eval() << endl;
    cout << *e2;    "x - x"     x x -        -x x

    Expr* e3 = new Add(new Const(3.0), new Const(4)); // 3 + 4
    cout << e3->eval() << endl;
    cout << *e3;

    Expr* e4 = e3->simplify(); // new Const(7);
    cout << e4->eval() << endl;
    cout << *e4;

    Expr* e5 = new Add(
        new Mul(new Const(2), new Var("x")), 
        new Mul(new Var("x"), new Const(3))
        ); // 2 * x  + x*3  = 5x
    cout << e5->eval() << endl;
    cout << *e5;

    Expr* e6 = new Add(
        new Add(
        new Mul(new Const(2), new Var("x")), 
        new Mul(new Var("x"), new Const(3))
        ),
        new Add(
            new Mul(new Const(3), new Var("y")),
            new Mul(new Const(4), new Var("x")),
        )
    );  // 2 * x  + x*3 + 3y + 4x = 9x + 3y
    cout << e6->eval() << endl;
    cout << *e6;
}