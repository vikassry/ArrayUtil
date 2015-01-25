#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arrayUtil.h"
#include "expr_assert.h"
typedef struct Student{
    int rollno;
    float age;
} student;

ArrayUtil arr1;
ArrayUtil arr2;


void test_areEqual_gives_1_when_two_int_ArrayUtils_are_equal(){
	arr1 = (ArrayUtil){(int[]){111111111,222222222,3333333333,444444444,555555555}, sizeof(int), 5};
	arr2 = (ArrayUtil){(int[]){111111111,222222222,3333333333,444444444,555555555}, sizeof(int), 5};

	assert(areEqual(arr1, arr2) == 1);
}

void test_areEqual_gives_0_when_two_int_ArrayUtils_elements_are_not_same(){
	arr1 = (ArrayUtil){(int[]){1011111,222222222,3333333333,444444444,555555555}, sizeof(int), 5};
	arr2 = (ArrayUtil){(int[]){111111111,222222222,3333333333,444444444,555555555}, sizeof(int), 5};

	assert(areEqual(arr1, arr2) == 0);
}

void test_areEqual_gives_1_when_two_char_ArrayUtils_are_equal(){
	char a[] = {'a','b','c','d','\0'}; char b[5];
	strcpy(b,a);
	arr1 = (ArrayUtil){a, sizeof(char),5};
	arr2 = (ArrayUtil){b, sizeof(char),5};

	assert(areEqual(arr1, arr2) == 1);
}

void test_areEqual_returns_0_if_two_char_array_are_not_equal(){
	char array1[] = {'a','a','c'};
	char array2[] = {'a','b','c'};
	ArrayUtil a1 = create(1,3);
	ArrayUtil a2 = create(1,3);
	a1.base = array1;
	a2.base = array2;
	assertEqual(areEqual(a1,a2),0);
}
void test_areEqual_gives_1_when_an_ArrayUtils_is_compared_with_itself(){
	char *a = "abcde";
	arr1 = (ArrayUtil){a, sizeof(char),5};
	arr2 = (ArrayUtil){a, sizeof(char),5};

	assert(areEqual(arr1, arr1) == 1);
}

void test_areEqual_gives_0_when_two_ArrayUtils_lenght_not_equal(){
	arr1 = (ArrayUtil){(int[]){1,2,3,4,5}, sizeof(int), 5};
	arr2 = (ArrayUtil){(int[]){1,2,3}, sizeof(int), 3};

	assert(areEqual(arr1, arr2) == 0);
}

void test_areEqual_gives_0_when_two__ArrayUtils_typesize_is_unequal(){
	arr1 = (ArrayUtil){(float[]){1.5,2.2,3.2,4.5,5.3}, sizeof(float), 5};
	arr2 = (ArrayUtil){(double[]){1.5,2.2,3.2,4.5,5.3}, sizeof(double), 5};

	assert(areEqual(arr1, arr2) == 0);
}

void test_areEqual_gives_1_when_two_float_ArrayUtils_elements_are_similar(){
	arr1 = (ArrayUtil){(float[]){1.5,2.2,3.2,4.5,5.3}, sizeof(float), 5};
	arr2 = (ArrayUtil){(float[]){1.5,2.2,3.2,4.5,5.3}, sizeof(float), 5};

	assert(areEqual(arr1, arr2) == 1);
}

void test_areEqual_gives_0_when_two_float_ArrayUtils_elements_are_different(){
	arr1 = (ArrayUtil){(float[]){1.5,2.2,3.2,4.5,5.3}, sizeof(float), 5};
	arr2 = (ArrayUtil){(float[]){1.5,2.2,3.2,4.5,5.35}, sizeof(float), 5};

	assert(areEqual(arr1, arr2) == 0);
}

void test_areEqual_gives_1_when_two_double_ArrayUtils_are_equal(){
	arr1 = (ArrayUtil){(double[]){1.2, 2.25, 3.7, 10.8, 4.2}, sizeof(double), 5};
	arr2 = (ArrayUtil){(double[]){1.2, 2.25, 3.7, 10.8, 4.2}, sizeof(double), 5};

	assert(areEqual(arr1, arr2) == 1);
}

