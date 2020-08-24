#include <stdio.h>

int main(void)
{
	printf("세 자리 숫자 두 개를 입력 하세요 (공백 문자로 구분): ");
	int number = 0;
	int multiply = 0;
	scanf("%d %d", &number, &multiply);
	printf("\n%6d\nx %4d\n------\n", number, multiply);

	int digit = 0;
	int m = 0;
	int x = 1;
	int result = 0;
	char format[32] ={0,};

	int p = 6;
	while (multiply != 0)
	{
		digit = multiply % 10;
		m = number * digit * x;
		sprintf(format, "%%%dd\n", p--);
		printf(format, m / x);
		result += m;

		x *= 10;
		multiply /= 10;
	}
	printf("------\n%d\n\n", result);
	return 0;
}
