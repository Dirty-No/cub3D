/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dirty <dirty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 14:52:42 by smaccary          #+#    #+#             */
/*   Updated: 2020/07/13 17:03:24 by dirty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "structs/structs.h"
# include "settings.h"
# include "frontend.h"
# include <time.h>

# define FRAME_CAP			60

# define S_BUFF_SIZE		1

# define SPRITE_RADIUS      0.5
# define ENNEMIES_TEX       6
# define EN_SPEED           0.005

# define LEFT_CLICK			1
# define MIDDLE_CLICK		2
# define RIGHT_CLICK		3

# define SHOT_COOLDOWN		0.20
# define SHOT_DURATION		0.20

# define ESC_KEY			65307

# ifdef __linux__

#  ifndef QWERTY
#   define FORWARD_KEY		122
#   define BACKWARD_KEY		115
#   define LEFT_KEY			113
#   define RIGHT_KEY			100
#   define CTRL_KEY			65507
#   define ALT_KEY			65513
#   define C_KEY				99
#  endif

#  ifdef QWERTY
#   define FORWARD_KEY		119
#   define BACKWARD_KEY		115
#   define LEFT_KEY			97
#   define RIGHT_KEY		100
#   define CTRL_KEY			65507
#   define ALT_KEY			65506
#   define C_KEY			99
#  endif

# endif

# ifdef __APPLE__

#  define FORWARD_KEY		13
#  define BACKWARD_KEY		1
#  define LEFT_KEY			0
#  define RIGHT_KEY			2
#  define CTRL_KEY			256
#  define ALT_KEY			258
#  define C_KEY				8

# endif

/*
** BACKEND
*/

t_keys	*key_chr(t_keys *arr, int keycode, size_t size);

/*
** EVENT HANDLERS
*/

int		mouse_press_handler(int keycode, int x, int y, t_vars *vars);
int		mouse_release_handler(int keycode, int x, int y, t_vars *vars);


int		keyboard_handler(t_vars *vars);
void	hooks(t_vars *vars);
int		loop_handler(t_vars *vars);
int		key_handler(int keycode, t_vars *vars);
int		release_handler(int keycode, t_vars *vars);

void	turn_right(t_vars *vars);
void	turn_left(t_vars *vars);

int		mouse_move_handler(t_vars *vars);

int		forward_handler(t_vars *vars);
int		backward_handler(t_vars *vars);
int		right_handler(t_vars *vars);
int		left_handler(t_vars *vars);
int		alt_handler(t_vars *vars);


/*
** ENNEMIES
*/

void	move_ennemy(t_sprite *sprite, t_camera *cam, char **map);
int		ennemies_handler(t_sprite *sprites, t_camera *cam, char **map);
double	my_dist(double x0, double y0, double x1, double y1);
int		sprite_collision(t_sprite *sprites, double x, double y);

/*
** EVENT DEFINITION
*/

# define NOEVENT_MASK			    0L
# define KEYPRESS_MASK			    1L
# define KEYRELEASE_MASK			2L
# define BUTTONPRESS_MASK			4L
# define BUTTONRELEASE_MASK		    8L
# define ENTERWINDOW_MASK			16L
# define LEAVEWINDOW_MASK			32L
# define POINTERMOTION_MASK		    64L
# define POINTERMOTIONHINT_MASK	    128L
# define FOCUS_CHANGE_MASK			2097152L

/*
** # define Button1MotionMask		(1L<<8)
** # define Button2MotionMask		(1L<<9)
** # define Button3MotionMask		(1L<<10)
** # define Button4MotionMask		(1L<<11)
** # define Button5MotionMask		(1L<<12)
** # define ButtonMotionMask		(1L<<13)
** # define KeymapStateMask			(1L<<14)
** # define ExposureMask			(1L<<15)
** # define VisibilityChangeMask	(1L<<16)
** # define StructureNotifyMask		(1L<<17)
** # define ResizeRedirectMask		(1L<<18)
** # define SubstructureNotifyMask	(1L<<19)
** # define SubstructureRedirectMask	(1L<<20)
** # define FocusChangeMask			(1L<<21)
** # define PropertyChangeMask		(1L<<22)
** # define ColormapChangeMask		(1L<<23)
** # define OwnerGrabButtonMask		(1L<<24)
*/

# define KEY_PRESS		    2
# define KEY_RELEASE		3
# define BUTTON_PRESS		4
# define BUTTON_RELEASE		5
# define FOCUS_IN			9
# define FOCUS_OUT			10

/*
** # define MotionNotify	    6
** # define EnterNotify		    7
** # define LeaveNotify		    8
** # define KeymapNotify	    11
** # define Expose			    12
** # define GraphicsExpose	    13
** # define NoExpose		    14
** # define VisibilityNotify    15
** # define CreateNotify		16
** # define DestroyNotify		17
** # define UnmapNotify		    18
** # define MapNotify		    19
** # define MapRequest		    20
** # define ReparentNotify		21
** # define ConfigureNotify		22
** # define ConfigureRequest	23
** # define GravityNotify		24
** # define ResizeRequest		25
** # define CirculateNotify		26
** # define CirculateRequest	27
** # define PropertyNotify		28
** # define SelectionClear		29
** # define SelectionRequest	30
** # define SelectionNotify		31
** # define ColormapNotify		32
** # define ClientMessage		33
** # define MappingNotify		34
** # define GenericEvent		35
** # define LASTEvent		    36
*/

#endif