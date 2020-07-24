﻿#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"
#include "Globals.h"
#include "Profiles.h"
#include "ColorSchemes.h"
#include "Keybindings.h"

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::TerminalSettings::implementation
{
    MainPage::MainPage()
    {
        InitializeComponent();

        // TODO: When we actually connect this to Windows Terminal,
        //       this section will clone the active AppSettings
        _settingsSource = AppSettings();
        _settingsClone = _settingsSource.Clone();
    }

    int32_t MainPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void MainPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {

    }

    void MainPage::SettingsNav_Loaded(IInspectable const&, RoutedEventArgs const&)
    {
        //// set the initial selectedItem
        for (uint32_t i = 0; i < SettingsNav().MenuItems().Size(); i++)
        {
            const auto item = SettingsNav().MenuItems().GetAt(i).as<Controls::NavigationViewItemBase>();
            const hstring globalsNav = L"Globals_Nav";
            const hstring itemTag = unbox_value<hstring>(item.Tag());

            if (itemTag == globalsNav)
            {
                item.IsSelected(true);
                SettingsNav().Header() = item.Tag();
                break;
            }
        }

        contentFrame().Navigate(xaml_typename<TerminalSettings::Globals>());
    }

    void MainPage::SettingsNav_SelectionChanged(Controls::NavigationView sender, Controls::NavigationViewSelectionChangedEventArgs args)
    {

    }

    void MainPage::SettingsNav_ItemInvoked(Controls::NavigationView sender, Controls::NavigationViewItemInvokedEventArgs args)
    {
        Controls::TextBlock item = args.InvokedItem().as<Controls::TextBlock>();

        if (item != NULL)
        {
            const hstring globalsPage = L"Globals_Page";
            const hstring profilesPage = L"Profiles_Page";
            const hstring colorSchemesPage = L"ColorSchemes_Page";
            const hstring keybindingsPage = L"Keybindings_Page";

            if (unbox_value<hstring>(item.Tag()) == globalsPage)
            {
                contentFrame().Navigate(xaml_typename<TerminalSettings::Globals>());
            }
            else if (unbox_value<hstring>(item.Tag()) == profilesPage)
            {
                contentFrame().Navigate(xaml_typename<TerminalSettings::Profiles>());
            }
            else if (unbox_value<hstring>(item.Tag()) == colorSchemesPage)
            {
                contentFrame().Navigate(xaml_typename<TerminalSettings::ColorSchemes>());
            }
            else if (unbox_value<hstring>(item.Tag()) == keybindingsPage)
            {
                contentFrame().Navigate(xaml_typename<TerminalSettings::Keybindings>());
            }
        }
    }
}


//void winrt::TerminalSettings::implementation::MainPage::SettingsNav_SelectionChanged(winrt::Windows::UI::Xaml::Controls::NavigationView const& sender, winrt::Windows::UI::Xaml::Controls::NavigationViewSelectionChangedEventArgs const& args)
//{
//
//}
