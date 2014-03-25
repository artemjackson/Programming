namespace JacksonAlgorithms{

void swap2(int &x,int &y)
{
    int tmp=x;
    x=y;
    y=tmp;
}

void BubbleSort(int *ar, int l, int r)
{
	for(int i=l; i<=r; ++i)
		for(int j=i; j<=r; ++j)
			if(ar[i]>ar[j])
			swap2(ar[i],ar[j]);
}
}