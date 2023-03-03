#pragma once

#include <string>
#include "esphome/components/homeThing/homeThingMenuDisplayState.h"
#include "esphome/components/homeThing/homeThingMenuGlobals.h"
#include "esphome/components/homeThing/homeThingMenuTextHelpers.h"
#include "esphome/components/homeThing/homeThingMenuTitle.h"
#include "esphome/components/homeassistant_light_group/HomeAssistantLightGroup.h"
#include "esphome/components/homeassistant_media_player/HomeAssistantMediaPlayerGroup.h"

namespace esphome {
namespace homething_menu_base {

class HomeThingMenuHeader {
 public:
  HomeThingMenuHeader(
      display::DisplayBuffer* new_display_buffer,
      HomeThingMenuDisplayState* new_display_state,
      HomeThingMenuTextHelpers* new_text_helpers,
      homeassistant_media_player::HomeAssistantMediaPlayerGroup*
          new_speaker_group,
      homeassistant_light_group::HomeAssistantLightGroup* new_light_group)
      : display_buffer_(new_display_buffer),
        display_state_(new_display_state),
        text_helpers_(new_text_helpers),
        speakerGroup(new_speaker_group),
        lightGroup(new_light_group) {}
  void drawHeader(int yPosOffset, const MenuStates activeMenuState);

 private:
  void drawHeaderTitleWithString(std::string title, int xPos,
                                 int yPosOffset = 0);
  void drawHeaderTitle(int yPosOffset, const MenuStates activeMenuState);
  int drawPlayPauseIcon(int oldXPos, MenuTitlePlayer menuTitle);
  int getHeaderTextYPos(int yPosOffset);
  int drawBattery(int oldXPos, int yPosOffset);
  int drawHeaderIcon(std::string title, int xPos, Color iconColor);
  int drawHeaderTime(int oldXPos, int yPosOffset);
  int drawShuffle(int oldXPos, int yPosOffset);
  int drawHeaderVolumeLevel(int oldXPos, int yPosOffset);
  homeassistant_media_player::HomeAssistantMediaPlayerGroup* speakerGroup;
  homeassistant_light_group::HomeAssistantLightGroup* lightGroup;
  display::DisplayBuffer* display_buffer_{nullptr};
  HomeThingMenuDisplayState* display_state_{nullptr};
  HomeThingMenuTextHelpers* text_helpers_{nullptr};
  sensor::Sensor* battery_percent_{nullptr};
  time::RealTimeClock* esp_time_{nullptr};
};

}  // namespace homething_menu_base
}  // namespace esphome
