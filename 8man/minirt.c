#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>

// mlx 구조체 mlx 포인터와 생성할 win포인터를 가지고 있는 구조체
typedef struct s_vars
{
	void *mlx;
	void *win;
}	t_vars;
// 이미지의 정보를 나타내는 변수를 저장한 구조체
typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
}	t_data;

// 원하는 좌표에 해당하는 주소에 color  값을 넣어주는 함수.
void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;
	dst = data->addr + (y *data->line_length + x*(data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// esc key press event
int key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}


int main(void)
{
	//void *mlx_ptr;
	//void *win_ptr; // 생성할 윈도우를 가리키는 포인터
	
	t_data image;
	t_vars vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx,500,500, "Halo alo!");
	
	//이미지 객체 생성
	image.img = mlx_new_image(vars.mlx, 500, 500);
	
	//이미지 주소 할당
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
	
	for (int i =0; i < 500; i++)
	{
		for (int j = 0; j < 500 ; j++)
		{
			//mlx_pixel_put(mlx_ptr, win_ptr, i,j,0x00FFFFFF);
			my_mlx_pixel_put(&image,i,j,0x00FFFFFF);
		}
	}
	mlx_put_image_to_window(vars.mlx,vars.win, image.img, 0, 0);
	mlx_key_hook(vars.win,key_hook,&vars); // esc key press event hooking
	mlx_loop(vars.mlx); // loop 을 돌면서 event를 기다리고 ,생성한윈도ㄹ우를 Rendering한다.
	return (0);
}