void test_areEqual_gives_1_when_two_double_ArrayUtils_are_unequal(){
	arr1 = (ArrayUtil){(double[]){1.25, 2.25, 3.7, 10.8, 4.2}, sizeof(double), 5};
	arr2 = (ArrayUtil){(double[]){1.2, 2.25, 3.7, 10.8, 4.2}, sizeof(double), 5};

	assert(areEqual(arr1, arr2) == 0);
}

void test_areEqual_gives_1_when_two_string_ArrayUtils_are_equal(){
	arr1 = (ArrayUtil){(char*[]){"hii","byee","","j","sssssssssssssss000000"}, sizeof(char*), 5};
	arr2 = (ArrayUtil){(char*[]){"hii","byee","","j","sssssssssssssss000000"}, sizeof(char*), 5};

	assert(areEqual(arr1, arr2) == 1);
}

void test_areEqual_gives_1_when_two_string_ArrayUtils_are_unequal(){
	arr1 = (ArrayUtil){(char*[]){"hii","byee","","j","sssssssssssssss000000"}, sizeof(char*), 5};
	arr2 = (ArrayUtil){(char*[]){"hii","byee","","jjj","sssssssssssssss000000"}, sizeof(char*), 5};

	assert(areEqual(arr1, arr2) == 0);
}


void test_ArrayUtil_create_creates_an_int_ArrayUtil_with_initial_value_0(){
	ArrayUtil array =  create(sizeof(int),3);
	arr1 = (ArrayUtil){(int[]){0,0,0}, 4, 3};

	assert(areEqual(array, arr1) == 1);
	dispose(array);
}

void test_ArrayUtil_create_creates_an_float_ArrayUtil_with_initial_value_0(){
	ArrayUtil array =  create(sizeof(float),3);
	assert(areEqual(array, (ArrayUtil){(float[]){0,0.0,0.0}, 4, 3}) == 1);
	dispose(array);
}

void test_ArrayUtil_create_creates_an_char_ArrayUtil_with_initial_value_slash_0(){
	ArrayUtil array =  create(sizeof(char),3);
	arr1 = (ArrayUtil){(char[]){'\0','\0','\0'}, 1,3};

	assert(areEqual(array, arr1) == 1);
	dispose(array);	
}

void test_create_returns_same_array_if_array_lengths_are_same_and_values_are_same() {
	arr1 = create(sizeof(int),2);
	arr2 = create(sizeof(int),2);
	assert(areEqual(arr1, arr2) == 1);
	dispose(arr1);  dispose(arr2);
}

void test_create_should_set_the_length_and_typeSize_fields_of_array_to_the_values_passed_to_create_function(){
	ArrayUtil a = create(1,3);
	assert(a.length == 3);
	assert(a.typeSize == 1);
	dispose(a);
}

void test_create_Structures_with_all_fields_NULL(){
    student temp = {0,0.0};
    student Student[1] = {temp};
    ArrayUtil expected = {Student,sizeof(student),1};
   	arr1 = create(sizeof(student),1);    
    assert(areEqual(expected,arr1) == 1);
    dispose(arr1);
};

void test_ArrayUtil_resizes_the_char_array_and_return_the_modified_array_upto_given_length_when_size_is_less_or_same(){
	arr1 = (ArrayUtil){(char[]){'a','b','c','d','e','\0'}, sizeof(char), 6};
	arr2 = resize(arr1,3);  

	assert(areEqual(arr2, (ArrayUtil){(char[]){'a','b','c'}, 1, 3}) == 1);
	dispose(arr2);
}

void test_ArrayUtil_resizes_the_char_array_and_return_the_modified_array_with_0_if_new_size_is_more(){
	arr1 = (ArrayUtil){(char[]){'a','b','\0'}, sizeof(char), 3};
	arr2 = resize(arr1,4);

	assert(areEqual(arr2, (ArrayUtil){(char[]){'a','b','\0','\0'},sizeof(char),4})==1);
	dispose(arr2);
}

void test_ArrayUtil_resizes_the_char256_array_and_return_the_modified_array_upto_given_length_when_size_is_less_or_same(){
	arr1 = (ArrayUtil){(char[256]){'a','b','c','d','e','\0'}, sizeof(char), 6};
	arr2 = resize(arr1,3);  

	assert(areEqual(arr2, (ArrayUtil){(char[]){'a','b','c'}, 1, 3}) == 1);
	dispose(arr2);
}

