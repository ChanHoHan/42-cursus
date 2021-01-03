#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

/*
size_t k_ft_strlcat(char *dst, const char *src, size_t size)
{
  size_t  rst;
//printf("%zu", size);
  rst = 0;
  while (*dst && dst)
  {
    if (0 < size)
    {
      --size;
      ++rst;
    }
    ++dst;
  }
  rst += strlcpy(dst, src, size);
  return (rst);
}
*/

	/*
int main()
{
	size_t x;
	x = -1;
	size_t tmp;
	char src[] = "good morning";
	char dst[] = "hello";
	int i = 0;
	tmp = ft_strlcat(dst, src, x);
	while(dst[i])
	{
		printf("%c", dst[i]);
		i++;
	}
	printf("\n");
	printf("temp is : %zu\n", tmp);
	printf("\n");
*/
/*
	char srcs[] = "good morning";
	char dsts[] = "hello";
	int i = 0;
	size_t tmp = k_ft_strlcat(dsts, srcs, -1);
	while(dsts[i])
	{
		printf("%c", dsts[i]);
		i++;
	}
	printf("\n");
	printf("temp is : %zu\n", tmp);

	return 0;
}
*/
/*

memmove can be very useful...... 에서, 문자열 시작 주소 부터 15 번째 부분 부터
11 바이트, 즉 "very useful" 을 문자열 시작 주소 부터 20 번째 부분, 즉 "use~"
부분에 복사해 넣는다. 다시말해, 위 문자열은 "memmove can be very very useful."
이 된다. 이 예제는 http://www.cplusplus.com/reference/clibrary/cstring/memmove/
에서 가져왔습니다.

 */
/*
int main() {
  char str[] = "memmove can be very useful......";
  ft_memmove(str + 20, str + 15, 11);
  puts(str);
  return 0;
}*/
/*
int main() {
	size_t tmp;
	char src[] = "good morning";
	char dst[] = "hello";
	int i = 0;
	tmp = ft_strlcat(dst, src, 7);
	while(dst[i])
	{
		printf("%c", dst[i]);
		i++;
	}
	printf("\n");
	printf("temp is : %zu\n", tmp);

	return 0;
}
*/
/*
#include<stdio.h>    //printf
 
int main(void)
{
    char str1[] = "BlockDMask";
    char str2[] = "Block";
    char str3[] = "BlockAAAAA";
    
    printf("strncmp(%s, %s, -1)\t = %d\n", str1, str2, ft_strncmp(str1, str2, -1));
    printf("strncmp(%s, %s, 0)\t = %d\n", str1, str2, ft_strncmp(str1, str2, 0));
    printf("strncmp(%s, %s, 5)\t = %d\n", str1, str2, ft_strncmp(str1, str2, 5));
    printf("strncmp(%s, %s, 6)\t = %d\n", str1, str2, ft_strncmp(str1, str2, 6));
    printf("strncmp(%s, %s, 1000) = %d\n", str1, str2, ft_strncmp(str1, str2, 1000));
 
    printf("strncmp(%s, %s, 5)\t = %d\n", str1, str3, ft_strncmp(str1, str3, 5));
    printf("strncmp(%s, %s, 555)\t = %d\n", str1, str3, ft_strncmp(str1, str3, 555));
 
    return 0;
}

*/
/*
int main()
{
	char big[] = "go go yogurt";
	char little[] = "gu";
	printf("return(gurt) : %s\n", strnstr(big,little,-1));	// return(gurt) : gurt

	printf("return(gurt) : %s\n", ft_strnstr(big,little,-1));	// return(gurt) : gurt
	printf("return(null) : %s\n", strnstr(big,little,9));	//return(null) : null

	printf("return(null) : %s\n", ft_strnstr(big,little,9));	//return(null) : null
       return 0;
}*/
/*

strrchr 함수를 통해 str 에서 s 가 포함된 가장 오른쪽 위치를 찾는다.
이 예제는
http://www.cplusplus.com/reference/clibrary/cstring/strrchr/
에서 가져왔습니다.

 */
/*
int main() {
  char str[] = "This is a sample string";
  char* pch;
  pch = strrchr(str, 's');
  printf("Last occurence of 's' found at %ld \n", pch - str + 1);
  pch = ft_strrchr(str, 's');
  printf("Last occurence of 's' found at %ld \n", pch - str + 1);
  return 0;
}
*/
/*
int main()
{
	char a[] = "9999999999999999999999999";
	printf("%d\n", atoi(a));
	printf("%d\n", ft_atoi(a));
	return (0);
}*/

//calloc
/*
int main()
{
	int n = 5;
	int *arr = ft_calloc(n, sizeof(int));
	for(int i = 0 ;i < 5 ; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}*/
/*
int main()
{
	char a[] = "     ";
	char c = ' ';
	char **x = ft_split(a, c);
	int i = 0;
	
	while(x[i])
	{
		printf("%s ", x[i]);
		i++;
	}
	return 0;
}*/

char	f(unsigned int x, char y)
{
	if (x % 2)
		y = 'i';
	else
		y = 'H';
	return (y);
}

int main()
{
	int i = -1;
	char a[] = "hehehe";
	char *b = ft_strmapi(a, f);
	while(b[++i])
		printf("%c", b[i]);
	free(b);
	return 0;
}
