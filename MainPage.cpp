#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"

using namespace winrt;
using namespace Windows::UI::Xaml;
using namespace Windows::System;
using namespace Windows::UI::Xaml::Controls;
using namespace winrt::Windows::Devices::SerialCommunication;
using namespace winrt::Windows::Devices::Enumeration;
using namespace winrt::Windows::Storage::Streams;

namespace winrt::RC_FPV_GUI::implementation
{
    int32_t MainPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void MainPage::W_Button_Click(IInspectable const&, RoutedEventArgs const&)
    {
        switch (wButton) {
            case false:
			    W_Button().Background(Media::SolidColorBrush(Windows::UI::Colors::LightGray()));
			    wButton = true;
			    break;
            case true:
                W_Button().Background(Media::SolidColorBrush(Windows::UI::Colors::Gray()));
                wButton = false;
                break;
        }
    }

    void MainPage::A_Button_Click(IInspectable const&, RoutedEventArgs const&)
    {
        switch (aButton) {
        case false:
			A_Button().Background(Media::SolidColorBrush(Windows::UI::Colors::LightGray()));
			aButton = true;
			break;
            case true:
                A_Button().Background(Media::SolidColorBrush(Windows::UI::Colors::Gray()));
                aButton = false;
                break;
        }
    }

    void MainPage::S_Button_Click(IInspectable const&, RoutedEventArgs const&)
    {
        switch (sButton) {
        case false:
            S_Button().Background(Media::SolidColorBrush(Windows::UI::Colors::LightGray()));
            sButton = true;
            break;
        case true:
            S_Button().Background(Media::SolidColorBrush(Windows::UI::Colors::Gray()));
            sButton = false;
            break;
        }
    }

    void MainPage::D_Button_Click(IInspectable const&, RoutedEventArgs const&)
    {
        switch (dButton) {
        case false:
            D_Button().Background(Media::SolidColorBrush(Windows::UI::Colors::LightGray()));
            dButton = true;
            break;
        case true:
            D_Button().Background(Media::SolidColorBrush(Windows::UI::Colors::Gray()));
            dButton = false;
            break;
        }
    }

    void MainPage::HandleKeyDown(Windows::Foundation::IInspectable const& sender, Input::KeyRoutedEventArgs const& e)
    {
        switch (e.Key())
        {
        case Windows::System::VirtualKey::W:
            if (wButton == false) { W_Button_Click(sender, e); }
            break;
        case Windows::System::VirtualKey::A:
            if (aButton == false) { A_Button_Click(sender, e); }
            break;
        case Windows::System::VirtualKey::S:
            if (sButton == false) { S_Button_Click(sender, e); }
            break;
        case Windows::System::VirtualKey::D:
            if (dButton == false) { D_Button_Click(sender, e); }
            break;
        }
    }
    void MainPage::HandleKeyUp(Windows::Foundation::IInspectable const& sender, Input::KeyRoutedEventArgs const& e)
    {
        switch (e.Key())
        {
        case Windows::System::VirtualKey::W:
            W_Button_Click(sender, e);
            break;
        case Windows::System::VirtualKey::A:
            A_Button_Click(sender, e);
            break;
        case Windows::System::VirtualKey::S:
            S_Button_Click(sender, e);
            break;
        case Windows::System::VirtualKey::D:
            D_Button_Click(sender, e);
            break;
        }
    }
    void winrt::RC_FPV_GUI::implementation::MainPage::Page_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
    {
        OutputDebugString(L"Hello, Debug Output!\n");
        //auto selector = SerialDevice::GetDeviceSelector();
        //auto devices = DeviceInformation::FindAllAsync(selector).get();
        auto selector = winrt::Windows::Devices::SerialCommunication::SerialDevice::GetDeviceSelector();
        auto devices = winrt::Windows::Devices::Enumeration::DeviceInformation::FindAllAsync(selector).get();
    }
}
