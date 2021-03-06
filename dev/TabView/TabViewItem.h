﻿// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

#pragma once

#include "pch.h"
#include "common.h"

#include "TabView.h"
#include "TabViewItem.g.h"
#include "TabViewItem.properties.h"
#include "TabViewItemAutomationPeer.h"
#include "TabViewItemTemplateSettings.h"

class TabViewItem :
    public ReferenceTracker<TabViewItem, winrt::implementation::TabViewItemT>,
    public TabViewItemProperties
{

public:
    TabViewItem();

    // IFrameworkElement
    void OnApplyTemplate();

    // IUIElement
    winrt::AutomationPeer OnCreateAutomationPeer();

    void OnIsClosablePropertyChanged(const winrt::DependencyPropertyChangedEventArgs& args);
    void OnHeaderPropertyChanged(const winrt::DependencyPropertyChangedEventArgs& args);
    void OnIconSourcePropertyChanged(const winrt::DependencyPropertyChangedEventArgs& args);

    void OnPointerEntered(winrt::PointerRoutedEventArgs const& args);
    void OnPointerExited(winrt::PointerRoutedEventArgs const& args);
    void OnPointerPressed(winrt::PointerRoutedEventArgs const& args);
    void OnPointerReleased(winrt::PointerRoutedEventArgs const& args);
    void OnPointerCanceled(winrt::PointerRoutedEventArgs const& args);
    void OnPointerCaptureLost(winrt::PointerRoutedEventArgs const& args);

    void RaiseRequestClose(TabViewTabCloseRequestedEventArgs const& args);

 private:
    tracker_ref<winrt::Button> m_closeButton{ this };
    tracker_ref<winrt::ToolTip> m_toolTip{ this };

    void UpdateCloseButton();
    void RequestClose();
    void OnIconSourceChanged();

    bool m_firstTimeSettingToolTip{ true };

    winrt::ButtonBase::Click_revoker m_closeButtonClickRevoker{};

    void OnLoaded(const winrt::IInspectable& sender, const winrt::RoutedEventArgs& args);
    void OnCloseButtonClick(const winrt::IInspectable& sender, const winrt::RoutedEventArgs& args);

    bool m_hasPointerCapture = false;
    bool m_isMiddlePointerButtonPressed = false;
};
