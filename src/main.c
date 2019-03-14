#define FPL_IMPLEMENTATION
#include "final_platform_layer.h"

#define FGL_IMPLEMENTATION
#include "final_dynamic_opengl.h"

int main(void) {
	if (!fplPlatformInit(fplInitFlags_All, fpl_null))
		goto err;
	if (!fglLoadOpenGL(true))
		goto err_release_platform;

	while (fplWindowUpdate()) {
		glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_TRIANGLES);
		glColor3f(1, 0, 0);
		glVertex2f(0, 0.5);
		glColor3f(0, 1, 0);
		glVertex2f(-0.5, -0.5);
		glColor3f(0, 0, 1);
		glVertex2f(0.5, -0.5);
		glEnd();
		fplVideoFlip();
	}

	fplPlatformRelease();
	return 0;

err_release_platform:
	fplPlatformRelease();
err:
	return -1;
}