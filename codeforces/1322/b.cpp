#include <bits/stdc++.h>
using namespace std;
 
int a[400005], b[400005];
int n, ans;
 
int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++) scanf("%d", a+i);
    for (int i=0;i<n;++i) b[i] = a[i];
	// for (int i = 0;i < n;i++) scanf("%d", b+i);
	for (int v = (1<<28);v;v>>=1)
	{
		for (int i = 0;i < n;i++) a[i] &= (v*2-1);
		for (int i = 0;i < n;i++) b[i] &= (v*2-1);
		sort(a, a+n); sort(b, b+n);
		int t = 0;
		for (int i = n-1, j = 0, k = 0, l = 0;i >= 0;i--)
		{
			while (j < n && a[i]+b[j] < v) j++;
			while (k < n && a[i]+b[k] < 2*v) k++;
			while (l < n && a[i]+b[l] < 3*v) l++;
			t += k-j+n-l;
            if (v<=2*a[i] && 2*a[i]<2*v || 3*v<=2*a[i] && 2*a[i]<4*v) --t;
		}
        t >>= 1;
		if (t&1) ans |= v;
	}

	printf("%d\n", ans);
	return 0;
}