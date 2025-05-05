#ifndef SIMX_H
#define SIMX_H


#ifdef __cplusplus
#define SIMX_LINKAGE extern "C"
#else
#define SIMX_LINKAGE extern
#endif


#if defined(SIMX_BUILD_DYNAMIC) && defined(SIMX_USE_DYNAMIC)
#error "SIMX_BUILD_DYNAMIC and SIMX_USE_DYNAMIC cannot both be defined at the same time"
#endif


#if defined(_MSC_VER) && defined(SIMX_BUILD_DYNAMIC)
#define SIMX_VISIBILITY __declspec(dllexport)
#elif defined(_MSC_VER) && defined(SIMX_USE_DYNAMIC)
#define SIMX_VISIBILITY __declspec(dllimport)
#elif defined(__GNUC__) && defined(SIMX_BUILD_DYNAMIC)
#define SIMX_VISIBILITY __attribute__((visibility("default")))
#else
#define SIMX_VISIBILITY
#endif


#define SIMX_API SIMX_LINKAGE SIMX_VISIBILITY


#define SIMX_API_VERSION_MAJOR 0
#define SIMX_API_VERSION_MINOR 0
#define SIMX_API_VERSION_PATCH 0


#define SIMX_ERROR_NONE 0
#define SIMX_ERROR_UNSPECIFIED 1
#define SIMX_ERROR_ARGUMENT_NULL 2
#define SIMX_ERROR_ARGUMENT_OUT_OF_RANGE 3
#define SIMX_ERROR_INSUFFICIENT_MEMORY 4


#define SIMX_LOG_LEVEL_TRACE 0
#define SIMX_LOG_LEVEL_DEBUG 1
#define SIMX_LOG_LEVEL_INFO 2
#define SIMX_LOG_LEVEL_WARN 3
#define SIMX_LOG_LEVEL_ERROR 4
#define SIMX_LOG_LEVEL_FATAL 5


struct SIMXentity;

struct SIMXvector3 {
    double x;
    double y;
    double z;
};

struct SIMXquaternion {
    double x;
    double y;
    double z;
    double w;
};


typedef void (*simx_log_callback)(int level, const char* message, void* user_data);


SIMX_API int simx_set_log_callback(simx_log_callback callback, void* user_data);

SIMX_API int simx_get_api_version_number(int* major, int* minor, int* patch);
SIMX_API const char* simx_get_api_version();

SIMX_API const char* simx_get_implementation_name();
SIMX_API const char* simx_get_implementation_description();
SIMX_API const char* simx_get_implementation_version();
SIMX_API const char* simx_get_implementation_author();

SIMX_API const char* simx_get_error_message();

SIMX_API int simx_get_interfaces(char** interfaces, int* length);

SIMX_API double simx_get_timestep();

SIMX_API int simx_create_entity(struct SIMXentity** entity);
SIMX_API int simx_set_entity_log_callback(struct SIMXentity* entity, simx_log_callback callback, void* user_data);
SIMX_API int simx_step_entity(struct SIMXentity* entity, double time);
SIMX_API void simx_destroy_entity(struct SIMXentity* entity);


#endif /* SIMX_H */
