#include <stdio.h>

/////////////////////////////////////////////////////
// Definitions & Macros
/////////////////////////////////////////////////////
#define MAX_LINE	4

/////////////////////////////////////////////////////
// Local functions
/////////////////////////////////////////////////////


/////////////////////////////////////////////////////
// Main function
/////////////////////////////////////////////////////
/**
 * @fn 
 * @brief
 * @param 
 * @return 
 */
int main(){
	int loop_index = 0;
	int return_value = 0;
	int is_get_first_number = 0, is_get_second_number = 0;
	int first_number = 0, second_number = 0;
	int temp_sec_number[MAX_LINE];
	int result[MAX_LINE];

	while( 1){
		if( is_get_first_number == 0){
			printf("\t| @ 첫 번쨰 숫자 입력 : ");
			return_value = scanf( "%d", &first_number);
			if( return_value == 0){
				continue;
			}
			is_get_first_number++;
		}

		if( is_get_second_number == 0){
			printf("\t| @ 두 번쨰 숫자 입력 : ");
			return_value = scanf( "%d", &second_number);
			if( return_value == 0){
				continue;
			}
			is_get_second_number++;
		}

		if( is_get_first_number > 0 && is_get_second_number > 0) break;
	}

	// line 5
	temp_sec_number[2] = second_number;
	temp_sec_number[2] /= 100;
	result[2] = first_number * temp_sec_number[2];
	temp_sec_number[2] *= 100;

	// line 4
	temp_sec_number[1] = second_number;
	temp_sec_number[1] /= 10;
	temp_sec_number[1] *= 10;
	temp_sec_number[1] -= temp_sec_number[2];
	temp_sec_number[1] /= 10;
	result[1] = first_number * temp_sec_number[1];
	temp_sec_number[1] *= 10;

	// line 3
	temp_sec_number[0] = second_number;
	temp_sec_number[0] -= temp_sec_number[1] + temp_sec_number[2];
	result[0] = first_number * temp_sec_number[0];

	// line 6
	result[3] = first_number * second_number;

	for( ; loop_index < 3; loop_index++){
		printf("%d\n", temp_sec_number[loop_index]);
	}

	printf("\n");

	for( loop_index = 0; loop_index < 4; loop_index++){
		printf("%d\n", result[loop_index]);
	}

	return 1;
}

