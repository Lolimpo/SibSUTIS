#include <iostream>
#include <map>
#include <limits>
#include <typeinfo>
#include <set>

#include "TMemory.h"
#include "TFrac.h"
#include "TComplex.h"
#include "TPNumber.h"
#include "TFracEditor.h"
#include "TComplexEditor.h"
#include "TPNumEditor.h"
#include "TProc.h"
#include "TPoly.h"
#include "TMonomial.h"
#include "TSet.h"

using namespace std;

int main()
{
	//cout << "TFrac:" << endl;
	//TFrac test("5/2");
	//TFrac test2("14/76");
	//cout << "First fraction: " << test.getFractionString() << endl;
	//cout << "Second fraction: " << test2.getFractionString() << endl;
	//cout << "Sum result: " << test.add(test2).getFractionString() << endl;
	//cout << "Subtract result: " << test.subtract(test2).getFractionString() << endl;
	//cout << "Multiply result: " << test.multiply(test2).getFractionString() << endl;
	//cout << "Divide result: " << test.divide(test2).getFractionString() << endl;
	//
	//cout << "\nTComplex:" << endl;
	//TComplex a5(5, 4);
	//TComplex b5("2+i*1");
	//cout << "First complex: " << a5.getComplexStr() << endl;
	//cout << "Second complex: " << b5.getComplexStr() << endl;
	//cout << "Sum result: " << a5.add(b5).getComplexStr() << endl;
	//cout << "Subtract result: " << a5.subtract(b5).getComplexStr() << endl;
	//cout << "Multiply result: " << a5.multiply(b5).getComplexStr() << endl;
	//cout << "Divide result: " << a5.divide(b5).getComplexStr() << endl;

	//cout << "\nTPNumber:" << endl;
	//TPNumber number(-335.228, 16, 3);
	//cout << number.getNumberString() << endl;

	//cout << "\nTFracEditor:" << endl;
	//TFracEditor fracEditor;
	//cout << "init: " << fracEditor.getFraction() << endl;
	//fracEditor.editFraction(Operations::ADD_DIGIT);
	//cout << "Add Number: " << fracEditor.getFraction() << endl;
	//fracEditor.editFraction(Operations::ADD_DIVIDER);
	//cout << "Add divider: " << fracEditor.getFraction() << endl;
	//fracEditor.editFraction(Operations::ADD_SIGN);
	//cout << "Add sign: " << fracEditor.getFraction() << endl;
	//fracEditor.editFraction(Operations::ADD_DIGIT);
	//cout << "Add Number: " << fracEditor.getFraction() << endl;
	//fracEditor.editFraction(Operations::REMOVE_LAST_DIGIT);
	//cout << "Remove digit: " << fracEditor.getFraction() << endl;

	//cout << "\nTPNumEditor:" << endl;
	//TPNumEditor pNumEditor;
	//cout << "init: " << pNumEditor.getNumberString() << endl;
	//pNumEditor.menu(_addDigit);
	//cout << "add digit: " << pNumEditor.getNumberString() << endl; // int 0-15
	//pNumEditor.menu(_addDigit);
	//cout << "add digit: " << pNumEditor.getNumberString() << endl; // int 0-15
	//pNumEditor.menu(_backspace);
	//cout << "backspace: " << pNumEditor.getNumberString() << endl;
	//pNumEditor.menu(_editNumber);
	//cout << "editNumber: " << pNumEditor.getNumberString() << endl; // 10 or greater than 10
	
	/*cout << "\nTMemory" << endl;
	TFrac a(1, 2);
	TMemory<TFrac> b(a);
	b.add(a);
	cout << "Add: " << b.get().getFractionString() << endl;
	b.write(TFrac(5, 6));
	cout << "Write: " << b.get().getFractionString() << endl;
	cout << "State: " << b.readFState() << endl;
	b.clear();
	cout << "Clear: " << b.readFState() << endl;
	cout << "State: " << b.readFState() << endl;*/

	/*cout << "\nTProc" << endl;
	TFrac tfrac1(1, 2);
	TProc<TFrac> tproc1(tfrac1, tfrac1);
	cout << "Answer: " << tproc1.readLeft().getFractionString() << endl;
	tproc1.writeOper(TOperations::Sub);
	tproc1.doOper();
	tproc1.doOper();
	cout << "Answer: " << tproc1.readLeft().getFractionString() << endl;*/

	/*cout << "\nTMonomial" << endl;
	TMonomial monomial(3, 1);
	cout << monomial.monomialToString() << ", x=2 : " << monomial.compute(2.0) << endl;
	TMonomial mon1 = monomial.differentiate();
	cout << mon1.monomialToString() << endl;
	
	cout << "\nTPoly" << endl;
	TPoly aa(5, 4);
	TPoly bb(2, 4);
	TPoly cc;
	cc = aa * bb;
	cout << aa[0].monomialToString() << " * " << bb[0].monomialToString() << " = " << cc[0].monomialToString() << endl;
	TPoly c1 = cc.differentiate();
	cout << "DIF: " << c1[0].monomialToString() << endl;
	cout << c1[0].monomialToString() << ", x=1 : " << c1.compute(1.0);*/

	//cout << "TComplexEditor:" << endl;
	//TComplexEditor a;
	//cout << "Init: "<< a.getComplexString() << endl;
	//cout << "isZero: " << a.isZero() << endl;
	//a.addNumber(-15);
	//cout << "Add Number 5: " << a.getComplexString() << endl;
	//a.setComplexString("6-i*15");
	//cout << "setComplexString 6-i*15: " << a.getComplexString() << endl;
	//a.addSign();
	//cout << "Add sign: " << a.getComplexString() << endl;

	TSet<int> a;
	a.insert_(1);
	a.insert_(2);
	a.insert_(3);

	TSet<int> b;
	b.insert_(1);
	b.insert_(2);
	b.insert_(4);

	cout << "size of a = " << a.count() << endl;
	cout << "2nd element of a = " << a.element(2) << endl;
	cout << "union: " << a.add(b).count() << endl;
	cout << "subtract: " << a.subtract(b).count() << endl;
	cout << "multiply: " << a.multiply(b).count() << endl;
	a.del(2);
	cout << "delete: " << a.count() << endl;

	return 0;
}