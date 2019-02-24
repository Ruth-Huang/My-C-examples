#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <tgmath.h>

int main(int argc, char *argv[])
{
double x, y;
//char *opp;
char op;//operator
double res;
char str[100];//whole string
char buf[100];
char a[100];//first number
char b[100];//second number
int i, p, len;
int num_read;
int dot_read;


/*
if(argc != 4) {
	printf("Usage: calculator <op> <num> <num>\n");
	exit(0);
}
*/

again:

fgets(str, 100, stdin);      //to scan all input

i = 0;
p = 0;
dot_read = 0;
num_read = 0;
while(str[i] == ' ') i++;              //skip spaces at start of input
while ((str[i] <='9' && str[i] >= '0') || str[i] == '.'){ 
      if(dot_read == 0 && str[i] == '.'){      //dot is included
            dot_read = 1;
	    a[p++] = str[i++];
	    continue;
      }
      if(dot_read == 1 && str[i] == '.'){     //not allow 2 dots
            printf("Invalid dot\n");
	    goto again;
      }
      if(num_read == 0 && str[i] != '.'){    //float num scanned
            num_read = 1;
	    a[p++] = str[i++];
	    continue;
      }
      if(num_read == 0 && str[i] == '.'){   //not allow 1 dot
            printf("Invalid dot\n");
            goto again;
      }
      a[p++] = str[i++];
}           
a[p] = 0;                              //to end array a

//printf("i is %d the num is %s\n", i, a);

while(str[i] == ' ') i++;              //skip spaces after array a

    if(str[i] == '+') {op = '+'; i++;}      //to recognise operators
    else if(str[i] == '-') {op = '-'; i++;}
    else if(str[i] == '*') {op = '*'; i++;}
    else if(str[i] == '/') {op = '/'; i++;}
    else {printf("Invalid operator %c\n", str[i]); goto again;}

/*
p = 0;
while(str[i] == ' ') i++;              //skip spaces after operator
while (str[i] <='9' && str[i] >= '0')  
      b[p++] = str[i++];
*/               //scan numbers into array b

p = 0;
dot_read = 0;
num_read = 0;
while(str[i] == ' ') i++;              //skip spaces at start of input
while ((str[i] <='9' && str[i] >= '0') || str[i] == '.'){
      if(dot_read == 0 && str[i] == '.')      //dot is included
            dot_read = 1;
            b[p++] = str[i++];
            continue;
      if(dot_read == 1 && str[i] == '.'){     //not allow 2 dots
            printf("Invalid dot\n");
            goto again;
      }
      if(num_read == 0 && str[i] != '.')    //float num scanned
            num_read = 1;
            b[p++] = str[i++];
            continue;
      if(num_read == 0 && str[i] == '.'){   //not allow 1 dot
            printf("Invalid dot\n");
            goto again;
      }
      b[p++] = str[i++];
}
b[p] = 0;                              //to end array b

while(str[i] == ' ') i++;         //skip spaces after input

if(str[i] != '\n') {printf("Invalid character %c\n", str[i]); goto again;}
         //input must end with newline

//printf("a is %s and b is %s\n", a, b);

sscanf(a, "%lf", &x);
sscanf(b, "%lf", &y);

//printf("%.*le\n",DBL_DIG, x);
//printf("%.*le\n",DBL_DIG, y); 

if(op == '+') res = x+y;         //forming calculation with x and y
else if(op == '-') res = x-y;
else if(op == '*') res = x*y;
else if(op == '/') res = x/y;

sprintf(buf, "%.8lf", res);           //printing result as float

//printf("%s\n", buf);

len = strlen(buf);
len--;
while(buf[len] == '0') buf[len--] = 0;

printf("%s\n", buf);

goto again;                    //repeat forever

}

