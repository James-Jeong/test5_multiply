#include <stdio.h>

/////////////////////////////////////////////////////
// Definitions & Macros
/////////////////////////////////////////////////////
/** 숫자 입력 고정 자리수 */
#define FIXED_COLUMN	3
/** 곱셉 중간 과정 출력 라인 최대 개수 */
#define MAX_LINE		4
/** 디버깅 여부 */
#define DEBUG			1

/** 함수 반환값 열거형 */
enum STATUS{
	UNKNOWN		= -1,	/** 알 수 없는 값 입력 */
	FAIL 		= 0,	/** 실패 */
	SUCCESS				/** 성공 */
};

/////////////////////////////////////////////////////
// Local functions
/////////////////////////////////////////////////////
/**
 * @fn int check_column( const int val)
 * @brief 숫자의 자리수를 검사하는 함수, 기존에 입력 자리수가 정해져 있다.
 * @param val 입력받은 정수
 * @return 검사 성공 여부, 성공 시 SUCCESS, 실패 시 FAIL 반환
 */
int check_column( const int val){
	if( val == 0){
#if DEBUG
		printf("\t| ! 0 에 대한 자리수 검사 불가능 in check_column function\n");
#endif
		return FAIL;
	}

	int temp_val = val;
	int return_value = FAIL;
	int column_count = 0;

	while( temp_val != 0){
		temp_val = temp_val / 10;
		column_count++;
	}

	if( column_count == FIXED_COLUMN){
		return_value = SUCCESS;
	}

	return return_value;
}

/**
 * @fn int input_number( int *val)
 * @brief 숫자를 입력받고 자리수를 확인하는 함수 
 * @param val 입력받을 int형 정수
 * @return 입력 성공 여부, 성공 시 SUCCESS, 실패 시 FAIL 반환
 */
int input_number( int *val){
	if( val == NULL){
#if DEBUG
		printf("\t| ! 알 수 없는 주소 참조(NULL) in input_number function\n");
#endif
		return FAIL;
	}

	int return_value_input = scanf( "%d", val);
	int return_value_column = FAIL;

	if( return_value_input == FAIL){
		printf("\t| ! 입력 오류, 문자열 입력\n");
		while( getchar() != '\n');
		return return_value_input;
	}

	return_value_column = check_column( *val);
	if( return_value_column == FAIL){
		printf("\t| ! 입력 오류, 자리수 불일치\n");
	}
	return return_value_column;
}

/**
 * @fn void input_numbers( int *number, int *multiply)
 * @brief 곱셈에 필요한 두 숫자를 입력받는 함수
 * @param number 곱해지는 값
 * @param multiply 곱하는 값
 * @return 입력 성공 여부, 성공 시 SUCCESS, 실패 시 FAIL 반환
 */
void input_numbers( int *number, int *multiply){
	if( number == NULL || multiply == NULL){
#if DEBUG
		printf("\t| ! 알 수 없는 주소 참조(NULL) in input_numbers function\n");
#endif
		return ;
	}

	int return_value = FAIL;

	// 곱해지는 값 입력
	do
	{
		printf("\t| @ 곱해지는 값 입력 (3자리수)\t: ");
		return_value = input_number( number);
	}
	while(return_value != SUCCESS);

	// 곱하는 값 입력
	do
	{
		printf("\t| @ 곱하는 값 입력 (3자리수)\t: ");
		return_value = input_number( multiply);
	}
	while(return_value != SUCCESS);
}

/////////////////////////////////////////////////////
// Main function
/////////////////////////////////////////////////////
/**
 * @fn int main()
 * @brief 두 숫자를 입력받아 곱셈 중간 과정과 결과를 출력하는 프로그램
 * @return SUCCESS
 */
int main(){
	// 곱해지는 값, 곱하는 값
	int number = 0, multiply = 0;
	// 곱하는 값의 현재 자리수의 숫자
	int current_digit = 0;
	// 곱하는값의 현재 자리수의 숫자와 곱해지는 값과 곱한 값
	int current_multiply = 0;
	// 곱하는 값의 현재 자리수
	int current_multiply_column = 1;
	// current_multiply 를 출력할 때 라인의 공백 관리
	int current_print_space = 6;
	// 곱하는 값과 곱해지는 값을 곱한 값(최종 곱셈 값)
	int total_result = 0;
	// current_multiply 를 출력할 때의 출력 양식
	char print_format[32] ={0,};

	// 1. 곱셈에 사용될 두 숫자를 입력받는다.
	printf("\n\t| @ 곱셈 출력 프로그램\n");
	printf("\t| @ (세자리수의 두 숫자 곱셈)\n\n");
	input_numbers( &number, &multiply);

	// 2. 곱셈을 실시하고, 중간 과정과 최종 결과를 출력한다.
	printf("\n");
	while (multiply != 0)
	{
		current_digit = multiply % 10;
		current_multiply = number * current_digit * current_multiply_column;
		sprintf( print_format, "	| @ %%%dd\n", current_print_space--);
		printf( print_format, current_multiply / current_multiply_column);
		total_result += current_multiply;

		current_multiply_column *= 10;
		multiply /= 10;
	}
	printf("	| @ ------\n");
	printf("	| @ %d\n\n", total_result);

	return SUCCESS;
}

