#include <stdio.h>
#include <string.h>

int main(){
	char s[51];
	double credit;
	char grade[3];

	double tp = 0.0;
	double tc = 0.0;

	for(int i=0;i<20;i++){
		scanf("%s %lf %s",s,&credit,grade);
		if(strcmp(grade,"P")==0) continue;
		
		double grade_point = 0.0;

		if (grade[0] == 'A') grade_point = 4.0;
 	       	else if (grade[0] == 'B') grade_point = 3.0;
        	else if (grade[0] == 'C') grade_point = 2.0;
        	else if (grade[0] == 'D') grade_point = 1.0;
        	else if (grade[0] == 'F') grade_point = 0.0;

		if(grade[1] == '+') grade_point += 0.5;
		
		tp += (credit * grade_point);
		tc += credit;
	}

	printf("%lf",tp/tc);
}
