
#include <stdio.h> 
int main() 
{ 
	// P0, P1, P2, P3, P4 are the names of Process

	int n, r, i, j, k; 
	n = 5; // no processes 
	r = 4; // Number of resources 
	int alloc[5][4] = { { 1, 4, 0, 1 }, // P0 // This is Allocation Matrix 
						{7, 3, 0, 0 }, // P1 
						{9, 1, 0, 1 }, // P2 
						{0, 2, 3, 2 }, // P3 
						{11, 0, 0, 3 } }; // P4 

	int max[5][4] = { { 8, 6, 12,4 }, // P0 // MAX Matrix 
					{ 7, 2, 2,9 }, // P1 
					{ 8, 4, 2,2 }, // P2 
					{ 2, 6, 2, 3 }, // P3 
					{ 6, 5, 2, 3 } }; // P4 

	int avail[4] = { 2, 3, 2,5 }; // These are Available Resources 

	int f[n], ans[n], ind = 0; 
	for (k = 0; k < n; k++) { 
		f[k] = 0; 
	} 
	int need[n][r]; 
	for (i = 0; i < n; i++) { 
		for (j = 0; j < r; j++) 
			need[i][j] = max[i][j] - alloc[i][j]; 
	} 
	int y = 0; 
	for (k = 0; k < 5; k++) { 
		for (i = 0; i < n; i++) { 
			if (f[i] == 0) { 

				int flag = 0; 
				for (j = 0; j < r; j++) { 
					if (need[i][j] > avail[j]){ 
						flag = 1; 
						break; 
					} 
				} 

				if (flag == 0) { 
					ans[ind++] = i; 
					for (y = 0; y < r; y++) 
						avail[y] += alloc[i][y]; 
					f[i] = 1; 
				} 
			} 
		} 
	} 

	printf("Th SAFE Sequence is as follows\n"); 
	for (i = 0; i < n - 1; i++) 
		printf(" P%d ->", ans[i]); 
	printf(" P%d", ans[n - 1]); 

	return (0); 

}
