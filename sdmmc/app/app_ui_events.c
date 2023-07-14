// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.2.3
// LVGL version: 8.3.4
// Project name: chat_gpt_new_gui

#include "app_sr.h"

#include "ui.h"
#include "app_ui_ctrl.h"
#include"open_ai.h"


void EventBtnSetupClick(lv_event_t *e)
{
    // Your code here
    ui_sleep_show_animation();
}

void EventPanelSleepClickCb(lv_event_t *e)
{
    // Your code here
    app_sr_start_once();
    printf("sr start once\n");
}

void EventSettingsRegionValueChange(lv_event_t *e)
{
    if (lv_dropdown_get_selected(lv_event_get_target(e)) == 0) {
        set_server(REGION_Espressif);
    } else {
        set_server(REGION_OpenAI);
    }
}
