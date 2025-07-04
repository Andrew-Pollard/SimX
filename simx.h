#ifndef SIMX_H
#define SIMX_H


#ifdef __cplusplus
/// @brief The linkage to be used for SimX API functions.
#define SIMX_LINKAGE extern "C"
#else
/// @brief The linkage to be used for SimX API functions.
#define SIMX_LINKAGE extern
#endif


#if defined(SIMX_BUILD_DYNAMIC) && defined(SIMX_USE_DYNAMIC)
#error "SIMX_BUILD_DYNAMIC and SIMX_USE_DYNAMIC cannot both be defined at the same time"
#endif


#if defined(_MSC_VER) && defined(SIMX_BUILD_DYNAMIC)
/// @brief The visibility to be used for SimX API functions.
#define SIMX_VISIBILITY __declspec(dllexport)
#elif defined(_MSC_VER) && defined(SIMX_USE_DYNAMIC)
/// @brief The visibility to be used for SimX API functions.
#define SIMX_VISIBILITY __declspec(dllimport)
#elif defined(__GNUC__) && defined(SIMX_BUILD_DYNAMIC)
/// @brief The visibility to be used for SimX API functions.
#define SIMX_VISIBILITY __attribute__((visibility("default")))
#else
/// @brief The visibility to be used for SimX API functions.
#define SIMX_VISIBILITY
#endif


/// @brief The macro SimX uses to export API functions.
///
/// This macro should be used by extension interfaces to export their API
/// functions in preference to defining their own.
#define SIMX_API SIMX_LINKAGE SIMX_VISIBILITY


/// @defgroup version Versioning
/// @brief How to check the version of the SimX interface that has been
/// implemented.
/// @{

/// @brief The major version number of the <a href=https://semver.org/>Semantic
/// Version</a> of the API.
#define SIMX_API_VERSION_MAJOR 0
/// @brief The minor version number of the <a href=https://semver.org/>Semantic
/// Version</a> of the API.
#define SIMX_API_VERSION_MINOR 0
/// @brief The patch version number of the <a href=https://semver.org/>Semantic
/// Version</a> of the API.
#define SIMX_API_VERSION_PATCH 0

/// @brief The <a href=https://semver.org/>Semantic Version</a> of the API
/// including any additional labels.
#define SIMX_API_VERSION "0.0.0"

/// @}


/// @defgroup error Errors
/// @brief How to determine if an operation has succeeded or failed.
/// @{

/// @defgroup error_code Error Codes
/// @brief The different categories of error that can occur in SimX.
/// @{

/// @brief The function executed successfully.
#define SIMX_ERROR_NONE 0
/// @brief The function executed unsuccessfully.
#define SIMX_ERROR_UNSPECIFIED 1
/// @brief One or more function arguments were @c NULL when they were not
/// allowed to be.
#define SIMX_ERROR_ARGUMENT_NULL 2
/// @brief One or more function arguments were outside of the range of
/// acceptable values.
#define SIMX_ERROR_ARGUMENT_OUT_OF_RANGE 3
/// @brief The function failed to allocate the required memory.
#define SIMX_ERROR_INSUFFICIENT_MEMORY 4

/// @}
/// @}


/// @defgroup logging Logging
/// @brief How to trace the flow of execution in a SimX implementation and
/// monitor events the occur.
/// @{

/// @defgroup log_level Log Levels
/// @brief The different levels of log message severity.
/// @{

/// @brief Very fine-grained information describing the flow of execution.
#define SIMX_LOG_LEVEL_TRACE 0
/// @brief Fine-grained information useful for debugging.
#define SIMX_LOG_LEVEL_DEBUG 1
/// @brief A notable event.
#define SIMX_LOG_LEVEL_INFO 2
/// @brief An unexpected event which may indicate something has gone wrong.
#define SIMX_LOG_LEVEL_WARN 3
/// @brief An error that must be handled by the caller.
#define SIMX_LOG_LEVEL_ERROR 4
/// @brief A fatal event that cannot be recovered from.
#define SIMX_LOG_LEVEL_FATAL 5

/// @}
/// @}


/// @defgroup entity Entities
/// @brief How to interact with SimX entities.
/// @{

/// @struct SIMXentity
/// @brief An instance of a model entity.
/// 
/// This structure is deliberately opaque for the purposes of data hiding /
/// encapsulation. To interact with an entity use @ref entity "entity"
/// functions.
struct SIMXentity;

