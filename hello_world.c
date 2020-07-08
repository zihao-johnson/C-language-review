#include <stdio.h>
#include <stdlib.h> 
/* <stdlib.h> For:                                    */
/* 1. for parsing string to numerical type, e.g. atof */

#include "experiment_pointer.h"
/* Invoke functions from other files, detail retrieved from https://stackoverflow.com/questions/21260735/how-to-invoke-function-from-external-c-file-in-c*/

// Notes:
// note_1: For convenience, every one of knowledges reviewed has been wrapped as a function.
// note_3: Functions invoked must be defined before invoked line.
void hello_world_func()
{
	// knowledge_1: input information to console
	printf("Hello World\n");
	//printf("Today is");
}

void data_types()
{
	//knowledge_2
	// Sizeof is to get data type's storage size, 
	// parameters can be type name(e.g. int/long),
	// or parameters (e.g. int i then use sizeof(i)).
	
	// integer types
	/*
								--> 1.unsigned
	int long short with their   --> !! but they are all signed (with +/-) by default
								--> 2. signed
	*/
	printf("Integer type:\n");
	printf("Int type is %lu bytes\n",sizeof(int));
	printf("Short type is %lu bytes\n", sizeof(short));
	printf("Long type is %lu bytes\n",sizeof(long));
	printf("Unsigned int is %lu bytes\n",sizeof(unsigned long));
	// char type
	/*
		  --> 1.unsigned 
	char  --> !!! char is unsigned by defualt
		  --> 2. signed
	*/
	printf("Char type is %lu byte\n",sizeof(char));

	// Float types:
	/*
								--> 1.unsigned
	int long short with their   --> !! but they are all signed (with +/-) by default
								--> 2. signed
	*/
	printf("Float type:\n");
	printf("float size is %lu\n",sizeof(float));
	printf("double size is %lu\n",sizeof(double));

}
// Loop test, difference - while or do while
void difference_do_while_and_while()
{   /*knowledge_3*/
	int i = 3;

	while(i<2)
	{
		i++;
		printf("while loop will never execute if condition is not met, you will never see this line until condition changes\ni is %d",i);
	}

	do
	{
		i++;
		printf("do...while loop will execute processes whatever condition is met or not\nfinal i is %d, even though condition is 'i<2'",i);
	} while (i<2);

}

// Enumeration type experiment:

void enumeration_type()
{   /*knowledge_5*/
	// Enumeration type is sort of c basic data type, defined by user (programmer) as needed,
	// after defined, user can create or declare any variables of the enumeration type (mostly like class from my understanding).
	// learned from tutorial https://www.geeksforgeeks.org/enumeration-enum-c/.
	enum COLOR {
		red = 1, green, blue, gray, yellow
	};
	enum COLOR favorate_color = 1;
	enum COLOR test_color = red;
	for (int i = red; i <= yellow; i++)
	{
		printf("%d\n", i);
	}
	if (favorate_color == red){
		printf("declared enum COLOR type can be assigned with number but can be compared with variables name\n");
	}
	else {
		printf("declared enum CLOR type can only compared with number\n");
	}

	if (test_color == red) {
		//printf("variable's value (s) is %s\n", test_color); 
		/* note_4 test_color as enum COLOR type can be assigned with elements name but it will then convert to nummber automatically,
		   so if print it out on console as string will fail*/
		printf("variable's value (s) is %s\n", "fail");
		printf("variable's value (d) is %d\n", test_color);
	}
	else {
		//printf("variable's value (s) is %s\n", test_color);// woring code, enum variables should be number. 
		printf("variable's value (d) is %d\n", test_color);
	}
	
}


// Numerical operator recaps:
float add_two_numbers(char a[], char b[])
{
	float result = atof(a) + atof(b);
	return result;
}
float minus_two_numbers(char a[], char b[])
{
	float result = atof(a) - atof(b);
	return result;
}
float divide_two_numbers(char a[], char b[])
{
	float result = atof(a) / atof(b);
	return result;
}
float multiply_two_numbers(char a[], char b[])
{
	float result = atof(a) * atof(b);
	return result;
}
float modulus_two_numbers(char a[], char b[])
{
	/*modulus operator needs both numbers to be integar, check if inputs valid is important*/
	//check input data type:
	int flag = 0;
	float result;
	if ((atof(a) - atoi(a)) == 0 && (atof(b) - atoi(b)) == 0)
	{
		flag = 1;
	}
	if (flag = 1)
	{
		result = atoi(a) % atoi(b);
	}
	else {
		printf("There are errors in during modulus processing! (inputs has to be integer)");
	}
	
	return result;
}
float simple_calculator(char operator,char to_be_process[][3])// operator is going to decide how to process numbers, char array to_be_process is data ro be processed.
{	/*knowledge_4*/
	// currently char array with two elements is default: 
	// ALL operation functions used below need knowledge How to parse char array (string in c) type to numerical type,
	// relevant method and libraries detail retrieved from: http://c.biancheng.net/cpp/html/1574.html.

	float result;
	int flag = 0;
	switch (operator)
	{
		case '+':
			result = add_two_numbers(to_be_process[0],to_be_process[1]);
			flag = 1;
			break;
		case '-':
			result = minus_two_numbers(to_be_process[0], to_be_process[1]);
			flag = 1;
			break;
		case '/':
			result = divide_two_numbers(to_be_process[0], to_be_process[1]);
			flag = 1;
			break;
		case '*':
			result = multiply_two_numbers(to_be_process[0], to_be_process[1]);
			flag = 1;
			break;
		case '%':
			result = modulus_two_numbers(to_be_process[0], to_be_process[1]);
			flag = 1;
			break;
	}
	if (flag == 1)
	{
		printf("result: %f\n", result);
	}
	else
	{
		printf("There are errors"); 
	}
}

//note_2: Main function is necessary every C program will start from main function but complied from first line of code
void main()
{
	/*knowledge_1*/
	//hello_world_func();

	/*knowledge_2*/
	//data_types();
	
	/*knowledge_3*/
	//difference_do_while_and_while();

	/*knowledge_4*/
	//char data[2][3] = {"13","12"};
	//simple_calculator('%', data);
	// detial for passing array around functions retrieved from https://www.runoob.com/cprogramming/c-passing-arrays-to-functions.html

	/*knowledge_5*/
	//enumeration_type();

	/*knowledge_6_pointer*/
	main_invoke_function();
}
