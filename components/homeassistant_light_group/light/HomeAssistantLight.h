#pragma once
#include <algorithm>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include "TextHelpers.h"
#include "esphome/components/api/custom_api_device.h"
#include "esphome/components/light/light_output.h"
#include "esphome/components/light/light_state.h"
#include "esphome/core/component.h"
#include "esphomeRemoteCommon.h"

#define MAX_BRIGHTNESS 255.0f

namespace esphome {
namespace homeassistant_light {

enum ColorModeType {
  // unknown_type, <- we only need supported modes
  // onoff_type, <- we only need supported modes
  brightness_type,
  color_temp_type,
  hs_type,
  rgb_type,
  rgbw_type,
  rgbww_type,
  white_type,
  xy_type
};

class HomeAssistantLightState : public light::LightState {
  using LightState::LightState;
};

class HomeAssistantLight : public light::LightOutput,
                           public EntityBase,
                           public Component,
                           public api::CustomAPIDevice {
 public:
  int min_mireds = 0;
  int max_mireds = 0;

  void setup() override;
  void set_entity_id(const std::string& entity_id) { entity_id_ = entity_id; }
  light::LightTraits get_traits() override;
  void add_on_state_callback(std::function<void()>&& callback);
  void increaseProperty(int max, bool* inSync, int* localValue, int incStep,
                        std::string serviceProperty, bool wrapData = false);
  void decreaseProperty(int min, bool* inSync, int* localValue, int decStep,
                        std::string serviceProperty, bool wrapData = false);
  void decTemperature();
  void incTemperature();
  void decBrightness();
  void incBrightness();
  void decColor();
  void incColor();
  void setAttribute(const std::map<std::string, std::string>& data);
  bool supportsBrightness();
  bool supportsColorTemperature();
  bool supportsColor();
  std::shared_ptr<MenuTitleSlider> makeSlider(
      int min, int max, int value, std::string title, std::string unit,
      int displayUnitMin, int displayUnitMax, int displayWidth);
  std::vector<std::shared_ptr<MenuTitleBase>> lightTitleItems(int displayWidth);
  int hsv_color();
  Color rgbLightColor();
  std::string icon();
  void setup_state(light::LightState* state) override;
  void update_state(light::LightState* state) override;
  void publish_api_state(light::LightState* state);
  void write_state(light::LightState* state) override;
  bool get_state();
  bool next_api_publish_ = false;

 private:
  CallbackManager<void()> state_callback_{};
  std::string entity_id_;
  light::LightState* light_state_{nullptr};
  light::LightTraits light_traits_ = light::LightTraits();
  void subscribe_states();
  void state_changed(std::string state);
  void min_mireds_changed(std::string state);
  void max_mireds_changed(std::string state);
  void brightness_changed(std::string state);
  void color_temp_changed(std::string state);
  optional<light::ColorMode> parse_color_mode(std::string color_mode);
  void update_supported_color_mode(light::ColorMode mode);
  void color_changed(std::string state);
  void color_mode_changed(std::string state);
  void supported_color_modes_changed(std::string state);
  uint32_t min_value_ = 0;
  uint32_t max_value_ = 255;
  uint32_t color_temperature_max_value_ = 500;
};

}  // namespace homeassistant_light
}  // namespace esphome