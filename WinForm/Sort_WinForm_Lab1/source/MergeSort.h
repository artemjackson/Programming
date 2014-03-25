namespace JacksonAlgorithms{
void merge(int *ar, int *buf, int l, int m, int r)
{
    int i=l;
    int j=m+1;
    int k=l;

    while((i<=m) && (j<=r))
    {
        if (ar[i]<ar[j])
        {
            buf[k]=ar[i];
            ++i;
        }
        else
        {
            buf[k]=ar[j];
            ++j;
        }
        ++k;
    }

    if(i>m)
    {
        for( ; j<=r; ++j)
        {
            buf[k]=ar[j];
            ++k;
        }
    }
    else
    {
        for( ;i<=m; ++i)
        {
            buf[k]=ar[i];
            ++k;
        }
    }

    for(int i=l; i<=r; ++i) ar[i]=buf[i];


}

void mergeSort(int *ar, int *buf, int l, int r)
{
 if(l<r)
    {
        int m=l+(r-l)/2;
        mergeSort(ar,buf,l,m);
        mergeSort(ar,buf,m+1,r);
        merge(ar,buf,l,m,r);
    }
	
}

void MergeSort(int *ar, int l, int r)
{
	int *buf = new int[r+1];
	mergeSort(ar,buf,l,r);
	delete []buf;
}


}