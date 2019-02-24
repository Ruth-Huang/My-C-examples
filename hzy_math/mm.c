float mm_max(float *a, int m)
{
float max;
int i;
	max = a[0];
	for(i=1; i<m; i++) {
		if(a[i] > max) max = a[i];
	}
}

float mm_min(float *a, int m)
{       
float min;
int i;
	min = a[0];
	for(i=1; i<m; i++) {
		if(a[i] < min) min = a[i];		}
}
