#pragma once

#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/checkbox.h>
#include <wx/radiobut.h>

#include "settings.h"

wxDECLARE_EVENT(SETTINGS_CHANGED_EVENT, wxCommandEvent);
wxDEFINE_EVENT(SETTINGS_CHANGED_EVENT, wxCommandEvent);

class SettingsPanel : public wxPanel
{
public:
    SettingsPanel(wxWindow *parent) : wxPanel(parent, wxID_ANY)
    {
        auto sizer = new wxBoxSizer(wxVERTICAL);

        zBufferCheckBox = new wxCheckBox(this, wxID_ANY, "Z-Buffer");

        lessZBufferOrderRadioButton = new wxRadioButton(this, wxID_ANY, "Less",
                                                        wxDefaultPosition, wxDefaultSize, wxRB_GROUP);

        greaterZBufferOrderRadioButton = new wxRadioButton(this, wxID_ANY, "Greater");

        sizer->Add(zBufferCheckBox, 0, wxALL, FromDIP(5));

        auto zBufferGroupSizer = new wxBoxSizer(wxVERTICAL);
        zBufferGroupSizer->Add(lessZBufferOrderRadioButton, 0, wxLEFT | wxBOTTOM, FromDIP(5));
        zBufferGroupSizer->Add(greaterZBufferOrderRadioButton, 0, wxLEFT | wxBOTTOM, FromDIP(5));

        sizer->Add(zBufferGroupSizer, 0, wxLEFT, FromDIP(5));

        SetSizer(sizer);

        UpdateBoxes();
        SetupCallbacks();
    }

    void SetSettings(const Settings &settings)
    {
        this->settings = settings;
        UpdateBoxes();
    }

    Settings GetSettings() const
    {
        return settings;
    }

private:
    Settings settings;

    wxCheckBox *zBufferCheckBox{nullptr};
    wxRadioButton *lessZBufferOrderRadioButton{nullptr}, *greaterZBufferOrderRadioButton{nullptr};

    void UpdateBoxes()
    {
        zBufferCheckBox->SetValue(settings.zBufferEnabled);

        lessZBufferOrderRadioButton->SetValue(settings.zBufferOrder == Settings::ZBufferOrder::Less);
        greaterZBufferOrderRadioButton->SetValue(settings.zBufferOrder == Settings::ZBufferOrder::Greater);

        lessZBufferOrderRadioButton->Enable(settings.zBufferEnabled);
        greaterZBufferOrderRadioButton->Enable(settings.zBufferEnabled);
    }

    void SetupCallbacks()
    {
        zBufferCheckBox->Bind(wxEVT_CHECKBOX, [this](wxCommandEvent &event)
                              {
            settings.zBufferEnabled = event.IsChecked();
            UpdateBoxes();
            PostSettingsChangedEvent(); });

        lessZBufferOrderRadioButton->Bind(wxEVT_RADIOBUTTON, [this](wxCommandEvent &event)
                                          {
            settings.zBufferOrder = Settings::ZBufferOrder::Less;
            UpdateBoxes();
            PostSettingsChangedEvent(); });

        greaterZBufferOrderRadioButton->Bind(wxEVT_RADIOBUTTON, [this](wxCommandEvent &event)
                                             {
            settings.zBufferOrder = Settings::ZBufferOrder::Greater;
            UpdateBoxes();
            PostSettingsChangedEvent(); });
    }

    void PostSettingsChangedEvent()
    {
        wxCommandEvent event(SETTINGS_CHANGED_EVENT);
        event.SetEventObject(this);
        ProcessWindowEvent(event);
    }
};