/// @}


/// @defgroup common_data_structures Common Data Structures
/// @brief Data structures likely to be used by many extensions.
/// @{

/// @brief A Cartesian vector composed of three double precision components.
struct SIMXvector3 {
    /// @brief The x component.
    double x;
    /// @brief The y component.
    double y;
    /// @brief The z component.
    double z;
};

/// @brief A quaternion composed of four double precision components.
struct SIMXquaternion {
    /// @brief The x value of the vector component.
    double x;
    /// @brief The y value of the vector component.
    double y;
    /// @brief The z value of the vector component.
    double z;
    /// @brief The rotation component.
    double w;
};

/// @}


/// @ingroup version
/// @brief Get the <a href=https://semver.org/>Semantic Version</a> number of
/// the SimX Core Interface.
/// @param[out] major The major version of the API.
/// @param[out] minor The minor version of the API.
/// @param[out] patch The patch version of the API.
/// @return
/// - If @p major, @p minor or @p patch is @c NULL returns
///   #SIMX_ERROR_ARGUMENT_NULL.
/// - Else returns #SIMX_ERROR_NONE.
SIMX_API int simx_get_api_version_number(int* major, int* minor, int* patch);

/// @ingroup version
/// @brief Get the <a href=https://semver.org/>Semantic Version</a> of the SimX
/// Core Interface including any
/// additional labels.
/// @return The version of the API as a null-terminated UTF-8 string.
SIMX_API const char* simx_get_api_version();


/// @defgroup meta Metadata
/// @brief How to get a description of the implementation and the extensions it
/// supports.
/// @{

/// @brief Get the name of the implementation.
///
/// This should be a human-readable "friendly name" suitable for showing to a
/// non-expert user.
/// @return The name of the implementation as a null-terminated UTF-8 string.
SIMX_API const char* simx_get_implementation_name();

/// @brief Get a description of the implementation.
///
/// This should be a brief human-readable description of the implementation.
/// @note The description should be unformatted (no control characters, HTML,
/// Markdown etc.).
/// @return A description of the implementation as a null-terminated UTF-8
/// string.
SIMX_API const char* simx_get_implementation_description();

/// @brief Get the version of the implementation.
///
/// The format of the version information is implementation-dependent but
/// <a href=https://semver.org/>Semantic Versioning</a> is encouraged.
/// @warning As the version information does not have a fixed format it should
/// only be used for informational purposes.
/// @return The version of the implementation as a null-terminated UTF-8 string.
SIMX_API const char* simx_get_implementation_version();

/// @brief Get the author(s) of the implementation.
///
/// The format of the author information is implementation-dependent but should
/// be sufficient for users to make contact.
/// @return The author(s) of the implementation as a null-terminated UTF-8
/// string.
SIMX_API const char* simx_get_implementation_author();

/// @brief Get the extension interfaces this implementation supports.
/// @param[out] extensions A list of supported extension identifiers as
/// null-terminated UTF-8 strings.
/// @param[out] length The length of @p interfaces.
/// @return
/// - If @p extensions or @p length is @c NULL returns
///   #SIMX_ERROR_ARGUMENT_NULL.
/// - Else returns #SIMX_ERROR_NONE.
SIMX_API int simx_get_extensions(char** extensions, int* length);

/// @}


/// @ingroup error
/// @brief Get the message describing the most recent error.
///
/// If a function returns an @ref error_code "error code" this function can be
/// called to get a human-readable description of the error that occurred.
/// @note The returned pointer is only valid until the next time an error
/// occurs; to persist the string copy it to caller-owned memory.
/// @return The message describing the most recent error as a null-terminated
/// UTF-8 string.
SIMX_API const char* simx_get_error_message();


/// @ingroup logging
/// @brief The definition of a SimX log callback.
/// @param[in] level The @ref log_level "log level" of this message.
/// @param[in] message The message as a null-terminated UTF-8 string.
/// @param[in] user_data The @p user_data argument that was passed to
/// @ref simx_set_log_callback / @ref simx_set_entity_log_callback when this
/// callback was set.
/// @sa simx_set_log_callback
/// @sa simx_set_entity_log_callback
typedef void (*simx_log_callback)(int level, const char* message, void* user_data);

