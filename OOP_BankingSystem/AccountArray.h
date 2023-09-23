/*
* 파일이름 : AccountArray.h
* 업데이트 정보 : 0.8
*/

#ifndef __ACCOUN_ARRAY_H__
#define __ACCOUN_ARRAY_H__

#include "Account.h"
typedef Account* ACCOUNT_PTR;
class BoundCheckAccuntPtrArray {
private:
	ACCOUNT_PTR* arr;
	int arrlen;
	BoundCheckAccuntPtrArray(const BoundCheckAccuntPtrArray& arr) {}
	BoundCheckAccuntPtrArray& operator = (const BoundCheckAccuntPtrArray& arr) { }

public:
	BoundCheckAccuntPtrArray(int len = 100);
	ACCOUNT_PTR& operator[] (int idx);
	ACCOUNT_PTR operator[] (int idx) const;
	int GetArrLen() const;
	~BoundCheckAccuntPtrArray();
};

#endif // !__ACCOUN_ARRAY_H__
