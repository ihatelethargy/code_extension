#include <iostream>
#include <cstdio>
using namespace std;

int col(int n) {
	int counter = 0;
	for (int l1 = 1;l1 <= 3;l1++) {
		if (n == l1) counter++;

		for (int l2 = 1;l2 <= 3;l2++) {
			if (n == l1 + l2) counter++;

			for (int l3 = 1;l3 <= 3;l3++) {
				if (n == l1 + l2 + l3) counter++;

				for (int l4 = 1;l4 <= 3;l4++) {
					if (n == l1 + l2 + l3 + l4) counter++;

					for (int l5 = 1;l5 <= 3;l5++) {
						if (n == l1 + l2 + l3 + l4 + l5) counter++;

						for (int l6 = 1;l6 <= 3;l6++) {
							if (n == l1 + l2 + l3 + l4 + l5 + l6) counter++;

							for (int l7 = 1;l7 <= 3;l7++) {
								if (n == l1 + l2 + l3 + l4 + l5 + l6 + l7) counter++;

								for (int l8 = 1;l8 <= 3;l8++) {
									if (n == l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8) counter++;

									for (int l9 = 1;l9 <= 3;l9++) {
										if (n == l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9) counter++;

										for (int l0 = 1;l0 <= 3;l0++) {
											if (n == l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l0) counter++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return counter;
}

int main() {
	int cas;
	scanf("%d", &cas);
	
	for (int i = 0;i < cas;i++) {
		int n;
		scanf("%d", &n);
		printf("%d\n", col(n));
	}
	
}