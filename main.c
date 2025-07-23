#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "ft_printf.h" 
int	main(void)
{
	int	ft_ret;
	int	sys_ret;

	// CHAR
	ft_ret = ft_printf("%s ");
	sys_ret = printf("%s ");
	printf("char => ft: %d | og: %d\n\n", ft_ret, sys_ret);


    // STRING
	ft_ret = ft_printf("ft: String test: %s\n", "Kemalettin");
	sys_ret = printf("og: String test: %s\n", "Kemalettin");
	printf("string => ft: %d | og: %d\n\n", ft_ret, sys_ret);

	// STRING NULL
	ft_ret = ft_printf("ft: String NULL test: %s\n", NULL);
	sys_ret = printf("og: String NULL test: %s\n", NULL);
	printf("string NULL => ft: %d | og: %d\n\n", ft_ret, sys_ret);

	// POINTER
	void *ptr = (void *)0xdeadbeef;
	ft_ret = ft_printf("ft: Pointer test: %p\n", ptr);
	sys_ret = printf("og: Pointer test: %p\n", ptr);
	printf("pointer => ft: %d | og: %d\n\n", ft_ret, sys_ret);

	// POINTER NULL
	ptr = NULL;
	ft_ret = ft_printf("ft: Null pointer: %p\n", ptr);
	sys_ret = printf("og: Null pointer: %p\n", ptr);
	printf("null pointer => ft: %d | og: %d\n\n", ft_ret, sys_ret);

	// INT
	ft_ret = ft_printf("ft: Int test: %d\n", -42);
	sys_ret = printf("og: Int test: %d\n", -42);
	printf("int => ft: %d | og: %d\n\n", ft_ret, sys_ret);

	// INT MIN/MAX
	ft_ret = ft_printf("ft: INT MIN: %d | MAX: %d\n", INT_MIN, INT_MAX);
	sys_ret = printf("og: INT MIN: %d | MAX: %d\n", INT_MIN, INT_MAX);
	printf("int min/max => ft: %d | og: %d\n\n", ft_ret, sys_ret);

	// UNSIGNED
	ft_ret = ft_printf("ft: Unsigned test: %u\n", 4294967295u);
	sys_ret = printf("og: Unsigned test: %u\n", 4294967295u);
	printf("unsigned => ft: %d | og: %d\n\n", ft_ret, sys_ret);

	// HEX LOWER
	ft_ret = ft_printf("ft: Hex lower test: %x\n", 0xdeadbeef);
	sys_ret = printf("og: Hex lower test: %x\n", 0xdeadbeef);
	printf("hex lower => ft: %d | og: %d\n\n", ft_ret, sys_ret);

	// HEX UPPER
	ft_ret = ft_printf("ft: Hex upper test: %X\n", 0xDEADBEEF);
	sys_ret = printf("og: Hex upper test: %X\n", 0xDEADBEEF);
	printf("hex upper => ft: %d | og: %d\n\n", ft_ret, sys_ret);

	// MIXED TEST
	ft_ret = ft_printf("ft: Mixed: char %c, str %s, ptr %p, int %d, uint %u, hex %x, HEX %X, %%\n",
						'A', "Test", (void *)0x1234, -123, 456u, 0xbeef, 0xBEEF);
	sys_ret = printf("og: Mixed: char %c, str %s, ptr %p, int %d, uint %u, hex %x, HEX %X, %%\n",
						'A', "Test", (void *)0x1234, -123, 456u, 0xbeef, 0xBEEF);
	printf("mixed => ft: %d | og: %d\n\n", ft_ret, sys_ret);

    // YÜZDE (%) KARAKTERİ TESTİ
	ft_ret = ft_printf("ft: Percent test: %%\n");
	sys_ret = printf("og: Percent test: %%\n");
	printf("percent => ft: %d | og: %d\n\n", ft_ret, sys_ret);

	// GEÇERSİZ FORMAT KARAKTERİ TESTİ (%k)
	ft_ret = ft_printf("ft: Invalid format: %h\n");
	sys_ret = printf("og: Invalid format: %h\n");
	printf("invalid format => ft: %d | og: %d\n\n", ft_ret, sys_ret);


	return (0);
}
