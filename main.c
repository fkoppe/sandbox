#include <dark/darkinfo.h>
#include <dark/darkstar.h>
#include <dark/darktest.h>
#include <dark/char/string_struct.h>
#include <dark/stream/ostream_struct.h>

static const Dark_Library LIBRARY_SANDBOX= { "sandbox", DARK_VERSION_MAKE(0, 0, 1, 0), ___DARK_CONFIGURATION, DARK_CONSOLE_COLOR_EFG_BLUE };

#undef DARK_LIBRARY
#define DARK_LIBRARY &LIBRARY_SANDBOX

//#undef DARK_MODULE
//#define DARK_MODULE "core"

//#undef DARK_UNIT
//#define DARK_UNIT "main"

int main()
{
    Dark_Allocator* const allocator = dark_os_allocator_new();













    Dark_Mutex* mutex = dark_mutex_new(allocator);

    Dark_Ostream_Settings ostream_settings;
    ostream_settings.keep_open_is = true;
    ostream_settings.binary_is = false;
    ostream_settings.force_size_is = false;
    ostream_settings.buffer_size = 10000;
    ostream_settings.auto_flush_ns = dark_duration_s_to_ns(2);

    Dark_Ostream* const file_stream = dark_ostream_new_file(allocator, ostream_settings, "log.txt", NULL);
    Dark_Ostream* const ostream = dark_ostream_new_stdout(allocator, ostream_settings, NULL);

    Dark_Logger_Settings logger_settings;
    logger_settings.name = "";
    logger_settings.log_is = true;
    logger_settings.update_is = false;

    Dark_Logger* const logger = dark_logger_new(allocator, logger_settings);
    Dark_Logger* const logger2 = dark_logger_new(allocator, logger_settings);
    Dark_Logger* const logger3 = dark_logger_new(allocator, logger_settings);
    Dark_Logger* const logger4 = dark_logger_new(allocator, logger_settings);

    Dark_Logger_Ostream_Settings logger_ostream_settings;
    logger_ostream_settings.color_is = true;
    logger_ostream_settings.level_min = DARK_LOG_LEVEL_TRACE;
    logger_ostream_settings.format.timestamp_is = true;
    logger_ostream_settings.format.thread = DARK_LOGGER_THREAD_HEX;
    logger_ostream_settings.format.name_is = true;
    logger_ostream_settings.format.library_is = true;
    logger_ostream_settings.format.module_is = true;
    logger_ostream_settings.format.unit_is = true;

    dark_logger_ostream_add(logger, logger_ostream_settings, ostream, NULL);
    dark_logger_ostream_add(logger2, logger_ostream_settings, ostream, NULL);
    dark_logger_ostream_add(logger3, logger_ostream_settings, ostream, NULL);
    dark_logger_ostream_add(logger4, logger_ostream_settings, ostream, NULL);

    //logger_ostream_settings.color_is = false;
    dark_logger_ostream_add(logger, logger_ostream_settings, file_stream, NULL);

    DARK_PLOG_CSTRING(logger, DARK_LOG_LEVEL_TRACE, "a test log message of some sort");
    DARK_DLOG_CSTRING(logger, DARK_LOG_LEVEL_COMMENT, "a test log message of some sort");
    DARK_LOG_CSTRING(logger, DARK_LOG_LEVEL_DEBUG, "a test log message of some sort");
    DARK_LOG_CSTRING(logger, DARK_LOG_LEVEL_NOTE, "a test log message of some sort");
    DARK_LOG_CSTRING(logger, DARK_LOG_LEVEL_INFO, "a test log message of some sort");
    DARK_LOG_CSTRING(logger, DARK_LOG_LEVEL_NOTICE, "a test log message of some sort");
    DARK_DLOG_CSTRING(logger, DARK_LOG_LEVEL_WARN, "a test log message of some sort");
    DARK_LOG_CSTRING(logger, DARK_LOG_LEVEL_ERROR, "a test log message of some sort");
    DARK_LOG_CSTRING(logger, DARK_LOG_LEVEL_CRITICAL, "a test log message of some sort");
    DARK_LOG_CSTRING(logger, DARK_LOG_LEVEL_ALERT, "a test log message of some sort");
    DARK_LOG_CSTRING(logger, DARK_LOG_LEVEL_EMERGENCY, "a test log message of some sort");

    DARK_LOG_CSTRING(logger2, DARK_LOG_LEVEL_TRACE, "a test log message of some sort");
    DARK_LOG_CSTRING(logger2, DARK_LOG_LEVEL_COMMENT, "a test log message of some sort");
    DARK_LOG_CSTRING(logger2, DARK_LOG_LEVEL_DEBUG, "a test log message of some sort");
    DARK_LOG_CSTRING(logger2, DARK_LOG_LEVEL_NOTE, "a test log message of some sort");
    DARK_PLOG_CSTRING(logger2, DARK_LOG_LEVEL_INFO, "a test log message of some sort");
    DARK_LOG_CSTRING(logger2, DARK_LOG_LEVEL_NOTICE, "a test log message of some sort");
    DARK_LOG_CSTRING(logger2, DARK_LOG_LEVEL_WARN, "a test log message of some sort");
    DARK_LOG_CSTRING(logger2, DARK_LOG_LEVEL_ERROR, "a test log message of some sort");
    DARK_LOG_CSTRING(logger2, DARK_LOG_LEVEL_CRITICAL, "a test log message of some sort");
    DARK_LOG_CSTRING(logger2, DARK_LOG_LEVEL_ALERT, "a test log message of some sort");
    DARK_LOG_CSTRING(logger2, DARK_LOG_LEVEL_EMERGENCY, "a test log message of some sort");

    DARK_LOG_CSTRING(logger3, DARK_LOG_LEVEL_TRACE, "a test log message of some sort");
    DARK_LOG_CSTRING(logger3, DARK_LOG_LEVEL_COMMENT, "a test log message of some sort");
    DARK_LOG_CSTRING(logger3, DARK_LOG_LEVEL_DEBUG, "a test log message of some sort");
    DARK_LOG_CSTRING(logger3, DARK_LOG_LEVEL_NOTE, "a test log message of some sort");
    DARK_LOG_CSTRING(logger3, DARK_LOG_LEVEL_INFO, "a test log message of some sort");
    DARK_LOG_CSTRING(logger3, DARK_LOG_LEVEL_NOTICE, "a test log message of some sort");
    DARK_LOG_CSTRING(logger3, DARK_LOG_LEVEL_WARN, "a test log message of some sort");
    DARK_LOG_CSTRING(logger3, DARK_LOG_LEVEL_ERROR, "a test log message of some sort");
    DARK_LOG_CSTRING(logger3, DARK_LOG_LEVEL_CRITICAL, "a test log message of some sort");
    DARK_LOG_CSTRING(logger3, DARK_LOG_LEVEL_ALERT, "a test log message of some sort");
    DARK_LOG_CSTRING(logger3, DARK_LOG_LEVEL_EMERGENCY, "a test log message of some sort");

    DARK_LOG_CSTRING(logger4, DARK_LOG_LEVEL_TRACE, "a test log message of some sort");
    DARK_LOG_CSTRING(logger4, DARK_LOG_LEVEL_COMMENT, "a test log message of some sort");
    DARK_LOG_CSTRING(logger4, DARK_LOG_LEVEL_DEBUG, "a test log message of some sort");
    DARK_LOG_CSTRING(logger4, DARK_LOG_LEVEL_NOTE, "a test log message of some sort");
    DARK_LOG_CSTRING(logger4, DARK_LOG_LEVEL_INFO, "a test log message of some sort");
    DARK_LOG_CSTRING(logger4, DARK_LOG_LEVEL_NOTICE, "a test log message of some sort");
    DARK_LOG_CSTRING(logger4, DARK_LOG_LEVEL_WARN, "a test log message of some sort");
    DARK_LOG_CSTRING(logger4, DARK_LOG_LEVEL_ERROR, "a test log message of some sort");
    DARK_LOG_CSTRING(logger4, DARK_LOG_LEVEL_CRITICAL, "a test log message of some sort");
    DARK_LOG_CSTRING(logger4, DARK_LOG_LEVEL_ALERT, "a test log message of some sort");
    DARK_LOG_CSTRING(logger4, DARK_LOG_LEVEL_EMERGENCY, "a test log message of some sort");

    dark_logger_delete(logger);
    dark_logger_delete(logger2);
    dark_logger_delete(logger3);
    dark_logger_delete(logger4);

    dark_ostream_delete(ostream);
    dark_ostream_delete(file_stream);

    dark_mutex_delete(mutex);

    dark_os_allocator_delete(allocator);

    return DARK_EXIT_SUCCESS;
}
