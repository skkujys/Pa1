#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/sched.h>


SYSCALL_DEFINE3(sse_formula, int, a, int, b, int, c)
{
	int D_arr[50] = {0, 10000, -1, -1, 20000, 22360, -1, -1, 28284, 30000, -1, -1, 34641, 36055, -1, -1, 40000, 41231, -1, -1, 44721, 45825, -1, -1, 48989, 50000, -1, -1, 52915, 53851, -1, -1, 56568, 57445, -1, -1, 60000, 60827, -1, -1, -1, 64031, -1, -1, -1, 67082, -1, -1, -1, 70000};
	
	int integ, root, D;
	D = b*b-4*a*c;
	int k;

	if(a==0) printk("SSE3044: ERROR: not a quadratic equation\n");
	else if(D<0) printk("SSE3044: ERROR: roots are imaginary numbers.\n");
	else
	{
		k = (((D_arr[D]-10000*b)*100)/(2*a))/100;
		integ = k/10000;
		root = k%10000;
		if(k<0) 
		{
			root*=-1;
			if(integ == 0) printk("SSE3044: %dx^2 + %dx + %d = 0 -> x can be -%d.%d\n", a, b, c, integ, root);
			else printk("SSE3044: %dx^2 + %dx + %d = 0 -> x can be %d.%d\n", a, b, c, integ, root);
			
		}
		else printk("SSE3044: %dx^2 + %dx + %d = 0 -> x can be %d.%d\n", a, b, c, integ, root);
	}
	
	return 0;
}
