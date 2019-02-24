float mean(float *a, int m)
{
int i;
float sum;

sum = 0.0;
for(i=0; i<m; i++) sum = sum + a[i];

return sum/m;
}
