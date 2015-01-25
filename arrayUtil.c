#include <stdio.h>
#include <stdlib.h>
#include "arrayUtil.h"

	
int isEven(void* a, void *b){
	return ( *(int*)a % *(int*)b == 0);
}
int isCapital(void *item, void *hint) {
    return (*(char *)item >=65) && (*(char *)item <= 90);
}
void intAddOperation(void* hint, void* item) {
	*(int*)item = *(int*)hint + *(int *)item;	
}
void intConvertFunc(void* hint, void* sourceItem, void* destinationItem){
	*(int *)destinationItem = *(int *)hint + *(int *)sourceItem;
}
void charConvertFunc(void* hint, void* sourceItem, void* destinationItem){
	*(char*)destinationItem = *(char*)sourceItem - 32;
}
int isLessThanTheHints(void* element,void* hint){
    return (*(float*)element) < (*(float*)hint);
}
int isBiggerStringThan(void *str, void *hint){
	return (strlen((char*)str) > 5);
}
int isLessThan(void* element,void* hint){
    return (*(double*)element < *(double*)hint);
}
int isEqual(void *item, void *hint){
	return (*(double*)item == *(double*)hint);
}
int isGreaterThan(void *a, void *b){
	return *(float*)a > *(float*)b;
}



int areEqual(ArrayUtil au1, ArrayUtil au2){
	int i;
	char *a1 = (char*)au1.base,  *a2 = (char*)au2.base;
	if (au1.length != au2.length || au1.typeSize != au2.typeSize) return 0;

	for(i=0; i<au1.length*au1.typeSize; i++)
		if(a1[i] != a2[i]) return 0;
	return 1;
}

ArrayUtil create(int typeSize, int length){
	return (ArrayUtil){(void*)calloc(length, typeSize), typeSize, length};
}


ArrayUtil resize(ArrayUtil array, int length){
	int i, limit;
	ArrayUtil new_array = {calloc(length, array.typeSize), array.typeSize, length} ;
	limit = (array.length < length) ? array.length : length;

	for(i=0; i < limit*array.typeSize; i++)
		((char*)new_array.base)[i] = ((char*)array.base)[i];
	return new_array;
}

int findIndex(ArrayUtil util, void *element){
	int i, index=-1, match=0;
	char *item = (char*)element;
	char *base = (char*)util.base;

	for(i=0; i<util.length*util.typeSize; i++){
		(match > 0 && item[match] != base[i]) && (match = 0);
		(item[match] == base[i]) && match++;
		(match == util.typeSize) && (index = i/util.typeSize);
	}
	return index;
}

void dispose(ArrayUtil util){
	free(util.base);
	util.length=0;
	util.typeSize=0;
}

int isDivisible(void *a, void *hint){
	return (float)(*(int*)a % *(int*)hint) == 0;
}

void *findFirst(ArrayUtil util, int_void_void match, void *hint){
	int i, j;
	char *base = (char*)util.base;
	char *item = (char*)malloc(util.typeSize);
	for(i=0; i<util.length; i++){
		for(j=0; j<util.typeSize; j++){
			item[j] = base[i * util.typeSize + j];
		}
		if(match(item, hint)) return item;
	}
	return NULL;
}

void *findLast(ArrayUtil util, int_void_void match, void *hint){
	int i, j;
	char *base = (char*)util.base;
	char *item = (char*)malloc(util.typeSize);
	for(i=util.length-1; i>=0; i--){

		for(j=util.typeSize-1; j>=0; j--){
			item[j] = base[i * util.typeSize + j];
		}
		if(match(item, hint)==1) return item;
	}
	return NULL;
}

// int count(ArrayUtil util, int_void_void match, void *hint){
// 	int i, count=0, *base = (int*)util.base;
// 	for(i=0; i<util.length; i++)
// 		(match((void*)&base[i], hint)) && count++;
// 	return count;
// }

int count(ArrayUtil util, int_void_void match, void *hint){
	int i, j, count=0;
	char *base = (char*)util.base;
	char *item = (char*)malloc(util.typeSize);
	for(i=util.length-1; i>=0; i--){
		for(j=util.typeSize-1; j>=0; j--){
			item[j] = base[i * util.typeSize + j];
		}
		(match(item, hint)) && count++;
	}
	return count;
}
