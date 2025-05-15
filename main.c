#include <dark/darkinfo.h>
#include <dark/darkstar.h>
#include <dark/darktest.h>
#include <dark/char/string_struct.h>
#include <dark/stream/ostream_struct.h>

#include <deep/deepnova.h>

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

    Dark_Ostream* const file_stream = dark_ostream_new_file(allocator, ostream_settings, dark_cstring_to_cbuffer_view("log.txt"), NULL);
    Dark_Ostream* const ostream = dark_ostream_new_stdout(allocator, ostream_settings, NULL);

    Dark_Logger_Settings logger_settings;
    logger_settings.name = "";
    logger_settings.log_is = true;
    logger_settings.update_is = false;

    Dark_Logger* const logger = dark_logger_new(allocator, logger_settings);

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

    logger_ostream_settings.color_is = false;
    dark_logger_ostream_add(logger, logger_ostream_settings, file_stream, NULL);

    Dark_Entropy entropy_pool = dark_entropy_seed();

    Deep_Event_Queue* const event_queue = deep_event_queue_new(allocator, logger);

    deep_handler_initialise(allocator, &entropy_pool, event_queue, logger);

    Deep_Window_Settings window_settings;
    window_settings.title = dark_cstring_to_cbuffer_view("test window");
    window_settings.file_drop_is = false;
    window_settings.min.is = false;
    window_settings.max.is = false;

    Deep_Grafic_Extend extend = { .width = 1920, .height = 1080};

    Deep_Window* const window = deep_window_new(allocator, 0, window_settings, event_queue, logger);

    Deep_Window_Option_Array options;
    options.data[DEEP_WINDOW_OPTION_RESIZE] = true;
    options.data[DEEP_WINDOW_OPTION_VISIBLE] = true;
    options.data[DEEP_WINDOW_OPTION_DECORATE] = true;
    options.data[DEEP_WINDOW_OPTION_FOCUS] = true;

    deep_window_open_windowed(window, options, extend);
    //dark_window_open_fullscreen(window);

    //-----GAMELOOP-----

    Dark_Stopwatch* const stopwatch = dark_stopwatch_new_start(allocator);

    bool done = false;

    while(dark_stopwatch_s(stopwatch) < 5)
    {
        if(dark_stopwatch_s(stopwatch) > 1 && !done)
        {
            done = true;
            //dark_window_fullscreen(window);
        }

        while(deep_event_queue_next_is(event_queue))
        {
            const Deep_Event event = deep_event_queue_next(event_queue);

            switch(event.type)
                {
                case DEEP_EVENT_TYPE_SCROLLED:
                    break;
                    //DARK_PRINTF_DEBUG("scrolled %lf-%lf\n", event->data.scroll.x, event->data.scroll.y);
                case DEEP_EVENT_TYPE_CURSOR_MOVED:
                    break;
                    //DARK_PRINTF_DEBUG("moved %i-%i\n", event->data.position.x, event->data.position.y);
                case DEEP_EVENT_TYPE_KEY_REPEATED:
                    int i = event.data.keyboard.key;
                    DARK_PRINTF_DEBUG("key %i\n", i);
                    break;

                default:
                    break;
                }
        }

        dark_ostream_update(ostream);
    }

    dark_stopwatch_delete(stopwatch);

    //------------------

    deep_window_close(window);

    deep_window_delete(window);

    deep_handler_shutdown();

    deep_event_queue_delete(event_queue);

    dark_logger_delete(logger);

    dark_ostream_delete(ostream);
    dark_ostream_delete(file_stream);

    dark_mutex_delete(mutex);

    dark_os_allocator_delete(allocator);

    return DARK_EXIT_SUCCESS;
}
