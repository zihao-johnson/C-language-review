// experiments for pointer
#include <stdio.h>
/* Every header file should include needed library independently */
// Declaration
#define array_length 3
void declareAndoperate_pointer()
{
	// print address of variable:
	int integer_one = 1;
	printf("interger_one's address is %x\n", &integer_one);

	// see if array elements' address are continuously;
	//const int array_length = 3; 
	/* cannot use const, detail: https://docs.microsoft.com/en-us/cpp/error-messages/compiler-errors-1/compiler-error-c2057?f1url=https%3A%2F%2Fmsdn.microsoft.com%2Fquery%2Fdev16.query%3FappId%3DDev16IDEF1%26l%3DEN-US%26k%3Dk(C2057)%26rd%3Dtrue&view=vs-2019*/
	int integer_array[array_length] = {1,2,3};

	int *pointers_array[array_length];
	for (int i = 0; i < array_length; i++)
	{
		pointers_array[i] = &integer_array[i];
		printf("integer_array element %d located at %x\n", i, pointers_array[i]);
		printf("integer_array element %d +1 located at %x\n", i, pointers_array[i]+1); 
		// pointer + 1 = physical address + 1 int type size (4 bytes) // try double, it will be = 8 byte
		printf("integer_array element's pointer %d located at %x\n", i, &pointers_array[i]);
	}
	double integer_double = 1.0;
	double* integer_double_p = &integer_double;
	// see how adress of double type variable changes
	printf("integer_double located at %x\n", integer_double_p);
	printf("integer_double_p +1 located at %x\n", ++integer_double_p);

	for (int i = 0; i < array_length-1; i++)
	{
		if (pointers_array[i] + 1 == pointers_array[i + 1]) {
			printf("array elements are stored continuously");
		}
		else {
			printf("array elements are not stored continuously");
		}
	}

	

	// statements like: data_type *pointer_aurgment_name
	int* pointer_int_one;
}

void normal_pointer_arugment(int *int_pointer)
{
	*int_pointer += 1;
}

void pass_arr(int *arr, int arr_size)
{
	// value of defined arr without indicate its index will return arr's first storage address:
	for (int i = 0; i < arr_size; i++)
	{
		arr[i] *= 2;
	}
}

int* return_pointer()
{
	int arr[array_length];
	printf("Initialized array is:");
	for (int i = 0; i < array_length; i++)
	{
		arr[i] = i + 1;
		printf("%d ",arr[i]);
	}printf("\n");
	int* pointer = arr;
	printf("returned value: %d\n", arr);
	return arr;
}

void pass_pointer_varibles_around_function()
{
	// passing pointer into function leads original value's changing because operation will affect on same storage place.
	int int_number = 2;
	int *int_pointer = &int_number;
	printf("Original number is %d with its assigned pointer %x\n", int_number, int_pointer);
	normal_pointer_arugment(int_pointer);
	printf("After pass its pointer and operate it, number is %d with its assigned pointer %x\n", int_number, int_pointer);
	// passing arr varible's name without index specified;
	int arr[array_length];
	for (int i = 0; i < array_length; i++)
	{
		arr[i] = i+1;
	}
	printf("Original Arr are {");
	for (int i = 0; i < array_length; i++)
	{
		printf("%d",arr[i]);
		if (i < array_length - 1)
		{
			printf(", ");
		}
	}printf("}\n");
	pass_arr(arr, array_length);
	printf("after invoke function, it changes to {");
	for (int i = 0; i < array_length; i++)
	{
		printf("%d", arr[i]);
		if (i < array_length - 1)
		{
			printf(", ");
		}
	}printf("}\n");

	int* from_function = return_pointer();
	printf("Got address: %d\n",from_function);
	printf("Int array returned from function is: ");
	for (int i=0;i<array_length;i++)
	{
		printf("%d ", *(from_function+i));
	}printf("\n");
}

//function to awake all other functions inside this file (for convenience):
void main_invoke_function()
{
	//declareAndoperate_pointer();
	pass_pointer_varibles_around_function();
	
}