/// @ingroup logging
/// @brief Set the log callback for global events.
/// 
/// This log callback will be invoked for any log events which are not
/// associated with a particular instance of an object (such as a
/// @ref SIMXentity).
/// @param[in] callback The callback to invoke for future global log events.
/// @param[in] user_data
/// @return Returns #SIMX_ERROR_NONE.
SIMX_API int simx_set_log_callback(simx_log_callback callback, void* user_data);

/// @ingroup logging
/// @brief Set the log callback for an entity's events.
/// 
/// This log callback will be invoked for all log events associated with the
/// given instance of @ref SIMXentity.
/// @param[in] entity The entity this callback is to be associated with.
/// @param[in] callback The callback to invoke for future global log events.
/// @param[in] user_data
/// @return
/// - If @p entity is @c NULL returns #SIMX_ERROR_ARGUMENT_NULL.
/// - Else returns #SIMX_ERROR_NONE.
SIMX_API int simx_set_entity_log_callback(struct SIMXentity* entity, simx_log_callback callback, void* user_data);


/// @ingroup entity
/// @brief Create a new entity.
/// @param[out] entity The newly created entity.
/// @return
/// - If @p entity is @c NULL returns #SIMX_ERROR_ARGUMENT_NULL.
/// - If a new entity cannot be allocated returns
///   #SIMX_ERROR_INSUFFICIENT_MEMORY.
/// - Else returns #SIMX_ERROR_NONE.
SIMX_API int simx_create_entity(struct SIMXentity** entity);

/// @ingroup entity
/// @brief Advance an entity by one timestep.
/// @param[in] entity The entity to advance.
/// @return 
/// - If @p entity is @c NULL returns #SIMX_ERROR_ARGUMENT_NULL.
/// - Else returns #SIMX_ERROR_NONE.
SIMX_API int simx_step_entity(struct SIMXentity* entity);

/// @ingroup entity
/// @brief Destroy an entity.
/// @remark Destroying a @c NULL pointer is permissible.
/// @warning Destroying an entity more that once will result in undefined
/// behavior.
/// @param[in] entity The entity to destroy.
SIMX_API void simx_destroy_entity(struct SIMXentity* entity);

/// @ingroup entity
/// @brief Get the amount of logical time that an entity has simulated.
/// @remarks Not all entities are guaranteed to use a fixed timestep - use this
/// function directly rather than performing calculations using @ref
/// simx_get_entity_timestep() and @ref simx_get_entity_iteration().
/// @param[in] entity The entity for which to get the logical time.
/// @param[out] time The amount of logical time that @p entity has simulated
/// in seconds.
/// @sa simx_step_entity()
/// @return 
/// - If @p entity or @p time is @c NULL returns #SIMX_ERROR_ARGUMENT_NULL.
/// - Else returns #SIMX_ERROR_NONE.
SIMX_API int simx_get_entity_time(const struct SIMXentity* entity, double* time);

/// @ingroup entity
/// @brief Get the amount of logical time that elapses during an entity
/// timestep.
/// @remarks Not all entities are guaranteed to use a fixed timestep - use this
/// function directly rather than performing calculations using @ref
/// simx_get_entity_time() and @ref simx_get_entity_iteration().
/// @param[in] entity The entity for which to get the logical timestep.
/// @param[out] timestep Delta time in seconds.
/// @sa simx_step_entity()
/// @return 
/// - If @p entity or @p timestep is @c NULL returns #SIMX_ERROR_ARGUMENT_NULL.
/// - Else returns #SIMX_ERROR_NONE.
SIMX_API int simx_get_entity_timestep(const struct SIMXentity* entity, double* timestep);

/// @ingroup entity
/// @brief Get the number of timesteps that an entity has simulated.
/// @remarks Not all entities are guaranteed to use a fixed timestep - use this
/// function directly rather than performing calculations using @ref
/// simx_get_entity_time() and @ref simx_get_entity_timestep().
/// @param[in] entity The entity for which to get the number of iterations.
/// @param[out] time The number of iterations that @p entity has simulated.
/// @sa simx_step_entity()
/// @return 
/// - If @p entity or @p iteration is @c NULL returns #SIMX_ERROR_ARGUMENT_NULL.
/// - Else returns #SIMX_ERROR_NONE.
SIMX_API int simx_get_entity_iteration(const struct SIMXentity* entity, long long* iteration);


#endif /* SIMX_H */
