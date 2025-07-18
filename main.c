#include "ft_printf.h"
#include <limits.h>
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	int	ft_len, og_len;

	// 1. CHAR
	ft_len = ft_printf("ft: Char test: %c\n", 'A');
	og_len = printf("og: Char test: %c\n", 'A');
	printf("char => ft: %d | og: %d\n\n", ft_len, og_len);

	// 2. STRING
	ft_len = ft_printf("ft: String test: %s\n", "Kemalettin");
	og_len = printf("og: String test: %s\n", "Kemalettin");
	printf("string => ft: %d | og: %d\n\n", ft_len, og_len);

	// 3. POINTER
	void *ptr = &ft_len;
	ft_len = ft_printf("ft: Pointer test: %p\n", ptr);
	og_len = printf("og: Pointer test: %p\n", ptr);
	printf("pointer => ft: %d | og: %d\n\n", ft_len, og_len);

	// 4. INTEGER
	ft_len = ft_printf("ft: Int test: %d\n", -123456);
	og_len = printf("og: Int test: %d\n", -123456);
	printf("int => ft: %d | og: %d\n\n", ft_len, og_len);

	// 5. UNSIGNED
	ft_len = ft_printf("ft: Unsigned test: %u\n", 4294967295U);
	og_len = printf("og: Unsigned test: %u\n", 4294967295U);
	printf("unsigned => ft: %d | og: %d\n\n", ft_len, og_len);

	// 6. HEX LOWER
	ft_len = ft_printf("ft: Hex lower test: %x\n", 3735928559U);
	og_len = printf("og: Hex lower test: %x\n", 3735928559U);
	printf("hex lower => ft: %d | og: %d\n\n", ft_len, og_len);

	// 7. HEX UPPER
	ft_len = ft_printf("ft: Hex upper test: %X\n", 3735928559U);
	og_len = printf("og: Hex upper test: %X\n", 3735928559U);
	printf("hex upper => ft: %d | og: %d\n\n", ft_len, og_len);

	// 8. PERCENT
	ft_len = ft_printf("ft: Percent test: %%\n");
	og_len = printf("og: Percent test: %%\n");
	printf("percent => ft: %d | og: %d\n\n", ft_len, og_len);

	// 9. NULL STRING
	char *null_str = NULL;
	ft_len = ft_printf("ft: NULL string: %s\n", null_str);
	og_len = printf("og: NULL string: %s\n", null_str);
	printf("null str => ft: %d | og: %d\n\n", ft_len, og_len);

	// 10. MIX TEST
	ft_len = ft_printf("ft: Mix: %c %s %p %d %u %x %X %%\n",
		'A', "Mix", ptr, -42, 42U, 0xbeef, 0xBEEF);
	og_len = printf("og: Mix: %c %s %p %d %u %x %X %%\n",
		'A', "Mix", ptr, -42, 42U, 0xbeef, 0xBEEF);
	printf("mix => ft: %d | og: %d\n\n", ft_len, og_len);

	return (0);
}
