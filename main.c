#include <stdio.h>
#include <ctype.h>

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

int check_number_column( const int val);
void input_number( int *val, char *msg);
void input_numbers( int *number, int *multiply);

/**
 * @fn int check_number_column( const int val)
 * @brief 숫자의 자리수를 검사하는 함수, 기존에 입력 자리수가 정해져 있다.
 * @param val 입력받은 정수
 * @return 정수의 자리수가 지정된 자리수와 동일하면 SUCCESS, 아니면 FAIL 반환
 */
int check_number_column( const int val){
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
 * @fn void input_number( int *val)
 * @brief 숫자를 입력받고 자리수를 확인하는 함수 
 * @param val 입력받을 int형 정수
 * @return 반환값 없음
 */
void input_number( int *val, char *msg){
	if( val == NULL){
#if DEBUG
		printf("\t| ! 알 수 없는 주소 참조(NULL) in input_number function.\n");
#endif
		return ;
	}

	int return_value_input = FAIL;
	int return_value_column = FAIL;

	do
	{
		printf("\t| @ %s\t입력 (3자리수)\t: ", msg);
		return_value_input = scanf( "%d", val);
		if( return_value_input == FAIL){
			printf("\t| ! 입력 오류, 정수가 아닌 문자열 입력.\n");
			while( getchar() != '\n');
			continue;
		}
	
		return_value_column = check_number_column( *val);
		if( return_value_column == FAIL){
			printf("\t| ! 입력 오류, 자리수 불일치.\n");
		}
	}
	while(( return_value_input != SUCCESS) || ( return_value_column != SUCCESS));
}

/**
 * @fn void input_numbers( int *number, int *multiply)
 * @brief 곱셈에 필요한 두 숫자를 입력받는 함수
 * @param number 곱해지는 값
 * @param multiply 곱하는 값
 * @return 반환값 없음
 */
void input_numbers( int *number, int *multiply){
	if( number == NULL || multiply == NULL){
#if DEBUG
		printf("\t| ! 알 수 없는 주소 참조(NULL) in input_numbers function.\n");
#endif
		return ;
	}

	// 곱해지는 값 입력
	input_number( number, "곱해지는 값");
	// 곱하는 값 입력
	input_number( multiply, "곱하는 값");
}

/**
 * @fn void print_results( const int number, const int multiply)
 * @brief 매개변수로 받은 두 숫자의 곱셈 중간 과정과 결과를 출력하는 함수
 * @param number 곱해지는 값
 * @param multiply 곱하는 값
 * @return 반환값 없음
 */
void print_results( int number, int multiply){
	// 곱하는 값의 현재 자리수의 숫자
	int current_digit = 0;
	// 곱하는값의 현재 자리수의 숫자와 곱해지는 값과 곱한 값
	int current_multiply = 0;
	// 곱하는 값의 현재 자리수
	int current_multiply_column = 1;
	// current_multiply 를 출력할 때 라인의 공백 관리
	int current_print_space = 5;
	// 곱하는 값과 곱해지는 값을 곱한 값(최종 곱셈 값)
	int total_result = 0;
	// current_multiply 를 출력할 때의 출력 양식
	char print_format[32] ={0,};

	printf("\n");
	printf("	| @   %d\n", number);
	printf("	| @ X %d\n", multiply);
	printf("	| @ -----\n");
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
	printf("	| @ -----\n");
	printf("	| @ %d\n\n", total_result);
}

/////////////////////////////////////////////////////
// Main function
/////////////////////////////////////////////////////

/**
 * @fn int main()
 * @brief 두 숫자를 입력받아 곱셈 중간 과정과 결과를 출력하는 프로그램
 * @return 반환값 없음
 */
void main(){
	// 곱해지는 값, 곱하는 값
	int number = 0, multiply = 0;

	// 1. 곱셈에 사용될 두 숫자를 입력받는다.
	printf("\n\t| @ 곱셈 출력 프로그램\n");
	printf("\t| @ (세자리수의 두 숫자 곱셈)\n\n");
	input_numbers( &number, &multiply);

	// 2. 곱셈을 실시하고, 중간 과정과 최종 결과를 출력한다.
	print_results( number, multiply);
}
