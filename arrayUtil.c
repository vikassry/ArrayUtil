#include <stdio.h>
#include <stdlib.h>
#include "arrayUtil.h"


int isDivisible(void *a, void *hint){
	return (float)(*(int*)a % *(int*)hint) == 0;
}
int isEven(void* a, void *b){
	return ( *(int*)a % 2 == 0);
}
int isCapital(void *item, void *hint) {
    return (*(char *)item >=65) && (*(char *)item <= 90);
}
void addDoubleHint(void* hint, void* src, void *dst) {
	*(double*)dst = *(double*)hint + *(double *)src;	
}
void increment(void* hint, void* src, void* dst){
	*(int *)dst = 1 + *(int *)src;
}
void Inc(void* hint, void* src, void* dst){
	*(float *)dst = 1 + *(float *)src;
}
void square_elements(void *hint, void *sourceItem, void *destinationItem){
	*(int*)destinationItem=*(int*)sourceItem * *(int*)sourceItem;
}
void toUpperCase(void* hint, void* sourceItem, void* destinationItem){
	*(char*)destinationItem = *(char*)sourceItem - 32;
}
void multiplyBy(void* hint, void* sourceItem, void* destinationItem){
    *(int*)destinationItem = *(int*)sourceItem * *(int*)(hint);
}
// void giveLength(void *hint, void *source, void *dest){
// 	printf("  %d\n", strlen(*(string *)source));
// 	*(int*)dest = strlen((*(string*)source));
// }
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
int compare(void *item,void* hint){
	return (*(char*)item=='a');
};
int stringCompare(void *item, void* hint){
	return(*(string*)item == *(string*)hint);
}



int areEqual(ArrayUtil au1, ArrayUtil au2){
	if (au1.length != au2.length || au1.typeSize != au2.typeSize)
		return 0;
	return (memcmp(au1.base, au2.base, au1.length*au1.typeSize)==0) ? 1 : 0;
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

int count(ArrayUtil util, int_void_void match, void *hint){
	int i, j, count=0;
	char *base = (char*)util.base;
	char *item = (char*)malloc(util.typeSize);
	for(i=0; i<util.length; i++){
		for(j=0; j<util.typeSize; j++){
			item[j] = base[i * util.typeSize + j];
		}
		(match(item, hint)) && count++;
	}
	return count;
}

int filter(ArrayUtil util, int_void_void predicate, void* hint, void** destination, int maxItems ){
	int i, j, k=0, count=0;
	char* dst = malloc(sizeof(char)*(maxItems*util.typeSize));
	char *base = (char*)util.base;
	char *item = (char*)malloc(util.typeSize);

	for(i=0; i<util.length; i++){
		for(j=0; j<util.typeSize; j++)
			item[j] = base[i * util.typeSize + j];
		if(predicate(item, hint) && count<maxItems){
			j=0;
			while(j<util.typeSize && k<util.typeSize*(count+1)){
 				dst[k] = item[j]; j++; k++;
			} count++;
		}
	}
	*destination = dst;
	return count;
}

void map(ArrayUtil source, ArrayUtil destination, void_3void convert, void* hint){
	int i;
	for(i=0; i < source.length*source.typeSize; i+=source.typeSize){
		convert(hint, &((char*)source.base)[i], &((char*)destination.base)[i]);
	}
}



// int filter(ArrayUtil util, int_void_void predicate, void* hint, void** destination, int maxItems ){
// 	int i, count=0;
// 	for(i=0; i < util.length*util.typeSize; i++){
// 		if(predicate(&(util.base)[i*util.typeSize],hint)){
// 			if(count == maxItems) return count;
// 			((float*)(*destination))[count] = ((float*)util.base)[i];
// 			count++;
// 		}
// 	}
// 	return count;
// }

	// // char *bs = (char*)malloc(sizeof(char) * source.typeSize);
	// // char *ds = (char*)malloc(sizeof(char) * source.typeSize);
	
	// // for(i=0; i<source.length; i++){
	// // 	for(j=0; j<source.typeSize; j++){
	// // 		bs[j] = ((char*)source.base)[i * source.typeSize + j];
	// // 		ds[j] = ((char*)destination.base)[i * source.typeSize + j];
	// // 	}
	// // 	convert(hint, bs, ds);
	// // 	for(j=0; j<source.typeSize; i++){
	// // 		if(k < source.length * source.typeSize){
	// // 			((char*)destination.base)[k] = ((char*)ds)[j];
	// // 			k++;
	// // 		}
	// // 	}
	// // }
	// 	printf("%d\n", ((int*)destination.base)[0] );
	// 	printf("%d\n", ((int*)destination.base)[1] );
	// 	printf("%d\n", ((int*)destination.base)[2] );
	// 	printf("%d\n", ((int*)destination.base)[3] );