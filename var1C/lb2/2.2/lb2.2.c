#include <stdio.h>
#include <math.h>

int main() {
	float a, b, c;
	const float EPS = 1e-5;

	printf("%s\n","Write coefficient a: ");	
	scanf("%f", &a);

	printf("%s\n","Write coefficient b: ");	
	scanf("%f", &b);

	printf("%s\n","Write coefficient c: ");	
	scanf("%f", &c);

	printf("%.2f *x*x + %.2f * x + %.2f = 0\n", a, b, c);
	printf("a = %f\n", a);
	printf("b = %f\n", b);
	printf("c = %f\n", c);

	float d = b*b-4*a*c;
	printf("D = %.2f\n", d);

	if (d > 0) {
		float x1 = (-b+sqrtf(d))/(2*a);
		float x2 = (-b-sqrtf(d))/(2*a);
		printf("Roots are %.2f, %.2f\n", x1, x2);
	} else 
		if (d < EPS && d >-EPS) {
			float x = -b/(2*a);
			printf("Root is %.2f\n", x);
		} else {
			printf("No roots\n");	
		}

	return 0;
}
		