void test_ArrayUtil_resizes_the_char256_array_and_return_the_modified_array_with_0_if_new_size_is_more(){
	arr1 = (ArrayUtil){(char[256]){'a','b','\0'}, sizeof(char), 3};
	arr2 = resize(arr1,4);

	assert(areEqual(arr2, (ArrayUtil){(char[]){'a','b','\0','\0'},sizeof(char),4})==1);
	dispose(arr2);
}


void test_ArrayUtil_resizes_the_int_array_and_return_the_modified_array_with_extra_values_initialized_to_0(){
	arr1 = (ArrayUtil){(int[]){1,2,3}, sizeof(int), 3};
	arr2 = resize(arr1,5);

	assert(areEqual(arr2, (ArrayUtil){(int[]){1,2,3,0,0}, 4, 5})==1);
	dispose(arr2);
}

void test_ArrayUtil_resizes_the_int_array_and_return_the_trimmed_array_when_length_less_than_utilLength(){
	arr1 = (ArrayUtil){(int[]){1,2,3,4,5}, sizeof(int), 5};
	arr2 = resize(arr1,3);

	assert(areEqual(arr2, (ArrayUtil){(int[]){1,2,3}, 4, 3})==1);
	dispose(arr2);
}

void test_ArrayUtil_resizes_the_float_array_and_return_the_modified_array_with_0_if_new_size_is_more(){
	arr1 = (ArrayUtil){(float[]){1.0,2.0,3.0}, sizeof(float), 3};
	arr2 = resize(arr1,4);

	assert(areEqual(arr2, (ArrayUtil){(float[]){1.0,2.0,3.0,0.0}, 4,4})==1);
	dispose(arr2);
}

void test_ArrayUtil_resizes_the_float_array_and_return_the_trimmed_array(){
	arr1 = (ArrayUtil){(float[]){1.0,2.0,3.0,4.5}, sizeof(float), 4};
	arr2 = resize(arr1,2);

	assert(areEqual(arr2, (ArrayUtil){(float[]){1.0,2.0}, 4,2})==1);
	dispose(arr2);
}

void test_ArrayUtil_resizes_the_double_array_and_return_the_modified_array_with_0_if_new_size_is_more(){
	arr1 = (ArrayUtil){(double[]){1.0,2.0,3.0}, sizeof(double), 3};
	arr2 = resize(arr1,4);

	assert(areEqual(arr2, (ArrayUtil){(double[]){1.0,2.0,3.0,0}, 8, 4})==1);
	dispose(arr2);
}

void test_ArrayUtil_resizes_the_double_array_and_return_the_trimmed_array(){
	arr1 = (ArrayUtil){(double[]){1.0,2.0,3.0,4.5}, sizeof(double), 4};
	arr2 = resize(arr1,2);

	assert(areEqual(arr2, (ArrayUtil){(double[]){1.0,2.0}, 8, 2})==1);
	dispose(arr2);
}

void test_ArrayUtil_after_resize_the_arrays_are_not_equal_when_resizing_with_different_length(){
	arr1 = (ArrayUtil){(double[]){1.0,2.0,3.0,4.5}, sizeof(double), 4};
	arr2 = resize(arr1,2);

	assert(areEqual(arr2, arr1) == 0);
	dispose(arr2);
}

void test_ArrayUtil_after_resize_the_arrays_are_equal_when__resized_with_same_length(){
	arr1 = (ArrayUtil){(double[]){1.0,2.0,3.0,4.5}, sizeof(double), 4};
	arr2 = resize(arr1,4);

	assert(areEqual(arr1, arr2) == 1);
	dispose(arr2);
}

void test_ArrayUtil_resizes_the_string_array_and_return_the_trimmed_array(){
	arr1 = (ArrayUtil){(char*[]){"hiii","bye","viaks","ppppppp"}, sizeof(char*), 4};
	arr2 = resize(arr1,2);

	assert(areEqual(arr2, (ArrayUtil){(char*[]){"hiii","bye"}, 4, 2})==1);
	dispose(arr2);
}

