#include "cbase.h"
#include "utils.h"

/*

// Handles messages generated by API routines
void STDCALL receiveLogMessage(void *, const char *buf, int buf_len)
{
    std::cerr << std::string(buf);
}

bool processKeyPress(smEngine engine, HWND video_display)
{
    if (!_kbhit())
    {
        return true;
    }
    char key = _getch();
    switch (key)
    {
    case 'r':
        {
            // Manually restart the tracking
            THROW_ON_ERROR(smEngineStart(engine));
        }
        return true;
    case 'a':
        {
            // Toggle auto-restart mode
            int on;
            smEngineType type;
            THROW_ON_ERROR(smEngineGetType(engine,&type));
            switch (type)
            {
            case SM_API_ENGINE_TYPE_HEAD_TRACKER_V1:
                THROW_ON_ERROR(smHTV1GetAutoRestartMode(engine,&on));
                THROW_ON_ERROR(smHTV1SetAutoRestartMode(engine,!on));
                break;
            case SM_API_ENGINE_TYPE_HEAD_TRACKER_V2:
                THROW_ON_ERROR(smHTV2GetAutoRestartMode(engine,&on));
                THROW_ON_ERROR(smHTV2SetAutoRestartMode(engine,!on));
                break;
            }
        }
        return true;
    case 'm':
        {
            // Move the video window to the right by 10 pixels
            RECT win_rect;
            if (GetWindowRect(video_display,&win_rect))
            {
                int width = win_rect.right - win_rect.left;
                int height = win_rect.bottom - win_rect.top;
                MoveWindow(video_display, win_rect.left+10, win_rect.top, width, height, true);
            }
        }
        return true;
    case 's':
        {
            // Make the video window a bit larger
            RECT win_rect;
            if (GetWindowRect(video_display,&win_rect))
            {
                int width = win_rect.right - win_rect.left;
                int height = win_rect.bottom - win_rect.top;
                MoveWindow(video_display, win_rect.left, win_rect.top, width+32, height+24, true);
            }
        }
        return true;
    case 'h':
        {
            // Toggle the visibility of the video window
            static bool hide = true;
            ShowWindow(video_display,hide?SW_HIDE:SW_SHOWNA);
            hide = !hide;
        }
        return true;
    default:
        return false;
    }
}
*/

float radToDeg(float rad)
{
	return rad*57.2957795f;
}

float degToRad(float deg)
{
	return deg/57.2957795f;
}

// Handles messages generated by API routines
void STDCALL receiveLogMessage(void *, const char *buf, int /*buf_len*/)
{
    std::cerr << std::string(buf);
}

bool processKeyPress(smEngineHandle engine, HWND video_display)
{
    if (!_kbhit())
    {
        return true;
    }
    int key = _getch();
    switch (key)
    {
    case 'r':
        {
            // Manually restart the tracking
            THROW_ON_ERROR(smEngineStart(engine));
        }
        return true;
    case 'a':
        {
            // Toggle auto-restart mode
            int on;
            THROW_ON_ERROR(smHTGetAutoRestartMode(engine,&on));
            THROW_ON_ERROR(smHTSetAutoRestartMode(engine,!on));
        }
        return true;
    case 'm':
        {
            // Move the video window to the right by 10 pixels
            RECT win_rect;
            if (GetWindowRect(video_display,&win_rect))
            {
                int width = win_rect.right - win_rect.left;
                int height = win_rect.bottom - win_rect.top;
                MoveWindow(video_display, win_rect.left+10, win_rect.top, width, height, true);
            }
        }
        return true;
    case 's':
        {
            // Make the video window a bit larger
            RECT win_rect;
            if (GetWindowRect(video_display,&win_rect))
            {
                int width = win_rect.right - win_rect.left;
                int height = win_rect.bottom - win_rect.top;
                MoveWindow(video_display, win_rect.left, win_rect.top, width+32, height+24, true);
            }
        }
        return true;
    case 'h':
        {
            // Toggle the visibility of the video window
            static bool hide = true;
            ShowWindow(video_display,hide?SW_HIDE:SW_SHOWNA);
            hide = !hide;
        }
        return true;
    default:
        return false;
    }
}

