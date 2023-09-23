/*
* 파일이름 : AccountArray.cpp
* 업데이트 정보 : 0.8
*/

#include "BankingCommonDecl.h"
#include "AccountArray.h"

BoundCheckAccuntPtrArray::BoundCheckAccuntPtrArray(int len) : arrlen(len)
{
	arr = new ACCOUNT_PTR[len];
}

ACCOUNT_PTR& BoundCheckAccuntPtrArray::operator[](int idx)
{
	if (idx < 0 || idx >= arrlen) {
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

ACCOUNT_PTR BoundCheckAccuntPtrArray::operator[](int idx) const
{
	if (idx < 0 || idx >= arrlen) {
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

int BoundCheckAccuntPtrArray::GetArrLen() const
{
	return arrlen;
}

BoundCheckAccuntPtrArray::~BoundCheckAccuntPtrArray()
{
	delete[]arr;
}
