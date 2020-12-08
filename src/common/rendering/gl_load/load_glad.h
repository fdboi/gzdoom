#include "khrplatform.h"
#include "glad.h"

#ifdef __cplusplus
extern "C" {
#endif /*__cplusplus*/


#define HAVE_GLES

enum ogl_LoadStatus
{
	ogl_LOAD_FAILED = 0,
	ogl_LOAD_SUCCEEDED = 1,
};

int ogl_LoadFunctions();


#ifdef __cplusplus
}
#endif /*__cplusplus*/
