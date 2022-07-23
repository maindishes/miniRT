#include <stdio.h>

int main(void)
{
	int i;
	int j;
	double r;
	double g;
	double b;
	int canvas_w;
	int canvas_h;
	
	//픽셀값
	canvas_w = 256;
	canvas_h = 256;
	
	// Rendering
	// P3 는 색상값이 아스키토드라는뜻,
	// 그리고 다음 줄은 캔버스의 가로, 세로 픽셀수, 마지막은 사용할 생삭값
	j = canvas_h - 1;
	while(j >= 0)
	{
		i = 0;
		while (i < canvas_w)
		{
			r = (double)j / (canvas_w -1);
			g = (double)j / (canvas_h -1);
			b = 0.25;
			printf("%d %d %d\n",(int)(255.999 * r), (int)(255.999 *g), (int)(255.999 *b));
			++i;
		}

		--j;
	}
	return (0);
}

