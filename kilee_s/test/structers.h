#ifndef stucters_h
# define structers_h

typedef struct s_vec3 t_vec3;
typedef struct s_vec3 t_point3;
typedef struct s_vec3 t_color3;

struct s_vec3
{
	double x;
	double y;
	double z;
};

typedef struct s_ray t_ray;
struct s_ray
{
	t_point3 orig;
	t_vec3 dir;
};

typedef struct s_camera t_camera;
typedef struct s_canvas t_canvas;

struct s_camera
{
	t_point3	orig; // camera 원점 위치
	double		viewport_h; // 뷰포트 세로길이
	double		viewport_w; // 뷰포트 가로 길이
							// 뷰포트란 3차원 장면을 2차원 에 투사하기 위해 사용되는 2차원 작사각형
	t_vec3		horizontal;
	t_vec3		vertical;
	double		focal_len;
	t_point3	left_bottom; //왼쪽 아래 코너점
};

struct s_canvas
{
	int width;
	int height;
	double aspect_ratio; // 종횡비

};


#endif




