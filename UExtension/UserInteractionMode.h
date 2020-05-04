#pragma once
#include "UserInteractionMode.g.h"
#include "Wnf.h"
#include "SysProc.h"
#include "winrt/Windows.System.Profile.h"
#include <winstring.h>
#include "winrt/Windows.UI.Xaml.h"

typedef enum class UserInteractionType
{
    MouseInDesktopMode = 0,
    TouchInDesktopMode = 1,
    MouseInTabletMode = 2,
    TouchInTabletMode = 3
};

namespace winrt::UExtension::implementation
{
    struct UserInteractionMode : UserInteractionModeT<UserInteractionMode>
    {
        UserInteractionMode()
        {
            Wnf::InitLib();
            SysProc::InitLib();
        }

        winrt::event_token DesktopTabletModeEvent(Windows::Foundation::EventHandler<UserInteractionType> const& handler);
        void DesktopTabletModeEvent(winrt::event_token const& token) noexcept;

        UserInteractionType GetUserInteractionMode();
        int GetSlateState();
        int GetDockState();

        void InvokeTabletModeChange();
        bool IsSubscribed()
        {
            return isSubscribed;
        }
    private:
        int GetSlateStateInt();
        winrt::event<Windows::Foundation::EventHandler<UserInteractionType>> event_desktopTabletModeEvent;
        int numSub_desktopTabletModeEvent = 0;
        bool firstTimeSubscription = true;
        bool isSubscribed = false;
    };
}
namespace winrt::UExtension::factory_implementation
{
    struct UserInteractionMode : UserInteractionModeT<UserInteractionMode, implementation::UserInteractionMode>
    {
    };
}