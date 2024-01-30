#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define FULLSCREEN false

//Target FPS can't be higher than 1000 [FPS]. At higher FPS the delta time is too small and movement wont be smooth
#define TARGET_FPS 360
#define TARGET_FRAME_TIME (1000 / TARGET_FPS) // ms per frame.
#define AVERAGE_DELTA_TIME_COUNT 60