void test_resize_returns_new_Array_util_with_string_array_of_new_length_by_putting_0s_in_new_created_spaces(){
    string array1[] = {"Mahesh","Kumar"}, array2[] = {"Mahesh","Kumar",0,0,0};
    ArrayUtil util1 = {array1,sizeof(char *),2};
    ArrayUtil util2 = {array2,sizeof(char *),5};
    assertEqual(areEqual(resize(util1, 5), util2), 1);
}

void test_findIndex_gives_4_for_5_in_ArrayUtil(){
	int x=5;
	arr1 = (ArrayUtil){(int[]){1,2,3,4,5}, sizeof(int), 5};

	assert(findIndex(arr1, &x)==4);
}

void test_findIndex_gives_minus_1_element_is_not_in_ArrayUtil(){
	int x=10;
	arr1 = (ArrayUtil){(int[]){1,2,3,4,5}, sizeof(int), 5};

	assert(findIndex(arr1, &x)== -1);
}

void test_findIndex_returns_1_if_the_search_char_is_found_on_1st_location (){
	char x = 'a';
	char *array = "cara";
	arr1 = create(1,3);
	arr1.base = (void*)array;
	assertEqual(findIndex(arr1,&x),1);
}

void test_findIndex_returns_minus_1_if_the_search_char_isnt_found_in_the_string(){
	char x = 'y';
	char *array = "cara";
	ArrayUtil util = create(1,3);
	util.base = (void*)array;
	assertEqual(findIndex(util,&x),-1);
}

void test_findIndex_gives_2_for_string_cd_in_ArrayUtil_string(){
	char *substr="bc";
	arr1 = (ArrayUtil){(char*)"abcde", sizeof(char), 6};

	assert(findIndex(arr1, substr)==1);
}

void test_findIndex_returns_1_if_the_search_char256_is_found_on_1st_location (){
	char x = 'a';
	char array[256] = "cara";
	arr1 = create(1,3);
	arr1.base = (void*)array;
	assertEqual(findIndex(arr1,&x),1);
}

void test_findIndex_returns_minus_1_if_the_search_char256_isnt_found_in_the_string(){
	int x = 'y';
	char array[256] = {'c','a','e','t','f','t','w'};
	ArrayUtil util = create(1,3);
	util.base = (void*)array;
	assertEqual(findIndex(util,&x),-1);
}


void test_findIndex_returns_index_of_the_String_element_where_it_presents(){
    string array1[] = {"Mahesh","Kumar","Kolla"};
    string element = "Kolla";
    arr1 = (ArrayUtil){array1,sizeof(string),3};
    assertEqual(findIndex(arr1, &element), 2);
}

void test_findIndex_returns_negative_1_if_the_String_element_is_not_present(){
    string array1[] = {"Mahesh","Kumar","Kolla"};
    string element = "KolA";
    arr1 = (ArrayUtil){array1,sizeof(string),3};
    assertEqual(findIndex(arr1,&element), -1);
}

void test_findIndex_returns_index_of_the_float_element_where_it_presents(){
    float array1[] = {1.1,2.2,3.3,4.4};
    float element = 4.4;
    ArrayUtil util1 = {array1,sizeof(float),4};
    assertEqual(findIndex(util1,&element), 3);
}

void test_findIndex_returns_minus_1_for_float_array_if_search_element_is_not_prsent(){
	float element = 78;
	arr1 = (ArrayUtil){(float[]){4.2,2.9,1.4,3.1,7.8,8.7},4,6};
	assertEqual(findIndex(arr1, &element), -1);
}

void test_findIndex_returns_index_of_the_double_element_where_it_presents(){
    double array1[] = {1.1,2.2,3.3,4.4};
    double element = 4.4;
    ArrayUtil util1 = {array1,sizeof(double),4};
    assertEqual(findIndex(util1,&element), 3);
}

void test_findIndex_returns_minus_1_of_the_double_element_where_it_presents(){
    double array1[] = {1.1,2.2,3.3,4.4};
    double element = 8.4;
    ArrayUtil util1 = {array1,sizeof(double),4};
    assertEqual(findIndex(util1,&element), -1);
}

void test_findIndex_retruns_the_index_of_an_element_in_an_string_array(){
    char array[]= {"heloo"};
    char element ='o';
    ArrayUtil util = {array,sizeof(char),4};
    assertEqual(findIndex(util,&element),3);
}

