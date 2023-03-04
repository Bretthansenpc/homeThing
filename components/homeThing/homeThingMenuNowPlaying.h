
#pragma once

#include <string>
#include <vector>
#include "esphome/components/display/display_buffer.h"
#include "esphome/components/homeThing/homeThingMenuDisplayState.h"
#include "esphome/components/homeThing/homeThingMenuGlobals.h"
#include "esphome/components/homeThing/homeThingMenuTextHelpers.h"
#include "esphome/components/homeThing/homeThingMenuTitle.h"
#include "esphome/components/homeassistant_media_player/HomeAssistantMediaPlayerGroup.h"

namespace esphome {
namespace homething_menu_base {

class HomeThingMenuNowPlaying {
 public:
  HomeThingMenuNowPlaying(
      display::DisplayBuffer* new_display_buffer,
      HomeThingMenuDisplayState* new_display_state,
      HomeThingMenuTextHelpers* new_text_helpers,
      homeassistant_media_player::HomeAssistantMediaPlayerGroup*
          new_speaker_group)
      : display_buffer_(new_display_buffer),
        display_state_(new_display_state),
        text_helpers_(new_text_helpers),
        speaker_group_(new_speaker_group) {}
  void drawNowPlaying(int menuIndex);
  void drawSpeakerOptionMenu();
  void drawTVOptionMenu();
  void drawVolumeOptionMenu();
  bool drawOptionMenuAndStop();

 private:
  display::DisplayBuffer* display_buffer_{nullptr};
  HomeThingMenuDisplayState* display_state_{nullptr};
  HomeThingMenuTextHelpers* text_helpers_{nullptr};
  homeassistant_media_player::HomeAssistantMediaPlayerGroup* speaker_group_;

  std::string secondsToString(int seconds);
  void drawMediaDuration();
  std::string stringForNowPlayingMenuState(NowPlayingMenuState state);
  std::vector<NowPlayingMenuState> getNowPlayingMenuStates();
  void drawNowPlayingSelectMenu(int menuIndex);
  std::vector<std::string>* getWrappedTitles(int xPos, int fontSize,
                                             display::TextAlign alignment,
                                             std::string text);
  int drawTextWrapped(int xPos, int yPos, int fontSize, display::Font* font,
                      Color color, display::TextAlign alignment,
                      std::vector<std::string> wrappedTitles, int maxLines);
};
}  // namespace homething_menu_base
}  // namespace esphome