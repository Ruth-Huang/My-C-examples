float sd(float *a, int m, float mean)
{
int i;
float sum;

sum = 0.0;
for(i=0; i<m; i++) sum = sum + (a[i]-mean)*(a[i]-mean);

return sum/(m-1);
}