void test_dispose_method_free_the_memory_of_array_in_arrayUtil(){
	arr1 = (ArrayUtil){(int[]){1,2,3,4,5}, sizeof(int), 5};	
}

void test_findFirst_gives_first_matching_value_in_ontArray(){
	ArrayUtil util = {(int[]){3,4,5,6,78,9,7,0}, sizeof(int), 8};
	int_void_void match = &isDivisible;
	int divider = 3;
	int *result = findFirst(util, match, &divider);

	assert(*result == 3);
}

void test_findFirst_gives_0_if_matching_value_is_not_found_in_intArray(){
	ArrayUtil util = {(int[]){3,4,5,6,78,9,7,0}, sizeof(int), 8};
	int_void_void match = &isDivisible;
	int divider = 11;
	int *result = findFirst(util, match, &divider);

	assertEqual(*result, 0); 
	free(result);
}

void test_findFirst_gives_occurence_of_first_element_in_floatArray_greaterThan5(){
	float hint = 5.1,  *result;
	int_void_void match = &isGreaterThan;
	ArrayUtil util = {(float[]){3.1,2.4,1.6,6.4,3.7,8.3,0.1},sizeof(float),7};
	result = findFirst(util,match,(void*)&hint);
	assertEqual(*result, (float)6.3);
	free(result);
}

void test_findFirst_gives_0_when_element_in_floatArray_is_not_found(){
	float hint = 5.1; int result;
	int_void_void match = &isGreaterThan;
	arr1 = (ArrayUtil){(float[]){3.1,2.4,1.6,4.4,3.7,0.1},sizeof(float),6};
	
	assertEqual((int)findFirst(arr1,match,(void*)&hint), 0);
}

void test_findFirst_returns_the_char_of_the_char_array_that_is_capital(){
    char array1[] = {'k','M','k','O'};
    ArrayUtil util1 = {array1,sizeof(char),3};
    assertEqual(*(char *)(findFirst(util1,&isCapital,0)), 'M');
}

void test_findFirst_returns_0_when_element_in_the_char_array_that_is_not_capital(){
    char array1[] = {'k','m','k','l'};
    ArrayUtil util1 = {array1,sizeof(char),3};
    assertEqual((char)(findFirst(util1,&isCapital,0)), 0);
}

void test_findFirst_returns_the_char_of_the_char256_array_that_is_capital(){
    char array1[256] = {'k','M','k','O'};
    ArrayUtil util1 = {array1,sizeof(char),3};
    assertEqual(*(char *)(findFirst(util1,&isCapital,0)), 'M');
}

void test_findFirst_returns_0_when_element_in_the_char256_array_that_is_not_capital(){
    char array1[256] = {'k','m','k','l'};
    ArrayUtil util1 = {array1,sizeof(char),3};
    assertEqual((char)(findFirst(util1,&isCapital,0)), 0);
}


void test_findFirst_for_double_gives_first_number_if_matching_value_is_not_found(){
	ArrayUtil util = {(double[]){3.25,4.5,5.0,7.5,78.0,9.5,0.0}, sizeof(double),7};
	int_void_void match = &isEqual;
	double hint = 5.0;
	double *result = findFirst(util, match, &hint);

	assertEqual(*result, (double)5.0);
	free(result);
}

void test_findFirst_for_double_gives_0_if_matching_value_is_not_found(){
	ArrayUtil util = {(double[]){3.25,4.5,5.7,7.5,78.0,9.5,0.0}, sizeof(double),7};
	int_void_void match = &isEqual;
	double hint = 5.0;

	assertEqual((int)findFirst(util, match, &hint), 0);
}

void test_findLast_gives_last_matching_value_from_int_array(){
	ArrayUtil util = {(int[]){3,4,5,6,78,9,7,10}, sizeof(int), 8};
	int_void_void match = &isDivisible;
	int divider = 3;

	assert(*(int*)findLast(util, match, &divider) == 9);
}

void test_findLast_returns_null_if_there_is_no_match_in_integer_array(){
	ArrayUtil a = {(int[]){1,3,5,7,9},sizeof(int),5};
	int x = 2;
	assertEqual((int)findLast(a,isEven,&x),0);
}

