#include "load_glad.h"

void* SDL_GL_GetProcAddress(const char* proc);

int ogl_LoadFunctions() {
	if(!gladLoadGLES2Loader(SDL_GL_GetProcAddress)) {
		ogl_LOAD_FAILED;
	}
	return ogl_LOAD_SUCCEEDED;
}
