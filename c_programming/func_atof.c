#include<stdio.h>
#include<ctype.h>
#include<math.h>
double pow(double x, double y);
double atof(char *s);
int main(int argc, char *argv[])
{
	printf("%f ", atof(argv[1]));
}

double pow(double x, double y)
{
	int i = 0;
	double result = 1.0;
	if(y<0)
	{
		for(i = 0; i<(-1*y); i++)
		{
			result = result*(1/x);
		}
	}
	else
	{
		for(i = 0; i<y; i++)
		{
			result = result*x;
			printf("Inside else\n");
		}
	}

	return result;
}

double atof(char *s)
{
	double val, power, power_10;
	int i, sign, sign2;
	power_10 = 1.0;
	
	for(i = 0; isspace(s[i]); i++)
		;/* Ignore Whitespaces*/

	sign = (s[i] == '-')?-1:1;
	for(val = 0.0; isdigit(s[i]); i++)
	{
		val = val*10.0 + (s[i] - '0');	
	}
	if(s[i] == '.')
		i++;
	for(power = 1.0; isdigit(s[i]); i++) {
		val = val*10.0 + (s[i]-'0');
		power = power*10.0;
	}

	if(s[i] == 'e' || s[i] == 'E')
	{
		i++;
		sign2 = (s[i] == '-')?-1:1;
		i++;
		power_10 = pow(10,(int)(s[i]-'0')*sign2);
		printf("%f \n", power_10);
	}
	return (sign * (val/power) * power_10);
}