void test_for_findLast_gives_the_last_element_of_less_than_float_value_an_float_Array(){
	ArrayUtil util = {(float[]){3.4,4.4,5.5,66.5,78,0.4}, sizeof(int), 6};
	int_void_void match = &isGreaterThan;
	float number = 11;
	float *result = (float*)findLast(util, match, &number);

	assertEqual(*result, (float)78);
}

void test_findLast_gives_0_if_matching_value_is_not_found_in_float_Array(){
    float hint = 6.3;
    float *result;
    int_void_void match = &isLessThanTheHints;
    ArrayUtil util = {(float[]){7.3,34.5,16.43,14.5,27.0},sizeof(float),5};

    assertEqual((int)findLast(util,&isLessThanTheHints,&hint),0);
};

void test_findLast_returns_the_last_element_if_there_is_match_in_character_array(){
	ArrayUtil a = {(char[]){'a','b','C','D','e'},sizeof(char),5};
	int x = 'D';
	assertEqual(*((char*)findLast(a,isCapital,&x)),'D');
}

void test_findLast_returns_0_if_there_is_no_match_in_character_array(){
	ArrayUtil a = {(char[]){'a','b','t','c','e'},sizeof(char),5};
	int x = 'D';
	assertEqual(((int)findLast(a,isCapital,&x)),0);
}

void test_findLast_returns_the_last_element_if_there_is_match_in_char256_array(){
	ArrayUtil a = {(char[256]){'a','b','C','D','e'},sizeof(char),5};
	int x = 'D';
	assertEqual(*((char*)findLast(a,isCapital,&x)),'D');
}

void test_findLast_returns_0_if_there_is_no_match_in_char256_array(){
	ArrayUtil a = {(char[256]){'a','b','t','c','e'},sizeof(char),5};
	int x = 'D';
	assertEqual(((int)findLast(a,isCapital,&x)),0);
}

void test_for_findLast_gives_the_last_element_of_less_than_double_value_an_float_Array(){
	ArrayUtil util = {(double[]){3.4,4.4,7.5,66.5,78}, sizeof(double), 5};
	int_void_void match = &isLessThan;
	double hint = 11.5;
	double *result = (double*)findLast(util, match, &hint);

	assertEqual(*result, (double)7.5);
}

void test_findLast_gives_0_if_matching_value_is_not_found_in_double_Array(){
    double hint = 11;
    double *result;
    int_void_void match = &isLessThan;
    ArrayUtil util = {(double[]){12.3,14.5,16.43,14.5,27.0}, sizeof(double),5};

    assertEqual((int)findLast(util, match, &hint),0);
};

// void test_findLast_gives_last_big_string_greater_than_given_hint_from_string_array(){
// 	int hint = 4;
// 	int_void_void predicate = &isBiggerStringThan;
// 	arr1 = (ArrayUtil){(string[]){"vikas","abcdefg","d","","hii"}, sizeof(string), 5};
// 	assert((string)findLast(arr1, predicate, &hint) == "abcdefg");
// }

void test_count_gives_the_number_of_matching_elements_from_int_array(){
	int hint = 12;
	int_void_void predicate = &isGreaterThan;
	arr1 = (ArrayUtil){(int[]){33,50,26,3,6,99,14}, sizeof(int), 7};

	assertEqual(count(arr1, predicate, &hint), 5);
}

void test_count_gives_0_when_no_matching_element_is_found_from_int_array(){
	int hint = 102;
	int_void_void predicate = &isGreaterThan;
	arr1 = (ArrayUtil){(int[]){33,50,26,3,6,99,14}, sizeof(int), 7};

	assertEqual(count(arr1, predicate, &hint), 0);
}

void test_count_gives_the_number_of_matching_elements_from_char_array(){
	int hint = 12;
	int_void_void predicate = &isCapital;
	arr1 = (ArrayUtil){(char[]){'A','a','b','D','I','p'}, sizeof(char), 6};

	assertEqual(count(arr1, predicate, &hint), 3);
}

void test_count_gives_0_when_no_matching_element_is_found_from_char_array(){
	int hint = 102;
	int_void_void predicate = &isCapital;
	arr1 = (ArrayUtil){(char[]){'f','a','c','e','b','o','0','k',}, sizeof(char), 7};

	assertEqual(count(arr1, predicate, &hint), 0);
}

void test_count_gives_the_number_of_matching_elements_from_char256_array(){
	int hint = 12;
	int_void_void predicate = &isCapital;
	arr1 = (ArrayUtil){(char[256]){'A','a','b','D','I','p'}, sizeof(char), 6};

	assertEqual(count(arr1, predicate, &hint), 3);
}

void test_count_gives_0_when_no_matching_element_is_found_from_char256_array(){
	int hint = 102;
	int_void_void predicate = &isCapital;
	arr1 = (ArrayUtil){(char[256]){'f','a','c','e','b','o','0','k',}, sizeof(char), 7};

	assertEqual(count(arr1, predicate, &hint), 0);
}

void test_count_gives_the_number_of_matching_elements_from_float_array(){
	float hint = 12.5;
	int_void_void predicate = &isGreaterThan;
	arr1 = (ArrayUtil){(float[]){33.1, 5.0, 26.1, 12.6, 12.5, 9.9, 14}, sizeof(float), 7};

	assertEqual(count(arr1, predicate, &hint), 4);
}

void test_count_gives_0_when_no_matching_element_is_found_from_float_array(){
	float hint = 102;
	int_void_void predicate = &isGreaterThan;
	arr1 = (ArrayUtil){(float[]){3.3, 50.0, 26.5, 36.2, 9.9, 1.4}, sizeof(float), 6};

	assertEqual(count(arr1, predicate, &hint), 0);
}

void test_count_gives_the_number_of_matching_elements_from_double_array(){
	double hint = 25.5;
	int_void_void predicate = &isLessThan;
	arr1 = (ArrayUtil){(double[]){33.1, 5.0, 26.1, 12.6, 25.4, 9.9, 14}, sizeof(double), 7};

	assertEqual(count(arr1, predicate, &hint), 5);
}

void test_count_gives_0_when_no_matching_element_is_found_from_double_array(){
	double hint = 2.4;
	int_void_void predicate = &isLessThan;
	arr1 = (ArrayUtil){(double[]){3.3, 50.0, 26.5, 36.2, 9.9, 2.5}, sizeof(double), 6};

	assertEqual(count(arr1, predicate, &hint), 0);
}

// void test_count_gives_number_of_strings(){
// 	string hint = "give";
// 	int_void_void predicate = &isBiggerStringThan;
// 	arr1 = (ArrayUtil){(string[]){"ksdjdkads","jdh","","no"},sizeof(string), 5};
// 	assert(count(arr1, predicate, &hint) == 1);
// }


ArrayUtil utils[3];
void test_create_005(){
	log("returns an ArrayUtil with bytes initialized to ZERO for char[256]");
	String array_empty_strings[2] = {"", ""};
	ArrayUtil util1 = {array_empty_strings, sizeOf_String, 2};
	ArrayUtil util2 = create(sizeOf_String, 2);
	assertEqual(areEqual(util1, util2), YES);
	dispose(util2);
}

void test_create_009(){
	log("returns an ArrayUtil with bytes initialized to ZERO for void *");
	void_star array_void_stars[1] = {0x0};
	ArrayUtil util1 = {array_void_stars, sizeOf_void_star, 1};
	ArrayUtil util2 = create(sizeOf_void_star, 1);
	assertEqual(areEqual(util1, util2), YES);
	dispose(util2);
}
void test_create_010(){
	log("returns an ArrayUtil with bytes initialized to ZERO for char *");
	char_star array_char_stars[1] = {(char *)('\0')};
	ArrayUtil util1 = {array_char_stars, sizeOf_char_star, 1};
	ArrayUtil util2 = create(sizeOf_char_star, 1);
	assertEqual(areEqual(util1, util2), YES);
	dispose(util2);
}
void test_create_011(){
	log("returns an ArrayUtil with bytes initialized to ZERO for int *");
	int_star array_int_stars[1] = {(int *)(0)};
	ArrayUtil util1 = {array_int_stars, sizeOf_int_star, 1};
	ArrayUtil util2 = create(sizeOf_int_star, 1);
	assertEqual(areEqual(util1, util2), YES);
	dispose(util2);
}